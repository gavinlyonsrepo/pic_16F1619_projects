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

// get/set SER_DATA aliases
#define SER_DATA_TRIS                 TRISCbits.TRISC0
#define SER_DATA_LAT                  LATCbits.LATC0
#define SER_DATA_PORT                 PORTCbits.RC0
#define SER_DATA_WPU                  WPUCbits.WPUC0
#define SER_DATA_OD                   ODCONCbits.ODC0
#define SER_DATA_ANS                  ANSELCbits.ANSC0
#define SER_DATA_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define SER_DATA_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define SER_DATA_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define SER_DATA_GetValue()           PORTCbits.RC0
#define SER_DATA_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define SER_DATA_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define SER_DATA_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define SER_DATA_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define SER_DATA_SetPushPull()        do { ODCONCbits.ODC0 = 0; } while(0)
#define SER_DATA_SetOpenDrain()       do { ODCONCbits.ODC0 = 1; } while(0)
#define SER_DATA_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define SER_DATA_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set SCLK aliases
#define SCLK_TRIS                 TRISCbits.TRISC1
#define SCLK_LAT                  LATCbits.LATC1
#define SCLK_PORT                 PORTCbits.RC1
#define SCLK_WPU                  WPUCbits.WPUC1
#define SCLK_OD                   ODCONCbits.ODC1
#define SCLK_ANS                  ANSELCbits.ANSC1
#define SCLK_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define SCLK_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define SCLK_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define SCLK_GetValue()           PORTCbits.RC1
#define SCLK_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define SCLK_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define SCLK_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define SCLK_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define SCLK_SetPushPull()        do { ODCONCbits.ODC1 = 0; } while(0)
#define SCLK_SetOpenDrain()       do { ODCONCbits.ODC1 = 1; } while(0)
#define SCLK_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define SCLK_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set RCLK aliases
#define RCLK_TRIS                 TRISCbits.TRISC2
#define RCLK_LAT                  LATCbits.LATC2
#define RCLK_PORT                 PORTCbits.RC2
#define RCLK_WPU                  WPUCbits.WPUC2
#define RCLK_OD                   ODCONCbits.ODC2
#define RCLK_ANS                  ANSELCbits.ANSC2
#define RCLK_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define RCLK_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define RCLK_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define RCLK_GetValue()           PORTCbits.RC2
#define RCLK_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define RCLK_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define RCLK_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define RCLK_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define RCLK_SetPushPull()        do { ODCONCbits.ODC2 = 0; } while(0)
#define RCLK_SetOpenDrain()       do { ODCONCbits.ODC2 = 1; } while(0)
#define RCLK_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define RCLK_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

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