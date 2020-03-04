/*
* Project Name: Nokia 5110
* File: NOKIA.h 
* Description: Nokia 5110  library header file
* Author: Gavin Lyons.
* Complier: xc8 v2.00 compiler
* PIC: PIC16F1619 
* IDE:  MPLAB X v5.00
* Development board: Microchip Curiosity Board, PIC16F1619
* Created March 2019
* Description: See URL for full details.
* URL: https://github.com/gavinlyonsrepo/pic_16F1619_projects
*/

#ifndef NOKIA_H
#define NOKIA_H

#include <xc.h>
#include <stdint.h>


// GPIO Defines
#define LCD_CLK RC0
#define LCD_DIN RC1
#define LCD_DC RC2
#define LCD_CE RC3
#define LCD_RST RC4

#define LCD_CLK_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define LCD_CLK_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define LCD_DIN_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define LCD_DIN_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define LCD_DC_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define LCD_DC_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define LCD_CE_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define LCD_CE_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define LCD_RST_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define LCD_RST_SetLow()             do { LATCbits.LATC4 = 0; } while(0)

//The DC pin tells the LCD if sending a command or data
#define LCD_COMMAND 0
#define LCD_DATA 1

// 84 by 48 pixels screen
#define LCD_X 84
#define LCD_Y 48

void LCDInit(void);
void LCDgotoXY(uint8_t , uint8_t);
void LCDClear(void);
void LCDWrite(unsigned char , unsigned char);
void LCDCharacter(char); 
void LCDString(char *characters);

#endif