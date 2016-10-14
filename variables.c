/********************************************************************
*
*
*
*********************************************************************
* FileName:         variables.c
* Dependencies:     See INCLUDES section below
* Processor:        PIC16LF1786
* Compiler:         XC8
* Company:          Microchip Technology, Inc.
* Tom Meehan           8/02/2016  Re-purposed version for Universal Glucometer
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
* Tom Meehan           8/02/2016  Re-purposed version for Universal Glucometer
********************************************************************/

/**
*   @file variables.c
*   @brief
*   @defgroup
*
*/
//*****************************************************************************
// Include and Header files
/* 
 */
#include "variables.h"

char gglucDataReady = 0, gSleepMode = 0,  gExitMemoryMode = 0, gMemorymode=0, gSetDateTime = 0;
char gDisplayPreviousReading = 0, RedingCount=0,gOneReadingDisplyed = 0;
unsigned long gcountIdleTime = COUNT_IDLE_TIME;
unsigned long gStripIdleTime = STRIP_IDLE_TIME;
unsigned long gtimeOutCount = 100000;

int gReadData=0,gcounter = COUNT_RESET,gcaptured2SValue=0,gReadTemp=0;
int gGlucoseValue[150], gglucoseIndex=0;
float gXadc=0, gY=0,gTemp=0, gYmmol=0, gYmmoldecimal=0;
char gYmmolchar=7, gYmmoldecimalchar=6;
int gYint=50, gYint2=0, gTempint=0, gTempint2=0;
unsigned long gSigmaGlucoseValue=0,gAverageGlucose=0;
char gSenseTestStrip=0;
char gStripRemoved = 0, gStripInserted = 0, gBloodNotInsetrted=0;
unsigned char gSavedReadingCnt=0, EEADRS=0;
char Seconds=0;
char Year=13, Month=1, Days=1, Hours=10, Minutes=10;
char gReadCount=0, gYmmolRead=0,gYmmolDecimalRead=0;
char gYearRead=0, gMonthRead=0, gDaysRead=0, gHoursRead=0, gMinutesRead=0;

char lcdFormatted[20];