/* 
 * File:   timer.c
 * Author: gvanhoy
 *
 * Created on August 27, 2015, 3:26 PM
 */

#include <xc.h>

#define PRESCALAR_256 3

void initTimer1(){
    //TODO: Initialize Timer 1 to have a period of
    // 1 second. Enable its interrupt
    
    // 5 registers to remember for timers
    
    TMR1 = 0;                           // register that keeps count
    T1CONbits.TCKPS = PRESCALAR_256;        // configure ticking rate (timer 1 configuration)
                                            // prescalar 256 = 3
    PR1 = 39061;      // period register, compare register (divide 10MHz by prescalar, multiply by desired time, subtract 1)
    T1CONbits.ON = 1;           // timer 1 configuration
    IEC0bits.T1IE = 1; // enables interrupt for timer 1
    IPC1bits.T1IP = 7; // timer 1 priority
    IFS0bits.T1IF = 0;  // put down interrupt flag
    
}