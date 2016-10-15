/******************************************************************************
 *
 * FileName:            Nokia.c
 * Dependencies:        see INCLUDES section 
 * Processor:           PIC16F1786
 * Compiler:            XC8
 * 
 ****************************************************************************** 
 *  
 * File Description:    user.c
 * Change History:
 * Author           Date        Version
 * Tom Meehan       7/24/16     V1.1
 * Adapted from: 
 * http://aranna.altervista.org/dragonsnest/microcontroller-projects/nokia-5110
 * -example-c-source-pic16f/?doing_wp_cron=1469323499.5610311031341552734375
 * 
 * ****************************************************************************
 * 
 * Include and Header files   
 *                                                         
 ******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#include <xc.h>           /* XC8 General Include File */

#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */

#include "nokia.h"

/******************************************************************************/
/* User Defines                                                               */
/******************************************************************************/
//                  Connections from PIC to LCD and LCD to Power
//                                 LCD GND              Pin 8 on Nokia 5110
//                                 LCD Backlight-GND    Pin 7 
//                                 LCD V+ 3.3           Pin 6
#define LCD_CLK LATDbits.LATD5  /*Pin 16 on PIC16F1786  Pin 5*/
#define LCD_DIN LATDbits.LATD4  /*Pin 15                Pin 4*/
#define LCD_DC  LATDbits.LATD3  /*Pin 14                Pin 3*/
#define LCD_CE  LATDbits.LATD6  /*Pin 17                Pin 2*/
#define LCD_RST LATDbits.LATD7  /*Pin 18                Pin 1*/
/*The DC pin tells the LCD if we are sending a COMMAND or DATA*/
#define LCD_COMMAND 0   /*Logic Low sent to DC to indicate sending COMMAND*/
#define LCD_DATA  1     /*Logic High sent to DC to indicate sending DATA*/

//#define _INTOSC 800000 /*Internal Oscillator set to 8MHz*/
/*Even though using Internal Oscillator had to set XTAL Frequency*/
#define _XTAL_FREQ 800000 /* to enable __delay_ms() to work*/

/*You may find a different size screen, Nokia 5110 is 84 by 48 pixels*/
#define LCD_X     84
#define LCD_Y     48

/* <Initialize variables in user.h and insert code for user algorithms.> */

