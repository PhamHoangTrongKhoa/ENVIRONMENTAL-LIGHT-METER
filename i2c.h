/* 
 * File:   i2c.h
 * Author: KhoaPham
 *
 * Created on May 7, 2019, 4:49 PM
 */

#ifndef I2C_H
#define	I2C_H

#define _XTAL_FREQ 10000000

void I2C_Master_Init();
void I2C_Master_Start();
void I2C_Master_Write(unsigned char d);
void I2C_Master_Stop();
unsigned char I2C_Master_Read(unsigned char a);



#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* I2C_H */

