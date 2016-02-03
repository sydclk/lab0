/* 
 * File:   led.c
 * Author: gvanhoy
 *
 * Created on August 27, 2015, 3:15 PM
 */

#include <xc.h>
#include "led.h"

#define OUTPUT 0
#define ON 1
#define OFF 0

void initLEDs(){
    
    //TODO: Initialize LEDs DONE
    
    TRISDbits.TRISD0 = OUTPUT; // initialize tri state as output
    TRISDbits.TRISD1 = OUTPUT;
    TRISDbits.TRISD2 = OUTPUT;
    
    LATDbits.LATD0 = ON; // initialize all leds to be on
    LATDbits.LATD1 = ON;
    LATDbits.LATD2 = ON;
    
}

void turnOnLED(int LEDState){
    
    if(LEDState == 1) {
        LATDbits.LATD0 = ON;
        LATDbits.LATD1 = OFF;
        LATDbits.LATD2 = OFF;
    }
    if(LEDState == 2){
        LATDbits.LATD0 = OFF;
        LATDbits.LATD1 = ON;
        LATDbits.LATD2 = OFF;
    }
    if(LEDState == 3){
        LATDbits.LATD0 = OFF;
        LATDbits.LATD1 = OFF;
        LATDbits.LATD2 = ON;
    }
    
}