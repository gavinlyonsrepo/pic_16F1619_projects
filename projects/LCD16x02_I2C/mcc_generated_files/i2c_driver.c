/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/


#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "mcc.h"
#include "i2c_driver.h"

#pragma warning disable 520        

inline void i2c_driver_close(void)
{
    SSP1CON1bits.SSPEN = 0;
}

/* Interrupt Control */
inline void mssp_enableIRQ(void)
{
    PIE1bits.SSP1IE = 1;
}

inline __bit mssp_IRQisEnabled(void)
{
    return PIE1bits.SSP1IE;
}

inline void mssp_disableIRQ(void)
{
    PIE1bits.SSP1IE = 0;
}

inline void mssp_clearIRQ(void)
{
    PIR1bits.SSP1IF = 0;
}

inline void mssp_setIRQ(void)
{
    PIR1bits.SSP1IF = 1;
}

inline __bit mssp_IRQisSet(void)
{
    return PIR1bits.SSP1IF;
}

inline void mssp_waitForEvent(uint16_t *timeout)
{
    //uint16_t to = (timeout!=NULL)?*timeout:100;
    //to <<= 8;

    if(PIR1bits.SSP1IF == 0)
    {
        while(1)// to--)
        {
            if(PIR1bits.SSP1IF) break;
            __delay_us(100);
        }
    }
}

__bit i2c_driver_open(void)
{
    if(!SSP1CON1bits.SSPEN)
    {
        SSP1STAT = 0x00;
        SSP1CON1 = 0x28;
        SSP1CON2 = 0x00;
        SSP1ADD = 0x9;
        return true;
    }
    else
        return false;
}

__bit i2c_driver_initSlaveHardware(void)
{
    if(!SSP1CON1bits.SSPEN)
    {
/* NOTE on AHEN:
 * If multiple slaves are to be emulated, then AHEN must be set.  It must be set
 * because the driver needs to selectively ACK/NACK the address depending on its
 * ability to handle the address.
*/

/* NOTE on DHEN:
 * DHEN must be set so that the data is not automatically NACK'ed if it is not read
 * from the SSPBUF.  This driver will ALWAYS read the SSPBUF so that it can pass
 * the value to the appropriate slave handler.  Because the data is ALWAYS read
 * the data will always be ACK'd if DHEN is cleared.  If the slave does not want
 * the data byte from the master then it will return false and a NACK will be returned.
 */

/* NOTE on SEN:
 * SEN will be set enabling clock stretching.  This is because we don't know how
 * long the user will take to process data bytes in their callbacks.  If they are fast,
 * we may not need to stretch the clock.  If they are slow, we need to stretch the clock.
 * If we ALWAYS stretch the clock, we will release the clock when the ISR is complete.
 */

/* NOTE on PCIE:
 * PCIE will be set to enable interrupts on STOP.  This will allow us know when
 * the master is finished
 */
        
/* NOTE on SCIE:
 * SCIE will be set to enable interrupts on START.  This will allow us to detect
 * both a START and a RESTART event and prepare to restart communications.
 */
        SSP1CON1 |= 0x06; //setup I2C Slave (7-bit Addressing)
        SSP1STAT = 0x00;
        SSP1CON2 = 0x00;
        
        SSP1CON1bits.SSPEN = 1;
        return true;
    }
    return false;
}

inline void i2c_driver_resetBus(void)
{
    
}

inline void i2c_driver_start(void)
{
    SSP1CON2bits.SEN = 1;
}

inline void i2c_driver_restart(void)
{
    SSP1CON2bits.RSEN = 1;
}

inline void i2c_driver_stop(void)
{
    SSP1CON2bits.PEN = 1;
}

inline __bit i2c_driver_isNACK(void)
{
    return SSP1CON2bits.ACKSTAT;
}

inline void i2c_driver_startRX(void)
{
    SSP1CON2bits.RCEN = 1;
}

inline char i2c_driver_getRXData(void)
{
    return SSP1BUF;
}

inline void i2c_driver_setAddr(char addr)
{
    SSP1ADD = addr;
}

inline void i2c_driver_setMask(char mask)
{
    SSP1MSK = mask;
}

inline void i2c_driver_TXData(char d)
{
    SSP1BUF = d;
}

inline char i2c_driver_getAddr(void)
{
    return SSP1ADD;
}

inline void i2c_driver_sendACK(void)
{
    SSP1CON2bits.ACKDT = 0;
    SSP1CON2bits.ACKEN = 1; // start the ACK/NACK
}

inline void i2c_driver_sendNACK(void)
{
    SSP1CON2bits.ACKDT = 1;
    SSP1CON2bits.ACKEN = 1; // start the ACK/NACK
}

inline void i2c_driver_releaseClock(void)
{
    SSP1CON1bits.CKP = 1;
}

inline __bit i2c_driver_isBufferFull(void)
{
    return SSP1STATbits.BF;
}

inline __bit i2c_driver_isStart(void)
{
    return SSP1STATbits.S;
}

inline __bit i2c_driver_isAddress(void)
{
    return !SSP1STATbits.D_nA;
}

inline __bit i2c_driver_isStop(void)
{
    return SSP1STATbits.P;
}

inline __bit i2c_driver_isData(void)
{
    return SSP1STATbits.D_nA;
}

inline __bit i2c_driver_isRead(void)
{
    return SSP1STATbits.R_nW;
}

inline __bit i2c_driver_isWriteCollision(void)
{
    return SSP1CON1bits.WCOL;
}

inline __bit i2c_driver_isReceiveOverflow(void)
{
    return SSP1CON1bits.SSPOV;
}

inline void i2c_driver_clearBusCollision(void)
{
    PIR2bits.BCL1IF = 0; // clear the bus collision.
}

inline void i2c_driver_setBusCollisionISR(interruptHandler handler){
    i2c_driver_busCollisionISR = handler;
}

inline void i2c_driver_setI2cISR(interruptHandler handler){
    i2c_driver_i2cISR = handler;
}
