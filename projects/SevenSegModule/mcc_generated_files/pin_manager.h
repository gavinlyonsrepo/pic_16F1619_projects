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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.76
        Device            :  PIC16F1619
        Driver Version    :  2.11
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

// get/set LED_STATUS aliases
#define LED_STATUS_TRIS                 TRISAbits.TRISA2
#define LED_STATUS_LAT                  LATAbits.LATA2
#define LED_STATUS_PORT                 PORTAbits.RA2
#define LED_STATUS_WPU                  WPUAbits.WPUA2
#define LED_STATUS_OD                   ODCONAbits.ODA2
#define LED_STATUS_ANS                  ANSELAbits.ANSA2
#define LED_STATUS_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define LED_STATUS_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define LED_STATUS_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define LED_STATUS_GetValue()           PORTAbits.RA2
#define LED_STATUS_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define LED_STATUS_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define LED_STATUS_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define LED_STATUS_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define LED_STATUS_SetPushPull()        do { ODCONAbits.ODA2 = 0; } while(0)
#define LED_STATUS_SetOpenDrain()       do { ODCONAbits.ODA2 = 1; } while(0)
#define LED_STATUS_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define LED_STATUS_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set POT_CHANNEL aliases
#define POT_CHANNEL_TRIS                 TRISAbits.TRISA4
#define POT_CHANNEL_LAT                  LATAbits.LATA4
#define POT_CHANNEL_PORT                 PORTAbits.RA4
#define POT_CHANNEL_WPU                  WPUAbits.WPUA4
#define POT_CHANNEL_OD                   ODCONAbits.ODA4
#define POT_CHANNEL_ANS                  ANSELAbits.ANSA4
#define POT_CHANNEL_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define POT_CHANNEL_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define POT_CHANNEL_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define POT_CHANNEL_GetValue()           PORTAbits.RA4
#define POT_CHANNEL_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define POT_CHANNEL_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define POT_CHANNEL_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define POT_CHANNEL_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define POT_CHANNEL_SetPushPull()        do { ODCONAbits.ODA4 = 0; } while(0)
#define POT_CHANNEL_SetOpenDrain()       do { ODCONAbits.ODA4 = 1; } while(0)
#define POT_CHANNEL_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define POT_CHANNEL_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set DIGIT1 aliases
#define DIGIT1_TRIS                 TRISBbits.TRISB4
#define DIGIT1_LAT                  LATBbits.LATB4
#define DIGIT1_PORT                 PORTBbits.RB4
#define DIGIT1_WPU                  WPUBbits.WPUB4
#define DIGIT1_OD                   ODCONBbits.ODB4
#define DIGIT1_ANS                  ANSELBbits.ANSB4
#define DIGIT1_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define DIGIT1_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define DIGIT1_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define DIGIT1_GetValue()           PORTBbits.RB4
#define DIGIT1_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define DIGIT1_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define DIGIT1_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define DIGIT1_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define DIGIT1_SetPushPull()        do { ODCONBbits.ODB4 = 0; } while(0)
#define DIGIT1_SetOpenDrain()       do { ODCONBbits.ODB4 = 1; } while(0)
#define DIGIT1_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define DIGIT1_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set DIGIT2 aliases
#define DIGIT2_TRIS                 TRISBbits.TRISB5
#define DIGIT2_LAT                  LATBbits.LATB5
#define DIGIT2_PORT                 PORTBbits.RB5
#define DIGIT2_WPU                  WPUBbits.WPUB5
#define DIGIT2_OD                   ODCONBbits.ODB5
#define DIGIT2_ANS                  ANSELBbits.ANSB5
#define DIGIT2_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define DIGIT2_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define DIGIT2_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define DIGIT2_GetValue()           PORTBbits.RB5
#define DIGIT2_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define DIGIT2_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define DIGIT2_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define DIGIT2_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define DIGIT2_SetPushPull()        do { ODCONBbits.ODB5 = 0; } while(0)
#define DIGIT2_SetOpenDrain()       do { ODCONBbits.ODB5 = 1; } while(0)
#define DIGIT2_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define DIGIT2_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set DIGIT3 aliases
#define DIGIT3_TRIS                 TRISBbits.TRISB6
#define DIGIT3_LAT                  LATBbits.LATB6
#define DIGIT3_PORT                 PORTBbits.RB6
#define DIGIT3_WPU                  WPUBbits.WPUB6
#define DIGIT3_OD                   ODCONBbits.ODB6
#define DIGIT3_ANS                  ANSELBbits.ANSB6
#define DIGIT3_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define DIGIT3_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define DIGIT3_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define DIGIT3_GetValue()           PORTBbits.RB6
#define DIGIT3_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define DIGIT3_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define DIGIT3_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define DIGIT3_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define DIGIT3_SetPushPull()        do { ODCONBbits.ODB6 = 0; } while(0)
#define DIGIT3_SetOpenDrain()       do { ODCONBbits.ODB6 = 1; } while(0)
#define DIGIT3_SetAnalogMode()      do { ANSELBbits.ANSB6 = 1; } while(0)
#define DIGIT3_SetDigitalMode()     do { ANSELBbits.ANSB6 = 0; } while(0)

