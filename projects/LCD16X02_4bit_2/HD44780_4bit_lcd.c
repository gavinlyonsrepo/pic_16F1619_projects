// Section : Includes
#include "HD44780_4bit_lcd.h"


// Section : Variables
uint8_t _NumRowsLCD = 2;
uint8_t _NumColsLCD = 16;

// Section : Functions

// Function name LCDtoggle 
// Flip the bit en The control pin enable data transfer with the LCD module 
void LCDtoggle(void)
   {
    EN_RB4_LAT= 1;       //enable-en
     __delay_ms(2);
    EN_RB4_LAT=0;        //disable-en
     __delay_ms(2);
   }

//LCDisplay shifts and masks the  nibble to the 
//four data bins A,B,C,D, map to D7,D6,D5,D4 using bit shift & AND mask.
void LCDdisplay(unsigned char value)  
{
    D4_RC0_LAT=(value >> 0) & 0x01;
    D5_RC1_LAT=(value >> 1) & 0x01;
    D6_RC2_LAT=(value >> 2) & 0x01;
    D7_RC3_LAT=(value >> 3) & 0x01;
    LCDtoggle();
}


//LCD Data Send a data byte to LCD
void LCDSendData(unsigned char data){
    
     RS_RB5_LAT = 1;       //register select-rs high
    __delay_us(100);
    LCDdisplay(data>>4);   //Send Higher nibble 4-bits of 8-bit data
    __delay_us(100);
    LCDdisplay(data);      //Send Lower nibble  4-bits of 8-bit data

}

//LCD Data Send a command  byte to LCD
void LCDSendCmd(unsigned char cmd){
          
    RS_RB5_LAT=0;          //register select-rs LOW 
   __delay_us(100);
   LCDdisplay(cmd>>4);          //Send Higher nibble 4-bits of 8-bit command
   __delay_us(100);
   LCDdisplay(cmd);             //Send Lower nibble 4-bits of 8-bit command
}


// Func Desc: Clear a line by writing spaces to every position
// Param1: enum LCDLineNumber_e lineNo, row number 1-4

void LCDClearLine(LCDLineNumber_e lineNo) {
    switch (lineNo) {
        case LCDLineNumberOne:
            LCDSendCmd(LCD_LINE_ADR1);
            break;
        case LCDLineNumberTwo:
            LCDSendCmd(LCD_LINE_ADR2);
            break;
        case LCDLineNumberThree:
            if (_NumColsLCD == 20)
                LCDSendCmd(LCD_LINE_ADR3_20);
            else
                LCDSendCmd(LCD_LINE_ADR3_16);
            break;
        case LCDLineNumberFour:
            if (_NumColsLCD == 20)
                LCDSendCmd(LCD_LINE_ADR4_20);
            else
                LCDSendCmd(LCD_LINE_ADR4_16);
            ;
            break;
    }

    for (uint8_t i = 0; i < _NumColsLCD; i++) {
        LCDSendData(' ');
    }
}

// Func Desc: Clear screen by writing spaces to every position
// Note : See also LCDClearScreenCmd for software command  clear alternative.

void LCDClearScreen(void) {
    if (_NumRowsLCD >= 1)
        LCDClearLine(LCDLineNumberOne);
    if (_NumRowsLCD >= 2)
        LCDClearLine(LCDLineNumberTwo);
    if (_NumRowsLCD >= 3)
        LCDClearLine(LCDLineNumberThree);
    if (_NumRowsLCD == 4)
        LCDClearLine(LCDLineNumberFour);
}


// Func Desc: Reset screen 
// Param1: enum LCD_CURSOR_TYPE_e cursor type, 4 choices
// Warning: if you are using a non-default entry mode this function will
// reset entry mode to default 

void LCDResetScreen(LCDCursorType_e cursorType) {
    LCDSendCmd(LCD_MODE_4BIT);
    LCDSendCmd(LCD_DISPLAY_ON);
    LCDSendCmd(cursorType);
    LCDSendCmd(LCDEntryModeThree);
    LCDSendCmd(LCD_CLRSCR);
     __delay_ms(5);

}


// Func Desc: Turn Screen on and off 
// Param1: passed bool, True = display on , false = display off

void LCDDisplayON(bool OnOff) {
    OnOff ? LCDSendCmd(LCD_DISPLAY_ON) : LCDSendCmd(LCD_DISPLAY_OFF);
     __delay_ms(5);
}


// Func Desc: Initialise LCD
// Param1: enum LCD_CURSOR_TYPE_e cursor type, 4 choices. 
// Param2: num of rows in LCD
// Param3: num of cols in LCD
// Param4: PCF8574 I2C slave address

