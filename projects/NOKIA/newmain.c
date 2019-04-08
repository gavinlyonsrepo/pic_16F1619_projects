/*
* Project Name: Nokia 5110
* File: newmain.c 
* Desc: NOkia 5110 main example file
* Author: Gavin Lyons.
* Complier: xc8 v2.00 compiler
* PIC: PIC16F1619 
* IDE:  MPLAB X v5.00
* Development board: Microchip Curiosity Board, PIC16F1619
* Created March 2019
* Description: See URL for full details.
* URL: https://github.com/gavinlyonsrepo/pic_16F1619_projects
*/

#include <xc.h>
#include "NOKIA.h"

#define _XTAL_FREQ 4000000

// CONFIG1
#pragma config FOSC = INTOSC    // Oscillator Selection Bits->INTOSC oscillator: I/O function on CLKIN pin
#pragma config PWRTE = OFF    // Power-up Timer Enable->PWRT disabled
#pragma config MCLRE = ON    // MCLR Pin Function Select->MCLR/VPP pin function is MCLR
#pragma config CP = OFF    // Flash Program Memory Code Protection->Program memory code protection is disabled
#pragma config BOREN = ON    // Brown-out Reset Enable->Brown-out Reset enabled
#pragma config CLKOUTEN = OFF    // Clock Out Enable->CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin
#pragma config IESO = ON    // Internal/External Switch Over->Internal External Switch Over mode is enabled
#pragma config FCMEN = ON    // Fail-Safe Clock Monitor Enable->Fail-Safe Clock Monitor is enabled

// CONFIG2
#pragma config WRT = OFF    // Flash Memory Self-Write Protection->Write protection off
#pragma config PPS1WAY = ON    // Peripheral Pin Select one-way control->The PPSLOCK bit cannot be cleared once it is set by software
#pragma config ZCD = OFF    // Zero Cross Detect Disable Bit->ZCD disable.  ZCD can be enabled by setting the ZCDSEN bit of ZCDCON
#pragma config PLLEN = OFF    // PLL Enable Bit->4x PLL is enabled when software sets the SPLLEN bit
#pragma config STVREN = ON    // Stack Overflow/Underflow Reset Enable->Stack Overflow or Underflow will cause a Reset
#pragma config BORV = LO    // Brown-out Reset Voltage Selection->Brown-out Reset Voltage (Vbor), low trip point selected.
#pragma config LPBOR = OFF    // Low-Power Brown Out Reset->Low-Power BOR is disabled
#pragma config LVP = ON    // Low-Voltage Programming Enable->Low-voltage programming enabled

// CONFIG3
#pragma config WDTCPS = WDTCPS1F    // WDT Period Select->Software Control (WDTPS)
#pragma config WDTE = OFF    // Watchdog Timer Enable->WDT disabled
#pragma config WDTCWS = WDTCWSSW    // WDT Window Select->Software WDT window size control (WDTWS bits)
#pragma config WDTCCS = SWC    // WDT Input Clock Selector->Software control, controlled by WDTCS bit

#define LED_STATUS RA2
#define LED_STATUS_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define LED_STATUS_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define LED_STATUS_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)

void Setup(void);
void DisplayData(void);
void GPIO_Init(void);
void OSC_Init(void);

/* ===============  Main application =============  */
void main(void)
{
    Setup();
    while (1)
    {
         DisplayData();
    }
}

/* ================= Function Space ============ */

// Function to setup PIC
void Setup(void)
{
    GPIO_Init();
    OSC_Init();
    LCDInit();
    LCDClear();
    LED_STATUS_SetHigh();
}

//Function to init the I/O ports
void GPIO_Init(void)
{
    /*LATx registers*/
    LATA = 0x00;
    LATB = 0x00;
    LATC = 0x00;

    /* TRISx registers*/
    TRISA = 0x33;
    TRISB = 0xF0;
    TRISC = 0xE0;

    /*ANSELx registers*/
    ANSELC = 0xC0;
    ANSELB = 0xF0;
    ANSELA = 0x07;

    /*WPUx registers */
    WPUB = 0x00;
    WPUA = 0x00;
    WPUC = 0x00;
    OPTION_REGbits.nWPUEN = 1;

    /* ODx registers */
    ODCONA = 0x00;
    ODCONB = 0x00;
    ODCONC = 0x00;

    /*SLRCONx registers*/
    SLRCONA = 0x37;
    SLRCONB = 0xF0;
    SLRCONC = 0xFF;   
}

//Function to init oscillator
void OSC_Init(void)
{
    // SCS FOSC; SPLLEN disabled; IRCF 4MHz_HF; 
    OSCCON = 0x68;
    // TUN 0; 
    OSCTUNE = 0x00;
    // SBOREN disabled; BORFS disabled; 
    BORCON = 0x00;
}

//Function to Display Data to LCD
void DisplayData(void)
{
        LED_STATUS_Toggle();
        LCDgotoXY(0,0);
        LCDString("Line 1");
        LCDgotoXY(4,1);
        LCDString("Line 2");
        LCDgotoXY(8,2);
        LCDString("Line 3");
        LCDgotoXY(12,3);
        LCDString("Line 4");
        LCDgotoXY(16,4);
        LCDString("Line 5");
        LCDgotoXY(20,5);
        LCDString("Line 6");
        __delay_ms(2000);
}
/* =============== EOF =========== */