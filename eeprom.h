/********************************************************************
*
*
*
*********************************************************************
* FileName:        eeprom.h
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
*   @file eeprom.h
*   @brief 	This module contains the functions used to write
*               and read glucose readings to the EEPROM. In memory mode
*               these previous readings can then be displayed on the LCD.
*   @defgroup eeprom
*
*/

//*****************************************************************************
// Include and Header files
//*****************************************************************************

#ifndef EEPROM_H
#define	EEPROM_H



void SaveGlucoReading(void);
void ReadSavedGlucoReading(unsigned char reading_count);
void DisplaySavedGlucoReading(void);


#endif	/* EEPROM_H */

