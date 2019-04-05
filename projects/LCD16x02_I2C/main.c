/*
* Project Name: 1619_LCD
* File: main.c 
* Desc: Display a analog input on a HD44780-based character LCD 16x02 using I2C PCF8574 
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
#include "lcd.h"

uint16_t potvalue=0; //var to hold pot value from RA4 

void Setup(void);
void DisplayData(void);

/**** MAIN ***/
void main(void)
{
    // initialize the device
   Setup();
   while(1)
   { 
       if (counter == 1)  // (counter is incremented in tmr0.c)
        {
           DisplayData();  
        }
    }
}
/*** END OF MAIN ******/

// Function to setup PIC
void Setup(void)
{
    SYSTEM_Initialize();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    LED_STATUS_SetHigh(); 
    __delay_ms(10);
    lcd_init (); 
}

//Function to displayData
void DisplayData(void)
{
    
    float voltage = 0;
    uint16_t display_value = 0;
    char str1[3];
    char str2[3];
    
    // Code to display 0-5V assumes vdd = 5V
    potvalue = ADC_GetConversion(ADC_IN)>>6;
    voltage = (potvalue *  0.00488281);
    display_value = (voltage*100);   
    sprintf(str1, "%u",  ( display_value/100)%10);
    sprintf(str2, "%u%u", ( display_value/10)%10, ( display_value/1)%10);
    
    // send string to LCD
    lcd_send_cmd (LCD_LINE1);
    lcd_send_string ("RA4 ADC Value:");
    lcd_send_cmd (LCD_LINE2); 
    lcd_send_string (str1);
    lcd_send_string (".");
    lcd_send_string  (str2);
    lcd_send_string (" Volts");
    
}
/******  EOF *******/