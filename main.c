/* 
 * File:   main.c
 * Author: gvanhoy
 * Description: lab 0.
 * Created on August 27, 2015, 10:14 AM
 */

#include <xc.h>
#include <sys/attribs.h>
#include "timer.h"
#include "led.h"
#include "interrupt.h"
#include "config.h"

#define OUTPUT 0
#define INPUT 1

#define LED1 1
#define LED2 2
#define LED3 3

// DONE - Define states of the state machine 
typedef enum stateTypeEnum{
    LED1ON, LED2ON, LED3ON
} stateType;

// DONE - TODO: Use volatile variables that change within interrupts

volatile stateType LEDSTATE = LED1ON;

int main() {
    SYSTEMConfigPerformance(10000000);    //Configures low-level system parameters for 10 MHz clock
    enableInterrupts();                   //This function is necessary to use interrupts.

    //DONE - TODO: Write each initialization function
    initLEDs();
    initTimer1();
    
    while(1){

        //DONE - TODO: Implement a state machine to create the desired functionality
        switch(LEDSTATE){
            case LED1ON:
                turnOnLED(LED1);
                break;
            case LED2ON:
                turnOnLED(LED2);
                break;
            case LED3ON:
                turnOnLED(LED3);
                break;    
        }
    }
    return 0;
}

//DONE - TODO: Add interrupt service routines that manage the change of states
//for particular events as needed

void __ISR(_TIMER_1_VECTOR, IPL7SRS) _T1Interupt(){
        IFS0bits.T1IF = 0; // put the flag down
        if(LEDSTATE == LED1ON) LEDSTATE = LED2ON;
        if(LEDSTATE == LED2ON) LEDSTATE = LED3ON;
        if(LEDSTATE == LED3ON) LEDSTATE = LED1ON;
}
    