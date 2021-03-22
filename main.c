/*
 * File:   main.c
 * Author: KhoaPham
 *
 * Created on March 6, 2019, 4:44 AM
 */

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include <pic18f8722.h>
#include "config.h"
#include "lcd.h"
#include "i2c.h"
#include "interrupt.h"

typedef struct {
    unsigned char highbyte;
    unsigned char lowbyte;
} byteRead;

byteRead readByte(void);
void printValue(byteRead lux);

__interrupt(low_priority) void timer_interrupt(){
    INTCONbits.TMR0IF = 0;
    byteRead lux;
    lux = readByte();
    //LCD_Command(0x01);
    printValue(lux);
    setup_timer0();
}



void main(void) {
    /////////////////////////////////////////////////
    //                  init_I2C
    ////////////////////////////////////////////////////
    I2C_Master_Init();
    LCD_Init();
    LCD_String("Light intensity");
    
    init_interrupt();
    init_interrupt_timer0();
    setup_timer0();
    
    while(1);
    return;
}


////////////////////////////////////////////
byteRead readByte(void){
    byteRead byte;
    I2C_Master_Start();
    I2C_Master_Write(0x46);//byte control write bh1750
    I2C_Master_Write(0x10);//chon mode - truyen data 
    I2C_Master_Stop();
    __delay_ms(180);
    I2C_Master_Start();
    I2C_Master_Write(0x47);//byte control read bh1750
    byte.highbyte = I2C_Master_Read(1);
    byte.lowbyte = I2C_Master_Read(0);
    I2C_Master_Stop();
    return byte;
}

void printValue(byteRead lux){
    long int value = 0;
    char str[6] = {'0','0','0','0','0'};
    value = (long int)(lux.highbyte)*256;
    value = (long int)(lux.lowbyte) + value;
    value = value /1.2;
    int i = 4;
    for (;value > 0; ){
        int number = value%10;
        value = value/10;
        str[i] = number + str[i];
        i--;
    }
    
    //LCD_Init();
    LCD_String_xy(1,7,str);
    LCD_String(" LUX");
    return;
}






