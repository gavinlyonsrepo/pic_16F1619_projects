/*
 * Project Name: Nokia 5110 ASCII text
 * File: NOKIA5110_TEXT.c
 * Description: Nokia library c file
 * Description: See URL for full details.
 * URL: https://github.com/gavinlyonsrepo/pic_16F1619_projects
 */

#include "mcc_generated_files/mcc.h"

#include "NOKIA5110_TEXT.h"
#include "NOKIA5110_TEXT_FONT_DATA.h"

uint8_t _contrast = LCD_CONTRAST;
uint8_t _FontNumber = LCDFont_Default;
uint8_t _bias = LCD_BIAS;
bool _sleep = false;
bool _inverse = false;
uint8_t _Block = 0;
uint8_t _Col = 0;

/*Function : LCDinit
This sends the  commands to the PCD8544 to  init LCD
 */
void LCDInit(bool Inverse, uint8_t Contrast, uint8_t Bias) {

    _inverse = Inverse;
    _contrast = Contrast;
    _bias = Bias;

    //Configure control pins
    LCD_DIN_SetLow();
    LCD_CLK_SetLow();
    LCD_DC_SetLow();
    //Reset the LCD to a known state
    LCD_RST_SetLow();
    LCD_RST_SetHigh();
    LCDWrite(LCD_COMMAND, LCD_COMMAND_MODE); //Tell LCD that extended commands follow
    LCDWrite(LCD_COMMAND, _contrast); //Set LCD Vop (Contrast): Try 0xB1(good @ 3.3V) or 0xBF if your display is too dark
    LCDWrite(LCD_COMMAND, LCD_TEMP_COEF); //Set Temp coefficent
    LCDWrite(LCD_COMMAND, _bias); //LCD bias mode 1:48: Try 0x13 or 0x14
    LCDWrite(LCD_COMMAND, LCD_FUNCTIONSET); //We must send 0x20 before modifying the display control mode
    if (_inverse == false)
        LCDWrite(LCD_COMMAND, LCD_DISPLAYCONTROL); //Set display control, normal mode. 0x0D for inverse
    else
        LCDWrite(LCD_COMMAND, LCD_DISPLAYCONTROL_INVERSE); //Set display control, normal mode. 0x0D for inverse
}

/* Function: LCDFont
Param 1:  a LCDFontType_e to set  font
 */
void LCDFont(LCDFontType_e FontNumber) {
    _FontNumber = FontNumber;
}

/* Function: LCDClear
Clears the LCD by writing data to the entire screen
 * param1: datapattern to be written 0x00 to 0xFF
 */
void LCDClear(uint8_t FillData) {
    for (uint16_t index = 0; index < (LCD_X_WIDTH * LCD_Y_HEIGHT / 8); index++) {
        LCDWrite(LCD_DATA, FillData);
    }
    LCDgotoXY(0, 0); //After we clear the display, return to the home position
}

/* Function: LCDClear
Clears one of the 6 row blocks(one byte height) on LCD
by writing zeros to the line. Send the row block number 0-5
 */
void LCDClearBlock(uint8_t RowBlockNum) {
    LCDgotoXY(0, RowBlockNum);
    for (uint8_t index = 0; index < (LCD_X_WIDTH); index++) {
        LCDWrite(LCD_DATA, 0x00);
    }
}

/* Function: gotoXY gotoXY routine to position cursor
 x - range: 0 to 84 (0 to 0x53)
 y - range: 0 to 5 ( 6 blocks one byte each 6*8 = 48*/
void LCDgotoXY(uint8_t x, uint8_t y) {
    LCDWrite(LCD_COMMAND, 0x80 | x); // Column. (result 0x80 to 0xD3)
    LCDWrite(LCD_COMMAND, 0x40 | y); // Row.
    _Block = y;
    _Col = x;
}

/* Function: LCDWrite
There are two  banks in the LCD, data and commands. This
function sets the DC pin high or low depending, and then sends
the data byte
 */
