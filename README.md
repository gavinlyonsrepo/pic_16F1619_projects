
![PIC](https://github.com/gavinlyonsrepo/pic_16F1619_projects/blob/master/images/pic16f1619.jpg)

Overview
--------------------------------------------
* Name: pic_16F1619_projects
* Description: A set of projects and libraries for a **Microchip** 
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

Project List
-----------------------------------------
A set of projects, libraries and example code for the 20-pin, 8-bit PIC 16F1619 Microcontroller,
made by *Microchip*. Each Project has a Readme, schematic and code files
in the relevant sub folder. All code is written in C (xc8 compiler).

**Project List:**

| Num | Desc | Link |
| --- | --- | --- |
| 1  | 4 digit 7 segment display, 7 GPIO | [URL](projects/SevenSeg) |
| 2  | 4 digit 7 segment displaying DHT11 sensor data, 7 GPIO| [URL](projects/DHT11) |
| 3 |  4 digit 7 segment 74HC595 based module, 3 GPIO | [URL](projects/SevenSegModule) |
| 4 |  4 digit 7 segment TM1637 based module library, 2 GPIO ,| [URL](projects/TM1637) |
| 5 |  3 digit 7 segment displaying LM35 sensor data, 11 GPIO | [URL](projects/LM35) |
| 6 |  HD44780-based LCD 16x02 library (4 bit mode, shift register, 3 GPIO ) | [URL](projects/LCD16x02)|
| 7 |  HD44780-based LCD 16x02 library (4 bit mode, 6 GPIO ) | [URL](projects/LCD16X02_4bit_2)|
| 8 |  HD44780-based LCD 16x02 library  (8-bit mode , 11 GPIO )| [URL](projects/LCD16x02_8bit)  |
| 9 |  HD44780-based LCD 16x02 library I2C bus & PCF8574 interface,  2 GPIO  |[URL](projects/LCD16x02_I2C)  |
| 10 |  SSD1306 OLED 128 by 32 library I2C bus ( ASCII, text only) 2 GPIO | [URL](projects/OLED_I2C)|
| 11 |  Nokia 5110 LCD PCD8544 controller library ( ASCII, text only)  | [URL](projects/NOKIA) |


Eagle Library
--------------
In the "lib" sub-folder there is a custom eagle library file (PIC_parts.lbr) for the PIC 16F1619 (DIL package)
 
 [Eagle library](docs/eagle/eagle_lib)

