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

// get/set EN_RB4 aliases
#define EN_RB4_TRIS                 TRISBbits.TRISB4
#define EN_RB4_LAT                  LATBbits.LATB4
#define EN_RB4_PORT                 PORTBbits.RB4
#define EN_RB4_WPU                  WPUBbits.WPUB4
#define EN_RB4_OD                   ODCONBbits.ODB4
#define EN_RB4_ANS                  ANSELBbits.ANSB4
#define EN_RB4_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define EN_RB4_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define EN_RB4_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define EN_RB4_GetValue()           PORTBbits.RB4
#define EN_RB4_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define EN_RB4_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define EN_RB4_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define EN_RB4_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define EN_RB4_SetPushPull()        do { ODCONBbits.ODB4 = 0; } while(0)
#define EN_RB4_SetOpenDrain()       do { ODCONBbits.ODB4 = 1; } while(0)
#define EN_RB4_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define EN_RB4_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set RS_RB5 aliases
#define RS_RB5_TRIS                 TRISBbits.TRISB5
#define RS_RB5_LAT                  LATBbits.LATB5
#define RS_RB5_PORT                 PORTBbits.RB5
#define RS_RB5_WPU                  WPUBbits.WPUB5
#define RS_RB5_OD                   ODCONBbits.ODB5
#define RS_RB5_ANS                  ANSELBbits.ANSB5
#define RS_RB5_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define RS_RB5_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define RS_RB5_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define RS_RB5_GetValue()           PORTBbits.RB5
#define RS_RB5_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define RS_RB5_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define RS_RB5_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define RS_RB5_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define RS_RB5_SetPushPull()        do { ODCONBbits.ODB5 = 0; } while(0)
#define RS_RB5_SetOpenDrain()       do { ODCONBbits.ODB5 = 1; } while(0)
#define RS_RB5_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define RS_RB5_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set D4_RC0 aliases
#define D4_RC0_TRIS                 TRISCbits.TRISC0
#define D4_RC0_LAT                  LATCbits.LATC0
#define D4_RC0_PORT                 PORTCbits.RC0
#define D4_RC0_WPU                  WPUCbits.WPUC0
#define D4_RC0_OD                   ODCONCbits.ODC0
#define D4_RC0_ANS                  ANSELCbits.ANSC0
#define D4_RC0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define D4_RC0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define D4_RC0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define D4_RC0_GetValue()           PORTCbits.RC0
#define D4_RC0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define D4_RC0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define D4_RC0_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define D4_RC0_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define D4_RC0_SetPushPull()        do { ODCONCbits.ODC0 = 0; } while(0)
#define D4_RC0_SetOpenDrain()       do { ODCONCbits.ODC0 = 1; } while(0)
#define D4_RC0_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define D4_RC0_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set D5_RC1 aliases
#define D5_RC1_TRIS                 TRISCbits.TRISC1
#define D5_RC1_LAT                  LATCbits.LATC1
#define D5_RC1_PORT                 PORTCbits.RC1
#define D5_RC1_WPU                  WPUCbits.WPUC1
#define D5_RC1_OD                   ODCONCbits.ODC1
#define D5_RC1_ANS                  ANSELCbits.ANSC1
#define D5_RC1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define D5_RC1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define D5_RC1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define D5_RC1_GetValue()           PORTCbits.RC1
#define D5_RC1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define D5_RC1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define D5_RC1_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define D5_RC1_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define D5_RC1_SetPushPull()        do { ODCONCbits.ODC1 = 0; } while(0)
#define D5_RC1_SetOpenDrain()       do { ODCONCbits.ODC1 = 1; } while(0)
#define D5_RC1_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define D5_RC1_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set D6_RC2 aliases
#define D6_RC2_TRIS                 TRISCbits.TRISC2
#define D6_RC2_LAT                  LATCbits.LATC2
#define D6_RC2_PORT                 PORTCbits.RC2
#define D6_RC2_WPU                  WPUCbits.WPUC2
#define D6_RC2_OD                   ODCONCbits.ODC2
#define D6_RC2_ANS                  ANSELCbits.ANSC2
#define D6_RC2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define D6_RC2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define D6_RC2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define D6_RC2_GetValue()           PORTCbits.RC2
#define D6_RC2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define D6_RC2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define D6_RC2_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define D6_RC2_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define D6_RC2_SetPushPull()        do { ODCONCbits.ODC2 = 0; } while(0)
#define D6_RC2_SetOpenDrain()       do { ODCONCbits.ODC2 = 1; } while(0)
#define D6_RC2_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define D6_RC2_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set D7_RC3 aliases
#define D7_RC3_TRIS                 TRISCbits.TRISC3
#define D7_RC3_LAT                  LATCbits.LATC3
#define D7_RC3_PORT                 PORTCbits.RC3
#define D7_RC3_WPU                  WPUCbits.WPUC3
#define D7_RC3_OD                   ODCONCbits.ODC3
#define D7_RC3_ANS                  ANSELCbits.ANSC3
#define D7_RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define D7_RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define D7_RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define D7_RC3_GetValue()           PORTCbits.RC3
#define D7_RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define D7_RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define D7_RC3_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define D7_RC3_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define D7_RC3_SetPushPull()        do { ODCONCbits.ODC3 = 0; } while(0)
#define D7_RC3_SetOpenDrain()       do { ODCONCbits.ODC3 = 1; } while(0)
#define D7_RC3_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define D7_RC3_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

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