#include "i2c.h"
#include <xc.h>
#include <pic18f8722.h>

void I2C_Master_Init(){
    TRISCbits.RC5 = 0;
    PORTCbits.RC5 = 0;
    TRISCbits.RC3 = 1;
    TRISCbits.RC4 = 1;
    SSPSTAT = 0x3f;//0X80;// configure 0011 1111
    SSPCON2 = 0X00;
    SSPCON1 = 0X18;//I2C master mode
    SSPADD = 24;//fsl = 100khz
    PIR1bits.SSPIF = 0;
    SSPCON1bits.SSPEN = 1;//access to I2C interface
    return;
}

void I2C_Master_Wait(){
    while(PIR1bits.SSPIF != 1);
    PIR1bits.SSPIF = 0;
    return;
}

void I2C_Master_Start(){
    SSPCON2bits.SEN = 1;
    I2C_Master_Wait();  
    return;
}

void I2C_Master_Write(unsigned char d){
    SSPBUF = d;
    while(SSPSTATbits.BF == 1);
    while(SSPCON2bits.ACKSTAT == 1);
    I2C_Master_Wait();  
    return;
}

void I2C_Master_Stop(){
    SSPCON2bits.PEN = 1;
    I2C_Master_Wait();
    return;
}

unsigned char I2C_Master_Read(unsigned char a){
    unsigned char  temp;
    SSPCON2bits.RCEN = 1;
    I2C_Master_Wait();
    WREG = 0X00;
    SSPCON2bits.ACKDT = (a)?0:1;
    SSPCON2bits.ACKEN = 1;
    I2C_Master_Wait();
    temp = SSPBUF;
    return temp;
}

///////////////////////
void I2C_Master_Restart(){
    SSPCON2bits.RSEN = 1;
    I2C_Master_Wait();
    return;
}