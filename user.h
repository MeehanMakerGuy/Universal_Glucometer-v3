/********************************************************************
*
*
*
*********************************************************************
* FileName:         user.h
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
********************************************************************/

/**
*   @file user.h
*   @brief
*   @defgroup
*
*/
//*****************************************************************************
// Include and Header files
//*****************************************************************************
#include <xc.h>
#include <stdio.h>
#include <stdarg.h>


#ifndef USER_H 
#define	USER_H

#ifndef _XTAL_FREQ  //currently using 8Mhz int osc
#define _XTAL_FREQ 8000000 //8Mhz  internal osc
#endif

#define	ANSEL_LCD_CS ANSA7 //****CHECK THIS****
#define	TEMP_SENSE_VDD LATB1 //pin22 to Vcc of MCP9700 temperature sensor
#define	REF_OUT LATB5 //reference voltage out pin26 to strip connector
#define	ADCON0_INIT 0x01 //0b00000001	// A/D enabled,
#define	ADCON1_INIT 0xA3 //0b10100011	// 2's complement, Fosc/32, VREF+ is connected internally to FVR Buffer 1, VREF- is connected to VSS
#define ADCON2_INIT 0x0F //0b00001111	// ADC Negative reference - selected by ADNREF.
#define CAPTURE_START_VOLTAGE 900       // 450 mV
#define FAULTY_STRIP_VOLTAGE 920        // 470 mV
#define GLUCO_READ_COUNT 4096
#define DAC400MVCOUNT 50
#define POLYFITBOUNDRY 1400
#define STRIP_INSERTED 0x00  //0
#define STRIP_NOT_INSERTED 0x01  //1
#define TRUE 1 //boolean definition
#define FALSE 0 //boolean definition
#define TIMEOUT_COUNT 60000

void HwInit(void); // clock and hardware initialization
void ConfigureOscillator(void); /* Handles clock switching/osc initialization - currently non functional*/
void InitApp(void);         /* I/O and Peripheral Initialization */
void SenseTestStrip(void);
void InitADC(void);
void InitTimer1(void);
void CalcGlucose(void);
void EnterDeepSleep(void);
void SetTime(void);
unsigned char SW1_pressed(void);
//SW2_NO connects Vpp to GND when closed
unsigned char SW3_pressed(void);
void Delay_1_Second(void);

////////////////////////////////////////////////////////////////////////////////
// Test whether a given year is a leap year.
// This optimized version only works for the period 1901 - 2099
//??keep or comment out for now??
////////////////////////////////////////////////////////////////////////////////
#define Is_Leap(year) (year%4 == 0)

#define	Ad_Set_Chan(x)	{ ADCON0 = ADCON0_INIT | (x << 2); }
			// for low conversion values, A2D result may be negative, sign-extended
#define	Ad_Convert()	{ GO_nDONE = 1; while(GO_nDONE); if(ADRESH > 127){ADRESH = 0;ADRESL = 0;}}


#endif	/* USER_H */

