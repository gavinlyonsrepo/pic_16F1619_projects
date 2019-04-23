/*
* Project Name: LCD_16x02
* File: lcd.c
* Description: HD44780-based character LCD 16x02 4-bit, without shift register, 
library SRC file
* Author: Gavin Lyons.
* Complier: xc8 v2.05 compiler
* PIC: PIC16F1619 
* IDE:  MPLAB X v5.15
* Development board: Microchip Curiosity Board, PIC16F1619
* Created March 2019
* Description: See URL for full details.
* URL: https://github.com/gavinlyonsrepo/pic_16F1619_projects
*/

#include "lcd.h"         
#include "mcc_generated_files/mcc.h"



/* Function Name : LCDinit
 * Initializes the 16×2 character LCD module to operate into 4-bit mode,
 * 2 lines display, 5×7 size character, display ON, with cursor OFF.
 */
void LCDinit(void)
   {
   __delay_ms(15);
   LCDcmd(START);
   __delay_ms(5);
   LCDcmd(START);
   __delay_ms(5);
   LCDcmd(START);
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

// Function name LCDtoggle 
// Flip the bit en The control pin enable data transfer with the LCD module 
void LCDtoggle(void)
   {
    EN_RB4_LAT= 1;       //enable-en
     __delay_ms(2);
    EN_RB4_LAT=0;        //disable-en
     __delay_ms(2);
   }

//LCDisplay shifts and masks the  nibble to the 
//four data bins A,B,C,D, map to D7,D6,D5,D4 using bit shift & AND mask.
void LCDdisplay(unsigned char value)  
{
    D4_RC0_LAT=(value >> 0) & 0x01;
    D5_RC1_LAT=(value >> 1) & 0x01;
    D6_RC2_LAT=(value >> 2) & 0x01;
    D7_RC3_LAT=(value >> 3) & 0x01;
    LCDtoggle();
}


//LCD Data Send a data byte to LCD
void LCDdata(unsigned char data){
    
     RS_RB5_LAT = 1;       //register select-rs high
    __delay_us(100);
    LCDdisplay(data>>4);   //Send Higher nibble 4-bits of 8-bit data
    __delay_us(100);
    LCDdisplay(data);      //Send Lower nibble  4-bits of 8-bit data

}

//LCD Data Send a command  byte to LCD
void LCDcmd(unsigned char cmd){
          
    RS_RB5_LAT=0;          //register select-rs LOW 
   __delay_us(100);
   LCDdisplay(cmd>>4);          //Send Higher nibble 4-bits of 8-bit command
   __delay_us(100);
   LCDdisplay(cmd);             //Send Lower nibble 4-bits of 8-bit command
}