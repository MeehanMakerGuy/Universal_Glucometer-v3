/********************************************************************
* FileName:         user.c
* Dependencies:     See INCLUDES section below
* Processor:        PIC16LF1786
* Compiler:         XC8
* Company:          Microchip Technology, Inc.
*
* Software License Agreement:
*
* The software supplied herewith by Microchip Technology Incorporated
* (the "Company") for its PICmicro® Microcontroller is intended and
* supplied to you, the Company's customer, for use solely and
* exclusively on Microchip PICmicro Microcontroller products. The
* software is owned by the Company and/or its supplier, and is
* protected under applicable copyright laws. All rights are reserved.
* Any use in violation of the foregoing restrictions may subject the
* user to criminal sanctions under applicable laws, as well as to
* civil liability for the breach of the terms and conditions of this
* license.
*
* THIS SOFTWARE IS PROVIDED IN AN "AS IS" CONDITION. NO WARRANTIES,
* WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
* TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
* PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT,
* IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
* CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
*********************************************************************
* File Description: This file contains functions related to initialization
*                   and configuration of the peripherals.
* Change History:
* Author               Date        Version
* Namrata Dalvi        10/18/2013  First version of code
* Tom Meehan           8/02/2016  Re-purposed version for Universal Glucometer 
********************************************************************/

/**
*   @file user.c
*   @brief
*   @defgroup
*
*/
//*****************************************************************************
// Include and Header files
//*****************************************************************************

#include <xc.h>             /* XC8 General Include File */
#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */
#include "user.h"
#include "nokia.h"
#include "variables.h"

#define LCD_BACKLIGHT_ON                    0
#define LCD_BACKLIGHT_OFF                   1
//*****************************************************************************
// SUPPORT FUNCTIONS
//*****************************************************************************
/********************************************************************
* Function:             HwInit
*
* PreCondition: 	None
*
* Side Effects: 	None
*/
/******************************************************************************
* @ingroup  		Main
*
* @brief    		This function configures the clock and initializes the peripherals
*
* @note    		CHECK THIS
*/

void HwInit(void)
{
    /* Configure the oscillator for the device */
    ConfigureOscillator();

    /* Initialize I/O and Peripherals for application */
    InitApp();
    InitTimer1();
    InitADC();
    LCDInit();
    gStripIdleTime = STRIP_IDLE_TIME;
    TEMP_SENSE_VDD = 1;
//    LCD_PWR = LCD_POWER_ON;        // power up the lcd controller
    LATAbits.LATA3 = 0;
    gSavedReadingCnt=0;
    gBloodNotInsetrted=0;
}

/********************************************************************
* Function:             InitApp
*
* PreCondition: 	None
*
* Side Effects: 	None
*/
/**
* @ingroup  		Main
*
* @brief    		This function initializes the peripherals FVR, OPAMP and DAC
*
* @note    		None
*/
/*******************************************************************/
void InitApp(void)
{
    /* FVR CONFIGURATION */
    //FVRCON = 0x88;
    FVRCONbits.FVREN = 1;
    FVRCONbits.CDAFVR = 0b10; //Comparator and DAC Fixed Voltage Reference Peripheral output is 2x (2.048V)
    FVRCONbits.ADFVR = 0b10;// ADC Fixed Voltage Reference Peripheral output is 2x (2.048V)

    // PORT A CONFIGURATION
    ANSELA = 0x3F;
    TRISA = 0x3F;
    ANSELAbits.ANSA3 = 0;
    TRISAbits.TRISA3 = 0;

    // PORT B CONFIGURATION
    TRISB = 0;            //PortB to output? then set individual bits?
    ANSELB = 0;           //Port B pins all set to digital
    TRISBbits.TRISB0 = 1; // PortB bit0 digital input STRIP_SENSE
    TRISBbits.TRISB5 = 1; // PortB bit5 digital input (REF_OUT should be output)
    TEMP_SENSE_VDD = 0;
    TRISBbits.TRISB2 = 1; // PortB bit2 analog input TEMP_OUT
    ANSELBbits.ANSB2 = 1; // PortB bit2 analog input TEMP_OUT
    TRISBbits.TRISB3 = 1; // PortB bit3 digital input SW3
    TRISBbits.TRISB4 = 1; // PortB bit4 digital input SW1
    IOCBNbits.IOCBN4 = 1;
    IOCBFbits.IOCBF4 = 0;
    IOCBNbits.IOCBN3 = 1;
    IOCBFbits.IOCBF3 = 0;
    REF_OUT = 0;

    // PORT C CONFIGURATION
    TRISC = 0;
    //TRISCbits.TRISC7 = 1; //Rx is input

    // OPAMP CONFIGURATION
    OPA1CONbits.OPA1EN = 1;
    OPA1CONbits.OPA1SP = 0;
    OPA1CONbits.OPA1PCH0 = 0b1;// 0b10; // SELECT DAC AS INPUT TO  OPAIN+
    OPA1CONbits.OPA1PCH1 = 0b1;// 0b10; // SELECT DAC AS INPUT TO  OPAIN+

    // DAC CONFIGURATION
    DACCON0bits.DACEN = 1;
    DACCON0bits.DACOE1= 1;
    DACCON0bits.DACNSS = 0;
    DACCON0bits.DACPSS= 0b10;

    OPTION_REGbits.INTEDG = 0;
    OPTION_REGbits.PS = 0b111; // timer 0 prescale = 256

    // Enable interrupts
    INTCONbits.INTF = 0;
    INTCONbits.INTE = 1;
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    PIE1bits.ADIE=1;
    INTCONbits.IOCIF= 0;
    INTCONbits.IOCIE= 1;


    VREGCONbits.VREGPM= 1;

}

