
Overview
--------------------------------------------
* Name: LCD 16X02 8 bit mode
* Description: Display the data to a  LCD 16x02 display HD44780 using 8-bit mode.
* Author: Gavin Lyons.
* Complier: xc8 v2.00 compiler
* PIC: PIC16F1619 
* IDE:  MPLAB X v5.00
* Development board: Microchip Curiosity Board, PIC16F1619

Table of contents
---------------------------

  * [Overview](#overview)
  * [Features](#features)

Features
----------------------

Display data to a LCD 16x02 in 8-bit mode takes 11 GPIO pins. 

In this folder the main source code in C for program can be found in file main.c
The code  generated using the MPLAB Code Configurator (MCC) tool is  
in folder called mcc_generated_files


1. RA2 = Status LED.


**HD44780-based character LCD**

HD44780 based character LCD displays use 14 wire connections: 8 data lines (D0-D7), 3 control lines (RS, E, R/W), and three power lines (Vdd, Vss, Vee). Some LCDs come with backlight features that help reading display data in low illumination conditions. They have two additional connections (LED+ and LED- or A and K).

The control pin RS determines if the data transfer between the LCD module and an external microcontroller are actual character data or command/status. The enable pin (E) initiates the actual data transfer. When writing to the LCD display, the data is transferred only on the high to low transition of the E pin.
Read/Write(RW): This signal is used to write the data/cmd to LCD and reads the busy flag of LCD. For write operation the RW should be LOW and for read operation the R/W should be HIGH.

The Vdd pin (2) should be connected to the positive power supply and Vss (1) to ground. Pin 3 (Vee) is for display contrast adjustment.

Pins 7 to 14 are data lines (D0-D7). Data transfer to and from the display can be achieved either in 8-bit or 4-bit mode. The 8-bit mode uses all eight data lines to transfer a byte, whereas, in 4-bit mode, a byte is transferred as two 4-bit nibbles. In the later case, only the upper 4 data lines (D4-D7) are used. This design uses 8-bit.

| PIC  Pin | LCD Pin |  	Symbol |	Pin Function  |
| --- | ---  | --- | --- |  
| Ground | 1  |	VSS |	Ground | 
| n/a | 2 |	VCC |	+5v | 
| n/a | 3 |	VEE |	Contrast adjustment (VO) | 
| RB0 |  4 |	RS 	| Register Select. 0:Command, 1: Data | 
| RB1 | 5 |	R/W |	Read/Write, R/W=0: Write & R/W=1: Read | 
| RB2 | 6 |	EN 	 | Enable. Falling edge triggered | 
| RC0 | 7 |	D0 	| Data Bit 0 | 
| RC1 | 8 |	D1 | 	Data Bit 1 | 
| RC2 |  9 |	D2 	| Data Bit 2 | 
| RC3 | 10 |	D3 	| Data Bit 3 | 
| RC4 | 11 |	D4 	| Data Bit 4 | 
| RC5 | 12 |	D5 	| Data Bit 5 | 
| RC6 | 13 |	D6 	| Data Bit 6 | 
| RC7 | 14 |	D7 	| Data Bit 7/Busy Flag | 
| n/a | 15 |	A/LED+ | 	Back-light Anode(+) | 
| n/a | 16 |	K/LED- | 	Back-Light Cathode(-) | 

![pinout](https://github.com/gavinlyonsrepo/pic_16F1619_projects/blob/master/images/LCD.jpg)


There is an lcd.h and lcd.c file which contain the code for an 8-bit library.


Schematic
------------------------

![schematic](https://github.com/gavinlyonsrepo/pic_16F1619_projects/blob/master/images/LCD16x02_8bit.png)