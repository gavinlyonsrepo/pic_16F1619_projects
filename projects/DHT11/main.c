/*
* Project Name: DHT11
* File: main.c 
* Description: Display DHT11 on a 4 digit seven segment display
* Author: Gavin Lyons.
* Complier: xc8 v2.05 compiler
* PIC: PIC16F1619 
* IDE:  MPLAB X v5.05
* Development board: Microchip Curiosity Board, PIC16F1619
* Created: March 2019
* URL: https://github.com/gavinlyonsrepo/pic_16F1619_projects
*/

/* ----------- Library ----------*/
#include "mcc_generated_files/mcc.h"

/* ----------- Globals -----------*/
char data[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67}; //Character array nums 1-10
unsigned short Check, Temp, RH, Sum ;

/* Function prototypes */
void sclock(void);
void sclock(void);
void DataDisplay(unsigned int);

void DHT11_Data(void);

char ReadData(void);
void StartSignal(void);
void CheckResponse(void);
void DataParse(void);

/* --------- Main application ----------- */

void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
        // Enable the Global Interrupts
    
    INTERRUPT_GlobalInterruptEnable();
    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();
    
    //Switch on one digit for error hangup on start up
     DataDisplay(data[7]);
     DIGIT1_SetHigh();
     
    while (1)
    {
       if (counter == 1)  // (counter is incremented by timer0 overflow)
         {
          StartSignal(); //send start signal to DHT11 sensor
          CheckResponse(); //get response from DHT11 sensor
          if (Check == 1) // Did DHT11 respond ? 
          {
             DataParse(); 
          }
        }
        DHT11_Data();
    }
}

/* ---------- Function Space ------------*/

/* DHT11: 
 * Parse data from DHT and send to 7-seg display
 */
void DHT11_Data(void)
{
    
    uint8_t  digit4, digit3, digit2 , digit1;
     if (Check == 0) // DHT did not respond if check 0 display zeros.
        {
            digit1 = 8;
            DataDisplay(data[digit1]);
            DIGIT1_SetHigh();
            return;
        }else if (Check == 1) // Good respond, display data
        {
            if (Sum == (RH + Temp))  // is the Checksum OK?
            {
                digit4 = (Temp / 10) % 10;
                digit3 = Temp % 10;
                digit2 = (RH / 10) % 10;
                digit1 = RH % 10;
            }else // bad checksum display all nines.
            {
                digit1 = 9;
                DataDisplay(data[digit1]);
                DIGIT1_SetHigh();
                return;
            }
        }
    
    
     DataDisplay(data[digit1]);
     DIGIT1_SetHigh();
      __delay_ms(1);
     DIGIT1_SetLow();
     
      DataDisplay(data[digit2]);
     DIGIT2_SetHigh();
     __delay_ms(1);
     DIGIT2_SetLow();
     
     DataDisplay(data[digit3]);
     DIGIT3_SetHigh();
     __delay_ms(1);
     DIGIT3_SetLow();
     
      DataDisplay(data[digit4]);
     DIGIT4_SetHigh();
     __delay_ms(1);
     DIGIT4_SetLow();
     
}

/* sclock:
 * This function clock will enable the storage Clock to 74HC595
 */
void sclock(void){
    SLK_595_SetHigh();
    __delay_us(500);
    SLK_595_SetLow();
    __delay_us(500);
}

/* rclock:
 * This function will strobe/latch and enable the output trigger of 74HC595
 */
void rclock(void){
    RLK_595_SetHigh();
    __delay_us(500);
    RLK_595_SetLow() ;
    }

/* DataDisplay:
 * This function will send the data to serial line 74HC9595
 */
void DataDisplay(unsigned int data){
    for (int i=0 ; i<8 ; i++){
        SER_595_LAT = (data >> i) & 0x01; // bit shift and bit mask data. 
        sclock(); //enable data storage clock
    }
    rclock(); // Data latch
}

/* StartSignal Function: 
  sends request 18uS low pulse for data to the sensor*/
void StartSignal(){
    DHT11_PIN_SetDigitalOutput();     //Set TRISIO0 as output
    DHT11_PIN_SetLow(); //GP4 sends 0 to DHT11 (request)
    __delay_ms(18);
    DHT11_PIN_SetHigh();    //GP4 sends 1 DHT 
    __delay_us(30); 
   DHT11_PIN_SetDigitalInput() ;  //Set TRISIO0 as input
  }

/* Check Response function: 
  Check if DHT responded to Start signal 
  40uS low pulse 80uS high pulse*/
 void CheckResponse(){
    Check = 0;
    __delay_us(40); 
    if (DHT11_PIN_PORT == 0){
    __delay_us(80);
    if (DHT11_PIN_PORT == 1)   Check = 1;  __delay_us(40);}
 }
 
 /* ReadData function:
  Read in one byte of data from DHT11 sensor returns byte as char.
  */
 char ReadData(){
    char i, j;
    for(j = 0; j < 8; j++){
       while(!DHT11_PIN_PORT); //Wait until GP4 goes HIGH (50uS)
       __delay_us(30);
       if(DHT11_PIN_PORT == 0)
             i&= ~(1 << (7 - j));  //Its a zero Clear bit 
       else {i|= (1 << (7 - j));  //Its a 1 Set bit 
       while(DHT11_PIN_PORT);}  //Wait until GP4 goes LOW
    }
 
 return i;
}
 
 /* dataParse function: read  the sensor data and put into data.*/
void DataParse()
{
            // Read in the four bytes
            RH = ReadData(); // intergal Humidity byte into RH
            ReadData();   // discard decimal byte
            Temp = ReadData(); //intergal temperature byte into temp
            ReadData();  // discard decimal byte
            Sum = ReadData(); // checksum byte into sum 
}

/*----------------EOF----------------*/