/********************************************************************
* Function:             ConfigureOscillator
*
* PreCondition: 	None
*
* Side Effects: 	None
*/
/**
* @ingroup  		Main
*
* @brief    		This function configures the clock for the cpu
*
* @note    		None
*/
/*******************************************************************/
void ConfigureOscillator(void) //****Likely can comment out for now
{
    /* TODO Add clock switching code if appropriate.  */

    /* Typical actions in this function are to tweak the oscillator tuning
    register, select new clock sources, and to wait until new clock sources
    are stable before resuming execution of the main project. */
    OSCCON = 0x68; //8MHz internal osc clk
}

/********************************************************************
* Function:             InitADC
*
* PreCondition: 	None
*
* Side Effects: 	None
*/
/**
* @ingroup  		Main
*
* @brief    		This function initializes the ADC 
*
* @note    		None
*/
/*******************************************************************/

void InitADC(void)
{
    ADCON0 = 	ADCON0_INIT;	// All A/D init values are in user.h
    ADCON1 = 	ADCON1_INIT;
    ADCON2 = 	ADCON2_INIT;
}

/********************************************************************
* Function:             SetTime
*
* PreCondition: 	Switch 3 pressed in the sleep mode
*
* Side Effects: 	None
*/
/**
* @ingroup  		Main
*
* @brief    		This function sets the date and time for RTCC
*
* @note    		None
*/
/*******************************************************************/
void SetTime(void)
{
    unsigned char confirm_count = 0,pre_confirm_count=0;
    unsigned char sw1_count = 0;
    unsigned char set_time_date_loop=1,tMonth=0,tDay=0, tYear=0, tHour=0, tMin=0;
    unsigned char year_1=0,year_2=0,month_1=0, month_2=0,day_1=0,day_2=0,hour_1=0, hour_2=0,min_1=0, min_2=0;
    // Disable interrupts
    INTCONbits.INTF = 0;
    INTCONbits.INTE = 0;
    INTCONbits.GIE = 0;
    INTCONbits.PEIE = 0;
    PIE1bits.ADIE=0;
    INTCONbits.IOCIF= 0;
    INTCONbits.IOCIE= 0;
    PIE1bits.TMR1IE = 0;

    TRISBbits.TRISB3 = 1; // PortB bit3 digital input SW3
    TRISBbits.TRISB4 = 1; // PortB bit4 digital input SW1
    ANSELBbits.ANSB3 = 0; // PortB bit3 digital input SW3
    ANSELBbits.ANSB4 = 0; // PortB bit4 digital input SW1
    LCDInit();
    LCDClear();
    gotoXY(0,0);
    LCDString("SetDate mm/dd/yy");
   // printf("SetDate mm/dd/yy");
    gotoXY(0,1);
    LCDString("Set Time hh:mm");
   // printf("Set Time hh:mm");
    NOP();
    
    while(set_time_date_loop)
    {
        char lcdFormatted = {0};
        if (SW1_pressed())
        {
            sw1_count++;
            LCDClear();
            gotoXY(0,0);
            switch  (confirm_count)
            {
                case 0:// month_1
                    sprintf(AMonth,"month = %02d", sw1_count);
                    LCDString(AMonth);
                    //printf("month = %02d      ", sw1_count);
                    break;
                case 1:// month_2
                    tMonth = (sw1_count *10) + month_1;
                    sprintf(TMonth, "month = %02d", tMonth);
                    LCDString(TMonth);
                    //printf("month = %02d      ", tMonth);
                    break;
                case 2:// day_1
                    sprintf(ADay, "day=%02d", sw1_count);
                    LCDString(ADay);
                    //printf("day=%02d", sw1_count);
                    break;
                case 3:// day_2
                    tDay = (sw1_count *10) + day_1;
                    sprintf(TDay, "day=%02d", tDay);
                    LCDString(TDay);
                    //printf("day=%02d", tDay);
                    break;
                case 4:// year_1
                    sprintf(AYear, "year = %02d", sw1_count);
                    LCDString(AYear);
                    //printf("year = %02d      ", sw1_count);
                    break;
                case 5:// year_2
                    tYear = (sw1_count *10) + year_1;
                    sprintf(TYear, "year = %02d", tYear);
                    LCDString(TYear);
                    //printf("year = %02d      ", tYear);
                    break;
                case 6:// hour_1
                    sprintf(AHour, "hour = %02d", sw1_count);
                    LCDString(AHour);
                    //printf("hour = %02d      ", sw1_count);
                    break;
                case 7:// hour_2
                    tHour= (sw1_count *10) + hour_1;
                    sprintf(THour, "hour = %02d", tHour);
                    LCDString(THour);
                    //printf("hour = %02d      ", tHour);
                    break;
                case 8:// min_1
                    sprintf(AMin, "min=%02d", sw1_count);
                    LCDString(AMin);
                    //printf("min=%02d", sw1_count);
                    break;
                case 9:// min_2
                    tMin = (sw1_count *10) + min_1;
                    sprintf(TMin, "min=%02d", tMin);
                    LCDString(TMin);
                    //printf("min=%02d", tMin);
                    
                    break;
                default:

                    sprintf(Somt, "%02d", 0);
                    LCDString(Somt);
                    //printf("%02d      ", 0);
                    break;
            }
            __delay_ms(100);
            NOP();

        }
        if (SW3_pressed())
        {
            confirm_count++;
            __delay_ms(100);
            NOP();

        }
        if (pre_confirm_count != confirm_count)
        {
            LCDClear();
            gotoXY(0,0);
            switch  (confirm_count)
            {
                case 1:// month_1
                    month_1 = sw1_count;
                    sw1_count = 0;
                    break;
                case 2:// month_0
                    month_2 = sw1_count;
                    Month = (month_2 *10) + month_1;

                    sprintf(AMonth, "..month = %02d", Month);
                    LCDString(AMonth);
                    //printf("..month = %02d", Month);
                    sw1_count = 0;
                    break;
                case 3:// day_1
                    day_1 = sw1_count;
                    sw1_count = 0;
                    break;
                case 4:// day_2
                    day_2 = sw1_count;
                    Days = (day_2 *10) + day_1;
                    sprintf(ADays,"..day = %02d", Days);
                    LCDString(ADays);
                    //printf("..day = %02d", Days);
                    sw1_count = 0;
                    break;
                case 5:// year_1
                    year_1 = sw1_count;
                    sw1_count = 0;
                    break;
                case 6:// year_2
                    year_2 = sw1_count;
                    Year = (year_2 *10) + year_1;

                    sprintf(AYear,"..year = %02d", Year);
                    LCDString(AYear);
                    //printf("..year = %02d", Year);
                    sw1_count = 0;
                case 7:// hour_1
                    hour_1 = sw1_count;
                    sw1_count = 0;
                    break;
                case 8:// hour_2
                    hour_2 = sw1_count;
                    Hours= (hour_2 *10) + hour_1;

                    sprintf(AHours,"..hour = %02d", Hours);
                    LCDString(AHours);
                    //printf("..hour = %02d", Hours);
                    sw1_count = 0;
                    break;
                case 9:// min_1
                    min_1 = sw1_count;
                    sw1_count = 0;
                    break;
                case 10:// min_2
                    min_2 = sw1_count;
                    Minutes = (min_2 *10) + min_1;

                    sprintf(AMinutes,"..min = %02d", Minutes);
                    LCDString(AMinutes);
                    //printf("..min = %02d", Minutes);
                    sw1_count = 0;
                    confirm_count++;
                    break;
                default:
                    sw1_count = 0;
                    confirm_count = 0;
                   // break;
            }
            pre_confirm_count = confirm_count;
            if (confirm_count == 11)
            {
                confirm_count = 0;
                LCDClear();
                gotoXY(0,0);

                sprintf(ATime, "Time= %02d:%02d   ", Hours, Minutes );
                LCDString(ATime);
               // printf(" Time= %02d:%02d   ", Hours, Minutes );
                gotoXY(0,1);

                sprintf(ADate, "Date = %02d/%02d/%02d", Month, Days, Year);
                LCDString(ADate);
               // printf(" Date = %02d/%02d/%02d", Month, Days, Year);
                set_time_date_loop = 0;
                __delay_ms(200);
                __delay_ms(200);
                __delay_ms(200);
                __delay_ms(200);
                __delay_ms(200);
                __delay_ms(200);
                __delay_ms(200);
                __delay_ms(200);

                NOP();

            }
            IOCBFbits.IOCBF3 = 0;
            IOCBFbits.IOCBF4 = 0;
        }
        gcountIdleTime = COUNT_IDLE_TIME;
        gStripIdleTime = STRIP_IDLE_TIME;
        gStripInserted = 0;
        gStripRemoved = 0;
        gBloodNotInsetrted = 0;


    }
    while(!(PORTB & 0x08));
    while(!(PORTB & 0x10));
    NOP();

// Enable interrupts
    INTCONbits.INTF = 0;
    INTCONbits.INTE = 1;
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    PIE1bits.ADIE=1;
    INTCONbits.IOCIF= 0;
    INTCONbits.IOCIE= 1;
    PIE1bits.TMR1IE = 1;
}