void LCDWrite(unsigned char data_or_command, unsigned char data) {
    unsigned char i, d;
    d = data;
    if (data_or_command == 0)LCD_DC_SetLow();
    else LCD_DC_SetHigh();
    //data_or_command;
    //Tell the LCD that we are writing either to data or a command
    //Send the data
    LCD_CE_SetLow();
    for (i = 0; i < 8; i++) {
        LCD_DIN_SetLow();
        if (d & 0x80)LCD_DIN_SetHigh(); // b1000000 Mask with 0 & all zeros out.
        LCD_CLK_SetHigh();
        d <<= 1;
        __delay_us(LCD_HIGH_FREQ_DELAY);
        LCD_CLK_SetLow();
    }
    LCD_CE_SetHigh();
}

/* Function: LCDCharacter.
 This function takes in a character, and  based on set font calls
 * relevant drawing function
 */
            
void LCDCharacter(char character) {
    switch (_FontNumber) {
        case LCDFont_Default: LCDDrawFonts1TO6(character, LCDFont_W_5);
            break;
        case LCDFont_Thick: LCDDrawFonts1TO6(character, LCDFont_W_7);
            break;
        case LCDFont_HomeSpun: LCDDrawFonts1TO6(character, LCDFont_W_7);
            break;
        case LCDFont_Seven_Seg: LCDDrawFonts1TO6(character, LCDFont_W_4);
            break;
        case LCDFont_Wide: LCDDrawFonts1TO6(character, LCDFont_W_8);
            break;
        case LCDFont_Tiny: LCDDrawFonts1TO6(character, LCDFont_W_3);
            break;
        case LCDFont_Large: LCDDrawFonts7(character);
            break;
        case LCDFont_Huge: LCDDrawFonts8TO9(character);
            break;
        case LCDFont_Mega: LCDDrawFonts8TO9(character);
            break;
    }
}

/* Function: LCDString.
 Given a string of characters, one by one is passed to the LCD
 */
void LCDString(const char *characters) {
    while (*characters)
        LCDCharacter(*characters++);
}

/* Function: LCDSetPixel
 Function to set one pixel on
 Passed two byte X and Y , Column and row position to set the the bit
 X = 0-83 , Y = 0-47.
 */
void LCDSetPixel(uint8_t col, uint8_t row) {
    uint8_t rowblock = row / 8; //0 -5
    unsigned char PixelPosition;
    LCDgotoXY(col, rowblock);
    PixelPosition = (unsigned char)(1 << (row - (rowblock * 8)));
    LCDWrite(LCD_DATA, PixelPosition);
}

/* Function: LCDSetContrast
 Function to set contrast passed a byte
 Set LCD VOP Contrast, range = ((0x00-0x7F) |0x80) 0xB5 = (0x35|0x80) try B1 - BF normally.
 */
void LCDsetContrast(uint8_t contrast) {
    _contrast = contrast;
    LCDWrite(LCD_COMMAND, LCD_COMMAND_MODE); //Tell LCD that extended commands follow
    LCDWrite(LCD_COMMAND, _contrast); //Set LCD Vop (Contrast):
    LCDWrite(LCD_COMMAND, LCD_FUNCTIONSET); //We must send 0x20 before modifying the display control mode
}

// Put the LCD to Sleep function

void LCDenableSleep() {
    _sleep = true;
    for (uint16_t index = 0; index < (LCD_X_WIDTH * LCD_Y_HEIGHT / 8); index++) {
        LCDWrite(LCD_DATA, 0x00);
    }
    LCDgotoXY(0, 0);
    LCDWrite(LCD_COMMAND, LCD_POWERDOWN);
}

// Wake the LCD up from Sleep function

void LCDdisableSleep() {
    _sleep = false;
    LCDWrite(LCD_COMMAND, LCD_COMMAND_MODE);
    LCDWrite(LCD_COMMAND, _contrast);
    LCDWrite(LCD_COMMAND, LCD_TEMP_COEF);
    LCDWrite(LCD_COMMAND, _bias);
    LCDWrite(LCD_COMMAND, LCD_FUNCTIONSET);
    if (_inverse == false)
        LCDWrite(LCD_COMMAND, LCD_DISPLAYCONTROL); //Set display control, normal mode. 0x0D for inverse
    else
        LCDWrite(LCD_COMMAND, LCD_DISPLAYCONTROL_INVERSE); //Set display control, normal mode. 0x0D for inverse
}

