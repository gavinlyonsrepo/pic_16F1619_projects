/*
* Project Name: 1619_LCD
* File: main.c 
* Description: Display a analog input on a HD44780-based character LCD 16x02 4 bit 3GPIO
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
#include "HD44780_4bit_shift_lcd.h"
#include <stdio.h> /* for sprintf */

#define ADCRES 0.00488281

/* ==== Function prototypes ===== */
void Setup(void);
void DisplayData(uint16_t );

/* =========== Main application==========*/
void main(void) {
    uint16_t potValue = 0; //var to hold pot value from RA4
    Setup();
    while (1) {
        if (counter == 1) // (counter is incremented by timer0 overflow)
        {
            potValue = ADC_GetConversion(ADC_IN) >> 6;
            DisplayData(potValue);
        }
    }
}

/* ---------- Function Space------------*/

/* function to parse analog value and send to LCD functions */
void DisplayData(uint16_t potValue) {
    double  voltage = 0.0;
    uint16_t displayValue = 0;
    char DisplayString[12];

    // Code to display 0-5V assumes vdd = 5V
    voltage = (potValue *  ADCRES);
    displayValue = (voltage*100);  
    
    sprintf( DisplayString, "%u.%u%u Volts", (displayValue / 100) % 10, (displayValue / 10) % 10, (displayValue / 1) % 10);
    
    LCDGOTO(LCDLineNumberOne, 0);
    LCDSendString("ADC VALUE");
    LCDGOTO(LCDLineNumberTwo, 0);
    LCDSendString(DisplayString);
}

void Setup(void) {
    // initialize the device
    SYSTEM_Initialize();
    INTERRUPT_GlobalInterruptEnable();
    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();
    LED_STATUS_SetHigh();
    __delay_ms(50);
    LCDInit(LCDCursorTypeOn, 2, 16);
    __delay_ms(10);
}



