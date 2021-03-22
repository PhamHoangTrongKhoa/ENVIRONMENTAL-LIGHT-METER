/* 
 * File:   interrupt.h
 * Author: KhoaPham
 *
 * Created on May 8, 2019, 10:33 AM
 */

#ifndef INTERRUPT_H
#define	INTERRUPT_H

void init_interrupt();
void init_interrupt_int0();
void init_interrupt_timer0();
void setup_timer0();

/*__interrupt(high_priority) void a(){
    //INTCONbits.INT0IF = 0;
    //PORTD = 0x00;
    return;
}*/
/*__interrupt(low_priority) void b(){
    INTCONbits.TMR0IF = 0;
    PORTD = PORTD + 1;
    setup_timer0();
}*/




#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* INTERRUPT_H */

