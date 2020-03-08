
Table of contents
---------------------------

  * [Overview](#overview)
  * [Features](#features)
  * [Schematic](#schematic)
  
Overview
--------------------------------------------
* Name: LM35
* Description: Display LM35 sensor data on 3 digit, common anode, 7 segment display.
* Author: Gavin Lyons.
* Complier: xc8 v2.10 compiler
* PIC: PIC16F1619 
* IDE:  MPLAB X v5.30

Features
----------------------


The display used here is a 3 digit, seven segment, common anode, red . 2381BS.
Port C is connected to the 8 segments. RC0 to a .. RC7 to DP point. i.e. R7R6R5R4R3R2R1R0 <=> Dpgfedcba .
Port B is used to control the digits.  D1D2D3 <=> RB6RB5RB4 where D1 is LSB.
The switching is done thru a PNP transistor switch circuit.
The decimal point of D2 is switched so 19.35 C is displayed as 19.3

![picture](https://github.com/gavinlyonsrepo/FourteenSegDisplay/blob/master/extra/image/7seg2.jpg)

Port A is used to read sensor and control optional status LED.

RA4 = Connected thru a 10-bit ADC to sensor input of LM35 temperature sensor.
RA2 = Status LED, optional, blinks every 4 seconds and at start up during a brief initialise delay. 
The blink represents a sensor data read. The timing is controlled by timer0

** LM35 sensor**

The LM35 outputs a signal on pin Vout. The LM35 is read via an analog input(RA4) 10mV per degree. 
The ADC 10-bit resolution for 5V / 2^10 = 5/1024 = 0.004883.

LM35 calculation:

Vout = ADC_value * (VCC/ADC resolution).

For example ADC_value reading = 40., Assume vdd is 5 volts.

1. Vout=0.01/°C
2. °C=Vout/0.01
3. °C=Vout*100
4. °C = ADC_value * (0.00488) * 100)
5. °C * 1000 = ADC_value * (0.00488) * 100000)  Note: Turn 0.00488 into 488 to avoid using float by * 1000
6. °C * 1000 = 40 * 488
7. °C * 1000 = 19520  Note: The RHS can then be parsed by code and displayed.
8. °C = 19.52°C

There is a define at top of file where ADC resolution can be set.
The ADC is setup for 5v so Vdd must be 5v this define can be adjusted for any variance in Vdd.
So for example for vdd 4.9  = 4.9/1023 = 480. 
There is also an optional offset define which can be used by user to calibrate sensor, IF it is required.


![ picture ](https://github.com/gavinlyonsrepo/pic_16F1619_projects/blob/master/images/LM35out.jpg)


Schematic
------------------------

Note:
You can leave out the pnp transistors and connect the 3 Dx , Digit common lines directly to PIC I/O
if the value of the 8 current limiting reistors is increased to at least 680 ohms.
The disadvantage being the display is dimmer. Also the code will have to changed
All Statements which switch Dx digits levels will have to be swapped.

1. Vcc-Vd/Rd = I , 5-2/680 = 4.4mA
2. I * No of LEDS = 4.4mA * 8 = 35mA
3. The absoulte limit of a PIC on this PIC is 50mA.

![ Schematic ](https://github.com/gavinlyonsrepo/pic_16F1619_projects/blob/master/images/LM35.png)
