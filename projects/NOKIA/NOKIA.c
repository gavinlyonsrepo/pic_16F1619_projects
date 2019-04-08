/*
* Project Name: Nokia 5110
* File: NOKIA.c
* Description: Nokia library c file
* Author: Gavin Lyons.
* Complier: xc8 v2.00 compiler
* PIC: PIC16F1619 
* IDE:  MPLAB X v5.00
* Development board: Microchip Curiosity Board, PIC16F1619
* Created March 2019
* Description: See URL for full details.
* URL: https://github.com/gavinlyonsrepo/pic_16F1619_projects
*/

#include "NOKIA.h"         
#include "font.h"

/*Function : LCDinit
This sends the  commands to the PCD8544 to  init LCD
*/
void LCDInit(void) {
    //Configure control pins
    LCD_DIN_SetLow();
    LCD_CLK_SetLow();
    LCD_DC_SetLow();
    //Reset the LCD to a known state
    LCD_RST_SetLow();
    LCD_RST_SetHigh();
    LCDWrite(LCD_COMMAND, 0x21); //Tell LCD that extended commands follow
    LCDWrite(LCD_COMMAND, 0xBF); //Set LCD Vop (Contrast): Try 0xB1(good @ 3.3V) or 0xBF if your display is too dark
    LCDWrite(LCD_COMMAND, 0x04); //Set Temp coefficent
    LCDWrite(LCD_COMMAND, 0x14); //LCD bias mode 1:48: Try 0x13 or 0x14
    LCDWrite(LCD_COMMAND, 0x20); //We must send 0x20 before modifying the display control mode
    LCDWrite(LCD_COMMAND, 0x0C); //Set display control, normal mode. 0x0D for inverse
}

/* Function: LCDClear 
Clears the LCD by writing zeros to the entire screen
 */
void LCDClear(void) {
    for (int index = 0 ; index < (LCD_X * LCD_Y / 8) ; index++)
    LCDWrite(LCD_DATA, 0x00);
    LCDgotoXY(0, 0); //After we clear the display, return to the home position
    }

/* Function: gotoXY gotoXY routine to position cursor 
 x - range: 0 to 84 (0 to 0x53)
 y - range: 0 to 5 ( 6 blocks one byte each 6*8 = 48*/
void LCDgotoXY(uint8_t  x, uint8_t  y) {
    LCDWrite(LCD_COMMAND, 0x80 | x); // Column. (result 0x80 to 0xD3)
    LCDWrite(LCD_COMMAND, 0x40 | y); // Row.
}

/* Function: LCDWrite 
There are two  banks in the LCD, data and commands. This
function sets the DC pin high or low depending, and then sends
the data byte
 */
void LCDWrite(unsigned char data_or_command, unsigned char data) {
    unsigned char i,d;
    d=data;
    if(data_or_command==0)LCD_DC_SetLow();
    else LCD_DC_SetHigh();
    //data_or_command; 
    //Tell the LCD that we are writing either to data or a command
    //Send the data
    LCD_CE_SetLow();
    for(i=0;i<8;i++)
    {
        LCD_DIN_SetLow();
        if(d&0x80)LCD_DIN_SetHigh(); // b1000000 Mask with 0 & all zeros out.
        LCD_CLK_SetHigh();
        d<<=1;
        LCD_CLK_SetLow();
    }
   LCD_CE_SetHigh();
}

/* Function: LCDCharacter.
 This function takes in a character, looks it up in the font table/array
And writes it to the screen
Each character is 8 bits tall and 5 bits wide. We pad one blank column of
pixels on each side of the character for readability.
 */
void LCDCharacter(char character) {
    LCDWrite(LCD_DATA, 0x00); //Blank vertical line padding
    for (int index = 0 ; index < 5 ; index++)
    LCDWrite(LCD_DATA, ASCII[character - 0x20][index]);
    //0x20 is the ASCII character for Space The font table starts with this character
    LCDWrite(LCD_DATA, 0x00); //Blank vertical line padding
}

/* Function: LCDString.
 Given a string of characters, one by one is passed to the LCD
 */
void LCDString(char *characters) {
    while (*characters)
    LCDCharacter(*characters++);
}

/* =========== EOF ===========*/