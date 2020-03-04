/*
* Project Name: 1619_LCD
* File: main.c 
* Desc: Display a analog input on a 128*32 OLED SSD1306 using I2C
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
#include "OLED.h"

void Setup(void);
void DisplayData(void);

/********* MAIN ***********/
void main(void)
{
   Setup();
   Oled_Init();
   Oled_Clear();   
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
}

//Function to Display Data to OLED
void DisplayData(void)
{
    
    
    uint16_t potvalue=0; //var to hold pot value from RA4 
    uint16_t display_value = 0; //var to hold voltage value
    char str1[3]; 
    char str2[3];
    char str3[5];
    // Code to display 0-5V assumes vdd = 5V
    potvalue = ADC_GetConversion(ADC_IN)>>6;
    display_value  = ((potvalue *  49)/100);
    sprintf(str1, "%u",  ( display_value/100)%10);
    sprintf(str2, "%u%u", ( display_value/10)%10, ( display_value/1)%10); 
    sprintf(str3, "%u",potvalue);

    Oled_SelectPage(0); //page 1 Select page/line 0-7 
    Oled_WriteString("PIC16F1619 RA4 Data:");
   
    Oled_SelectPage(2); //page 2 //Select page/line 0-7 
    Oled_WriteString(str1);
    Oled_WriteString(".");
    Oled_WriteString(str2);
    Oled_WriteString(" Volts ");
    Oled_WriteString(str3);
    Oled_WriteString(" ADC  ");


}
/********** EOF *******/