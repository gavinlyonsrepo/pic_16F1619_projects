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

#ifndef __I2C_DRIVER_H
#define __I2C_DRIVER_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#define INLINE  inline 

typedef void (*interruptHandler)(void);

/* arbitration interface */
INLINE void i2c_driver_close(void);

/* Interrupt interfaces */
INLINE void mssp_enableIRQ(void);
INLINE __bit  mssp_IRQisEnabled(void);
INLINE void mssp_disableIRQ(void);
INLINE void mssp_clearIRQ(void);
INLINE void mssp_setIRQ(void);
INLINE __bit  mssp_IRQisSet(void);
INLINE void mssp_waitForEvent(uint16_t*);

/* I2C interfaces */
__bit  i2c_driver_open(void);
INLINE char i2c_driver_getRXData(void);
INLINE char i2c_driver_getAddr(void);
INLINE void i2c_driver_setAddr(char addr);
INLINE void i2c_driver_setMask(char mask);
INLINE void i2c_driver_TXData(char d);
INLINE void i2c_driver_resetBus(void);
INLINE void i2c_driver_start(void);
INLINE void i2c_driver_restart(void);
INLINE void i2c_driver_stop(void);
INLINE __bit  i2c_driver_isNACK(void);
INLINE void i2c_driver_startRX(void);
INLINE void i2c_driver_sendACK(void);
INLINE void i2c_driver_sendNACK(void);
INLINE void i2c_driver_clearBusCollision(void);

__bit  i2c_driver_initSlaveHardware(void);
INLINE void i2c_driver_releaseClock(void);
INLINE __bit  i2c_driver_isBufferFull(void);
INLINE __bit  i2c_driver_isStart(void);
INLINE __bit  i2c_driver_isStop(void);
INLINE __bit  i2c_driver_isAddress(void);
INLINE __bit  i2c_driver_isData(void);
INLINE __bit  i2c_driver_isRead(void);
INLINE __bit  i2c_driver_isWriteCollision(void);
INLINE __bit  i2c_driver_isReceiveOverflow(void);

INLINE void i2c_driver_setBusCollisionISR(interruptHandler handler);
INLINE void i2c_driver_setI2cISR(interruptHandler handler);
void (*i2c_driver_busCollisionISR)(void);
void (*i2c_driver_i2cISR)(void);

#endif // __I2C_DRIVER_H
