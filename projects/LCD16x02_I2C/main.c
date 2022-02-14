/*
 * Project Name: 1619_LCD
 * File: main.c 
 * Desc: HD44780-based character LCD 16x02 using I2C(PCF8574) library
 * Author: Gavin Lyons.
 * Complier: xc8 v2.10 compiler
 * PIC: PIC16F1619 
 * IDE:  MPLAB X v6.00
 * Created March 2019 , updated Feb 2022 
 * Description: See URL for full details.
 * URL: https://github.com/gavinlyonsrepo/pic_16F1619_projects
 */

// Section: Included Files
#include "mcc_generated_files/mcc.h"
#include <stdio.h> /* for sprintf */
#include "HD44780_I2C_lcd.h"


// Section: Defines
#define INIT_DELAY 1000
#define DISPLAY_DELAY_2 2000
#define DISPLAY_DELAY 5000

// Section: Function Prototypes
void Setup(void);
void HelloWorld(void);
void CursorMoveTest(void);
void ScrollTest(void);
void gotoTest(void);
void resetTest(void);
void customChar(void);
void backLightTest(void);

// Section::  MAIN Loop 
void main(void) {
    Setup();
    while (1) {
        HelloWorld();
        CursorMoveTest();
        ScrollTest();
        gotoTest();
        resetTest();
        customChar();
        backLightTest();

    }
}
// End of main


// Section : Function Space


// Function to setup PIC

void Setup(void) {
    // initialize the device
    SYSTEM_Initialize();
    __delay_ms(INIT_DELAY);
    PCF8574_LCDInit(CURSOR_ON);
}

void HelloWorld(void) {
    PCF8574_LCDGOTO(1, 0);
    PCF8574_LCDSendString("Hello");
    PCF8574_LCDGOTO(2, 0);
    PCF8574_LCDSendString("World"); // Display a string
    PCF8574_LCDSendChar('!'); // Display a single character
    __delay_ms(DISPLAY_DELAY);
}

void CursorMoveTest(void) {
    PCF8574_LCDMoveCursor(MOVE_RIGHT, 2);
    __delay_ms(DISPLAY_DELAY);
    PCF8574_LCDMoveCursor(MOVE_LEFT, 2);
}

void ScrollTest(void) {
    for (uint8_t i = 0; i < 5; i++) {
        PCF8574_LCDScroll(MOVE_RIGHT, 1);
        __delay_ms(DISPLAY_DELAY_2);
    }
    PCF8574_LCDScroll(MOVE_LEFT, 5);
    __delay_ms(DISPLAY_DELAY_2);
}

void gotoTest(void) {
    PCF8574_LCDClearScreen();
    PCF8574_LCDGOTO(1, 10);
    PCF8574_LCDSendChar('A');
    PCF8574_LCDGOTO(2, 2);
    PCF8574_LCDSendString("Line");
    __delay_ms(DISPLAY_DELAY);
}

void resetTest(void) {
    PCF8574_LCDResetScreen(CURSOR_BLINK);
    __delay_ms(DISPLAY_DELAY);
}

void customChar(void) {

    // Data to test custom function
    uint8_t bell[8] = {0x4, 0xe, 0xe, 0xe, 0x1f, 0x0, 0x4};
    uint8_t note[8] = {0x2, 0x3, 0x2, 0xe, 0x1e, 0xc, 0x0};
    uint8_t clock[8] = {0x0, 0xe, 0x15, 0x17, 0x11, 0xe, 0x0};
    uint8_t heart[8] = {0x0, 0xa, 0x1f, 0x1f, 0xe, 0x4, 0x0};
    uint8_t duck[8] = {0x0, 0xc, 0x1d, 0xf, 0xf, 0x6, 0x0};
    uint8_t check[8] = {0x0, 0x1, 0x3, 0x16, 0x1c, 0x8, 0x0};
    uint8_t cross[8] = {0x0, 0x1b, 0xe, 0x4, 0xe, 0x1b, 0x0};
    uint8_t retarrow[8] = {0x1, 0x1, 0x5, 0x9, 0x1f, 0x8, 0x4};

    PCF8574_LCDClearScreen();

    // Load the CGRAM with the data , custom characters
    PCF8574_LCDCreateCustomChar(0, bell);
    PCF8574_LCDCreateCustomChar(1, note);
    PCF8574_LCDCreateCustomChar(2, clock);
    PCF8574_LCDCreateCustomChar(3, heart);
    PCF8574_LCDCreateCustomChar(4, duck);
    PCF8574_LCDCreateCustomChar(5, check);
    PCF8574_LCDCreateCustomChar(6, cross);
    PCF8574_LCDCreateCustomChar(7, retarrow);

    PCF8574_LCDGOTO(1, 0);

    // Print out custom characters

    for (uint8_t i = 0; i < 8; i++) {
        PCF8574_LCDSendData(i);
    }

    __delay_ms(DISPLAY_DELAY);
    PCF8574_LCDClearScreen();
}

void backLightTest(void) {
    PCF8574_LCDBackLightSet(false);
    PCF8574_LCDGOTO(2, 1);
    PCF8574_LCDSendString("Backlight test");
    __delay_ms(DISPLAY_DELAY);
    PCF8574_LCDBackLightSet(true);
    PCF8574_LCDClearScreen();
}

// EOF