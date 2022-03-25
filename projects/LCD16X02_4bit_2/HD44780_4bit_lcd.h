/*
 * File: HD44780_I2C_lcd.h
 * Description:
 * HD44780-based character LCD 16x02 4 bit mode library header file
 * Author: Gavin Lyons.
*/

#include <stdint.h>
#include <stdio.h>                      // vsprintf
#include <stdarg.h>                     // varg

#include "mcc_generated_files/mcc.h"

#ifndef LCD_HD44780_FOUR_H
#define LCD_HD44780_FOUR_H

// Section: Defines

// Command Byte Codes See  URL : dinceraydin.com/lcd/commands.htm for HD44780 CMDs

#define LCD_MODE_8BIT 0x38 // Function set (8-bit interface, 2 lines, 5*7 Pixels)
#define LCD_MODE_4BIT 0x28 // Function set (4-bit interface, 2 lines, 5*7 Pixels)

#define LCD_SCROLL_RIGHT 0x1E // Scroll display one character right (all lines)
#define LCD_SCROLL_LEFT 0x18 // Scroll display one character left (all lines)
#define LCD_MOV_CURSOR_LEFT 0x10 // Move cursor one character left
#define LCD_MOV_CURSOR_RIGHT 0x14 //Move cursor one character right

#define LCD_DISPLAY_ON 0x0C  // Restore the display (with cursor hidden)
#define LCD_DISPLAY_OFF 0x08 // Blank the display (without clearing)
#define LCD_CLRSCR 0x01 // clear screen
#define LCD_HOME  0x02 // Home (move cursor to top/left character position)

#define LCD_LINE_ADR1 0x80 // Set cursor position (DDRAM address) 80+ addr
#define LCD_LINE_ADR2 0xC0 // Set cursor position line 2 (DDRAM address) C0+ addr
#define LCD_LINE_ADR3_20  0x94 // line 3 untested no part, for 20x04 
#define LCD_LINE_ADR4_20  0xD4 // line 4 untested no part, for 20x04 
#define LCD_LINE_ADR3_16  0x90 // line 3 untested no part, for 16x04
#define LCD_LINE_ADR4_16  0xD0 // line 4 untested no part, for 16x04  
#define LCD_CG_RAM 0x40 //Set pointer in character-generator RAM (CG RAM address)


// Section: enums

typedef enum {
    LCDEntryModeOne = 0x04, // Display Shift :OFF Decrement Address Counter
    LCDEntryModeTwo = 0x05, // Display Shift :ON  Decrement Address Counter 	
    LCDEntryModeThree = 0x06, // Display Shift :OFF Increment Address Counter, default 
    LCDEntryModeFour = 0x07, // Display Shift :ON Increment Address Counter
} LCDEntryMode_e; // Entry mode  set command

typedef enum {
    LCDCursorTypeOff = 0x0C, // Make cursor invisible
    LCDCursorTypeBlink = 0x0D, // Turn on blinking-block cursor
    LCDCursorTypeOn = 0x0E, // Turn on visible  underline cursor
    LCDCursorTypeOnBlink = 0x0F, // Turn on blinking-block cursor + visible underline cursor
} LCDCursorType_e; // Cursor mode

typedef enum {
    LCDMoveRight = 1, // move right
    LCDMoveLeft = 2, // move left
} LCDDirectionType_e; // Direction mode for scroll and move

typedef enum {
    LCDLineNumberOne = 1, // row 1
    LCDLineNumberTwo = 2, // row 2
    LCDLineNumberThree = 3, // row 3
    LCDLineNumberFour = 4, // row 4
} LCDLineNumber_e; // line number 


// Section: Function prototypes
void LCDInit(LCDCursorType_e c, uint8_t row, uint8_t col);
void LCDDisplayON(bool onOff);
void LCDResetScreen(LCDCursorType_e c);
void LCDBackLightSet(bool onOff);
void LCDClearLine(LCDLineNumber_e lineNo);
void LCDClearScreen(void);
void LCDClearScreenCmd(void);
void LCDHome(void);
void LCDMoveCursor(LCDDirectionType_e, uint8_t moveSize);
void LCDScroll(LCDDirectionType_e, uint8_t ScrollSize);
void LCDGOTO(LCDLineNumber_e, uint8_t col);

void LCDSendCmd(unsigned char cmd);
void LCDSendData(unsigned char data);
void LCDSendString(char *str);
void LCDSendChar(char data);
void LCDCreateCustomChar(uint8_t location, uint8_t* charmap);
void LCDPrintCustomChar(uint8_t location);
int LCDPrintf(const char *fmt, ...);

void LCDdisplay(unsigned char value)  ;
void LCDtoggle(void);
#endif