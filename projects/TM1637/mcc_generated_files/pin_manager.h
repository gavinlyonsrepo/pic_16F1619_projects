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

// get/set LED_RA2 aliases
#define LED_RA2_TRIS                 TRISAbits.TRISA2
#define LED_RA2_LAT                  LATAbits.LATA2
#define LED_RA2_PORT                 PORTAbits.RA2
#define LED_RA2_WPU                  WPUAbits.WPUA2
#define LED_RA2_OD                   ODCONAbits.ODA2
#define LED_RA2_ANS                  ANSELAbits.ANSA2
#define LED_RA2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define LED_RA2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define LED_RA2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define LED_RA2_GetValue()           PORTAbits.RA2
#define LED_RA2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define LED_RA2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define LED_RA2_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define LED_RA2_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define LED_RA2_SetPushPull()        do { ODCONAbits.ODA2 = 0; } while(0)
#define LED_RA2_SetOpenDrain()       do { ODCONAbits.ODA2 = 1; } while(0)
#define LED_RA2_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define LED_RA2_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set pinDIO aliases
#define pinDIO_TRIS                 TRISBbits.TRISB4
#define pinDIO_LAT                  LATBbits.LATB4
#define pinDIO_PORT                 PORTBbits.RB4
#define pinDIO_WPU                  WPUBbits.WPUB4
#define pinDIO_OD                   ODCONBbits.ODB4
#define pinDIO_ANS                  ANSELBbits.ANSB4
#define pinDIO_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define pinDIO_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define pinDIO_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define pinDIO_GetValue()           PORTBbits.RB4
#define pinDIO_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define pinDIO_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define pinDIO_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define pinDIO_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define pinDIO_SetPushPull()        do { ODCONBbits.ODB4 = 0; } while(0)
#define pinDIO_SetOpenDrain()       do { ODCONBbits.ODB4 = 1; } while(0)
#define pinDIO_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define pinDIO_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set pinClk aliases
#define pinClk_TRIS                 TRISBbits.TRISB5
#define pinClk_LAT                  LATBbits.LATB5
#define pinClk_PORT                 PORTBbits.RB5
#define pinClk_WPU                  WPUBbits.WPUB5
#define pinClk_OD                   ODCONBbits.ODB5
#define pinClk_ANS                  ANSELBbits.ANSB5
#define pinClk_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define pinClk_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define pinClk_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define pinClk_GetValue()           PORTBbits.RB5
#define pinClk_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define pinClk_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define pinClk_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define pinClk_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define pinClk_SetPushPull()        do { ODCONBbits.ODB5 = 0; } while(0)
#define pinClk_SetOpenDrain()       do { ODCONBbits.ODB5 = 1; } while(0)
#define pinClk_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define pinClk_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

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