#include "lcd.h"
#include <xc.h>
#include <pic18f8722.h>

void LCD_Init(void){
    TRISCbits.RC0 = 0;// rs
    TRISCbits.RC1 = 0;// en
    
    TRISBbits.RB4 = 0;
    TRISBbits.RB5 = 0;
    TRISBbits.RB6 = 0;
    TRISBbits.RB7 = 0;
    
    
    __delay_ms(20);        // LCD Power On initialization time > 15 ms
    LCD_Command(0x02);      // 4 bit mode
    LCD_Command(0x28);      // initiazation of 16x2 LCD in 4 bit mode
    LCD_Command(0x0C);      // display ON Cursor OFF
    LCD_Command(0x06);      // Auto Increment cursor
    LCD_Command(0x01);      // Clear display
    LCD_Command(0x80);      // Cursor at home position
    return;
}

void LCD_Command(char cmnd){
    char LCD_Port = 0;
    PORTBbits.RB7 = cmnd >> 7;
    PORTBbits.RB6 = cmnd >> 6;
    PORTBbits.RB5 = cmnd >> 5;
    PORTBbits.RB4 = cmnd >> 4;
    rs = 0;
    en = 1;
    __delay_ms(1);
    en = 0;
    __delay_ms(2);
    
    PORTBbits.RB7 = cmnd >> 3;
    PORTBbits.RB6 = cmnd >> 2;
    PORTBbits.RB5 = cmnd >> 1;
    PORTBbits.RB4 = cmnd;
    en = 1;
    __delay_ms(1);
    en = 0;
    __delay_ms(5);
           
    return;
}

void LCD_Char (char char_data){
    PORTBbits.RB7 = char_data >> 7;
    PORTBbits.RB6 = char_data >> 6;
    PORTBbits.RB5 = char_data >> 5;
    PORTBbits.RB4 = char_data >> 4;
    rs = 1;
    en = 1;
    __delay_ms(1);
    en = 0;
    __delay_ms(2);
    
    PORTBbits.RB7 = char_data >> 3;
    PORTBbits.RB6 = char_data >> 2;
    PORTBbits.RB5 = char_data >> 1;
    PORTBbits.RB4 = char_data;
    en = 1;
    __delay_ms(1);
    en = 0;
    __delay_ms(5);
           
    return;
}

void LCD_String(char* str){
    int i;
    for (i = 0; str[i] != 0; i++){
        LCD_Char(str[i]);
    }
    
    return;
}

void LCD_String_xy(char row, char pos, char* str){
    if (row == 0){
        LCD_Command((pos & 0x0F)|0x80);
    }else if (row == 1){
        LCD_Command((pos & 0x0F)|0xC0);
    }
    LCD_String(str);
    
    return;
}


