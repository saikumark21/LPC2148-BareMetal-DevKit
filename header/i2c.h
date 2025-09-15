#ifndef I2C_H
#define I2C_H

//Header files
#include"lpc214x.h"
#include"delay.h"
#include"defines.h"

//Pin configuration
#define SDA_PIN     10      // P0.10
#define SCL_PIN     11      // P0.11

//function prototypes
void I2C_Init(void);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_WriteBit(unsigned char bit);
unsigned char I2C_ReadBit(void);
unsigned char I2C_WriteByte(unsigned char byte);
unsigned char I2C_ReadByte(unsigned char ack);

void I2C_Delay(void);
void SDA_High(void);
void SDA_Low(void);
void SDA_Input(void);
unsigned char SDA_Read(void);
void SCL_High(void);
void SCL_Low(void);

#endif