/* Function: LCDCustomChar
 Write a custom character to screen X by Y. Y is fixed at 8
 Parameters 1 Example: 5 by 8 = || || = Char array unsigned char power[5] = {0xFF, 0xFF, 0x00, 0xFF, 0xFF};
 Parameters 2: Size of array,  sizeof(power)/sizeof(unsigned char)
 Parameter 3: Blank vertical line padding  enum  LCDPaddingType_e 4 values
 0 = no padding
 1 = Left hand side padding only
 2 = Right hand side padding only
 3 = LHS + RHS

 */
void LCDCustomChar(const unsigned char character[], uint16_t numChars, LCDPaddingType_e padding) {

    uint16_t column = 0; // max 504 bytes.
    if (padding == LCDPadding_LHS || padding == LCDPadding_Both) {
        LCDWrite(LCD_DATA, 0x00); //Blank vertical line padding , LHS
    }

    for (column = 0; column < numChars; column++) {
        LCDWrite(LCD_DATA, character[column]);
    }

    if (padding == LCDPadding_RHS || padding == LCDPadding_Both) {
        LCDWrite(LCD_DATA, 0x00); //Blank vertical line padding RHS
    }
}

//Desc: takes in character and font width looks it up in the font table/array
//And writes it to the screen , we pad one blank column of
//pixels on each side of the character for readability.
void LCDDrawFonts1TO6(char character, LCDFontWidth_e font_width) {
    LCDWrite(LCD_DATA, 0x00); //Blank vertical line padding , LHS
    for (uint8_t column = 0; column < font_width; column++) {
        switch (_FontNumber) {
            case LCDFont_Default:
#ifdef NOKIA5110_FONT_Default
                LCDWrite(LCD_DATA, FontDefault[character - LCDFont_O_Space][column]);
#endif
                break;
            case LCDFont_Thick:
#ifdef NOKIA5110_FONT_Thick
                LCDWrite(LCD_DATA, FontThick[character - LCDFont_O_Space][column]);
#endif
                break;
            case LCDFont_HomeSpun:
#ifdef NOKIA5110_FONT_HomeSpun
                LCDWrite(LCD_DATA, FontHomeSpun[character - LCDFont_O_Space][column]);
#endif
                break;
            case LCDFont_Seven_Seg:
#ifdef NOKIA5110_FONT_SevenSeg
                LCDWrite(LCD_DATA, FontSevenSegment[character - LCDFont_O_Space][column]);
#endif
                break;
            case LCDFont_Wide:
#ifdef NOKIA5110_FONT_Wide
                LCDWrite(LCD_DATA, FontWide[character - LCDFont_O_Space][column]);
#endif
                break;
            case LCDFont_Tiny:
#ifdef NOKIA5110_FONT_Tiny
                LCDWrite(LCD_DATA, FontTiny[character - LCDFont_O_Space][column]);
#endif
                break;
        }
    }
    LCDWrite(LCD_DATA, 0x00); //Blank vertical line padding RHS
}

// Desc : used to draw fonts: 7 large
// Param1 : passed a char
// Notes: data format
// 0xAABB font 7  16 bit high
// 7
// BB 	Upper byte
// AA   lower byte

void LCDDrawFonts7(char character) {
#ifdef NOKIA5110_FONT_Large
    uint16_t totalchar = 0;
    uint8_t topchar = 0;
    uint8_t botchar = 0;
    uint8_t column = 0;
    //print upper byte
    for (column = 0; column < LCDFont_W_12; column++) {
        totalchar = FontLarge[character - LCDFont_O_Space ][column];
        topchar = totalchar & 0x00FF;
        LCDWrite(LCD_DATA, topchar);
    }
    //Move to next block
    LCDgotoXY(_Col, _Block + 1);
    //print lowerbyte
    for (column = 0; column < LCDFont_W_12; column++) {
        totalchar = FontLarge[character - LCDFont_O_Space ][column];
        botchar = (totalchar >> 8) & 0xFF;
        LCDWrite(LCD_DATA, botchar);
    }
    //move back to upper block
    LCDgotoXY(_Col + LCDFont_W_12, _Block - 1);
#endif
}