/********************************************************************
* Function:             SW1_pressed
*
* PreCondition: 	None
*
* Side Effects: 	None
*/
/**
* @ingroup  		Set time
*
* @brief    		This function detects the switch 1 press
*
* @note    		None
*/
/*******************************************************************/
unsigned char SW1_pressed(void)
{
    unsigned char SW1_press = 1;

    SW1_press = PORTB & 0x10;
    if (SW1_press)
        return 0;
    else
    {

        while(!(PORTB & 0x10));
        IOCBFbits.IOCBF4 = 0;
        return 1;
        
    }
}

/********************************************************************
* Function:             SW3_pressed
*
* PreCondition: 	None
*
* Side Effects: 	None
*/
/**
* @ingroup  		Set time
*
* @brief    		This function detects the switch 3 press
*
* @note    		None
*/
/*******************************************************************/
unsigned char SW3_pressed(void)
{
    unsigned char SW3_press = 1;

    SW3_press = PORTB & 0x08;
    if (SW3_press)
        return 0;
    else
    {
        while(!(PORTB & 0x08));
        IOCBFbits.IOCBF3 = 0;
        return 1;
        
    }
}

/********************************************************************
* Function:             InitTimer1
*
* PreCondition: 	None
*
* Side Effects: 	None
*/
/**
* @ingroup  		Main
*
* @brief    		This function initializes the timer 1 for the RTCC
*
* @note    		None
*/
/*******************************************************************/
void InitTimer1(void)
{
    T1CONbits.TMR1CS = 0b10;
    T1CONbits.T1OSCEN =1;
    T1CONbits.TMR1ON = 1;
    T1CONbits.nT1SYNC = 1;
    PIE1bits.TMR1IE = 1;
}

/********************************************************************
* Function:             Delay_1_Second
*
* PreCondition: 	None
*
* Side Effects: 	None
*/
/**
* @ingroup  		Main
*
* @brief    		This function inserts delay of 1 second
*
* @note    		None
*/
/*******************************************************************/
void Delay_1_Second(void)
{
    __delay_ms(200);
    __delay_ms(200);
    __delay_ms(200);
    __delay_ms(200);
    __delay_ms(200);
}

/********************************************************************
* Function:             putch
*
* PreCondition: 	<stdio.h>
*
* Side Effects: 	None
*/
/**
* @ingroup  		LCD
*
* @brief    		This function is used to enable printf()
*
* @note    		None
*/
/*******************************************************************/
//void putch(char c)
//{
//    lcd_putchar(c);
//}