void LCDInit(LCDCursorType_e cursorType, uint8_t numRow, uint8_t numCol) {

     __delay_ms(50);
    LCDSendCmd(LCD_HOME);
     __delay_ms(5);
    LCDSendCmd(LCD_HOME);
     __delay_ms(5);
    LCDSendCmd(LCD_HOME);
     __delay_ms(1);
    LCDSendCmd(LCD_MODE_4BIT);
    LCDSendCmd(LCD_DISPLAY_ON);
    LCDSendCmd(cursorType);
    LCDSendCmd(LCDEntryModeThree);
    LCDSendCmd(LCD_CLRSCR);
     __delay_ms(5);


    _NumRowsLCD = numRow;
    _NumColsLCD = numCol;

}

// Func Desc: Send string to LCD
// Param1: Pointer to the char array

void LCDSendString(char *str) {
    while (*str) LCDSendData(*str++);
}


// Func Desc: Sends a character to screen , simply wraps SendData command.
// Param1: Character to display

void LCDSendChar(char data) {
    LCDSendData(data);
}

// Func Desc: Moves cursor 
// Param1. enum LCD_DIRECTION_TYPE_e left or right 
// Param2. uint8_t number of spaces to move

void LCDMoveCursor(LCDDirectionType_e direction, uint8_t moveSize) {
    uint8_t i = 0;
    if (direction == LCDMoveRight) {
        for (i = 0; i < moveSize; i++) {
            LCDSendCmd(LCD_MOV_CURSOR_RIGHT);
        }
    } else {
        for (i = 0; i < moveSize; i++) {
            LCDSendCmd(LCD_MOV_CURSOR_LEFT);
        }
    }

}

// Func Desc: Scrolls screen 
// Param1. enum LCD_DIRECTION_TYPE_e , left or right 
// Param2. uint8_t number of spaces to scroll

void LCDScroll(LCDDirectionType_e direction, uint8_t ScrollSize) {
    uint8_t i = 0;
    if (direction == LCDMoveRight) {
        for (i = 0; i < ScrollSize; i++) {
            LCDSendCmd(LCD_SCROLL_RIGHT);
        }
    } else {
        for (i = 0; i < ScrollSize; i++) {
            LCDSendCmd(LCD_SCROLL_LEFT);
        }
    }

}
// Func Desc: moves cursor to X Y position 
// Param1: enum LCDLineNumber_e  row 1-4
// Param2: uint8_t col 0 -> _NumColsLCD value

void LCDGOTO(LCDLineNumber_e line, uint8_t col) {
    switch (line) {
        case LCDLineNumberOne:
            LCDSendCmd(LCD_LINE_ADR1 | col);
            break;
        case LCDLineNumberTwo:
            LCDSendCmd(LCD_LINE_ADR2 | col);
            break;
        case LCDLineNumberThree:
            if (_NumColsLCD == 20)
                LCDSendCmd(LCD_LINE_ADR3_20 + col);
            else
                LCDSendCmd(LCD_LINE_ADR3_16 | col);
            break;
        case LCDLineNumberFour:
            if (_NumColsLCD == 20)
                LCDSendCmd(LCD_LINE_ADR4_20 + col);
            else
                LCDSendCmd(LCD_LINE_ADR4_16 | col);
            ;
            break;
    }
}

// Func Desc: Saves a custom character to a location in CG_RAM
// Param1: CG_RAM location 0-7 we only have 8 locations 0-7
// Param2: An array of 8 bytes representing a custom character data

void LCDCreateCustomChar(uint8_t location, uint8_t * charmap) {
    if (location >= 8) {
        return;
    }
    // Base ram address 64 + location * 8
    LCDSendCmd(LCD_CG_RAM | (location << 3));
    for (uint8_t i = 0; i < 8; i++) {
        LCDSendData(charmap[i]);
    }
}

// Print out a custom character from CGRAM
// Param1 CGRAM location 0-7 

void LCDPrintCustomChar(uint8_t location) {
    if (location >= 8) {return;}

    LCDSendData(location);
}


// Func Desc: vsprintf wrapper to print numerical data
// Parameters: https://www.tutorialspoint.com/c_standard_library/c_function_vsprintf.htm 
// The C library function int vsprintf(char *str, const char *format, va_list arg) 
// sends formatted output to a string using an argument list passed to it.
// Returns: If successful, the total number of characters written is returned, 
// otherwise a negative number is returned.
// Note: requires stdio.h and stdarg.h libraries

int LCDPrintf(const char *fmt, ...) {
    int length;
    char buffer[50];
    va_list ap;

    va_start(ap, fmt);
    length = vsprintf(buffer, fmt, ap);
    va_end(ap);
    if (length > 0) {
        LCDSendString(buffer);
    }
    return length;
}

// Clear display using software command , set cursor position to zero
// See also LCDClearScreen for manual clear 

void LCDClearScreenCmd(void) {
    LCDSendCmd(LCD_CLRSCR);
     __delay_ms(2); // Requires a delay
}

// Set Cursor position to zero

void LCDHome(void) {
    LCDSendCmd(LCD_HOME);
     __delay_ms(2); // Requires a delay
}

// ********* EOF ********