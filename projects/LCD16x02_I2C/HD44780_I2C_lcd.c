/*
 * File: HD44780_I2C_lcd.c
 * Description: 
 * HD44780-based character LCD 16x02 I2C(PCF8574) library source file
 * Author: Gavin Lyons.
 * Complier: xc32 v4.00 compiler
 * PIC: PIC32CM1216CM00032
 * IDE:  MPLAB X v6.00 , Harmony V3
 * Created : Feb 2022
 * Description: See URL for full details.
 * URL: https://github.com/gavinlyonsrepo/pic_32_projects
 */

// Section : Includes
#include "HD44780_I2C_lcd.h"


// Section : Global
uint8_t LCDBACKLIGHT = LCD_BACKLIGHTON_MASK;

// Section : Functions

//  Func Desc: Send data byte to  lcd
//  Param1: data byte
void PCF8574_LCDSendData(unsigned char data) {
    unsigned char data_l, data_u;
    uint8_t data_I2C[4];

    data_l = (data << 4)&0xf0; //select lower nibble by moving it to the upper nibble position
    data_u = data & 0xf0; //select upper nibble
    data_I2C[0] = data_u | (DATA_BYTE_ON & LCDBACKLIGHT); //enable=1 and rs =1 1101  YYYY-X-en-X-rs
    data_I2C[1] = data_u | (DATA_BYTE_OFF & LCDBACKLIGHT); //enable=0 and rs =1 1001 YYYY-X-en-X-rs
    data_I2C[2] = data_l | (DATA_BYTE_ON & LCDBACKLIGHT); //enable=1 and rs =1 1101  YYYY-X-en-X-rs
    data_I2C[3] = data_l | (DATA_BYTE_OFF &  LCDBACKLIGHT); //enable=0 and rs =1 1001 YYYY-X-en-X-rs

   i2c_writeNBytes (LCD_SLAVE_ADDRESS, data_I2C, 4);
}

//  Func Desc: Send command byte to  lcd
//  Param1: command byte

void PCF8574_LCDSendCmd(unsigned char cmd) {
    unsigned char cmd_l, cmd_u;
    uint8_t cmd_I2C[4];

    cmd_l = (cmd << 4)&0xf0; //select lower nibble by moving it to the upper nibble position
    cmd_u = cmd & 0xf0; //select upper nibble
    cmd_I2C[0] = cmd_u | (CMD_BYTE_ON & LCDBACKLIGHT); // YYYY-1100 YYYY-led-en-rw-rs ,enable=1 and rs =0
    cmd_I2C[1] = cmd_u | (CMD_BYTE_OFF & LCDBACKLIGHT); // YYYY-1000 YYYY-led-en-rw-rs ,enable=0 and rs =0
    cmd_I2C[2] = cmd_l | (CMD_BYTE_ON & LCDBACKLIGHT); // YYYY-1100 YYYY-led-en-rw-rs ,enable=1 and rs =0
    cmd_I2C[3] = cmd_l | (CMD_BYTE_OFF & LCDBACKLIGHT); // YYYY-1000 YYYY-led-en-rw-rs ,enable=0 and rs =0

   i2c_writeNBytes ( LCD_SLAVE_ADDRESS, cmd_I2C, 4);
}

// Func Desc: Clear a line by writing spaces to every position
// Param1: uint8_t lineNo, row number 1-2

void PCF8574_LCDClearLine(uint8_t lineNo) {
    if (lineNo == 1) {
        PCF8574_LCDSendCmd(LCD_LINE_ADR1);
    } else if (lineNo == 2) {
        PCF8574_LCDSendCmd(LCD_LINE_ADR2);
    } else {
        return;
    }

    for (uint8_t i = 0; i < 16; i++) {
        PCF8574_LCDSendData(' ');
    }
}

// Func Desc: Clear screen by writing spaces to every position

void PCF8574_LCDClearScreen(void) {
    PCF8574_LCDClearLine(1);
    PCF8574_LCDClearLine(2);
}


// Func Desc: Reset screen 
// Param1: enum LCD_CURSOR_TYPE_e cursor type, 4 choices

void PCF8574_LCDResetScreen(LCD_CURSOR_TYPE_e CursorType) {
    PCF8574_LCDSendCmd(LCD_MODE_4BIT);
    PCF8574_LCDSendCmd(LCD_DISPLAY_ON);
    PCF8574_LCDSendCmd(CursorType);
    PCF8574_LCDSendCmd(LCD_CLRSCR);
    PCF8574_LCDSendCmd(LCD_INC_MODE);
}


