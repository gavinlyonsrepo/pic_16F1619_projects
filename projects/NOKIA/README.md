
Table of contents
---------------------------

  * [Overview](#overview)
  * [Features](#features)
  * [Schematic](#schematic)
  
Overview
--------------------------------------------
* Name: Nokia 5110
* Description: Nokia 5110 library LCD display(PCD8544) ASCII text only
* Author: Gavin Lyons.
* Complier: xc8 v2.00 compiler
* PIC: PIC16F1619 
* IDE:  MPLAB X v5.00
* Arduino: This library was forked to arduino and expanded it is in the arduino [library manager](https://github.com/gavinlyonsrepo/NOKIA5110_TEXT)

Features
----------------------

The Nokia 5110 is a basic graphic LCD screen for lots of applications. 
It was originally intended to be used as a cell phone screen.  
It uses the PCD8544 controller, which is the same used in the Nokia 3310 LCD. 
The PCD8544 is a low power CMOS LCD controller/driver, designed to drive a graphic display of 48 rows and 84 columns. 
All necessary functions for the display are provided in a single chip, including on-chip generation of LCD supply and bias voltages, 
resulting in a minimum of external components and low power consumption. 
The PCD8544 interfaces to microcontrollers through a serial bus interface(SPI).
I did not use the MCC or the in-built SPI hardware for this library,
it uses bit banging/software SPI. 

GPIO function on PIC, 5 Nokia 5110 LCD lines SPI bus

| Pic 16F1619 pin  | Nokia 5110 LCD |
| ------ | ------ |
| RC0 | LCD_CLK Pin 5 clock in |
| RC1 | LCD_DIN Pin 4 data in |
| RC2 | LCD_DC Pin 3 data/command|
| RC3 | LCD_CE Pin 2 chip enable |
| RC4 | LCD_RST Pin 1 reset|

Connect Nokia 5110 VCC(pin 6)to 3.3V, many may appear work at 5V
but they are not supposed to and may
overtime fail or work intermittently.
The user may have to adjust LCD contrast and bias settings in code
to the screen at hand for optimal display.
These settings are in the LCDinit function.
A resistor or potentiometer can be connected between (Nokia LCD) GND(pin8) and LIGHT(pin7) to switch on backlight
and adjust it. 

The library has 3 files (nokia.c nokia.h and font.h).
The goto function can be passed X and Y co-ords.
The X range(columns) is 0-80 or 0-0x53.
The Y range(rows) is 0-5 i.e the 48 pixels are divided by 6 row blocks. 
Each block containing one byte in height. 6 * 8 = 48.

The ASCII library is in file font.h, Each character is 5 pixel wide. Plus one pixel of empty space on each side.
Also each character is a byte of pixels in height.
So each character is in a 7 by 8 pixel block. So you can fit (84/7) 12 characters in each row block and with 6 row blocks that gives 72 characters in total (12X06).

This library is minimalist. This library is ASCII text only. 
This example program takes just 3% of data and 12% of program  space.

RA2 = Status LED, toggles every 2 seconds , screen is refreshed on toggle.

[Nokia 5110 LCD dataSheet ](https://www.sparkfun.com/datasheets/LCD/Monochrome/Nokia5110.pdf)

Library output sample:

![PICTURE](https://github.com/gavinlyonsrepo/pic_16F1619_projects/blob/master/images/NOKIA.jpg)

Pinout:

![PICTURE](https://github.com/gavinlyonsrepo/pic_16F1619_projects/blob/master/images/NOKIA2.jpg)

Schematic
------------------------

![PICTURE ](https://github.com/gavinlyonsrepo/pic_16F1619_projects/blob/master/images/NOKIA5110.png)
