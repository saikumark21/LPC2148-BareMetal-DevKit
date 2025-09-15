#include"i2c.h"

// functions
void I2C_Delay(void)
{
    delay_us(50);  //Adjust based on timing
}
void SDA_High(void)
{
    SETBIT(IO0SET, SDA_PIN);   // Logic High
}

void SDA_Low(void)
{
    SETBIT(IO0CLR, SDA_PIN);   // Logic Low
}

void SDA_Input(void) 
{
    CLRBIT(IO0DIR, SDA_PIN);   // Input
}

 unsigned char SDA_Read(void) 
{
    return READBIT(IO0PIN, SDA_PIN);
}

void SCL_High(void) 
{
    SETBIT(IO0SET, SCL_PIN);
    I2C_Delay();
}

void SCL_Low(void) 
{
    SETBIT(IO0CLR, SCL_PIN);
    I2C_Delay();
}


//I2C functions
void I2C_Init(void) {
    SETBIT(IO0DIR, SDA_PIN); // Output
    SETBIT(IO0DIR, SCL_PIN); // Output

    SETBIT(IO0SET, SDA_PIN); // High
    SETBIT(IO0SET, SCL_PIN); // High
}

void I2C_Start(void) {
    SDA_High();
    SCL_High();
    I2C_Delay();
    SDA_Low();
    I2C_Delay();
    SCL_Low();
}

void I2C_Stop(void) {
    SDA_Low();
    SCL_High();
    I2C_Delay();
    SDA_High();
    I2C_Delay();
}

void I2C_WriteBit(unsigned char bit) {
    if (bit)
        SDA_High();
    else
        SDA_Low();

    SCL_High();
    SCL_Low();
}

unsigned char I2C_ReadBit(void) {
    unsigned char bit;
    SDA_Input();
    SCL_High();
    bit = SDA_Read();
    SCL_Low();
    return bit;
}

unsigned char I2C_WriteByte(unsigned char byte) {
    for (int i = 0; i < 8; i++) {
        I2C_WriteBit((byte & 0x80) != 0);
        byte <<= 1;
    }
    return I2C_ReadBit(); // Read ACK
}

unsigned char I2C_ReadByte(unsigned char ack) {
    unsigned char byte = 0;
    SDA_Input();

    for (int i = 0; i < 8; i++) {
        byte <<= 1;
        byte |= I2C_ReadBit();
    }

    I2C_WriteBit(ack); // Send ACK or NACK
    return byte;
}