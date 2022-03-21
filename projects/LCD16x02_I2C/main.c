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
#define INIT_DELAY 50
#define DISPLAY_DELAY_2 2000
#define DISPLAY_DELAY 5000

// Section: Function Prototypes
void Setup(void);
void HelloWorld(void);
void CursorMoveTest(void);
void ScrollTest(void);
void gotoTest(void);
void CursorTypeTest(void);
void EntryModeTest(void);
void customChar(void);
void backLightTest(void);

// Section::  MAIN Loop 
void main(void) {
    Setup();
    while (1) {
        EntryModeTest(); // test entry mode commands
        HelloWorld(); // test string + character data
        CursorMoveTest(); //test cursor move
        ScrollTest();
        gotoTest();
        CursorTypeTest();
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
    PCF8574_LCDInit(LCDCursorTypeOn, 2, 16, 0x27);
}

void HelloWorld(void) {
    PCF8574_LCDGOTO(LCDLineNumberOne, 0);
    PCF8574_LCDSendString("Hello");
    PCF8574_LCDGOTO(LCDLineNumberTwo, 0);
    PCF8574_LCDSendString("World"); // Display a string
    PCF8574_LCDSendChar('!'); // Display a single character
    __delay_ms(DISPLAY_DELAY);
}

void CursorMoveTest(void) {
    PCF8574_LCDMoveCursor(LCDMoveRight, 2);
    __delay_ms(DISPLAY_DELAY);
    PCF8574_LCDMoveCursor(LCDMoveLeft, 2);
}

void ScrollTest(void) {
    for (uint8_t i = 0; i < 5; i++) {
        PCF8574_LCDScroll(LCDMoveRight, 1);
        __delay_ms(DISPLAY_DELAY_2);
    }
    PCF8574_LCDScroll(LCDMoveLeft, 5);
    __delay_ms(DISPLAY_DELAY_2);
}

void gotoTest(void) {
    PCF8574_LCDClearScreen();
    PCF8574_LCDGOTO(LCDLineNumberOne, 10);
    PCF8574_LCDSendChar('A');
    PCF8574_LCDGOTO(LCDLineNumberTwo, 2);
    PCF8574_LCDSendString("Line");
    __delay_ms(DISPLAY_DELAY);
}

void CursorTypeTest(void) {
    PCF8574_LCDResetScreen(LCDCursorTypeOnBlink); //type 4 cursor
    PCF8574_LCDGOTO(LCDLineNumberTwo, 0);
    PCF8574_LCDSendString("Cursor no 4");
    __delay_ms(DISPLAY_DELAY);
    PCF8574_LCDClearLine(LCDLineNumberTwo);

    PCF8574_LCDResetScreen(LCDCursorTypeOff); //type 1 cursor
    PCF8574_LCDGOTO(LCDLineNumberTwo, 0);
    PCF8574_LCDSendString("Cursor no 1");
    __delay_ms(DISPLAY_DELAY);
    PCF8574_LCDClearLine(LCDLineNumberTwo);

    PCF8574_LCDResetScreen(LCDCursorTypeBlink); //type 2 cursor
    PCF8574_LCDGOTO(LCDLineNumberTwo, 0);
    PCF8574_LCDSendString("Cursor no 2");
    __delay_ms(DISPLAY_DELAY);
    PCF8574_LCDClearLine(LCDLineNumberTwo);

    PCF8574_LCDResetScreen(LCDCursorTypeOn); // Back to initial state , type 3
    PCF8574_LCDGOTO(LCDLineNumberTwo, 0);
    PCF8574_LCDSendString("Cursor no 3");
    __delay_ms(DISPLAY_DELAY_2);
}

void EntryModeTest(void) {

    PCF8574_LCDSendCmd(LCDEntryModeOne);
    PCF8574_LCDGOTO(LCDLineNumberOne, 8);
    PCF8574_LCDSendString("1234"); // <-C4321
    __delay_ms(DISPLAY_DELAY_2);
    PCF8574_LCDClearScreenCmd();

    PCF8574_LCDSendCmd(LCDEntryModeTwo);
    PCF8574_LCDGOTO(LCDLineNumberTwo, 8);
    PCF8574_LCDSendString("1234"); // C4321->
    __delay_ms(DISPLAY_DELAY_2);
    PCF8574_LCDClearScreenCmd();

    PCF8574_LCDSendCmd(LCDEntryModeFour);
    PCF8574_LCDGOTO(LCDLineNumberTwo, 8);
    PCF8574_LCDSendString("1234"); // <-1234C
    __delay_ms(DISPLAY_DELAY_2);
    PCF8574_LCDClearScreenCmd();

    PCF8574_LCDSendCmd(LCDEntryModeThree); // Set back to default entry mode
    PCF8574_LCDClearScreenCmd();
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
        PCF8574_LCDPrintCustomChar(i);
        PCF8574_LCDMoveCursor(LCDMoveRight, 1);
    }

    __delay_ms(DISPLAY_DELAY);
    PCF8574_LCDClearScreen();
}

void backLightTest(void) {
    PCF8574_LCDBackLightSet(false);
    PCF8574_LCDGOTO(LCDLineNumberTwo, 1);
    PCF8574_LCDSendString("Backlight test");
    __delay_ms(DISPLAY_DELAY);
    PCF8574_LCDBackLightSet(true);
    PCF8574_LCDClearScreen();
}


// EOF