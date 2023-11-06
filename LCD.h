/*******************************************************************************
 *                                                                             *
 * [FILE NAME]:   LCD.h                                                        *
 *                                                                             *
 * [AUTHOR]:      Ahmed Saeed, Mohamed Teleb, Hossam Mostafa,                  *
 *                Amr Hafez, Marco Ashraf, and Muhammed ALsahfie               *
 *                                                                             *
 * [Version]:     1.0.0                                                        *
 *                                                                             *
 * [DATE]:        28/09/2023                                                   *
 *                                                                             *
 * [DESCRIPTION]: header file for LCD driver                                   *
 *                                                                             *
 *******************************************************************************/
#ifndef LCD_H_
#define LCD_H_

/*******************************************************************************
 *                                 Includes                                    *
 *******************************************************************************/
#include "DIO_Types.h"
#include "DIO.h"
#include "Delay.h"
#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define MODE8BIT (0U)
#define MODE4BIT (1U)

#define MYMODE  MODE8BIT

#define LCDPort     DIO_PortB
#define CONTROLPORT DIO_PortF
#define RS          1
#define RW          2
#define EN          3

#define  CLEAR_DISPLAY            ((unsigned char) 0X01 )
#define  HOME_POSITION            ((unsigned char) 0X02 )
#define  SHIFT_CURSOR_LEFT        ((unsigned char) 0X04 )
#define  SHIFT_CURSOR_RIGHT       ((unsigned char) 0X06 )
#define  SHIFT_DISPLAY_LEFT       ((unsigned char) 0X07 )
#define  SHIFT_DISPLAY_RIGHT      ((unsigned char) 0X05 )
#define  DISPLAY_OFF_CURSOR_OFF   ((unsigned char) 0X08 )
#define  DISPLAY_OFF_CURSOR_ON    ((unsigned char) 0X0A )
#define  DISPLAY_ON_CURSOR_OFF    ((unsigned char) 0X0C )
#define  DISPLAY_ON_CURSOR_ON     ((unsigned char) 0X0E )
#define  DISPLAY_ON_CURSOR_BLINK  ((unsigned char) 0X0F )
#define  FUNC_SET_4BIT_1LINE      ((unsigned char) 0X20 )
#define  FUNC_SET_4BIT_2LINE      ((unsigned char) 0X28 )
#define  FUNC_SET_8BIT_1LINE      ((unsigned char) 0X30 )
#define  FUNC_SET_8BIT_2LINE      ((unsigned char) 0X038)
#define  CURSOR_START_1ST_LINE    ((unsigned char) 0X80 )
#define  CURSOR_START_2ND_LINE    ((unsigned char) 0XC0 )

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
void LCD_Cmd(char cmd);
void LCD_Clear(void);
void LCD_Init(void);
void LCD_SendChar(char data);
void LCD_SendString(uint8_t *data);
void LCD_GoToString(uint8_t line, uint8_t pos, uint8_t string[]);
void LCD_Write_Int(int num);
void LCD_GoTo(int line, int pos);


#endif 
