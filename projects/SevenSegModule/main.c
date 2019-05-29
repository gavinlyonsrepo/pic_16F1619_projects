/*
* Project Name: SevenSeg
* File: main.c 
* Description: Display a analog input on a 4 Data_digit seven segment display
* module 3641BS dual 74HC595 kit.
* Author: Gavin Lyons.
* Complier: xc8 v2.05 compiler
* PIC: PIC16F1619 
* IDE:  MPLAB X v5.05
* Development board: Microchip Curiosity Board, PIC16F1619
* Created Feb 2018
*/

/* ----------- Library ----------*/
#include "mcc_generated_files/mcc.h"

/*--------------Defines ---------*/
#define symbol_DASH 0xBF
#define Time_delay 100 //For clking shift reg in uS

/* ----------- Globals -----------*/
 
//Character array nums 1-10
char data[10] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90}; 
uint16_t potvalue=0; //var to hold pot value from RA4
uint8_t counter=0; //counter incremented by Timer0 overflow.

/* Function prototypes */
void sclock(void);
void DataDisplay(unsigned int );
void ADC_Data(void);

/* --------- Main application ----------- */
void main(void)
{
    SYSTEM_Initialize();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    
    while (1)
    {
        if (counter == 1)  // (counter is incremented by timer0 overflow)
        {
           potvalue = ADC_GetConversion(POT_CHANNEL)>>6;
        }
        ADC_Data();
    }
}

/* ---------- Function Space---------*/

/* ADC_data:
 Parse the return value from the ADC and display to 7-seg 
 */
void ADC_Data(void)
{
    float voltage=0;
    uint16_t display_value =0;
    uint8_t Data_digit[4];
    const uint8_t  Digit_Select[4] = {0x08,0x04,0x02,0x01}; //d1 d2 d3 d4
    // Code to display 0-5V assume vdd = 5V , 5-00V
     voltage = (potvalue *  0.00488281);
     display_value = (voltage*100);
     Data_digit[0] = (display_value /100)%10;
     Data_digit[1] = symbol_DASH;
     Data_digit[2] = (display_value /10)%10;
     Data_digit[3] = display_value %10;
    
     for(uint8_t  i = 0; i <= 3; i++) 
     {
        RLK_595_SetLow();
        if (i == 1)
        {
            DataDisplay(Data_digit[1]);
        }else
        {
            DataDisplay(data[Data_digit[i]]);
        }
        DataDisplay(Digit_Select[i]);
        RLK_595_SetHigh(); // Data latch
        __delay_us(Time_delay);
     }
}

/* sclock:
 * This function clock will enable the storage Clock to 74HC595
 */
void sclock(void){
    SLK_595_SetHigh();
    __delay_us(Time_delay);
    SLK_595_SetLow();
    __delay_us(Time_delay);
}

/* DataDisplay:
 * This function will send the data to serial line 74HC9595
 */
void DataDisplay(unsigned int data){
    for (int i=0 ; i<8 ; i++){
       // bit shift and bit mask data. MSB
        SER_595_LAT = (data >>(7-i)) & 0x01;
        sclock(); //enable data storage clock
    }
  
}

/*----------------EOF----------------*/
