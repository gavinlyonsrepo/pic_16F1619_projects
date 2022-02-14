/*
* File: HD44780_I2C_lcd.h
* Description: 
 * HD44780-based character LCD 16x02 I2C(PCF8574) library header file
* Author: Gavin Lyons.
* Complier: xc32 v4.00 compiler
* PIC: PIC32CM1216CM00032
* IDE:  MPLAB X v6.00 , Harmony V3
* Created : Feb 2022
* Description: See URL for full details.
* URL: https://github.com/gavinlyonsrepo/pic_32_projects
*/

#include <stdint.h>
#include <stdbool.h>
#include "mcc_generated_files/mcc.h"

#ifndef LCD_HD44780_H
#define LCD_HD44780_H

// Section: Defines 

#define LCD_SLAVE_ADDRESS 0x27 //I2C  address for I2C module PCF8574 backpack on LCD

// Command Byte Codes See  URL : dinceraydin.com/lcd/commands.htm for HD44780 CMDs

#define LCD_MODE_8BIT 0x38 // Function set (8-bit interface, 2 lines, 5*7 Pixels)
#define LCD_MODE_4BIT 0x28 // Function set (4-bit interface, 2 lines, 5*7 Pixels)

#define LCD_SCROLL_RIGHT 0x1E // Scroll display one character right (all lines)
#define LCD_SCROLL_LEFT 0x18 // Scroll display one character left (all lines)
#define LCD_HOME  0x02 // Home (move cursor to top/left character position)

#define LCD_MOV_CURSOR_LEFT 0x10 // Move cursor one character left
#define LCD_MOV_CURSOR_RIGHT 0x14 //Move cursor one character right

#define LCD_INC_MODE 0x06 // Entry mode set Display Shift 
                        // OFF Increment Address Counter(can be set 4 to 7)

#define LCD_DISPLAY_ON 0x0C  // Restore the display (with cursor hidden) 
#define LCD_DISPLAY_OFF 0x08 // Blank the display (without clearing)
#define LCD_CLRSCR 0x01 // clear screen

#define LCD_LINE_ADR1 0x80 // Set cursor position (DDRAM address) 80+ addr
#define LCD_LINE_ADR2 0xC0 // Set cursor position line 2 (DDRAM address) C0+ addr

#define LCD_CG_RAM 0x40 //Set pointer in character-generator RAM (CG RAM address)	


typedef enum 
{
    CURSOR_OFF= 0x0C, // Make cursor invisible
    CURSOR_BLINK = 0x0D, // Turn on blinking-block cursor
    CURSOR_ON = 0x0E, // Turn on visible  underline cursor
    CURSOR_ON_BLINK  = 0x0F, // Turn on blinking-block cursor + visible underline curso
}LCD_CURSOR_TYPE_e; // Cursor mode


typedef enum 
{
    MOVE_RIGHT= 1, // move right 
    MOVE_LEFT = 2, // move left
}LCD_DIRECTION_TYPE_e; // Direction mode for scroll and move

// Codes for I2C byte, 
// Byte = DATA-led-en-rw-rs (en=enable rs = reg select)(led always on rw always write)
#define DATA_BYTE_ON 0x0D //enable=1 and rs =1 1101  DATA-led-en-rw-rs
#define DATA_BYTE_OFF 0x09 // enable=0 and rs =1 1001 DATA-led-en-rw-rs
#define CMD_BYTE_ON 0x0C  // enable=1 and rs =0 1100 COMD-led-en-rw-rs 
#define CMD_BYTE_OFF 0x08 // enable=0 and rs =0 1000 COMD-led-en-rw-rs 
#define LCD_BACKLIGHTON_MASK 0x0F // XXXX-1111 , XXXX = don't care 
#define LCD_BACKLIGHTOFF_MASK 0x07 // XXXX-0111


// Section: Function prototypes 
void PCF8574_LCDInit (LCD_CURSOR_TYPE_e);
void PCF8574_LCDDisplayON(bool );
void PCF8574_LCDResetScreen(LCD_CURSOR_TYPE_e);

void PCF8574_LCDSendCmd (unsigned char cmd);
void PCF8574_LCDSendData (unsigned char data);

void PCF8574_LCDClearLine (uint8_t lineNo);
void PCF8574_LCDClearScreen(void);

void PCF8574_LCDSendString (char *str);
void PCF8574_LCDSendChar (char data);

void PCF8574_LCDMoveCursor(LCD_DIRECTION_TYPE_e, uint8_t moveSize);
void PCF8574_LCDScroll(LCD_DIRECTION_TYPE_e, uint8_t ScrollSize);
void PCF8574_LCDGOTO(uint8_t  row, uint8_t  col);

void PCF8574_LCDCreateCustomChar(uint8_t location, uint8_t* charmap);

void PCF8574_LCDBackLightSet(bool);

#endif