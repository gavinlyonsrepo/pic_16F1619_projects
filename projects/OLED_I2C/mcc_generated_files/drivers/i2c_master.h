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

#ifndef I2C_MASTER_H
#define	I2C_MASTER_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "i2c_types.h"

// These functions are the I2C API

i2c_error_t i2c_open(i2c_address_t address);
void        i2c_setAddress(i2c_address_t address);
i2c_error_t i2c_close(void);
i2c_error_t i2c_masterOperation(bool read);
i2c_error_t i2c_masterWrite(void); // to be depreciated
i2c_error_t i2c_masterRead(void);  // to be depreciated

void i2c_setTimeOut(uint8_t to);
void i2c_setBuffer(void *buffer, size_t bufferSize);

// Event Callback functions.
void i2c_setDataCompleteCallback(i2c_callback cb, void *p);
void i2c_setWriteCollisionCallback(i2c_callback cb, void *p);
void i2c_setAddressNACKCallback(i2c_callback cb, void *p);
void i2c_setDataNACKCallback(i2c_callback cb, void *p);
void i2c_setTimeOutCallback(i2c_callback cb, void *p);

// Interrupt Stuff : only needed when building the Interrupt driven driver
void i2c_ISR(void);
void i2c_busCollisionISR(void);

#endif	/* I2C_MASTER_H */

