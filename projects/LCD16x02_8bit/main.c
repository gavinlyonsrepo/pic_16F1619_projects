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
#include "lcd.h"

/*  Main application  */
void main(void)
{
    SYSTEM_Initialize();
    LED_STATUS_SetHigh(); 
    LCD_init();
    __delay_ms(10);
    while (1)
    {
            LCD_cmd(LCD_LINE1);
            LCD_string("Hello Line 1:");
            LCD_cmd(LCD_LINE2);
            LCD_string("Hello Line 2:");
            __delay_ms(2000);    
    }
}
/* EOF */