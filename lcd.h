/* 
 * File:   lcd.h
 * Author: KhoaPham
 *
 * Created on May 6, 2019, 1:11 AM
 */


#ifndef LCD_H
#define	LCD_H

#define _XTAL_FREQ 10000000
#define rs PORTCbits.RC0
#define en PORTCbits.RC1 
void LCD_Init(void);
void LCD_Command(char cmnd);
void LCD_Char(char char_data);
void LCD_String(char* str);
void LCD_String_xy(char row, char pos, char* str);

















/////////////////////////////////////////////////////////////
#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* LCD_H */