// get/set DIGIT4 aliases
#define DIGIT4_TRIS                 TRISBbits.TRISB7
#define DIGIT4_LAT                  LATBbits.LATB7
#define DIGIT4_PORT                 PORTBbits.RB7
#define DIGIT4_WPU                  WPUBbits.WPUB7
#define DIGIT4_OD                   ODCONBbits.ODB7
#define DIGIT4_ANS                  ANSELBbits.ANSB7
#define DIGIT4_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define DIGIT4_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define DIGIT4_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define DIGIT4_GetValue()           PORTBbits.RB7
#define DIGIT4_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define DIGIT4_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define DIGIT4_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define DIGIT4_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define DIGIT4_SetPushPull()        do { ODCONBbits.ODB7 = 0; } while(0)
#define DIGIT4_SetOpenDrain()       do { ODCONBbits.ODB7 = 1; } while(0)
#define DIGIT4_SetAnalogMode()      do { ANSELBbits.ANSB7 = 1; } while(0)
#define DIGIT4_SetDigitalMode()     do { ANSELBbits.ANSB7 = 0; } while(0)

// get/set SER_595 aliases
#define SER_595_TRIS                 TRISCbits.TRISC0
#define SER_595_LAT                  LATCbits.LATC0
#define SER_595_PORT                 PORTCbits.RC0
#define SER_595_WPU                  WPUCbits.WPUC0
#define SER_595_OD                   ODCONCbits.ODC0
#define SER_595_ANS                  ANSELCbits.ANSC0
#define SER_595_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define SER_595_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define SER_595_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define SER_595_GetValue()           PORTCbits.RC0
#define SER_595_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define SER_595_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define SER_595_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define SER_595_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define SER_595_SetPushPull()        do { ODCONCbits.ODC0 = 0; } while(0)
#define SER_595_SetOpenDrain()       do { ODCONCbits.ODC0 = 1; } while(0)
#define SER_595_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define SER_595_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set RLK_595 aliases
#define RLK_595_TRIS                 TRISCbits.TRISC1
#define RLK_595_LAT                  LATCbits.LATC1
#define RLK_595_PORT                 PORTCbits.RC1
#define RLK_595_WPU                  WPUCbits.WPUC1
#define RLK_595_OD                   ODCONCbits.ODC1
#define RLK_595_ANS                  ANSELCbits.ANSC1
#define RLK_595_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define RLK_595_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define RLK_595_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define RLK_595_GetValue()           PORTCbits.RC1
#define RLK_595_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define RLK_595_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define RLK_595_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define RLK_595_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define RLK_595_SetPushPull()        do { ODCONCbits.ODC1 = 0; } while(0)
#define RLK_595_SetOpenDrain()       do { ODCONCbits.ODC1 = 1; } while(0)
#define RLK_595_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define RLK_595_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set SLK_595 aliases
#define SLK_595_TRIS                 TRISCbits.TRISC2
#define SLK_595_LAT                  LATCbits.LATC2
#define SLK_595_PORT                 PORTCbits.RC2
#define SLK_595_WPU                  WPUCbits.WPUC2
#define SLK_595_OD                   ODCONCbits.ODC2
#define SLK_595_ANS                  ANSELCbits.ANSC2
#define SLK_595_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define SLK_595_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define SLK_595_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define SLK_595_GetValue()           PORTCbits.RC2
#define SLK_595_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define SLK_595_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define SLK_595_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define SLK_595_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define SLK_595_SetPushPull()        do { ODCONCbits.ODC2 = 0; } while(0)
#define SLK_595_SetOpenDrain()       do { ODCONCbits.ODC2 = 1; } while(0)
#define SLK_595_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define SLK_595_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

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