// Desc : used to draw fonts: huge and mega , 8 and 9
// Param1 : passed a char
// Notes: data format
// 0xAABBCCDD font 9  32 bit high
// 0x--BBCCDD font 8  24 bit high
// 9    8      Font
// DD  DD	Upper byte
// CC  CC   upper middle byte
// BB  BB   lower middle byte
// AA  --  lower byte , -- = n/a for font 8

void LCDDrawFonts8TO9(char character) {
    uint32_t totaldata = 0;
    uint8_t topbyte = 0;
    uint8_t middleupperbyte = 0;
    uint8_t middlelowerbyte = 0;
    uint8_t lowerbyte = 0;
    uint8_t column = 0;
    //print upper byte  DD
    for (column = 0; column < LCDFont_W_16; column++) {
        if (_FontNumber == LCDFont_Huge) {
#ifdef NOKIA5110_FONT_Huge
            totaldata = FontHuge[character - LCDFont_O_Number][column];
#endif
        } else {
#ifdef NOKIA5110_FONT_Mega
            totaldata = FontMega[character - LCDFont_O_Number][column];
#endif
        }
        topbyte = totaldata & 0xFF;
        LCDWrite(LCD_DATA, topbyte);
    }
    totaldata = 0;
    LCDgotoXY(_Col, _Block + 1); //goto next block

    // print middle upper byte CC
    for (column = 0; column < LCDFont_W_16; column++) {
        if (_FontNumber == LCDFont_Huge) {
#ifdef NOKIA5110_FONT_Huge
            totaldata = FontHuge[character - LCDFont_O_Number][column];
#endif
        } else {
#ifdef NOKIA5110_FONT_Mega
            totaldata = FontMega[character - LCDFont_O_Number][column];
#endif
        }
        middleupperbyte = (totaldata >> 8) & 0xFF;
        LCDWrite(LCD_DATA, middleupperbyte);
    }
    totaldata = 0;
    LCDgotoXY(_Col, _Block + 1); //goto next block

    // print middle lower byte BB
    for (column = 0; column < LCDFont_W_16; column++) {
        if (_FontNumber == LCDFont_Huge) {
#ifdef NOKIA5110_FONT_Huge
            totaldata = FontHuge[character - LCDFont_O_Number][column];
#endif
        } else {
#ifdef NOKIA5110_FONT_Mega
            totaldata = FontMega[character - LCDFont_O_Number][column];
#endif
        }
        middlelowerbyte = (totaldata >> 16) & 0xFF;
        LCDWrite(LCD_DATA, middlelowerbyte);
    }

    // print lower byte AA, no need if printing font 8
    if (_FontNumber == LCDFont_Huge)
        LCDgotoXY(_Col + LCDFont_W_16, _Block - 2); //move back for next character
    else {
        totaldata = 0;
        LCDgotoXY(_Col, _Block + 1); //goto next block
        for (column = 0; column < LCDFont_W_16; column++) {
#ifdef NOKIA5110_FONT_Mega
            totaldata = FontMega[character - LCDFont_O_Number][column];
            lowerbyte = (totaldata >> 24) & 0xFF;
            LCDWrite(LCD_DATA, lowerbyte);
#endif
        }
        LCDgotoXY(_Col + LCDFont_W_16, _Block - 3); //move back for next character
    }

}

bool LCDIsSleeping() {
    return _sleep;
}

// Desc : Fills a row block
// Param 1: Fill pattern 00 to 0xFF
// Param 2: row block number 0 to 5

void LCDFillBlock(uint8_t FillData, uint8_t RowBlockNum) {
    LCDgotoXY(0, RowBlockNum);
    for (uint8_t index = 0; index < (LCD_X_WIDTH); index++) {
        LCDWrite(LCD_DATA, FillData);
    }
}
/* =========== EOF ===========*/
