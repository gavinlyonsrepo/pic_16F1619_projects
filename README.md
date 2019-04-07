
![PIC](https://github.com/gavinlyonsrepo/pic_16F1619_projects/blob/master/images/pic16f1619.jpg)

Overview
--------------------------------------------
* Name: pic_16F1619_projects
* Description: A set of projects for a **Microchip** 
 PIC 16F1619 Micro-controller, written in C (xc8 complier).
* Author: Gavin Lyons 

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
A set of Projects and example code for the 20-pin, 8-bit PIC 16F1619 Microcontroller,
made by *Microchip*. 

This is the PIC that was in included with the
DM164137 - Development Kit, Curiosity, Integrated Programmer/Debugger,
which supports 8/14/20 Pin 8-Bit PIC MCU's. 
The curiosity board was used during the development of these programs.

![PICTURE](https://github.com/gavinlyonsrepo/pic_16F1619_projects/blob/master/images/pcb.jpg)

Each Project has a short Readme, schematic and code files
in the relevant sub folder. All code is written in C(xc8 compiler)


**Project Code List:**

| Num | Desc | Link |
| --- | --- | --- |
| 1  | Seven segment display displaying Analog input data | [URL](projects/SevenSeg) |
| 2  | Seven segment displaying DHT11 sensors data | [URL](projects/DHT11) |
| 3 |  HD44780-based LCD 16x02 displaying Analog input data (4 bit mode, 3 pins) | [URL](projects/LCD16x02)|
| 4 |  HD44780-based LCD 16x02 library  (8-bit mode , 11 pins)| [URL](projects/LCD16x02_8bit)  |
| 5 |  HD44780-based LCD 16x02 library I2C bus & PCF8574 interface (2 pins) |[URL](projects/LCD16x02_I2C)  |
| 6 |  SSD1306 OLED 128 by 32 library ( ASCII, text only) | [URL](projects/OLED_I2C)|
| 7 | ----------- | --------------- |
| 8 | ----------- | --------------- |
| 9 | ----------- | --------------- |

Eagle Library
--------------
In the "lib" sub-folder there is a custom eagle library file (PIC_parts.lbr) for the PIC 16F1619 (DIL package)
 
 [Eagle library](docs/eagle/eagle_lib)


Communication
-----------
* Contact: Upstream repo at github site below or glyons66@hotmail.com
* Upstream repository: https://github.com/gavinlyonsrepo/pic_16F1619_projects

Copyright
---------
Copyright (C) 2018 Gavin Lyons 
These programs are free software; you can redistribute it and/or modify
it under the terms of the GNU General Public license published by
the Free Software Foundation, see LICENSE.md in documentation section 
for more details.
