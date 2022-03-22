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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16F1619
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB 	          :  MPLAB X 5.45	
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

// get/set LCD_RST aliases
#define LCD_RST_TRIS                 TRISCbits.TRISC0
#define LCD_RST_LAT                  LATCbits.LATC0
#define LCD_RST_PORT                 PORTCbits.RC0
#define LCD_RST_WPU                  WPUCbits.WPUC0
#define LCD_RST_OD                   ODCONCbits.ODC0
#define LCD_RST_ANS                  ANSELCbits.ANSC0
#define LCD_RST_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define LCD_RST_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define LCD_RST_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define LCD_RST_GetValue()           PORTCbits.RC0
#define LCD_RST_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define LCD_RST_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define LCD_RST_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define LCD_RST_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define LCD_RST_SetPushPull()        do { ODCONCbits.ODC0 = 0; } while(0)
#define LCD_RST_SetOpenDrain()       do { ODCONCbits.ODC0 = 1; } while(0)
#define LCD_RST_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define LCD_RST_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set LCD_CE aliases
#define LCD_CE_TRIS                 TRISCbits.TRISC1
#define LCD_CE_LAT                  LATCbits.LATC1
#define LCD_CE_PORT                 PORTCbits.RC1
#define LCD_CE_WPU                  WPUCbits.WPUC1
#define LCD_CE_OD                   ODCONCbits.ODC1
#define LCD_CE_ANS                  ANSELCbits.ANSC1
#define LCD_CE_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define LCD_CE_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define LCD_CE_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define LCD_CE_GetValue()           PORTCbits.RC1
#define LCD_CE_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define LCD_CE_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define LCD_CE_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define LCD_CE_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define LCD_CE_SetPushPull()        do { ODCONCbits.ODC1 = 0; } while(0)
#define LCD_CE_SetOpenDrain()       do { ODCONCbits.ODC1 = 1; } while(0)
#define LCD_CE_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define LCD_CE_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set LCD_DC aliases
#define LCD_DC_TRIS                 TRISCbits.TRISC2
#define LCD_DC_LAT                  LATCbits.LATC2
#define LCD_DC_PORT                 PORTCbits.RC2
#define LCD_DC_WPU                  WPUCbits.WPUC2
#define LCD_DC_OD                   ODCONCbits.ODC2
#define LCD_DC_ANS                  ANSELCbits.ANSC2
#define LCD_DC_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define LCD_DC_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define LCD_DC_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define LCD_DC_GetValue()           PORTCbits.RC2
#define LCD_DC_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define LCD_DC_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define LCD_DC_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define LCD_DC_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define LCD_DC_SetPushPull()        do { ODCONCbits.ODC2 = 0; } while(0)
#define LCD_DC_SetOpenDrain()       do { ODCONCbits.ODC2 = 1; } while(0)
#define LCD_DC_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define LCD_DC_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set LCD_DIN aliases
#define LCD_DIN_TRIS                 TRISCbits.TRISC3
#define LCD_DIN_LAT                  LATCbits.LATC3
#define LCD_DIN_PORT                 PORTCbits.RC3
#define LCD_DIN_WPU                  WPUCbits.WPUC3
#define LCD_DIN_OD                   ODCONCbits.ODC3
#define LCD_DIN_ANS                  ANSELCbits.ANSC3
#define LCD_DIN_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define LCD_DIN_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define LCD_DIN_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define LCD_DIN_GetValue()           PORTCbits.RC3
#define LCD_DIN_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define LCD_DIN_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define LCD_DIN_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define LCD_DIN_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define LCD_DIN_SetPushPull()        do { ODCONCbits.ODC3 = 0; } while(0)
#define LCD_DIN_SetOpenDrain()       do { ODCONCbits.ODC3 = 1; } while(0)
#define LCD_DIN_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define LCD_DIN_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set LCD_CLK aliases
#define LCD_CLK_TRIS                 TRISCbits.TRISC4
#define LCD_CLK_LAT                  LATCbits.LATC4
#define LCD_CLK_PORT                 PORTCbits.RC4
#define LCD_CLK_WPU                  WPUCbits.WPUC4
#define LCD_CLK_OD                   ODCONCbits.ODC4
#define LCD_CLK_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define LCD_CLK_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define LCD_CLK_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define LCD_CLK_GetValue()           PORTCbits.RC4
#define LCD_CLK_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define LCD_CLK_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define LCD_CLK_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define LCD_CLK_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define LCD_CLK_SetPushPull()        do { ODCONCbits.ODC4 = 0; } while(0)
#define LCD_CLK_SetOpenDrain()       do { ODCONCbits.ODC4 = 1; } while(0)

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