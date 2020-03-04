
![PIC](https://github.com/gavinlyonsrepo/pic_16F1619_projects/blob/master/images/pic16f1619.jpg)

Overview
--------------------------------------------
* Name: pic_16F1619_projects
* Description: A set of projects for a **Microchip** 
 PIC 16F1619 Micro-controller, written in C (xc8 complier).
* Author: Gavin Lyons 
* Contact: Upstream repo at github site below or glyons66@hotmail.com.
* Copyright (C) 2018 Gavin Lyons , see LICENSE.md in documentation section.

Table of contents
---------------------------

  * [Overview](#overview)
  * [Table of contents](#table-of-contents)
  * [Project List](#project-list)
  * [Eagle Library](#eagle-library)
  * [Communication](#communication)
  * [Copyright](#copyright)

Project List
-----------------------------------------
A set of display projects and example code for the 20-pin, 8-bit PIC 16F1619 Microcontroller,
made by *Microchip*. 

This is the PIC that was in included with the
DM164137 - Development Kit, Curiosity, Integrated Programmer/Debugger,
which supports 8/14/20 Pin 8-Bit PIC MCU's. 
The curiosity board was used during the development of these programs.

![PICTURE](https://github.com/gavinlyonsrepo/pic_16F1619_projects/blob/master/images/pcb.jpg)

Each Project has a short Readme, schematic and code files
in the relevant sub folder. All code is written in C (xc8 compiler).


**Project List:**

| Num | Desc | Link |
| --- | --- | --- |
| 1  | 4 digit Seven segment display , 7 GPIO | [URL](projects/SevenSeg) |
| 2  | 4 digit Seven segment displaying DHT11 sensors data, 7 GPIO| [URL](projects/DHT11) |
| 3 |  HD44780-based LCD 16x02 library (4 bit mode, shift register, 3 GPIO ) | [URL](projects/LCD16x02)|
| 4 |  HD44780-based LCD 16x02 library (4 bit mode, 6 GPIO ) | [URL](projects/LCD16X02_4bit_2)|
| 5 |  HD44780-based LCD 16x02 library  (8-bit mode , 11 GPIO )| [URL](projects/LCD16x02_8bit)  |
| 6 |  HD44780-based LCD 16x02 library I2C bus & PCF8574 interface,  2 GPIO  |[URL](projects/LCD16x02_I2C)  |
| 7 |  SSD1306 OLED 128 by 32 library I2C bus ( ASCII, text only) 2 GPIO | [URL](projects/OLED_I2C)|
| 8 |  Nokia 5110 LCD  PCD8544 controller library ( ASCII, text only)  | [URL](projects/NOKIA) |
| 9 |  4 digit Seven segment module 74HC595, 3 GPIO | [URL](projects/SevenSegModule) |
| 10 | 4 digit Seven segment module TM1637 library, 2 GPIO  | [URL](projects/TM1637) |
| 11 | LM35 sensor data on 3 digit 7 segment, 11 GPIO | [URL](projects/LM35) |

Eagle Library
--------------
In the "lib" sub-folder there is a custom eagle library file (PIC_parts.lbr) for the PIC 16F1619 (DIL package)
 
 [Eagle library](docs/eagle/eagle_lib)