// Func Desc: Turn Screen on and off 
// Param1: passed bool, True = display on , false = display off

void PCF8574_LCDDisplayON(bool OnOff) {
    OnOff ? PCF8574_LCDSendCmd(LCD_DISPLAY_ON) : PCF8574_LCDSendCmd(LCD_DISPLAY_OFF);

}


// Func Desc: Initialise LCD
// Param1: enum LCD_CURSOR_TYPE_e cursor type, 4 choices. 

void PCF8574_LCDInit(LCD_CURSOR_TYPE_e CursorType) {

    __delay_ms(15);
    PCF8574_LCDSendCmd(LCD_HOME);
    __delay_ms(5);
    PCF8574_LCDSendCmd(LCD_HOME);
    __delay_ms(5);
    PCF8574_LCDSendCmd(LCD_HOME);
    __delay_ms(5);
    PCF8574_LCDSendCmd(LCD_MODE_4BIT);
    PCF8574_LCDSendCmd(LCD_DISPLAY_ON);
    PCF8574_LCDSendCmd(CursorType);
    PCF8574_LCDSendCmd(LCD_INC_MODE);
    PCF8574_LCDSendCmd(LCD_CLRSCR);
   
}

// Func Desc: Send string to LCD
// Param1: Pointer to the char array

void PCF8574_LCDSendString(char *str) {
    while (*str) PCF8574_LCDSendData(*str++);
}


// Func Desc: Sends a character to screen , simply wraps SendData command.
// Param1: Character to display
void PCF8574_LCDSendChar(char data) {
    PCF8574_LCDSendData(data);
}

// Func Desc: Moves cursor 
// Param1. enum LCD_DIRECTION_TYPE_e left or right 
// Param2. uint8_t number of spaces to move

void PCF8574_LCDMoveCursor(LCD_DIRECTION_TYPE_e direction, uint8_t moveSize) {
    uint8_t i = 0;
    if (direction == MOVE_RIGHT) {
        for (i = 0; i < moveSize; i++) {
            PCF8574_LCDSendCmd(LCD_MOV_CURSOR_RIGHT);
        }
    } else {
        for (i = 0; i < moveSize; i++) {
            PCF8574_LCDSendCmd(LCD_MOV_CURSOR_LEFT);
        }
    }

}

// Func Desc: Scrolls screen 
// Param1. enum LCD_DIRECTION_TYPE_e , left or right 
// Param2. uint8_t number of spaces to scroll

void PCF8574_LCDScroll(LCD_DIRECTION_TYPE_e direction, uint8_t ScrollSize) {
    uint8_t i = 0;
    if (direction == MOVE_RIGHT) {
        for (i = 0; i < ScrollSize; i++) {
            PCF8574_LCDSendCmd(LCD_SCROLL_RIGHT);
        }
    } else {
        for (i = 0; i < ScrollSize; i++) {
            PCF8574_LCDSendCmd(LCD_SCROLL_LEFT);
        }
    }

}
// Func Desc: moves cursor
// Param1: uint8_t row 1-2 
// Param2: uint8_t col 0-15
void PCF8574_LCDGOTO(uint8_t row, uint8_t col) {
    switch (row) {
        case 1:
            PCF8574_LCDSendCmd(LCD_LINE_ADR1 | col);
            break;

        case 2:
            PCF8574_LCDSendCmd(LCD_LINE_ADR2 | col);
            break;

        default:
            __nop();
    }
}

void PCF8574_LCDCreateCustomChar(uint8_t location, uint8_t * charmap)
{
    //location &= 0x08; // we only have 8 locations 0-7
    PCF8574_LCDSendCmd(LCD_CG_RAM | (location<<3));
    //PCF8574_LCDSendString(charmap);
	for (uint8_t i=0; i<8; i++) {
		PCF8574_LCDSendData(charmap[i]);
	}
}

// Func Desc: Turn LED backlight on and off 
// Param1: passed bool True = LED on , false = display LED off
// Note: another command must be issued before takes effect.
void PCF8574_LCDBackLightSet(bool OnOff)
{
     OnOff ? (LCDBACKLIGHT = LCD_BACKLIGHTON_MASK) : (LCDBACKLIGHT = LCD_BACKLIGHTOFF_MASK);
}
