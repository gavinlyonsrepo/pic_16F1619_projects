/*
* Project Name: SevenSeg
* File: main.c 
* Description: Display a analog input on a 4 digit seven segment display
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
#define sym_DASH 0x40

/* ----------- Globals -----------*/
char data[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67}; //Character array nums 1-10
uint16_t potvalue=0; //var to hold pot value from RA4
uint8_t counter=0; //counter incremented by Timer0 overflow.

/* Function prototypes */
void sclock(void);
void rclock(void);
void DataDisplay(unsigned int );

void ADC_Data(void);

/* --------- Main application ----------- */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
        // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();
    // Enable the Peripheral Interrupts
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

/* ---------- Function SPace*/

/* ADC_data:
 Parse the return value from the ADC and display to 7-seg 
 */
void ADC_Data(void)
{
    float voltage=0;
    uint8_t digit4, digit3, digit2 , digit1;
    uint16_t display_value =0;
    digit1 = 9;
    digit2 = 9;
    digit3 = 9;
    digit4 = 9;
    
    /* code to display 0-1023
    digit4 = (potvalue/1000)%10;
    digit3 = (potvalue/100)%10;
    digit2 = (potvalue/10)%10;
    digit1 = potvalue%10;
      */
    
    // Code to display 0-5V assuems vdd = 5V
    voltage = (potvalue *  0.00488281);
     display_value = (voltage*100);
     digit4 = (display_value /100)%10;
     digit2 = (display_value /10)%10;
     digit1 = display_value %10;
    
    
     DataDisplay(data[digit1]);
     DIGIT1_SetHigh();
      __delay_ms(1);
     DIGIT1_SetLow();
     
      DataDisplay(data[digit2]);
     DIGIT2_SetHigh();
     __delay_ms(1);
     DIGIT2_SetLow();
     
     DataDisplay(sym_DASH);
     DIGIT3_SetHigh();
     __delay_ms(1);
     DIGIT3_SetLow();
     
      DataDisplay(data[digit4]);
     DIGIT4_SetHigh();
     __delay_ms(1);
     DIGIT4_SetLow();
     
}

/* sclock:
 * This function clock will enable the storage Clock to 74HC595
 */
void sclock(void){
    SLK_595_SetHigh();
    __delay_us(500);
    SLK_595_SetLow();
    __delay_us(500);
}

/* rclock:
 * This function will strobe/latch and enable the output trigger of 74HC595
 */
void rclock(void){
    RLK_595_SetHigh();
    __delay_us(500);
    RLK_595_SetLow() ;
    }

/* DataDisplay:
 * This function will send the data to serial line 74HC9595
 */
void DataDisplay(unsigned int data){
    for (int i=0 ; i<8 ; i++){
        SER_595_LAT = (data >> i) & 0x01; // bit shift and bit mask data. 
        sclock(); //enable data storage clock
    }
    rclock(); // Data latch
}

/*----------------EOF----------------*/
