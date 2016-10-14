/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using MPLAB(c) Code Configurator

  @Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 3.16
        Device            :  PIC16F1789
        Version           :  1.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.20

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

    Microchip licenses to you the right to use, modify, copy and distribute
    Software only when embedded on a Microchip microcontroller or digital signal
    controller that is integrated into your product or third party product
    (pursuant to the sublicense terms in the accompanying license agreement).

    You should refer to the license agreement accompanying this Software for
    additional information regarding your rights and obligations.

    SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
    EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
    MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
    IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
    CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
    OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
    INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
    CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
    SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
    (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

*/


#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set IO_RA3 aliases
#define IO_RA3_TRIS               TRISA3
#define IO_RA3_LAT                LATA3
#define IO_RA3_PORT               RA3
#define IO_RA3_WPU                WPUA3
#define IO_RA3_ANS                ANSA3
#define IO_RA3_SetHigh()    do { LATA3 = 1; } while(0)
#define IO_RA3_SetLow()   do { LATA3 = 0; } while(0)
#define IO_RA3_Toggle()   do { LATA3 = ~LATA3; } while(0)
#define IO_RA3_GetValue()         PORTAbits.RA3
#define IO_RA3_SetDigitalInput()    do { TRISA3 = 1; } while(0)
#define IO_RA3_SetDigitalOutput()   do { TRISA3 = 0; } while(0)

#define IO_RA3_SetPullup()    do { WPUA3 = 1; } while(0)
#define IO_RA3_ResetPullup()   do { WPUA3 = 0; } while(0)
#define IO_RA3_SetAnalogMode()   do { ANSA3 = 1; } while(0)
#define IO_RA3_SetDigitalMode()   do { ANSA3 = 0; } while(0)


// get/set IO_RA3 aliases
#define IO_RA3_TRIS               TRISA3
#define IO_RA3_LAT                LATA3
#define IO_RA3_PORT               RA3
#define IO_RA3_WPU                WPUA3
#define IO_RA3_ANS                ANSA3
#define IO_RA3_SetHigh()    do { LATA3 = 1; } while(0)
#define IO_RA3_SetLow()   do { LATA3 = 0; } while(0)
#define IO_RA3_Toggle()   do { LATA3 = ~LATA3; } while(0)
#define IO_RA3_GetValue()         PORTAbits.RA3
#define IO_RA3_SetDigitalInput()    do { TRISA3 = 1; } while(0)
#define IO_RA3_SetDigitalOutput()   do { TRISA3 = 0; } while(0)

#define IO_RA3_SetPullup()    do { WPUA3 = 1; } while(0)
#define IO_RA3_ResetPullup()   do { WPUA3 = 0; } while(0)
#define IO_RA3_SetAnalogMode()   do { ANSA3 = 1; } while(0)
#define IO_RA3_SetDigitalMode()   do { ANSA3 = 0; } while(0)


// get/set IO_RB3 aliases
#define IO_RB3_TRIS               TRISB3
#define IO_RB3_LAT                LATB3
#define IO_RB3_PORT               RB3
#define IO_RB3_WPU                WPUB3
#define IO_RB3_ANS                ANSB3
#define IO_RB3_SetHigh()    do { LATB3 = 1; } while(0)
#define IO_RB3_SetLow()   do { LATB3 = 0; } while(0)
#define IO_RB3_Toggle()   do { LATB3 = ~LATB3; } while(0)
#define IO_RB3_GetValue()         PORTBbits.RB3
#define IO_RB3_SetDigitalInput()    do { TRISB3 = 1; } while(0)
#define IO_RB3_SetDigitalOutput()   do { TRISB3 = 0; } while(0)

#define IO_RB3_SetPullup()    do { WPUB3 = 1; } while(0)
#define IO_RB3_ResetPullup()   do { WPUB3 = 0; } while(0)
#define IO_RB3_SetAnalogMode()   do { ANSB3 = 1; } while(0)
#define IO_RB3_SetDigitalMode()   do { ANSB3 = 0; } while(0)


// get/set IO_RB4 aliases
#define IO_RB4_TRIS               TRISB4
#define IO_RB4_LAT                LATB4
#define IO_RB4_PORT               RB4
#define IO_RB4_WPU                WPUB4
#define IO_RB4_ANS                ANSB4
#define IO_RB4_SetHigh()    do { LATB4 = 1; } while(0)
#define IO_RB4_SetLow()   do { LATB4 = 0; } while(0)
#define IO_RB4_Toggle()   do { LATB4 = ~LATB4; } while(0)
#define IO_RB4_GetValue()         PORTBbits.RB4
#define IO_RB4_SetDigitalInput()    do { TRISB4 = 1; } while(0)
#define IO_RB4_SetDigitalOutput()   do { TRISB4 = 0; } while(0)

#define IO_RB4_SetPullup()    do { WPUB4 = 1; } while(0)
#define IO_RB4_ResetPullup()   do { WPUB4 = 0; } while(0)
#define IO_RB4_SetAnalogMode()   do { ANSB4 = 1; } while(0)
#define IO_RB4_SetDigitalMode()   do { ANSB4 = 0; } while(0)


// get/set IO_RB4 aliases
#define IO_RB4_TRIS               TRISB4
#define IO_RB4_LAT                LATB4
#define IO_RB4_PORT               RB4
#define IO_RB4_WPU                WPUB4
#define IO_RB4_ANS                ANSB4
#define IO_RB4_SetHigh()    do { LATB4 = 1; } while(0)
#define IO_RB4_SetLow()   do { LATB4 = 0; } while(0)
#define IO_RB4_Toggle()   do { LATB4 = ~LATB4; } while(0)
#define IO_RB4_GetValue()         PORTBbits.RB4
#define IO_RB4_SetDigitalInput()    do { TRISB4 = 1; } while(0)
#define IO_RB4_SetDigitalOutput()   do { TRISB4 = 0; } while(0)

#define IO_RB4_SetPullup()    do { WPUB4 = 1; } while(0)
#define IO_RB4_ResetPullup()   do { WPUB4 = 0; } while(0)
#define IO_RB4_SetAnalogMode()   do { ANSB4 = 1; } while(0)
#define IO_RB4_SetDigitalMode()   do { ANSB4 = 0; } while(0)


// get/set IO_RB4 aliases
#define IO_RB4_TRIS               TRISB4
#define IO_RB4_LAT                LATB4
#define IO_RB4_PORT               RB4
#define IO_RB4_WPU                WPUB4
#define IO_RB4_ANS                ANSB4
#define IO_RB4_SetHigh()    do { LATB4 = 1; } while(0)
#define IO_RB4_SetLow()   do { LATB4 = 0; } while(0)
#define IO_RB4_Toggle()   do { LATB4 = ~LATB4; } while(0)
#define IO_RB4_GetValue()         PORTBbits.RB4
#define IO_RB4_SetDigitalInput()    do { TRISB4 = 1; } while(0)
#define IO_RB4_SetDigitalOutput()   do { TRISB4 = 0; } while(0)

#define IO_RB4_SetPullup()    do { WPUB4 = 1; } while(0)
#define IO_RB4_ResetPullup()   do { WPUB4 = 0; } while(0)
#define IO_RB4_SetAnalogMode()   do { ANSB4 = 1; } while(0)
#define IO_RB4_SetDigitalMode()   do { ANSB4 = 0; } while(0)


// get/set IO_RD0 aliases
#define IO_RD0_TRIS               TRISD0
#define IO_RD0_LAT                LATD0
#define IO_RD0_PORT               RD0
#define IO_RD0_WPU                WPUD0
#define IO_RD0_ANS                ANSD0
#define IO_RD0_SetHigh()    do { LATD0 = 1; } while(0)
#define IO_RD0_SetLow()   do { LATD0 = 0; } while(0)
#define IO_RD0_Toggle()   do { LATD0 = ~LATD0; } while(0)
#define IO_RD0_GetValue()         PORTDbits.RD0
#define IO_RD0_SetDigitalInput()    do { TRISD0 = 1; } while(0)
#define IO_RD0_SetDigitalOutput()   do { TRISD0 = 0; } while(0)

#define IO_RD0_SetPullup()    do { WPUD0 = 1; } while(0)
#define IO_RD0_ResetPullup()   do { WPUD0 = 0; } while(0)
#define IO_RD0_SetAnalogMode()   do { ANSD0 = 1; } while(0)
#define IO_RD0_SetDigitalMode()   do { ANSD0 = 0; } while(0)


// get/set IO_RD1 aliases
#define IO_RD1_TRIS               TRISD1
#define IO_RD1_LAT                LATD1
#define IO_RD1_PORT               RD1
#define IO_RD1_WPU                WPUD1
#define IO_RD1_ANS                ANSD1
#define IO_RD1_SetHigh()    do { LATD1 = 1; } while(0)
#define IO_RD1_SetLow()   do { LATD1 = 0; } while(0)
#define IO_RD1_Toggle()   do { LATD1 = ~LATD1; } while(0)
#define IO_RD1_GetValue()         PORTDbits.RD1
#define IO_RD1_SetDigitalInput()    do { TRISD1 = 1; } while(0)
#define IO_RD1_SetDigitalOutput()   do { TRISD1 = 0; } while(0)

#define IO_RD1_SetPullup()    do { WPUD1 = 1; } while(0)
#define IO_RD1_ResetPullup()   do { WPUD1 = 0; } while(0)
#define IO_RD1_SetAnalogMode()   do { ANSD1 = 1; } while(0)
#define IO_RD1_SetDigitalMode()   do { ANSD1 = 0; } while(0)


// get/set LCD_ON aliases
#define LCD_ON_TRIS               TRISD2
#define LCD_ON_LAT                LATD2
#define LCD_ON_PORT               RD2
#define LCD_ON_WPU                WPUD2
#define LCD_ON_ANS                ANSD2
#define LCD_ON_SetHigh()    do { LATD2 = 1; } while(0)
#define LCD_ON_SetLow()   do { LATD2 = 0; } while(0)
#define LCD_ON_Toggle()   do { LATD2 = ~LATD2; } while(0)
#define LCD_ON_GetValue()         PORTDbits.RD2
#define LCD_ON_SetDigitalInput()    do { TRISD2 = 1; } while(0)
#define LCD_ON_SetDigitalOutput()   do { TRISD2 = 0; } while(0)

#define LCD_ON_SetPullup()    do { WPUD2 = 1; } while(0)
#define LCD_ON_ResetPullup()   do { WPUD2 = 0; } while(0)
#define LCD_ON_SetAnalogMode()   do { ANSD2 = 1; } while(0)
#define LCD_ON_SetDigitalMode()   do { ANSD2 = 0; } while(0)


// get/set LCD_DC aliases
#define LCD_DC_TRIS               TRISD3
#define LCD_DC_LAT                LATD3
#define LCD_DC_PORT               RD3
#define LCD_DC_WPU                WPUD3
#define LCD_DC_SetHigh()    do { LATD3 = 1; } while(0)
#define LCD_DC_SetLow()   do { LATD3 = 0; } while(0)
#define LCD_DC_Toggle()   do { LATD3 = ~LATD3; } while(0)
#define LCD_DC_GetValue()         PORTDbits.RD3
#define LCD_DC_SetDigitalInput()    do { TRISD3 = 1; } while(0)
#define LCD_DC_SetDigitalOutput()   do { TRISD3 = 0; } while(0)

#define LCD_DC_SetPullup()    do { WPUD3 = 1; } while(0)
#define LCD_DC_ResetPullup()   do { WPUD3 = 0; } while(0)


// get/set LCD_DIN aliases
#define LCD_DIN_TRIS               TRISD4
#define LCD_DIN_LAT                LATD4
#define LCD_DIN_PORT               RD4
#define LCD_DIN_WPU                WPUD4
#define LCD_DIN_SetHigh()    do { LATD4 = 1; } while(0)
#define LCD_DIN_SetLow()   do { LATD4 = 0; } while(0)
#define LCD_DIN_Toggle()   do { LATD4 = ~LATD4; } while(0)
#define LCD_DIN_GetValue()         PORTDbits.RD4
#define LCD_DIN_SetDigitalInput()    do { TRISD4 = 1; } while(0)
#define LCD_DIN_SetDigitalOutput()   do { TRISD4 = 0; } while(0)

#define LCD_DIN_SetPullup()    do { WPUD4 = 1; } while(0)
#define LCD_DIN_ResetPullup()   do { WPUD4 = 0; } while(0)


// get/set ICD_CLK aliases
#define ICD_CLK_TRIS               TRISD5
#define ICD_CLK_LAT                LATD5
#define ICD_CLK_PORT               RD5
#define ICD_CLK_WPU                WPUD5
#define ICD_CLK_SetHigh()    do { LATD5 = 1; } while(0)
#define ICD_CLK_SetLow()   do { LATD5 = 0; } while(0)
#define ICD_CLK_Toggle()   do { LATD5 = ~LATD5; } while(0)
#define ICD_CLK_GetValue()         PORTDbits.RD5
#define ICD_CLK_SetDigitalInput()    do { TRISD5 = 1; } while(0)
#define ICD_CLK_SetDigitalOutput()   do { TRISD5 = 0; } while(0)

#define ICD_CLK_SetPullup()    do { WPUD5 = 1; } while(0)
#define ICD_CLK_ResetPullup()   do { WPUD5 = 0; } while(0)


// get/set LCD_CE aliases
#define LCD_CE_TRIS               TRISD6
#define LCD_CE_LAT                LATD6
#define LCD_CE_PORT               RD6
#define LCD_CE_WPU                WPUD6
#define LCD_CE_SetHigh()    do { LATD6 = 1; } while(0)
#define LCD_CE_SetLow()   do { LATD6 = 0; } while(0)
#define LCD_CE_Toggle()   do { LATD6 = ~LATD6; } while(0)
#define LCD_CE_GetValue()         PORTDbits.RD6
#define LCD_CE_SetDigitalInput()    do { TRISD6 = 1; } while(0)
#define LCD_CE_SetDigitalOutput()   do { TRISD6 = 0; } while(0)

#define LCD_CE_SetPullup()    do { WPUD6 = 1; } while(0)
#define LCD_CE_ResetPullup()   do { WPUD6 = 0; } while(0)


// get/set LCD_RST aliases
#define LCD_RST_TRIS               TRISD7
#define LCD_RST_LAT                LATD7
#define LCD_RST_PORT               RD7
#define LCD_RST_WPU                WPUD7
#define LCD_RST_SetHigh()    do { LATD7 = 1; } while(0)
#define LCD_RST_SetLow()   do { LATD7 = 0; } while(0)
#define LCD_RST_Toggle()   do { LATD7 = ~LATD7; } while(0)
#define LCD_RST_GetValue()         PORTDbits.RD7
#define LCD_RST_SetDigitalInput()    do { TRISD7 = 1; } while(0)
#define LCD_RST_SetDigitalOutput()   do { TRISD7 = 0; } while(0)

#define LCD_RST_SetPullup()    do { WPUD7 = 1; } while(0)
#define LCD_RST_ResetPullup()   do { WPUD7 = 0; } while(0)



/**
 * @Param
    none
 * @Returns
    none
 * @Description
    GPIO and peripheral I/O initialization
 * @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);





#endif // PIN_MANAGER_H
/**
 End of File
*/