/********************************************************************
*
*
*
*********************************************************************
* FileName:        eeprom.c
* Dependencies:    See INCLUDES section below
* Processor:       PIC16LF1786
* Compiler:        XC8
* Company:         Microchip Technology, Inc.
*
* Software License Agreement:
*
* The software supplied herewith by Microchip Technology Incorporated
* (the "Company") for its PICmicro? Microcontroller is intended and
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
* File Description: This module contains the functions used to write
*                   and read glucose readings to the EEPROM. In memory mode
*                   these previous readings can then be displayed on the LCD
*
* Change History:
* Author               Date        Comment
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Namrata Dalvi        10/18/2013  First revision of code
********************************************************************/

//*****************************************************************************
// Include and Header files
//*****************************************************************************

/**
*   @file eeprom.c
*   @brief 	This module contains the functions used to write
*               and read glucose readings to the EEPROM. In memory mode
*               these previous readings can then be displayed on the LCD.
*   @defgroup eeprom
*
*/

//*****************************************************************************
// Include and Header files
//*****************************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <xc.h>         /* XC8 General Include File */
#include <htc.h>
#include "user.h"
#include "variables.h"
#include "EEPROM.h"
#include "nokia.h"

/********************************************************************
* Function:             SaveGlucoReading
*
* PreCondition: 	None
*
* Side Effects: 	Write glucose reading to EEPROM
*/
/**
* @ingroup  		EEPROM
*
* @brief    		This function will write glucose reading to EEPROM
*                       along with the date and time stamp
*
* @note
*/
/*******************************************************************/
void SaveGlucoReading(void)
{
    if (gSavedReadingCnt == 32)gSavedReadingCnt = 0;
        EEADRS = gSavedReadingCnt<<3;

    eeprom_write(EEADRS, gSavedReadingCnt);
    eeprom_write(EEADRS+1, gYmmolchar );
    eeprom_write(EEADRS+2, gYmmoldecimalchar);
    eeprom_write(EEADRS+3, Hours );
    eeprom_write(EEADRS+4, Minutes);
    eeprom_write(EEADRS+5, Month);
    eeprom_write(EEADRS+6, Days);
    eeprom_write(EEADRS+7, Year);
    gSavedReadingCnt++;
    NOP();
}

/********************************************************************
* Function:             ReadSavedGlucoReading
*
* PreCondition: 	Previous Glucose reading written to EEPROM
*
* Side Effects: 	Read glucose reading from EEPROM
*/
/**
* @ingroup  		EEPROM
*
* @brief    		This function will read previously stored glucose reading from EEPROM
*
* @note
*/
/*******************************************************************/

void ReadSavedGlucoReading(unsigned char reading_count)
{
    EEADRS = reading_count<<3;
    gReadCount = eeprom_read(EEADRS) ;//0
    EEADRS++;
    gYmmolRead = eeprom_read(EEADRS) ;//1
    EEADRS++;
    gYmmolDecimalRead = eeprom_read(EEADRS) ;//2
    EEADRS++;
    gHoursRead = eeprom_read(EEADRS) ;//3
    EEADRS++;
    gMinutesRead = eeprom_read(EEADRS) ;//4
    EEADRS++;
    gMonthRead = eeprom_read(EEADRS) ;//5
    EEADRS++;
    gDaysRead = eeprom_read(EEADRS) ;//6
    EEADRS++;
    gYearRead = eeprom_read(EEADRS) ;//7

}
/********************************************************************
* Function:             DisplaySavedGlucoReading
*
* PreCondition: 	Read previous stored Glucose reading from EEPROM
*
* Side Effects: 	Display glucose reading on LCD
*/
/**
* @ingroup  		EEPROM
*
* @brief    		This function will display previous saved glucose reading
*                       on the LCD along with the date and time stamp
*
* @note
*/
/*******************************************************************/
void DisplaySavedGlucoReading(void)
{
    float read_mgdl=0;
    int read_mgdl_int = 0;

    read_mgdl = gYmmolRead + (gYmmolDecimalRead/10);
    read_mgdl = read_mgdl*18;
    read_mgdl_int = (int)read_mgdl;

    LCDClear();
//    LCDString("%3dmg/dl%02d/%02d/%02d", read_mgdl_int, gMonthRead, gDaysRead, gYearRead);
    gotoXY(0,1);
//    LCDString(".%d.%dmmol/l %02d:%02d", gYmmolRead, gYmmolDecimalRead, gHoursRead, gMinutesRead);
    NOP();
}