/*5 x 8bit columns encoding 5 columns of 8 pixels LSBL? I think*/
const unsigned char ASCII[][5] = {
  {0x00, 0x00, 0x00, 0x00, 0x00}  // 20
  ,{0x00, 0x00, 0x5f, 0x00, 0x00} // 21 !
  ,{0x00, 0x07, 0x00, 0x07, 0x00} // 22 "
  ,{0x14, 0x7f, 0x14, 0x7f, 0x14} // 23 #
  ,{0x24, 0x2a, 0x7f, 0x2a, 0x12} // 24 $
  ,{0x23, 0x13, 0x08, 0x64, 0x62} // 25 %
  ,{0x36, 0x49, 0x55, 0x22, 0x50} // 26 &
  ,{0x00, 0x05, 0x03, 0x00, 0x00} // 27 '
  ,{0x00, 0x1c, 0x22, 0x41, 0x00} // 28 (
  ,{0x00, 0x41, 0x22, 0x1c, 0x00} // 29 )
  ,{0x14, 0x08, 0x3e, 0x08, 0x14} // 2a *
  ,{0x08, 0x08, 0x3e, 0x08, 0x08} // 2b +
  ,{0x00, 0x50, 0x30, 0x00, 0x00} // 2c ,
  ,{0x08, 0x08, 0x08, 0x08, 0x08} // 2d -
  ,{0x00, 0x60, 0x60, 0x00, 0x00} // 2e .
  ,{0x20, 0x10, 0x08, 0x04, 0x02} // 2f /
  ,{0x3e, 0x51, 0x49, 0x45, 0x3e} // 30 0
  ,{0x00, 0x42, 0x7f, 0x40, 0x00} // 31 1
  ,{0x42, 0x61, 0x51, 0x49, 0x46} // 32 2
  ,{0x21, 0x41, 0x45, 0x4b, 0x31} // 33 3
  ,{0x18, 0x14, 0x12, 0x7f, 0x10} // 34 4
  ,{0x27, 0x45, 0x45, 0x45, 0x39} // 35 5
  ,{0x3c, 0x4a, 0x49, 0x49, 0x30} // 36 6
  ,{0x01, 0x71, 0x09, 0x05, 0x03} // 37 7
  ,{0x36, 0x49, 0x49, 0x49, 0x36} // 38 8
  ,{0x06, 0x49, 0x49, 0x29, 0x1e} // 39 9
  ,{0x00, 0x36, 0x36, 0x00, 0x00} // 3a :
  ,{0x00, 0x56, 0x36, 0x00, 0x00} // 3b ;
  ,{0x08, 0x14, 0x22, 0x41, 0x00} // 3c <
  ,{0x14, 0x14, 0x14, 0x14, 0x14} // 3d =
  ,{0x00, 0x41, 0x22, 0x14, 0x08} // 3e >
  ,{0x02, 0x01, 0x51, 0x09, 0x06} // 3f ?
  ,{0x32, 0x49, 0x79, 0x41, 0x3e} // 40 @
  ,{0x7e, 0x11, 0x11, 0x11, 0x7e} // 41 A
  ,{0x7f, 0x49, 0x49, 0x49, 0x36} // 42 B
  ,{0x3e, 0x41, 0x41, 0x41, 0x22} // 43 C
  ,{0x7f, 0x41, 0x41, 0x22, 0x1c} // 44 D
  ,{0x7f, 0x49, 0x49, 0x49, 0x41} // 45 E
  ,{0x7f, 0x09, 0x09, 0x09, 0x01} // 46 F
  ,{0x3e, 0x41, 0x49, 0x49, 0x7a} // 47 G
  ,{0x7f, 0x08, 0x08, 0x08, 0x7f} // 48 H
  ,{0x00, 0x41, 0x7f, 0x41, 0x00} // 49 I
  ,{0x20, 0x40, 0x41, 0x3f, 0x01} // 4a J
  ,{0x7f, 0x08, 0x14, 0x22, 0x41} // 4b K
  ,{0x7f, 0x40, 0x40, 0x40, 0x40} // 4c L
  ,{0x7f, 0x02, 0x0c, 0x02, 0x7f} // 4d M
  ,{0x7f, 0x04, 0x08, 0x10, 0x7f} // 4e N
  ,{0x3e, 0x41, 0x41, 0x41, 0x3e} // 4f O
  ,{0x7f, 0x09, 0x09, 0x09, 0x06} // 50 P
  ,{0x3e, 0x41, 0x51, 0x21, 0x5e} // 51 Q
  ,{0x7f, 0x09, 0x19, 0x29, 0x46} // 52 R
  ,{0x46, 0x49, 0x49, 0x49, 0x31} // 53 S
  ,{0x01, 0x01, 0x7f, 0x01, 0x01} // 54 T
  ,{0x3f, 0x40, 0x40, 0x40, 0x3f} // 55 U
  ,{0x1f, 0x20, 0x40, 0x20, 0x1f} // 56 V
  ,{0x3f, 0x40, 0x38, 0x40, 0x3f} // 57 W
  ,{0x63, 0x14, 0x08, 0x14, 0x63} // 58 X
  ,{0x07, 0x08, 0x70, 0x08, 0x07} // 59 Y
  ,{0x61, 0x51, 0x49, 0x45, 0x43} // 5a Z
  ,{0x00, 0x7f, 0x41, 0x41, 0x00} // 5b [
  ,{0x02, 0x04, 0x08, 0x10, 0x20} // 5c "\" need quotes or it skips next line seeing it as a comment
  ,{0x00, 0x41, 0x41, 0x7f, 0x00} // 5d ]
  ,{0x04, 0x02, 0x01, 0x02, 0x04} // 5e ^
  ,{0x40, 0x40, 0x40, 0x40, 0x40} // 5f _
  ,{0x00, 0x01, 0x02, 0x04, 0x00} // 60 `
  ,{0x20, 0x54, 0x54, 0x54, 0x78} // 61 a 
  ,{0x7f, 0x48, 0x44, 0x44, 0x38} // 62 b
  ,{0x38, 0x44, 0x44, 0x44, 0x20} // 63 c
  ,{0x38, 0x44, 0x44, 0x48, 0x7f} // 64 d
  ,{0x38, 0x54, 0x54, 0x54, 0x18} // 65 e
  ,{0x08, 0x7e, 0x09, 0x01, 0x02} // 66 f
  ,{0x0c, 0x52, 0x52, 0x52, 0x3e} // 67 g
  ,{0x7f, 0x08, 0x04, 0x04, 0x78} // 68 h
  ,{0x00, 0x44, 0x7d, 0x40, 0x00} // 69 i
  ,{0x20, 0x40, 0x44, 0x3d, 0x00} // 6a j
  ,{0x7f, 0x10, 0x28, 0x44, 0x00} // 6b k
  ,{0x00, 0x41, 0x7f, 0x40, 0x00} // 6c l
  ,{0x7c, 0x04, 0x18, 0x04, 0x78} // 6d m
  ,{0x7c, 0x08, 0x04, 0x04, 0x78} // 6e n
  ,{0x38, 0x44, 0x44, 0x44, 0x38} // 6f o
  ,{0x7c, 0x14, 0x14, 0x14, 0x08} // 70 p
  ,{0x08, 0x14, 0x14, 0x18, 0x7c} // 71 q
  ,{0x7c, 0x08, 0x04, 0x04, 0x08} // 72 r
  ,{0x48, 0x54, 0x54, 0x54, 0x20} // 73 s
  ,{0x04, 0x3f, 0x44, 0x40, 0x20} // 74 t
  ,{0x3c, 0x40, 0x40, 0x20, 0x7c} // 75 u
  ,{0x1c, 0x20, 0x40, 0x20, 0x1c} // 76 v
  ,{0x3c, 0x40, 0x30, 0x40, 0x3c} // 77 w
  ,{0x44, 0x28, 0x10, 0x28, 0x44} // 78 x
  ,{0x0c, 0x50, 0x50, 0x50, 0x3c} // 79 y
  ,{0x44, 0x64, 0x54, 0x4c, 0x44} // 7a z
  ,{0x00, 0x08, 0x36, 0x41, 0x00} // 7b {
  ,{0x00, 0x00, 0x7f, 0x00, 0x00} // 7c |
  ,{0x00, 0x41, 0x36, 0x08, 0x00} // 7d }
  ,{0X30, 0X7c, 0x7f, 0x7c, 0x30} //{0x10, 0x08, 0x08, 0x10, 0x08} // 7e ~ changed to blood drop
  ,{0x78, 0x46, 0x41, 0x46, 0x78} // 7f DEL
}; 

