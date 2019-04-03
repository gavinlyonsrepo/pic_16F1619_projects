/*
* Project Name: LCD_16x02_8bit
* File: lcd.h 
* Description: HD44780-based character LCD 16x02 8-bit library main file
* Author: Gavin Lyons.
* Complier: xc8 v2.00 compiler
* PIC: PIC16F1619 
* IDE:  MPLAB X v5.00
* Development board: Microchip Curiosity Board, PIC16F1619
* Created March 2019
* Description: See URL for full details.
* URL: https://github.com/gavinlyonsrepo/pic_16F1619_projects
*/

#ifndef LCD_H
#define LCD_H

#define DATAPORT LATC // Port C mapped to LCD

/************** Command Byte Codes ******************/
#define LCD_LINE1 0x80
#define LCD_LINE2 0xC0
#define CLRSCR 0x01
#define DISPLAY_ON 0x0C
#define DISPLAY_OFF 0x08
#define CURSOR_ON 0x0A
#define CURSOR_OFF 0x08
#define CURSOR_INC 0x06
#define MODE_8BIT 0x38
#define MODE_4BIT 0x28

/************* Function prototypes */
void LCD_init(void);
void LCD_data(unsigned char data);
void LCD_cmd(unsigned char cmd);
void LCD_string(const char *ptr);
void LCD_isbusy(void);
#endif