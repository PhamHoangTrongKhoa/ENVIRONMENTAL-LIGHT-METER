#include "interrupt.h"
#include <xc.h>
#include <pic18f8722.h>

void init_interrupt(){
    RCONbits.IPEN = 1;  // enable priority
    INTCONbits.GIEH = 1;// high priority
    INTCONbits.GIEL = 1;// low  priority
}
void init_interrupt_int0(){// INT_0 interrupt is only high priority
    TRISBbits.RB0 = 1;//set RB0 being input
    //enable INT_0 interrupt
    INTCONbits.INT0IF = 0;// clear INT_0 flag
    INTCONbits.INT0IE = 1;// enable INT_0 priority
}
void init_interrupt_timer0(){//mode timer
    INTCONbits.TMR0IF = 0;
    INTCONbits.TMR0IE = 1;
    INTCON2bits.TMR0IP = 0; // set low priority for TMR_0
    T0CON = 0x00;
    T0CONbits.T0PS2 = 1;//set buoc dem
    T0CONbits.T0PS1 = 1;
    T0CONbits.T0PS0 = 0;
}
void setup_timer0(){//set up time
    //T0CON = 0x00;
    T0CONbits.TMR0ON = 0;
    TMR0H = 0x67;
    TMR0L = 0x69;
    T0CONbits.TMR0ON = 1;
}
