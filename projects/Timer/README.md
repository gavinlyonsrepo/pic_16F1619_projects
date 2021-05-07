  
Overview
-----------------------------
* Name: Timer/Alarm unit
* Description: Timer/Alarm unit using a 3 digit, common anode, 7 segment display.

Features
----------------------

The time is selected by potentiometer. A push button is used to start and restart timer,
also during countdown mode the push button turns on/off display to save power.
Sound output is a passive buzzer driven by PWM.

The display used here is a 3 digit, seven segment, common anode, red . 2381BS.
Port C is connected to the 8 segments. RC0 to a .. RC7 to DP point. i.e. R7R6R5R4R3R2R1R0 <=> Dpgfedcba .
Most of Port B is used to control the digits.  D1-D2-D3. <=> RB6-RB5-RB4 where D1 is LSB.
The decimal point of D3 is used as a status LED. ON in ADC mode and blinking in countdown mode.

![ picture ](https://github.com/gavinlyonsrepo/FourteenSegDisplay/blob/master/extra/image/7seg2.jpg)

1. RB7 = Push button.
2. RA4 = Connected thru a 10-bit ADC to sensor input of potentiometer.
3. RA1 = PWM for Passive buzzer 2 Kh.

Timer1 is controlling the clock timing
Timer2 is used to generate PWM for the passive buzzer.

Schematic
------------------------

Note:
I avoid using transistor switching on the digits by using 680 ohm current resistors on the segments
The disadvantage being the display is dimmer. Do not use lower than 600 ohm resistors.

1. Vcc-Vd/Rd = I , (5-2)/680 = 4.4mA
2. I * No of LEDS = 4.4mA * 8 = 35mA, "worst case"
3. The absolute limit of a I/O pin on this PIC is 50mA.

![ Schematic ](https://github.com/gavinlyonsrepo/pic_16F1619_projects/blob/master/images/Timer.png)
