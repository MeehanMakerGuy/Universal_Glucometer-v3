/******************************************************************************
 *
 * FileName:            Nokia.h
 * Dependencies:        see INCLUDES section 
 * Processor:           PIC16F1786
 * Compiler:            XC8
 * 
 ****************************************************************************** 
 * 
 * File Description:    user.h
 * Change History:
 * Author           Date        Version
 * Tom Meehan       7/24/16     V1.1
 * Adapted from: 
 * http://aranna.altervista.org/dragonsnest/microcontroller-projects/nokia-5110
 * -example-c-source-pic16f/?doing_wp_cron=1469323499.5610311031341552734375
 * 
 ******************************************************************************
 * User Level #define Macros                                                  *
 ******************************************************************************/

/* TODO Application specific user parameters used in user.c may go here       */

/******************************************************************************/
/* User Function Prototypes                                                   */
/******************************************************************************/

/* TODO User level functions prototypes (i.e. InitApp) go here                */

void LCDWrite(char data_or_command, char data);//changed to char from unsigned
void gotoXY(char x, char y);//changed to char from unsigned
//void LCDBitmap(const unsigned char Bender[]);
void LCDCharacter(char character);
void LCDString(char *characters);
void LCDClear(void);
void LCDInit(void) ;

void NokiaInitApp(void);         /* I/O and Peripheral Initialization */
