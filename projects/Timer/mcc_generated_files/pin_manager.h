/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.80.0
        Device            :  PIC16F1619
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.10 and above
        MPLAB 	          :  MPLAB X 5.30	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RA1 procedures
#define RA1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define RA1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define RA1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define RA1_GetValue()              PORTAbits.RA1
#define RA1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define RA1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define RA1_SetPullup()             do { WPUAbits.WPUA1 = 1; } while(0)
#define RA1_ResetPullup()           do { WPUAbits.WPUA1 = 0; } while(0)
#define RA1_SetAnalogMode()         do { ANSELAbits.ANSA1 = 1; } while(0)
#define RA1_SetDigitalMode()        do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set POT_AN3 aliases
#define POT_AN3_TRIS                 TRISAbits.TRISA4
#define POT_AN3_LAT                  LATAbits.LATA4
#define POT_AN3_PORT                 PORTAbits.RA4
#define POT_AN3_WPU                  WPUAbits.WPUA4
#define POT_AN3_OD                   ODCONAbits.ODA4
#define POT_AN3_ANS                  ANSELAbits.ANSA4
#define POT_AN3_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define POT_AN3_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define POT_AN3_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define POT_AN3_GetValue()           PORTAbits.RA4
#define POT_AN3_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define POT_AN3_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define POT_AN3_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define POT_AN3_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define POT_AN3_SetPushPull()        do { ODCONAbits.ODA4 = 0; } while(0)
#define POT_AN3_SetOpenDrain()       do { ODCONAbits.ODA4 = 1; } while(0)
#define POT_AN3_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define POT_AN3_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set D3_RB4 aliases
#define D3_RB4_TRIS                 TRISBbits.TRISB4
#define D3_RB4_LAT                  LATBbits.LATB4
#define D3_RB4_PORT                 PORTBbits.RB4
#define D3_RB4_WPU                  WPUBbits.WPUB4
#define D3_RB4_OD                   ODCONBbits.ODB4
#define D3_RB4_ANS                  ANSELBbits.ANSB4
#define D3_RB4_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define D3_RB4_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define D3_RB4_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define D3_RB4_GetValue()           PORTBbits.RB4
#define D3_RB4_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define D3_RB4_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define D3_RB4_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define D3_RB4_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define D3_RB4_SetPushPull()        do { ODCONBbits.ODB4 = 0; } while(0)
#define D3_RB4_SetOpenDrain()       do { ODCONBbits.ODB4 = 1; } while(0)
#define D3_RB4_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define D3_RB4_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set D2_RB5 aliases
#define D2_RB5_TRIS                 TRISBbits.TRISB5
#define D2_RB5_LAT                  LATBbits.LATB5
#define D2_RB5_PORT                 PORTBbits.RB5
#define D2_RB5_WPU                  WPUBbits.WPUB5
#define D2_RB5_OD                   ODCONBbits.ODB5
#define D2_RB5_ANS                  ANSELBbits.ANSB5
#define D2_RB5_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define D2_RB5_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define D2_RB5_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define D2_RB5_GetValue()           PORTBbits.RB5
#define D2_RB5_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define D2_RB5_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define D2_RB5_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define D2_RB5_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define D2_RB5_SetPushPull()        do { ODCONBbits.ODB5 = 0; } while(0)
#define D2_RB5_SetOpenDrain()       do { ODCONBbits.ODB5 = 1; } while(0)
#define D2_RB5_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define D2_RB5_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set D1_RB6 aliases
#define D1_RB6_TRIS                 TRISBbits.TRISB6
#define D1_RB6_LAT                  LATBbits.LATB6
#define D1_RB6_PORT                 PORTBbits.RB6
#define D1_RB6_WPU                  WPUBbits.WPUB6
#define D1_RB6_OD                   ODCONBbits.ODB6
#define D1_RB6_ANS                  ANSELBbits.ANSB6
#define D1_RB6_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define D1_RB6_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define D1_RB6_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define D1_RB6_GetValue()           PORTBbits.RB6
#define D1_RB6_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define D1_RB6_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define D1_RB6_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define D1_RB6_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define D1_RB6_SetPushPull()        do { ODCONBbits.ODB6 = 0; } while(0)
#define D1_RB6_SetOpenDrain()       do { ODCONBbits.ODB6 = 1; } while(0)
#define D1_RB6_SetAnalogMode()      do { ANSELBbits.ANSB6 = 1; } while(0)
#define D1_RB6_SetDigitalMode()     do { ANSELBbits.ANSB6 = 0; } while(0)

