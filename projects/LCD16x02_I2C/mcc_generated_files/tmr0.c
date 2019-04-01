/**
  TMR0 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    tmr0.c

  @Summary
    This is the generated driver implementation file for the TMR0 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This source file provides APIs for TMR0.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.76
        Device            :  PIC16F1619
        Driver Version    :  2.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.00
        MPLAB 	          :  MPLAB X 5.10
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

/**
  Section: Included Files
*/

#include <xc.h>
#include "tmr0.h"
#include "mcc.h"

/**
  Section: Global Variables Definitions
*/

volatile uint8_t timer0ReloadVal;
void (*TMR0_InterruptHandler)(void);
/**
  Section: TMR0 APIs
*/

void TMR0_Initialize(void)
{
    // Set TMR0 to the options selected in the User Interface
	
    // PSA assigned; PS 1:256; TMRSE Increment_hi_lo; mask the nWPUEN and INTEDG bits
    OPTION_REG = (uint8_t)((OPTION_REG & 0xC0) | (0xD7 & 0x3F)); 
	
    // TMR0 178; 
    TMR0 = 0xB2;
	
    // Load the TMR value to reload variable
    timer0ReloadVal= 178;

    // Clear Interrupt flag before enabling the interrupt
    INTCONbits.TMR0IF = 0;

    // Enabling TMR0 interrupt
    INTCONbits.TMR0IE = 1;

    // Set Default Interrupt Handler
    TMR0_SetInterruptHandler(TMR0_DefaultInterruptHandler);
}

uint8_t TMR0_ReadTimer(void)
{
    uint8_t readVal;

    readVal = TMR0;

    return readVal;
}

void TMR0_WriteTimer(uint8_t timerVal)
{
    // Write to the Timer0 register
    TMR0 = timerVal;
}

void TMR0_Reload(void)
{
    // Write to the Timer0 register
    TMR0 = timer0ReloadVal;
}

void TMR0_ISR(void)
{

    // Clear the TMR0 interrupt flag
    INTCONbits.TMR0IF = 0;

    TMR0 = timer0ReloadVal;

    if(TMR0_InterruptHandler)
    {
        TMR0_InterruptHandler();
    }

    // add your TMR0 interrupt custom code
     // ---------- Glyons ------------
        counter++;
        if(counter==60)
        { 
          counter=0;
         LED_STATUS_Toggle();
} 
}


void TMR0_SetInterruptHandler(void (* InterruptHandler)(void)){
    TMR0_InterruptHandler = InterruptHandler;
}

void TMR0_DefaultInterruptHandler(void){
    // add your TMR0 interrupt custom code
    // or set custom function using TMR0_SetInterruptHandler()
}

/**
  End of File
*/
