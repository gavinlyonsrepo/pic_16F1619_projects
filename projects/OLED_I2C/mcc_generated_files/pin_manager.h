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

// get/set ADC_IN aliases
#define ADC_IN_TRIS                 TRISAbits.TRISA4
#define ADC_IN_LAT                  LATAbits.LATA4
#define ADC_IN_PORT                 PORTAbits.RA4
#define ADC_IN_WPU                  WPUAbits.WPUA4
#define ADC_IN_OD                   ODCONAbits.ODA4
#define ADC_IN_ANS                  ANSELAbits.ANSA4
#define ADC_IN_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define ADC_IN_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define ADC_IN_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define ADC_IN_GetValue()           PORTAbits.RA4
#define ADC_IN_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define ADC_IN_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define ADC_IN_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define ADC_IN_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define ADC_IN_SetPushPull()        do { ODCONAbits.ODA4 = 0; } while(0)
#define ADC_IN_SetOpenDrain()       do { ODCONAbits.ODA4 = 1; } while(0)
#define ADC_IN_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define ADC_IN_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set SDA aliases
#define SDA_TRIS                 TRISBbits.TRISB4
#define SDA_LAT                  LATBbits.LATB4
#define SDA_PORT                 PORTBbits.RB4
#define SDA_WPU                  WPUBbits.WPUB4
#define SDA_OD                   ODCONBbits.ODB4
#define SDA_ANS                  ANSELBbits.ANSB4
#define SDA_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define SDA_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define SDA_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define SDA_GetValue()           PORTBbits.RB4
#define SDA_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define SDA_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define SDA_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define SDA_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define SDA_SetPushPull()        do { ODCONBbits.ODB4 = 0; } while(0)
#define SDA_SetOpenDrain()       do { ODCONBbits.ODB4 = 1; } while(0)
#define SDA_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define SDA_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set SCL aliases
#define SCL_TRIS                 TRISBbits.TRISB6
#define SCL_LAT                  LATBbits.LATB6
#define SCL_PORT                 PORTBbits.RB6
#define SCL_WPU                  WPUBbits.WPUB6
#define SCL_OD                   ODCONBbits.ODB6
#define SCL_ANS                  ANSELBbits.ANSB6
#define SCL_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define SCL_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define SCL_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define SCL_GetValue()           PORTBbits.RB6
#define SCL_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define SCL_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define SCL_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define SCL_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define SCL_SetPushPull()        do { ODCONBbits.ODB6 = 0; } while(0)
#define SCL_SetOpenDrain()       do { ODCONBbits.ODB6 = 1; } while(0)
#define SCL_SetAnalogMode()      do { ANSELBbits.ANSB6 = 1; } while(0)
#define SCL_SetDigitalMode()     do { ANSELBbits.ANSB6 = 0; } while(0)

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