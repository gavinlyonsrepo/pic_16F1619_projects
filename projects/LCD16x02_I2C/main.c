/*
* Project Name: 1619_LCD
* File: main.c 
* Desc:  HD44780-based character LCD 16x02 using I2C
* Author: Gavin Lyons.
* Complier: xc8 v2.00 compiler
* PIC: PIC16F1619 
* IDE:  MPLAB X v5.00
* Development board: Microchip Curiosity Board, PIC16F1619
* Created March 2019
* Description: See URL for full details.
* URL: https://github.com/gavinlyonsrepo/pic_16F1619_projects
*/

#include "mcc_generated_files/mcc.h"
uint16_t potvalue=0; //var to hold pot value from RA4

#define SLAVE_ADDRESS_LCD 0x27

// send data to lcd
void lcd_send_data (unsigned char data)
{
	unsigned char data_l, data_u;
	data_l = (data<<4)&0xf0;  //select lower nibble by moving it to the upper nibble position
	data_u = data&0xf0;  //select upper nibble
        
    i2c_driver_start();
    
    i2c_driver_TXData (SLAVE_ADDRESS_LCD);
    i2c_driver_TXData (data_u|0x0D);  //enable=1 and rs =0
    i2c_driver_TXData (data_u|0x09);  //enable=0 and rs =0
    
    i2c_driver_TXData (data_l|0x0D);  //enable=1 and rs =0
    i2c_driver_TXData (data_l|0x09);  //enable=0 and rs =0
    i2c_driver_stop();
}

// send command to LCD
void lcd_send_cmd (unsigned char data)
{
	unsigned char data_l, data_u;
	data_l = (data<<4)&0xf0;  //select lower nibble by moving it to the upper nibble position
	data_u = data&0xf0;  //select upper nibble

    i2c_driver_start();
    
    i2c_driver_TXData (SLAVE_ADDRESS_LCD);
    i2c_driver_TXData (data_u|0x0C);  //enable=1 and rs =0
    i2c_driver_TXData (data_u|0x08);  //enable=0 and rs =0
    
    i2c_driver_TXData (data_l|0x0C);  //enable=1 and rs =0
    i2c_driver_TXData (data_l|0x08);  //enable=0 and rs =0
    i2c_driver_stop();
}

lcd_clear (void)
{
    lcd_send_cmd (0x80);
    for (int i=0;i<60;i++)
    {
        lcd_send_data (' ');
    }
    lcd_send_cmd (0xc0);
    for (int i=0;i<60;i++)
    {
        lcd_send_data (' ');
    }
    
}

// initialise LCD
void lcd_init (void)
{
	lcd_send_cmd (0x02);
	lcd_send_cmd (0x28);// 4-bits, 2 lines, 5x7 font
    lcd_send_cmd (0x0C);// Display ON, No cursors
	lcd_send_cmd (0x06);// Entry mode- Auto-increment, No Display shifting
    lcd_send_cmd  (0x01); 
}

/* Function name LCDgoto
 * Changes the current cursor position
 */
void LCDgoto(char x, char y)
   {
   char addr = 0x80;
   if(y==2) addr = 0xC0;
   addr+=x;
  lcd_send_cmd (addr);
}

// send string to LCD
void lcd_send_string (char *str)
{
	while (*str) lcd_send_data (*str++);
}


/* Main */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    INTERRUPT_GlobalInterruptEnable();
    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();
    LED_STATUS_SetHigh(); 
   __delay_ms(10);
    // initialise LCD
    lcd_init ();
    // send string to LCD
     LCDgoto(0,0);
    lcd_send_string ("Hello WORLD");
    __delay_ms(3000);
   while(1)
   { 
       if (counter == 1)  // (counter is incremented by timer0 overflow)
        {
           potvalue = ADC_GetConversion(ADC_IN)>>6;
           //DisplayData();
        }
    }
}
/* EOF  */