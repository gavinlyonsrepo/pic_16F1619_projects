/*
 * Project Name: NOKIA5110_TEXT
 * File: NOKIA5110_TEXT.h
 * Description: Nokia library header file  
 * Author: Gavin Lyons.
 * URL: https://github.com/gavinlyonsrepo/pic_16F1619_projects
 */

#ifndef NOKIA5110_TEXT_H
#define NOKIA5110_TEXT_H

// Section :: libraries 
#include <stdint.h>
#include <stdbool.h>
#include "mcc_generated_files/mcc.h"


// Section :: Defines 

//LCD Commands PCD8544_
#define LCD_COMMAND_MODE 0x21  //FUNCTIONSET + extended instruction
#define LCD_CONTRAST     0xBF  //Set LCD VOP Contrast Try 0xB1 or 0xBF if is too dark range = ((0x00-0x7F) |0x80)
#define LCD_TEMP_COEF    0x04  //Set Temp coefficient
#define LCD_BIAS         0x14  // //LCD bias mode 1:48: Try 0x13 or 0x14
#define LCD_FUNCTIONSET  0x20  //We must send 0x20 before modifying the display control mode
#define LCD_DISPLAYCONTROL 0x0C //Set display control, normal mode. 0x0D for inverse
#define LCD_DISPLAYCONTROL_INVERSE 0x0D //Set display control, inverse mode. 0x0D for inverse
#define LCD_POWERDOWN    0x24 //LCD power off

//The DC pin tells the LCD if sending a command or data
#define LCD_COMMAND 0
#define LCD_DATA 1

// 84 by 48 pixels screen
#define LCD_X_WIDTH 84
#define LCD_Y_HEIGHT 48

#define LCD_HIGH_FREQ_DELAY 1 // uS delay used in sw SPI at high MC Freq 

// Section :: enums

typedef enum {
    LCDFont_Default = 1, // Default 5X8
    LCDFont_Thick = 2, // Thick 7X8  (NO LOWERCASE LETTERS)
    LCDFont_HomeSpun = 3, // homespun 7X8 
    LCDFont_Seven_Seg = 4, // seven segment 4X8
    LCDFont_Wide = 5, // Wide  8X8 (NO LOWERCASE LETTERS)
    LCDFont_Tiny = 6, // tiny 3x8
    LCDFont_Large = 7, // Large 12 X 16 (no lowercase letters)
    LCDFont_Huge = 8, // Huge 16 X24 (numbers + . : only) 
    LCDFont_Mega = 9 // Mega 16 X 32 (numbers + . : / only)
} LCDFontType_e; // type of font

typedef enum {
    LCDFont_W_3 = 3, // tiny font
    LCDFont_W_4 = 4, // seven segment font
    LCDFont_W_5 = 5, // Default 
    LCDFont_W_7 = 7, // thick + homeSpun
    LCDFont_W_8 = 8, // wide
    LCDFont_W_12 = 12, // large , no lowercase letters
    LCDFont_W_16 = 16 // mega and huge , numbers only
} LCDFontWidth_e; // Size width of fonts in pixels, add padding for font_width < 9

typedef enum {
    LCDFont_O_Full = 0x00, //   full ASCII
    LCDFont_O_Space = 0x20, // Starts at Space
    LCDFont_O_Number = 0x2E, // // ASCII code for . is 0X2E (. / 0 1 etc)
} LCDFontOffset_e; // font offset in the ASCII table

typedef enum {
    LCDPadding_None = 0, // no padding 
    LCDPadding_LHS = 1, // Left hand side padding only
    LCDPadding_RHS = 2, // Right hand side padding only 
    LCDPadding_Both = 3 // LHS + RHS padding
} LCDPaddingType_e; // Padding value

// Section :: Functions prototypes

void LCDInit(bool, uint8_t, uint8_t);
void LCDgotoXY(uint8_t, uint8_t);
void LCDClear(uint8_t);
void LCDClearBlock(uint8_t);
void LCDString(const char *characters);
void LCDsetContrast(uint8_t);
void LCDenableSleep(void);
void LCDdisableSleep(void);
void LCDCharacter(char);
void LCDWrite(unsigned char, unsigned char);
void LCDFont(LCDFontType_e);
void LCDSetPixel(uint8_t, uint8_t);
void LCDFillBlock(uint8_t, uint8_t);
void LCDCustomChar(const unsigned char character[], uint16_t, LCDPaddingType_e);
bool LCDIsSleeping(void);

void LCDDrawFonts1TO6(char character, LCDFontWidth_e); // 8 bit tall fonts
void LCDDrawFonts7(char character); // 16 bit tall fonts
void LCDDrawFonts8TO9(char character); // 24 and 32 bit tall fonts

#endif