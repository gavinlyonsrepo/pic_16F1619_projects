/*
 * File: main.c 
 * Author: Gavin Lyons
 * PIC: PIC16F1619
 * Purpose: See URL Project 2 PWM LED.
 * IDE: MPLAB X v5.05
 * Compiler: xc8 v2.0
 * Created on 20 Jan 2019, 18:01
 * URL: https://github.com/gavinlyonsrepo/pic_16F1619_projects
 */

#include "mcc_generated_files/mcc.h"

/* Main Loop */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    while (1)
    {
        __nop();
    }
}
/*End of File*/
