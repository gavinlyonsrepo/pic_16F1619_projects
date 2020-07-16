/*
* Project Name: Alarm_timer
* File: main.c 
* Description: Alarm_timer with 3 digit 7 segment module.
* Author: Gavin Lyons.
* Complier: xc8 v2.10 compiler
* PIC: PIC16F1619
* IDE:  MPLAB X v5.30 
* Created March 2020
* URL: https://github.com/gavinlyonsrepo/pic_16F1619_projects
*/


#include "mcc_generated_files/mcc.h"

/*-------------- Defines ---------*/
#define COMMON_ANODE_MASK 0xFF
#define DEC_POINT_MASK 0x7F
#define DIGIT_DELAY 5 // digit delay multiplexing in milliseconds 
#define INIT_DELAY 500
#define DEBOUNCE_DELAY 20
#define LETTER_H  0x76
#define LETTER_I  0x10
#define LETTER_U  0x3E
#define LETTER_E  0x79
#define LETTER_N  0x37
#define LETTER_D  0x5E

/* ------------ Globals ----------- */
uint16_t Time_value = 0;
bool buttonpressed = false;

/* -------- Function prototypes -------- */
uint16_t map(long x, uint16_t in_min, uint16_t in_max, uint16_t out_min, uint16_t out_max);
void DisplayData(uint8_t, uint16_t, uint8_t);
void Setup(void);
void DisplayStartMessage(void);
void DisplayADCValue(void);
void Countdown(void);
void DisplayEnd(void);
bool ReadPushButton(void);

/*  ------- Main application loop -------*/
void main(void)
{
    Setup();
    DisplayStartMessage();
    while(1)
    {
        DisplayADCValue();
        Countdown();
        DisplayEnd();
    }
}
/* -------- End of Main loop --------*/


/* ------ Function Space------- */

// Function to display data on Segment display.
// Mode has four options
// 1 --- Start message 
// 2 --- Display ADC
// 3 --- Countdown display (passed Minutes and seconds during this phase)
// 4 --- End message
void DisplayData(uint8_t mode, uint16_t minutes, uint8_t seconds)
{
    //Character array nums 0 - 9 
    char numData[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67}; 
    
    // Digit One MSB D1D2D3
    switch (mode)
    {
        case 1:  LATC = LETTER_H ^ COMMON_ANODE_MASK ; break;
        case 2:  LATC = (numData[(Time_value/100)%10]) ^ COMMON_ANODE_MASK; break;
        case 3:  LATC = (numData[(minutes/100)%10]) ^ COMMON_ANODE_MASK; break;
        case 4:  LATC = LETTER_E ^ COMMON_ANODE_MASK ; break;
    }
     D1_RB6_SetHigh();
      __delay_ms(DIGIT_DELAY);
     D1_RB6_SetLow();
     
     // Digit Two Center digit D1D2D3 
    switch (mode)
    {
        case 1:  LATC = LETTER_I ^ COMMON_ANODE_MASK; break;
        case 2:  LATC = (numData[(Time_value/10)%10]) ^ COMMON_ANODE_MASK; break;
        case 3:  LATC = (numData[(minutes/10)%10]) ^ COMMON_ANODE_MASK; break;
        case 4:  LATC = LETTER_N ^ COMMON_ANODE_MASK ; break;
    }
     D2_RB5_SetHigh();
     __delay_ms(DIGIT_DELAY);
     D2_RB5_SetLow();
     
     // Digit three LSB D1D2D3.
    switch (mode)
    {
        case 1:  LATC = LETTER_U ^ COMMON_ANODE_MASK; break;
        case 2:  LATC = (numData[Time_value%10]) ^ DEC_POINT_MASK; break;
        case 3:  
            if ( seconds % 2 == 0)
                LATC = (numData[minutes%10]) ^ COMMON_ANODE_MASK; 
            else
                LATC = (numData[minutes%10]) ^  DEC_POINT_MASK; 
            break;
        case 4:  LATC = LETTER_D ^ COMMON_ANODE_MASK; break;
    }
     D3_RB4_SetHigh();
     __delay_ms(DIGIT_DELAY);
     D3_RB4_SetLow();  
}

// Map the ADC to the time 1023-0 480-0
uint16_t map(long x, uint16_t in_min, uint16_t in_max, uint16_t out_min, uint16_t out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

// Initialize the device
void Setup(void)
{
    SYSTEM_Initialize();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    TMR1_StopTimer();
    TMR2_StopTimer();
    LATC = 0x00;
    D1_RB6_SetLow();
    D2_RB5_SetLow();
    D3_RB4_SetLow();
    __delay_ms(INIT_DELAY);
}

// Function to display start message. HiU
void DisplayStartMessage(void)
{ 
    uint8_t counter = 0;
    while(counter++ < 254) // 254 * ~15 mS(display time)  ~= 3 seconds
    {
        DisplayData(1, 0, 0); // Display HiU
    }
}

// Function to display ADC value
void DisplayADCValue(void)
{
    uint16_t ADC_Read = 0;
    uint8_t counter = 0;
    while(buttonpressed == false)
    {
        if (++counter == 100) // 100 * ~15mS (display time) ~= 1.5 seconds
        {
            ADC_Read = ADC_GetConversion(POT_AN3)>>6;
            Time_value = map(ADC_Read, 0, 1023, 1, 99);
            counter = 0;
        }
        DisplayData(2, 0, 0);
        buttonpressed = ReadPushButton();
    }
    buttonpressed = false;
    __delay_ms(INIT_DELAY);
}

// Function to Display countdown
void Countdown(void)
{
    bool showDisplay = true;
    uint8_t seconds = 59;
    uint16_t minutes = 0;
    Time_value--;
    minutes = Time_value;
    TMR1_StartTimer();  // Timer1 make count true every second. 
        while (1)
        {     
           if (myTimercount == true)
           {
               seconds --;
               myTimercount = false;
               if ((seconds == 1) && (minutes == 0)) break;
               if (seconds == 0)
               {
                   minutes --;
                   seconds = 59; 
               }
           }
           
           if ( SW_RB7_PORT == 0)
           {
               __delay_ms(DEBOUNCE_DELAY);
               if ( SW_RB7_PORT == 0)
                {
                   showDisplay = !showDisplay;
                   while(SW_RB7_PORT == 0);
                }
           }
           
           if (showDisplay == true) 
               DisplayData(3 , minutes, seconds);
           else
               {
               LATC = 0x00;
               D1_RB6_SetLow();
               D2_RB5_SetLow();
               D3_RB4_SetLow();
               }
        }
}

// Function to Display end message. END
void DisplayEnd(void)
{
   while(buttonpressed == false)
   {   
       TMR2_StartTimer();
        DisplayData(4, 0, 0);
        buttonpressed = ReadPushButton();
   }
   //Reset globals and stop timers
   buttonpressed = false;
   Time_value = 0;
   TMR1_StopTimer(); //time
   TMR2_StopTimer(); //Buzzer PWM
   __delay_ms(INIT_DELAY);
}

//Function to read button
// state returns button state, true for a press, false for no
bool ReadPushButton(void)
{
        if ( SW_RB7_PORT == 0)
        {
            __delay_ms(DEBOUNCE_DELAY) ;
            if (SW_RB7_PORT == 0) return true ;
        }
        return false;
}

/* End of File */