//larger number font 10 bit by 12 bit column by row - good for bG display
const unsigned char LARGEnum[][10] = {
        0xC0, 0x01, 0xC0, 0x01, 0xC0, 0x01, 0xC0, 0x01, 0xC0, 0x01, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char -
        0x00, 0x00, 0x00, 0x0E, 0x00, 0x0E, 0x00, 0x0E, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char .
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char <sp>
        0x00, 0x00, 0xFC, 0x03, 0xFE, 0x07, 0xFF, 0x0F, 0x03, 0x0C, 
        0x03, 0x0C, 0xFF, 0x0F, 0xFE, 0x07, 0xFC, 0x03, 0x00, 0x00,  // Code for char 0
        0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x38, 0x00, 0x1C, 0x00, 
        0xFF, 0x0F, 0xFF, 0x0F, 0xFF, 0x0F, 0x00, 0x00, 0x00, 0x00,  // Code for char 1
        0x00, 0x00, 0x0C, 0x0C, 0x0E, 0x0E, 0x0F, 0x0F, 0x83, 0x0F, 
        0xC3, 0x0D, 0xFF, 0x0C, 0x7E, 0x0C, 0x3C, 0x0C, 0x00, 0x00,  // Code for char 2
        0x00, 0x00, 0x04, 0x03, 0x0E, 0x07, 0x0F, 0x0F, 0x63, 0x0C, 
        0x63, 0x0C, 0xFF, 0x0F, 0xFE, 0x07, 0x9C, 0x03, 0x00, 0x00,  // Code for char 3
        0x00, 0x00, 0xC0, 0x01, 0xE0, 0x01, 0xF8, 0x01, 0x9C, 0x01, 
        0x8E, 0x01, 0xFF, 0x0F, 0xFF, 0x0F, 0xFF, 0x0F, 0x80, 0x01,  // Code for char 4
        0x00, 0x00, 0x78, 0x03, 0x7F, 0x07, 0x7F, 0x0F, 0x33, 0x0C, 
        0x33, 0x0C, 0xF3, 0x0F, 0xE3, 0x07, 0xC3, 0x03, 0x00, 0x00,  // Code for char 5
        0x00, 0x00, 0xF8, 0x01, 0xFE, 0x07, 0xFF, 0x0F, 0x23, 0x0C, 
        0x33, 0x0C, 0xF7, 0x0F, 0xE7, 0x07, 0xC6, 0x03, 0x00, 0x00,  // Code for char 6
        0x00, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x0E, 0xC3, 0x0F, 
        0xF3, 0x0F, 0xFB, 0x00, 0x0F, 0x00, 0x03, 0x00, 0x00, 0x00,  // Code for char 7
        0x00, 0x00, 0x9C, 0x03, 0xFE, 0x07, 0xFF, 0x0F, 0x63, 0x0C, 
        0x63, 0x0C, 0xFF, 0x0F, 0xFE, 0x07, 0x9C, 0x03, 0x00, 0x00,  // Code for char 8
        0x00, 0x00, 0x3C, 0x06, 0x7E, 0x0E, 0xFF, 0x0E, 0xC3, 0x0C, 
        0x43, 0x0C, 0xFF, 0x0F, 0xFE, 0x07, 0xF8, 0x01, 0x00, 0x00   // Code for char 9
        };


