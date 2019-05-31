/*
* Project Name: tm1637
* File: main.c 
* Description: TM1637  4 digit seven segment module 3462BS
* Author: Gavin Lyons.
* Complier: xc8 v2.05 compiler
* PIC: PIC16F1619 
* IDE:  MPLAB X v5.05
* Development board: Microchip Curiosity Board, PIC16F1619
* Created May 2019
*/

#include "mcc_generated_files/mcc.h"
#include "TM1637Display.h"

// The amount of time (in milliseconds) between tests
#define TEST_DELAY   2000

const uint8_t SEG_DONE[] = {
	SEG_B | SEG_C | SEG_D | SEG_E | SEG_G,           // d
	SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,   // O
	SEG_C | SEG_E | SEG_G,                           // n
	SEG_A | SEG_D | SEG_E | SEG_F | SEG_G            // E
	};


/* ========= Main application ============= */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    TM1637Display();
    setBrightness(0x0f, true);
    uint8_t data[] = { 0xff, 0xff, 0xff, 0xff };
    LED_RA2_SetHigh(); //Status LED
    
    while (1)
    {
    
    int k;
    uint8_t data[] = { 0xff, 0xff, 0xff, 0xff };
    
    
     // All segments on
     setSegments(data,4,0); // 8888
     __delay_ms(TEST_DELAY);
     
     LED_RA2_Toggle();
     
     // Selectively set different digits
     data[0] = 0b01001001;
     data[1] = encodeDigit(1);
     data[2] = encodeDigit(2);
     data[3] = encodeDigit(3);

     for(k = 3; k >= 0; k--) {
       setSegments(data, 1, k); // loop dashes and nums one digit at time
       __delay_ms(TEST_DELAY); 
       }

     setSegments(data+2, 2, 2); // dash dash 2 3
     __delay_ms(TEST_DELAY);

     setSegments(data+2, 2, 1); // dash 2 2 3
     __delay_ms(TEST_DELAY);

     setSegments(data+1, 3, 1); //  dash 1 2 3 
     __delay_ms(TEST_DELAY);
     
     LED_RA2_Toggle();
     
     // Show decimal numbers with/without leading zeros
     // 0 7  42 217 1092 5467 0000 0007 0042 0217 1092 5467 
     bool lz = false;
     for (uint8_t z = 0; z < 2; z++) {
       for(k = 0; k < 10000; k += k*4 + 7) {
           showNumberDec(k, lz, 4, 0);
           __delay_ms(TEST_DELAY);
       }
       lz = true;
     }
     
    
     
      // turn on central dots
     for(k = 0; k < 4; k++)
       data[k] = 0;
     setSegments(data,4,0); //0000
       for(k=0; k <= 4; k++) {
           showNumberDecEx(0, (0x80 >> k), true,4,0);
           __delay_ms(TEST_DELAY);
       }
     
      LED_RA2_Toggle();
      // Show decimal number whose length is smaller than 4
     showNumberDec(153, false, 3, 1); // 0153
     __delay_ms(TEST_DELAY);
     showNumberDec(22, false, 2, 2);  // 0122
     __delay_ms(TEST_DELAY);
     showNumberDec(0, true, 1, 3);    // 0120
     __delay_ms(TEST_DELAY);
     showNumberDec(0, true, 1, 2);   // 0120
     __delay_ms(TEST_DELAY);
     showNumberDec(0, true, 1, 1);  // 0100
     __delay_ms(TEST_DELAY);
     showNumberDec(0, true, 1, 0);  // 0000
     __delay_ms(TEST_DELAY);
     LED_RA2_Toggle();
     
     // Brightness Test
     for(k = 0; k < 4; k++)
       data[k] = 0xff;
     for(k = 0; k < 7; k++) {
       setBrightness(k, true);
       setSegments(data,4,0); // 8888
       __delay_ms(TEST_DELAY);
     }
      LED_RA2_Toggle();
      
     // On/Off test
     for(k = 0; k < 4; k++) {
       setBrightness(7, false);  // Turn off
       setSegments(data,4,0);
       __delay_ms(TEST_DELAY);
       setBrightness(7, true); // Turn on
       setSegments(data,4,0);
       __delay_ms(TEST_DELAY);  
     }
      LED_RA2_Toggle();
      
     // Show Done!
     setSegments(SEG_DONE,4,0);

     while(1);
       
    }
}

/* ========== End of File =========== */