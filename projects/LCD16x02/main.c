/*
* Project Name: 1619_LCD
* File: main.c 
* Description: Display a analog input on a HD44780-based character LCD 16x02
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
#include <stdio.h> /* for sprintf */

/* ======= Globals========*/
unsigned char dataout;
uint16_t potvalue=0; //var to hold pot value from RA4


/* ==== Function prototypes ===== */
void setup(void);
// Shift register 595
void shiftout(unsigned char ch);
// LCD
void LCDtoggle(void);
void LCDnibbles(unsigned char ch);
void LCDcmd(unsigned char cmd);
void LCDdata(unsigned char data);
void LCDinit(void);
void LCDprint(const char* str);
void LCDgoto(char x, char y);
// Data
void DisplayData(void);

/* =========== Main application==========*/
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    INTERRUPT_GlobalInterruptEnable();
    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();
    
   LED_STATUS_SetHigh(); 
   LCDinit(); 
   __delay_ms(10);
   while(1)
   {
       
       if (counter == 1)  // (counter is incremented by timer0 overflow)
        {
           potvalue = ADC_GetConversion(ADC_IN)>>6;
           DisplayData();
        }
   }
}

/* ---------- Function Space------------*/

/* function to parse analog value and send to LCD functions */
void DisplayData(void)
{
    float voltage=0;
    uint16_t display_value =0;
    // Code to display 0-5V assumes vdd = 5V
    voltage = (potvalue *  0.00488281);
    display_value = (voltage*100);   
    char str1[3];
    char str2[3];
    sprintf(str1, "%u",  ( display_value/100)%10);
    sprintf(str2, "%u%u", ( display_value/10)%10, ( display_value/1)%10);
    LCDgoto(0,0);
    LCDprint("ADC VALUE");
    LCDgoto(0,2);
    LCDprint(str1);
    LCDprint(".");
    LCDprint(str2);
    LCDprint(" Volts");
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

//flip the bit RW The control pin R/W determines if the data transfer between the LCD module and 
//an external microcontroller are actual character data or command/status.
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
   LCDcmd(0x28); // 4-bits, 2 lines, 5x7 font
   LCDcmd(0xC); // Display ON, No cursors
   LCDcmd(0x6); // Entry mode- Auto-increment, No Display shifting
   LCDcmd(0x1); 
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
   char addr = 0x80;
   if(y==2) addr = 0xC0;
   addr+=x;
   LCDcmd(addr);
}