void gotoXY(unsigned char x, unsigned char y) { //moves cursor to x,y position 00-54, 00-30 - need 8 bit int
  LCDWrite(0, 0x80 | x);  // 0b10000000 column
  LCDWrite(0, 0x40 | y);  // 0b01000000 Row 
}

//This takes a large array of bits and sends them to the LCD
/*void LCDBitmap(const unsigned char Bender[]){ // char my_array
  for (int index = 0 ; index < (LCD_X * LCD_Y / 8) ; index++){ //
    LCDWrite(LCD_DATA, Bender[index]);
}
}*/

void LCDCharacter(char character) {
  LCDWrite(LCD_DATA, 0x00); //Blank vertical line padding

  for (int index = 0 ; index < 5 ; index++)
    LCDWrite(LCD_DATA, ASCII[character - 0x20][index]);
    //0x20 is the ASCII character for Space (' '). The font table starts with this character

  LCDWrite(LCD_DATA, 0x00); //Blank vertical line padding
}
void LCDBigNum(char character) {
    LCDWrite(LCD_DATA, 0x00);
    for (int index = 0; index < 10; index++)
        LCDWrite(LCD_DATA, LARGEnum[character - 0x20][index]);
                
  LCDWrite(LCD_DATA, 0x00);
}
//Given a string of characters, one by one is passed to the LCD
void LCDString(char *characters) { //testing if just using variable and not pointer
  while (*characters)               // * means pointer"
    LCDCharacter(*characters++);
  //__delay_ms(500);
}

//Clears the LCD by writing zeros to the entire screen
void LCDClear(void) {
  for (int index = 0 ; index < (LCD_X * (LCD_Y / 8)) ; index++){
    LCDWrite(LCD_DATA, 0x00);
  }
  gotoXY(0, 0); //After we clear the display, return to the home position

}
//This sends the magical commands to the PCD8544
void LCDInit(void) {
  //Configure control pins -setting pins to output
    TRISDbits.TRISD3=0;
    TRISDbits.TRISD4=0;
    TRISDbits.TRISD5=0;
    TRISDbits.TRISD6=0;
    TRISDbits.TRISD7=0;

    LCD_DIN=0;
    LCD_CLK=0;
    LCD_DC=0;

  //Reset the LCD to a known state
  LCD_RST=0;
  __delay_ms(10);
  LCD_RST=1;

  LCDWrite(LCD_COMMAND, 0x21); //Tell LCD that extended commands follow
  LCDWrite(LCD_COMMAND, 0xBB); //Set LCD Vop (Contrast):initial BB Try 0xB1(good @ 3.3V) or 0xBF if your display is too dark
  LCDWrite(LCD_COMMAND, 0x04); //Set Temp coefficent initial 04
  LCDWrite(LCD_COMMAND, 0x14); //LCD bias mode 1:48: Try 0x13 or 0x14

  LCDWrite(LCD_COMMAND, 0x20); //We must send 0x20 before modifying the display control mode
  LCDWrite(LCD_COMMAND, 0x0C); //Set display control,0x0C normal mode. 0x0D for inverse
}

//There are two memory banks in the LCD, data/RAM and commands. This
//function sets the DC pin high or low depending, and then sends
//the data byte
void LCDWrite(char data_or_command, char data) { //refers too LCDWrite(aaa,bbb);)
  char i,d;  //changed to char from unsigned
  d=data;
  if(data_or_command==0)LCD_DC=0;   //0 means COMMAND so low sent to DC pin of Nokia
  else LCD_DC=1; //else 1, meaning data, is sent to DC pin of Nokia
    //Send the data
  LCD_CE=0;

  for(i=0;i<8;i++)  {
      LCD_DIN=0;
      if(d&0x80)LCD_DIN=1;
      LCD_CLK=1;
      d<<=1;    //what does << do?
      LCD_CLK=0;
  }
    LCD_CE=1;
}

void NokiaInitApp(void)
{
    /* TODO Initialize User Ports/Peripherals/Project here */
    /* Setup analog functionality and port direction */
    //ANSELA=0;ANSELB=0;ANSELD=0;ANSELC
    TRISD=0; //PortD pins outputs
    /* Initialize peripherals */
    OPTION_REG=0x80; //0b10000000
    /* Enable interrupts */
    //TMR0IE=1; //what is this?
    //GIE=1;  //what is this?

}

