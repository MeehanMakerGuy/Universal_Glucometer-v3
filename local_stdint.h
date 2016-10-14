/********************************************************************
*
*
*
*********************************************************************
* FileName:         local_stdint.h
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
* File Description: This file contains typedef used througout program.
*
* Change History:
* Author               Date        Version
* Chris Tucker        5/2/11         1.1  (Initial Release)
********************************************************************/

/**
*   @file local_stdint.h
*   @brief
*   @defgroup
*
*/

#ifndef __STDINT_H
#define __STDINT_H

//******************************************************/
//		C99 Standard Defines
//******************************************************/
// defines for 8-bit XC8 Compilers
typedef signed char   int8_t;
typedef unsigned char uint8_t;
typedef signed int    int16_t;
typedef unsigned int  uint16_t;
typedef signed long   int32_t;
typedef unsigned long uint32_t;

#endif //__STDINT_H