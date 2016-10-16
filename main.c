/**
 * Project:  Universal Glucometer
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using MPLAB(c) Code Configurator

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 3.16
        Device            :  PIC16F1789
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.20
*/

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <xc.h>         /* XC8 General Include File */
#include "user.h"
#include "variables.h"
#include "nokia.h"
#include "EEPROM.h"

#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    LCDInit();
    LCDClear();
    gotoXY(0,0);   //upper left corner
    LCDClear();
    __delay_ms(250);
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
    __delay_ms(500);
    gotoXY(20,1);
    LCDString("Insert");
    gotoXY(30,2);
    LCDString("Test");
    gotoXY(25,3);
    LCDString("Strip");    
    __delay_ms(250);
    LCDClear();
    gotoXY(0,1);
    LCDString("Strip Is In");
    gotoXY(0,2);
    LCDString("Place Sample");
    gotoXY(35,3);
    LCDString("~");
    __delay_ms(500);   

    while (1)
    {
        // Add your application code
    }
}
/**
 End of File
*/