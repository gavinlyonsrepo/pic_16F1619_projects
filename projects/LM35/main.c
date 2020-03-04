/*
* Project Name: LM35
* File: main.c 
* Description: Display LM35 sensor data on 3 digit common anode 7 segment. 
* Author: Gavin Lyons.
* Complier: xc8 v2.10 compiler
* PIC: PIC16F1619 
* IDE:  MPLAB X v5.30
* Development board: Microchip Curiosity Board, PIC16F1619
* Created Feb 2020
*/

/* ----------- Library ----------*/
#include "mcc_generated_files/mcc.h"

/*--------------Defines ---------*/
#define COMMON_ANODE_MASK 0xFF
#define DEC_POINT_MASK 0x7F
#define ADC_VOLT 488 // voltage / ADC resolution = 5/1023 * 100000(to avoid using float))
#define OFFSET  250 // OPTIONAL , USER DEFINED, negative offset to calibrate sensor 100 = 1 degrees
#define DIGIT_DELAY 1 // digit delay multiplexing in milliseconds 
#define INIT_DELAY 1000 //init delay in milliseconds

/* ----------- Globals -----------*/
uint16_t temperature =0;
        
/* --------- Function prototypes -------- */
void DisplayData(void);
void GetSensorData(void);

/* --------- Main application ----------- */
void main(void)
{
    // initialize the device, Enable the Peripheral and Global Interrupts
    SYSTEM_Initialize();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    LED_RA2_SetHigh(); 
    LATC = 0x00;
    D1_RB6_SetHigh();
    D2_RB5_SetHigh();
    D3_RB4_SetHigh();
    __delay_ms(INIT_DELAY); //init delay
    
    while (1)
    {
        if (counter == 0)  // (counter is incremented by timer0 overflow)
        {
            LED_RA2_SetHigh();
            GetSensorData();   //get sensor data
            counter = 1;
        }
        DisplayData();
    }
}

/* ---------- Function Space ----------------*/

// Function to get data from LM35 sensor
void GetSensorData(void)
{
    //var to hold sensor value from RA4/AN3 0-1023
    temperature = ADC_GetConversion(LM35_AN3)>>6;
    temperature = (temperature * ADC_VOLT )/10; 
    temperature = temperature - OFFSET; // OPTIONAL calibration
    //(ADC * (5/1023)*100000)/10 gives TT.TT 
    //where for example TT.TT = 19.52 degrees for ADC of 40
}

//Function to display data on Segment display.
void DisplayData(void)
{
    //Character array nums 1-10 
    char numData[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67}; 
    
    // Digit One MSB D1D2.D3 
    LATC = numData[(temperature/1000)%10] ^ COMMON_ANODE_MASK;
     D1_RB6_SetLow();
      __delay_ms(DIGIT_DELAY);
     D1_RB6_SetHigh();
     
     // Digit Two Center digit D1D2.D3 
     LATC = numData[(temperature/100)%10] ^ DEC_POINT_MASK;
     D2_RB5_SetLow();
     __delay_ms(DIGIT_DELAY);
     D2_RB5_SetHigh();
     
     // Digit three LSB D1D2.D3 
     LATC = numData[(temperature/10)%10] ^ COMMON_ANODE_MASK;
     D3_RB4_SetLow();
     __delay_ms(DIGIT_DELAY);
     D3_RB4_SetHigh();
     
     LED_RA2_SetLow();
}
/*---------------- EOF ----------------*/