// get/set SW_RB7 aliases
#define SW_RB7_TRIS                 TRISBbits.TRISB7
#define SW_RB7_LAT                  LATBbits.LATB7
#define SW_RB7_PORT                 PORTBbits.RB7
#define SW_RB7_WPU                  WPUBbits.WPUB7
#define SW_RB7_OD                   ODCONBbits.ODB7
#define SW_RB7_ANS                  ANSELBbits.ANSB7
#define SW_RB7_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define SW_RB7_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define SW_RB7_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define SW_RB7_GetValue()           PORTBbits.RB7
#define SW_RB7_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define SW_RB7_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define SW_RB7_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define SW_RB7_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define SW_RB7_SetPushPull()        do { ODCONBbits.ODB7 = 0; } while(0)
#define SW_RB7_SetOpenDrain()       do { ODCONBbits.ODB7 = 1; } while(0)
#define SW_RB7_SetAnalogMode()      do { ANSELBbits.ANSB7 = 1; } while(0)
#define SW_RB7_SetDigitalMode()     do { ANSELBbits.ANSB7 = 0; } while(0)

// get/set a_RC0 aliases
#define a_RC0_TRIS                 TRISCbits.TRISC0
#define a_RC0_LAT                  LATCbits.LATC0
#define a_RC0_PORT                 PORTCbits.RC0
#define a_RC0_WPU                  WPUCbits.WPUC0
#define a_RC0_OD                   ODCONCbits.ODC0
#define a_RC0_ANS                  ANSELCbits.ANSC0
#define a_RC0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define a_RC0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define a_RC0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define a_RC0_GetValue()           PORTCbits.RC0
#define a_RC0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define a_RC0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define a_RC0_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define a_RC0_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define a_RC0_SetPushPull()        do { ODCONCbits.ODC0 = 0; } while(0)
#define a_RC0_SetOpenDrain()       do { ODCONCbits.ODC0 = 1; } while(0)
#define a_RC0_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define a_RC0_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set b_RC1 aliases
#define b_RC1_TRIS                 TRISCbits.TRISC1
#define b_RC1_LAT                  LATCbits.LATC1
#define b_RC1_PORT                 PORTCbits.RC1
#define b_RC1_WPU                  WPUCbits.WPUC1
#define b_RC1_OD                   ODCONCbits.ODC1
#define b_RC1_ANS                  ANSELCbits.ANSC1
#define b_RC1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define b_RC1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define b_RC1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define b_RC1_GetValue()           PORTCbits.RC1
#define b_RC1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define b_RC1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define b_RC1_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define b_RC1_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define b_RC1_SetPushPull()        do { ODCONCbits.ODC1 = 0; } while(0)
#define b_RC1_SetOpenDrain()       do { ODCONCbits.ODC1 = 1; } while(0)
#define b_RC1_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define b_RC1_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set c_RC2 aliases
#define c_RC2_TRIS                 TRISCbits.TRISC2
#define c_RC2_LAT                  LATCbits.LATC2
#define c_RC2_PORT                 PORTCbits.RC2
#define c_RC2_WPU                  WPUCbits.WPUC2
#define c_RC2_OD                   ODCONCbits.ODC2
#define c_RC2_ANS                  ANSELCbits.ANSC2
#define c_RC2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define c_RC2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define c_RC2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define c_RC2_GetValue()           PORTCbits.RC2
#define c_RC2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define c_RC2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define c_RC2_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define c_RC2_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define c_RC2_SetPushPull()        do { ODCONCbits.ODC2 = 0; } while(0)
#define c_RC2_SetOpenDrain()       do { ODCONCbits.ODC2 = 1; } while(0)
#define c_RC2_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define c_RC2_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set d_RC3 aliases
#define d_RC3_TRIS                 TRISCbits.TRISC3
#define d_RC3_LAT                  LATCbits.LATC3
#define d_RC3_PORT                 PORTCbits.RC3
#define d_RC3_WPU                  WPUCbits.WPUC3
#define d_RC3_OD                   ODCONCbits.ODC3
#define d_RC3_ANS                  ANSELCbits.ANSC3
#define d_RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define d_RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define d_RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define d_RC3_GetValue()           PORTCbits.RC3
#define d_RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define d_RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define d_RC3_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define d_RC3_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define d_RC3_SetPushPull()        do { ODCONCbits.ODC3 = 0; } while(0)
#define d_RC3_SetOpenDrain()       do { ODCONCbits.ODC3 = 1; } while(0)
#define d_RC3_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define d_RC3_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set e_RC4 aliases
#define e_RC4_TRIS                 TRISCbits.TRISC4
#define e_RC4_LAT                  LATCbits.LATC4
#define e_RC4_PORT                 PORTCbits.RC4
#define e_RC4_WPU                  WPUCbits.WPUC4
#define e_RC4_OD                   ODCONCbits.ODC4
#define e_RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define e_RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define e_RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define e_RC4_GetValue()           PORTCbits.RC4
#define e_RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define e_RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define e_RC4_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define e_RC4_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define e_RC4_SetPushPull()        do { ODCONCbits.ODC4 = 0; } while(0)
#define e_RC4_SetOpenDrain()       do { ODCONCbits.ODC4 = 1; } while(0)

