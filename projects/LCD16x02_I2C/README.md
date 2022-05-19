Overview
--------------------------------------------
* Name: LCD16x02_I2C
* Description: 
 Library , LCD 16X02 display HD44780 via the I2C bus and a PCF8574 Interface "backpack" board. 
* Author: Gavin Lyons.
* Complier: xc8 v2.10 compiler
* IDE:  MPLAB X v6.00


Features
----------------------

**HD44780-based character LCD**

HD44780 based character LCD displays use 14 wire connections: 8 data lines (D0-D7), 3 control lines (RS, E, R/W), and three power lines (Vdd, Vss, Vee). Some LCDs come with backlight features that help reading display data in low illumination conditions. They have two additional connections (LED+ and LED- or A and K). The LCD library will also support other sizes eg 20x04.

In this example code, a 4-pin PCF8574 Interface "backpack" board is attached to LCD. It is controlled via the two pin I2C bus. 

1. RB4 = SDA
2. RB6 = SCLK 

The Data is sent in 4-bit mode. The upper nibble holds the data and lower nibble of byte manipulates the control bits of LCD.

![PCF8574 & LCD ](https://github.com/gavinlyonsrepo/pic_16F1619_projects/blob/master/images/LCDPCF.jpg)
