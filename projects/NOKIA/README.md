  
Overview
--------------------------------------------
* Name: Nokia 5110 Text
* Description: Nokia 5110 library LCD display (PCD8544) 
* Author: Gavin Lyons.
* Pic:  pic16f1619 
* Toolchain: xc8 v2.36 , MPLABX IDE v6.00 , MCC v5

Features
----------------------

This is pic version of my[Arduino Library here](https://github.com/gavinlyonsrepo/NOKIA5110_TEXT)
Full information and pictures of output there. 
Main difference is this is software SPI only.
Also this Pic program memory is limited at 8K.
so you will not be able to use use every single font enabled simultaneously 
+ bitmap data in main.c at same time. The main.c contains a sequence of tests to 
test library. If a font is not enabled nothing will show for that specific test.

GPIO function on PIC, 5 Nokia 5110 LCD lines Software SPI bus

| Pic 16F1619 pin  | Nokia 5110 LCD |
| ------ | ------ |
| RC4 | LCD_CLK Pin 5 clock in |
| RC3 | LCD_DIN Pin 4 data in |
| RC2 | LCD_DC Pin 3 data/command|
| RC1 | LCD_CE Pin 2 chip enable |
| RC0 | LCD_RST Pin 1 reset|


[Nokia 5110 LCD dataSheet ](https://www.sparkfun.com/datasheets/LCD/Monochrome/Nokia5110.pdf)

Pinout:

![PICTURE](https://github.com/gavinlyonsrepo/pic_16F1619_projects/blob/master/images/NOKIA2.jpg)
