/*
 * File: main.c 
 * Author: Gavin Lyons
 * PIC: PIC16F1619
 * Purpose: See URL Project 1 blink LED.
 * IDE: MPLAB X v5.05
 * Compiler: xc8 v2.0
 * Created on 20 December 2018, 18:59
 * URL: https://github.com/gavinlyonsrepo/pic_16F1619_projects
 */

/* ======= Includes ========*/
#include "mcc_generated_files/mcc.h"

/* ====== Main loop ======= */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    while (1)
    {
        LED_SetHigh();
        __delay_ms(1000);
        LED_SetLow();
        __delay_ms(1000);
    }
}
/* End of File*/