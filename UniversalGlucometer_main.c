/*
 * File:   UniversalGlucometer_main.c
 * Author: Tom
 * Dependencies:    See INCLUDES section below
 * Processor:       PIC16LF1789
 * Compiler:        XC8
 * Created on October 11, 2016, 9:19 PM
 */

/*Include and Header files*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <xc.h>         /* XC8 General Include File */
#include "user.h"
#include "variables.h"
#include "nokia.h"
#include "EEPROM.h"

/*PIC Configuration - PIC16F1789*/


void main(void) {
  
    HwInit(); //configure oscillator, initialize peripherals 
    LCDInit(); //Initialize the Nokia LCD Display
    LCDClear(); //Clear the Nokia LCD
    gotoXY(0,0); //set cursor on Nokia LCD to upper left corner
    __delay_ms(125);
    gotoXY(10,1); //26
    LCDString("Learn");
    gotoXY(23,2);  
    LCDString("By");
    gotoXY(30,3);  
    LCDString("Making");
    Delay_1_Second();
    LCDClear();
    LCDWrite(0, 0x20); //We must send 0x20 before modifying the display control mode
    LCDWrite(0, 0x0D); //Set display control,0x0C normal mode. 0x0D for inverse
    __delay_ms(500);//Delay_1_Second();
    gotoXY(12,1 );  
    LCDString("UNIVERSAL");
    gotoXY(6,3);  
    LCDString("GLUCOMETER");
    __delay_ms(500);
    LCDClear();    
    LCDWrite(0, 0x20); //We must send 0x20 before modifying the display control mode
    LCDWrite(0, 0x0C); //Set display control,0x0C normal mode. 0x0D for inverse  
    
    return;
}