// get/set f_RC5 aliases
#define f_RC5_TRIS                 TRISCbits.TRISC5
#define f_RC5_LAT                  LATCbits.LATC5
#define f_RC5_PORT                 PORTCbits.RC5
#define f_RC5_WPU                  WPUCbits.WPUC5
#define f_RC5_OD                   ODCONCbits.ODC5
#define f_RC5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define f_RC5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define f_RC5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define f_RC5_GetValue()           PORTCbits.RC5
#define f_RC5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define f_RC5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define f_RC5_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define f_RC5_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define f_RC5_SetPushPull()        do { ODCONCbits.ODC5 = 0; } while(0)
#define f_RC5_SetOpenDrain()       do { ODCONCbits.ODC5 = 1; } while(0)

// get/set g_RC6 aliases
#define g_RC6_TRIS                 TRISCbits.TRISC6
#define g_RC6_LAT                  LATCbits.LATC6
#define g_RC6_PORT                 PORTCbits.RC6
#define g_RC6_WPU                  WPUCbits.WPUC6
#define g_RC6_OD                   ODCONCbits.ODC6
#define g_RC6_ANS                  ANSELCbits.ANSC6
#define g_RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define g_RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define g_RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define g_RC6_GetValue()           PORTCbits.RC6
#define g_RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define g_RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define g_RC6_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define g_RC6_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define g_RC6_SetPushPull()        do { ODCONCbits.ODC6 = 0; } while(0)
#define g_RC6_SetOpenDrain()       do { ODCONCbits.ODC6 = 1; } while(0)
#define g_RC6_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define g_RC6_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set dp_RC7 aliases
#define dp_RC7_TRIS                 TRISCbits.TRISC7
#define dp_RC7_LAT                  LATCbits.LATC7
#define dp_RC7_PORT                 PORTCbits.RC7
#define dp_RC7_WPU                  WPUCbits.WPUC7
#define dp_RC7_OD                   ODCONCbits.ODC7
#define dp_RC7_ANS                  ANSELCbits.ANSC7
#define dp_RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define dp_RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define dp_RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define dp_RC7_GetValue()           PORTCbits.RC7
#define dp_RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define dp_RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define dp_RC7_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define dp_RC7_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define dp_RC7_SetPushPull()        do { ODCONCbits.ODC7 = 0; } while(0)
#define dp_RC7_SetOpenDrain()       do { ODCONCbits.ODC7 = 1; } while(0)
#define dp_RC7_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define dp_RC7_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/