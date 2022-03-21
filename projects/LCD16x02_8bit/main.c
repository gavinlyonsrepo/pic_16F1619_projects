/*
* Project Name: LCD_16x02_8bit
* File: main.c 
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

#include "mcc_generated_files/mcc.h"
#include "HD44780_8bit_lcd.h"

/*  Main application  */
void main(void)
{
    SYSTEM_Initialize();
    LED_STATUS_SetHigh(); 
    __delay_ms(10);
    LCDInit(LCDCursorTypeOn, 2, 16);
    while (1)
    {
            LCDGOTO(LCDLineNumberOne, 0);
            LCDSendString("Hello Line 1:");
            LCDGOTO(LCDLineNumberTwo, 0);
            LCDSendString("Hello Line 2:");
            __delay_ms(2000);    
    }
}
/* EOF */