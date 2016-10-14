/********************************************************************
*
*
*
*********************************************************************
* FileName:         variables.h
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
* File Description: This file contains declaration of the global variables.
* Change History:
* Author               Date        Version
* Namrata Dalvi        10/18/2013  First version of code
* Thomas Meehan        8/02/2016   Major code changes for Universal Glucometer
*                                  Changes to variable assignments, peripherals-
*                                  LCD, added EEPROM chip to hold additional data
*                                  enable storage and use of multiple glucose 
*                                  calculations based on selection of test strip used
*                                  calibrate to strips using standard glucose solutions 
*                                  changes to actions of buttons, additional menus
*                                  ETC....                     
********************************************************************/

/**
*   @file variables.h
*   @brief
*   @defgroup
*
*/
//*****************************************************************************
// Include and Header files
//*****************************************************************************

#ifndef VARIABLES_H  
#define	VARIABLES_H


extern char gglucDataReady, gSleepMode ,  gExitMemoryMode , gMemorymode, gSetDateTime ;
extern char gDisplayPreviousReading , RedingCount, gOneReadingDisplyed  ;
extern unsigned long gcountIdleTime ;
extern unsigned long gStripIdleTime ;
extern unsigned long gtimeOutCount ;
extern int gReadData, gcounter, gcaptured2SValue, gReadTemp;
extern int gGlucoseValue[150], gglucoseIndex;
extern float gXadc, gY, gTemp, gYmmol, gYmmoldecimal;
extern char gYmmolchar, gYmmoldecimalchar;
/*extern char gYmmolchartemp, gYmmoldecimalchartemp;*/
extern int gYint, gYint2, gTempint, gTempint2;
extern unsigned long gSigmaGlucoseValue, gAverageGlucose;
extern char gSenseTestStrip;
extern char gStripRemoved, gStripInserted,gBloodNotInsetrted;
/*extern int gYint, gYint2, gTempint, gTempint2;*/
extern unsigned char gYmmolchar;
extern unsigned char gSavedReadingCnt, EEADRS;

extern char Seconds;
extern char Year, Month, Days, Hours, Minutes;
extern char gReadCount, gYmmolRead,gYmmolDecimalRead;
extern char gYearRead, gMonthRead, gDaysRead, gHoursRead, gMinutesRead;

char ATime[15], bGmgdate[15], ADCval[15], bGmmoltime[15], ATemp[15], AMonth[12];
char TMonth[12], ADay[12], TDay[12], AYear[12], TYear[12], AHour[12], THour[12];
char AMin[12], TMin[12], Somt[6], ADate[12], ADays[12], AHours[12],AMinutes[12];

#define COUNT_RESET   8000
#define COUNT_RESET_1   7992
#define SCALING_FACTOR          0.5                /* Scaling Factor for ADC*/

/*#define SLOPE1                   0.3255           Value of m in y = mx + c, arrived at statistically*/
/*#define GLUCO_OFFSET1            -358.71        */
/*#define SLOPE2                   0.3255          */
/*#define GLUCO_OFFSET2            -358.71         */
#define SLOPE1                   0.362             
#define GLUCO_OFFSET1            -368              
#define SLOPE2                   0.362             
#define GLUCO_OFFSET2            -368              

#define TEMPOFFSET 1000                             /* 0 dec 500 mv 10mv = 20 counts*/
#define TEMPSCALE 0.05
#define STRIP_IDLE_TIME 250000
#define COUNT_IDLE_TIME 120000
#endif	/* VARIABLES_H */

