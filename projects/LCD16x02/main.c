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
#include "lcd.h" 
#include <stdio.h> /* for sprintf */


/* ======= Globals========*/
uint16_t potvalue=0; //var to hold pot value from RA4

/* ==== Function prototypes ===== */
void Setup(void);
void DisplayData(void);

/* =========== Main application==========*/
void main(void)
{
   Setup();
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

void Setup(void)
{
     // initialize the device
    SYSTEM_Initialize();
    INTERRUPT_GlobalInterruptEnable();
    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();
   LED_STATUS_SetHigh(); 
   LCDinit(); 
   __delay_ms(10);
}



