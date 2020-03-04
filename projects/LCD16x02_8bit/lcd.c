/*
* Project Name: LCD_16x02_8bit
* File: lcd.c
* Description: HD44780-based character LCD 16x02 8-bit library main file
* Author: Gavin Lyons.
* Complier: xc8 v2.00 compiler
* PIC: PIC16F1619 
* IDE:  MPLAB X v5.00
* Development board: Microchip Curiosity Board, PIC16F1619
* Created March 2019
* Description: See URL for full details.
* URL: https://github.com/gavinlyonsrepo/pic_16F1619_projects
*/

#include "lcd.h"         
#include "mcc_generated_files/mcc.h"

void LCD_init(void){
    LCD_cmd(MODE_8BIT);                   // 2 Line, 5x7 display, 8 bit
    LCD_cmd(CLRSCR);                      // Clear the screen
    LCD_cmd(CURSOR_INC);                  // Cursor Increments on each write
    LCD_cmd(DISPLAY_ON | CURSOR_OFF);     // Display on and Cursor Off
    return;
}

/*
Function Name: LCD_data
Inputs: data Byte
Desc: This function is used to write a 8 bit parallel data 
into the DD RAM of the LCD.
*/
void LCD_data(unsigned char data){
    LCD_isbusy();
    LCD_RS_SetHigh(); 
    LCD_RW_SetLow(); 
    LCD_EN_SetHigh();
    DATAPORT = data;
    __delay_ms(50);
    LCD_EN_SetLow(); 
}


/*
Function Name: LCD_cmd
Inputs: command Byte 
Desc: This function is used to send data to the command register. 
*/
void LCD_cmd(unsigned char cmd){
    LCD_isbusy();
    LCD_RS_SetLow(); 
    LCD_RW_SetLow(); 
    LCD_EN_SetHigh();
    DATAPORT = cmd;
    __delay_ms(50);
    LCD_EN_SetLow(); 
}

/*
Function Name: LCD_string
Inputs: Character pointer.
Desc: This function take the address of the first character of the string 
that you wish to write to the LCD as a parameter until string is empty.
*/
void LCD_string(const char *buffer)
{
    while(*buffer)              // Write data to LCD up to null
    {
        LCD_isbusy();           // Wait while LCD is busy
        LCD_data(*buffer);      // Write character to LCD
        buffer++;               // Increment buffer
    }
}

/*
Function Name: LCD_isbusy
Desc: This function is used to check for the busy flag (DB7). 
The LCD cannot do any operations as long as it is busy. 
*/
void LCD_isbusy(void)
{
    IO_RC7_SetDigitalInput();        // Make D7 as input
    LCD_RS_SetLow(); 
    LCD_RW_SetHigh(); 
    LCD_EN_SetHigh();
    __delay_ms(10);
    while( IO_RC7_PORT);
    IO_RC7_SetDigitalOutput();        // Back to Output
     LCD_EN_SetLow();
}