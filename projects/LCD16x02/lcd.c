/*
* Project Name: LCD_16x02
* File: lcd.c
* Description: HD44780-based character LCD 16x02 4-bit library main file
* Author: Gavin Lyons.
* Complier: xc8 v2.00 compiler
* PIC: PIC16F1619 
* IDE:  MPLAB X v5.00
* Development board: Microchip Curiosity Board, PIC16F1619
* Created March 2019
* Description: See URL for full details.
* URL: https://github.com/gavinlyonsrepo/pic_16F1619_projects
*/

#include "lcd.h"         
#include "mcc_generated_files/mcc.h"

/* Function Name : Write_LCD_Data 
 * Sends a character byte to display at current cursor position.
 */
void LCDdata(unsigned char data)
   {
   dataout = 0x20;
   LCDnibbles(data);
   __delay_us(100);
   }

/* Function Name : LCDinit
 * Initializes the 16×2 character LCD module to operate into 4-bit mode,
 * 2 lines display, 5×7 size character, display ON, with cursor OFF.
 */
void LCDinit(void)
   {
   __delay_ms(15);
   dataout = 2;
   LCDtoggle(); // Wake-Up Sequence
   __delay_ms(5);
   LCDtoggle();
   __delay_ms(5);
   LCDtoggle();
   __delay_ms(5);
   LCDcmd(MODE_4BIT); // 4-bits, 2 lines, 5x7 font
   LCDcmd(DISPLAY_ON); // Display ON, No cursors
   LCDcmd(CURSOR_INC); // Entry mode- Auto-increment, No Display shifting
   LCDcmd(CLRSCR); 
   }
 
/* Function name LCDprint :
 *  Writes a character string at the current cursor position.
 */
void LCDprint(const char* str)
   {
   while(*str != 0)
       LCDdata(*str++);
   }

/* Function name LCDgoto
 * Changes the current cursor position
 */
void LCDgoto(char x, char y)
   {
   char addr = LCD_LINE1;
   if(y==2) addr = LCD_LINE2;
   addr+=x;
   LCDcmd(addr);
}

//Flip the bit en The control pin enable  data transfer with the LCD module 
void LCDtoggle(void)
   {
   dataout ^= 0x10;
   shiftout(dataout);
   dataout ^= 0x10;
   shiftout(dataout);
   }

/* Function Name :Write_LCD_Nibble
 *  Used by LCDData() and LCD_Cmd() 
 * functions to send LCD data and command as two nibbles.
*/
void LCDnibbles(unsigned char ch)
   {
   dataout &= 0xF0;
   dataout += (ch>>4) & 0xF;
   shiftout(dataout);
   LCDtoggle();
   dataout &= 0xF0;
   dataout += ch & 0xF;
   shiftout(dataout);
   LCDtoggle();
   }

/* Function Name : Write_LCD_Cmd
 *  Writes a command byte to the LCD module.
 */
void LCDcmd(unsigned char cmd)
   {
   dataout = 0;
   LCDnibbles(cmd);
   __delay_us(100);
   }

/* Function name : shiftout
 * Shift out data to shift register
 */
void shiftout(unsigned char ch)
   {
   char x;
   unsigned char dummy = ch;
   for(x=0;x<8;x++)
       {
       SER_DATA_SetLow();
       if(dummy & 0x80) SER_DATA_SetHigh() ;
       SCLK_SetHigh();
       __nop();
       SCLK_SetLow();
       dummy<<=1;    
       }
   RCLK_SetHigh();
   __nop();
   RCLK_SetLow();
   }