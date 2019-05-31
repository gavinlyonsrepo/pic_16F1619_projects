/*
* Project Name: tm1637
* File: TM1637Display.h 
* Description: Source file library TM1637  4 digit seven segment module 3462BS
* Author: Gavin Lyons.
* Complier: xc8 v2.05 compiler
* PIC: PIC16F1619 
* IDE:  MPLAB X v5.05
* Development board: Microchip Curiosity Board, PIC16F1619
* Created May 2019
*/

#include "TM1637Display.h"
#include "mcc_generated_files/mcc.h"

#define TM1637_I2C_COMM1    0x40  // automatic data incrementing
#define TM1637_I2C_COMM2    0xC0 // Data Data1~N: Transfer display data
#define TM1637_I2C_COMM3    0x80 // display intensity

const uint8_t digitToSegment[] = {
 // XGFEDCBA
  0b00111111,    // 0
  0b00000110,    // 1
  0b01011011,    // 2
  0b01001111,    // 3
  0b01100110,    // 4
  0b01101101,    // 5
  0b01111101,    // 6
  0b00000111,    // 7
  0b01111111,    // 8
  0b01101111,    // 9
  0b01110111,    // A
  0b01111100,    // b
  0b00111001,    // C
  0b01011110,    // d
  0b01111001,    // E
  0b01110001     // F
  };


void TM1637Display(void)
{
	// Set the pin direction.
	pinClk_SetDigitalInput() ;
	pinDIO_SetDigitalInput() ;
}

void setBrightness(uint8_t brightness, bool on)
{
	m_brightness = (brightness & 0x7) | (on? 0x08 : 0x00);
}

void setSegments(const uint8_t segments[], uint8_t length, uint8_t pos)
{
    // Write COMM1
	start();
	writeByte(TM1637_I2C_COMM1);
	stop();

	// Write COMM2 + first digit address
	start();
	writeByte(TM1637_I2C_COMM2 + (pos & 0x03));

	// Write the data bytes
	for (uint8_t k=0; k < length; k++)
	  writeByte(segments[k]);

	stop();

	// Write COMM3 + brightness
	start();
	writeByte(TM1637_I2C_COMM3 + (m_brightness & 0x0f));
	stop();
}

void showNumberDec(int num,  bool leading_zero ,uint8_t length, uint8_t pos)
{
  showNumberDecEx(num, 0, leading_zero, length, pos);
}

void showNumberDecEx(int num, uint8_t dots,  bool leading_zero ,uint8_t length, uint8_t pos)
{
  uint8_t digits[4];
	const static int divisors[] = { 1, 10, 100, 1000 };
	bool leading = true;

	for(int8_t k = 0; k < 4; k++) {
	    int divisor = divisors[4 - 1 - k];
		int d = num / divisor;
    uint8_t digit = 0;

		if (d == 0) {
		  if (leading_zero || !leading || (k == 3))
		      digit = encodeDigit(d);
	      else
		      digit = 0;
		}
		else {
			digit = encodeDigit(d);
			num -= d * divisor;
			leading = false;
		}
    
    // Add the decimal point/colon to the digit
    digit |= (dots & 0x80); 
    dots <<= 1;
    
    digits[k] = digit;
	}

	setSegments(digits + (4 - length), length, pos);
}


void bitDelay()
{
	__delay_us(75);
}

void start()
{
  pinDIO_SetDigitalOutput();
  bitDelay();
}

void stop()
{
	pinDIO_SetDigitalOutput();
	bitDelay();
	pinClk_SetDigitalInput() ;
	bitDelay();
	pinDIO_SetDigitalInput() ;
	bitDelay();
}

bool writeByte(uint8_t b)
{
  uint8_t data = b;

  // 8 Data Bits
  for(uint8_t i = 0; i < 8; i++) {
    // CLK low
    pinClk_SetDigitalOutput();
    bitDelay();

	// Set data bit
    if (data & 0x01)
       pinDIO_SetDigitalInput();
    else
      pinDIO_SetDigitalOutput();

    bitDelay();

	// CLK high
    pinClk_SetDigitalInput();
    bitDelay();
    data = data >> 1;
  }

  // Wait for acknowledge
  // CLK to zero
  pinClk_SetDigitalOutput();
  pinDIO_SetDigitalInput();
  bitDelay();

  // CLK to high
  pinClk_SetDigitalInput();
  bitDelay();
  uint8_t ack = pinDIO_GetValue();
  if (ack == 0)
    pinDIO_SetDigitalOutput() ;

  bitDelay();
  pinClk_SetDigitalOutput();
  bitDelay();

  return ack;
}

uint8_t encodeDigit(uint8_t digit)
{
	return digitToSegment[digit & 0x0f];
}
