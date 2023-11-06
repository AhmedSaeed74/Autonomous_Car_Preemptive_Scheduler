/*******************************************************************************
 *                                                                             *
 * [FILE NAME]:   LCD.c                                                        *
 *                                                                             *
 * [AUTHOR]:      Ahmed Saeed, Mohamed Teleb, Hossam Mostafa,                  *
 *                Amr Hafez, Marco Ashraf, and Muhammed ALsahfie               *
 *                                                                             *
 * [Version]:     1.0.0                                                        *
 *                                                                             *
 * [DATE]:        28/09/2023                                                   *
 *                                                                             *
 * [DESCRIPTION]: source file for LCD driver                                   *
 *                                                                             *
 *******************************************************************************/

/*******************************************************************************
 *                                 Includes                                    *
 *******************************************************************************/
#include "LCD.h"

/************************************************************************************
* API Name: LCD_Cmd
* Parameters (in): cmd
* Parameters (inout): None
* Parameters (out): None
* Return value:
* Description: Send Command to LCD
************************************************************************************/
void LCD_Cmd(char cmd){
#if MYMODE == MODE8BIT
    DIO_WritePort(LCDPort, cmd);
    DIO_WritePin(CONTROLPORT, RS, LOW);
    DIO_WritePin(CONTROLPORT, RW, LOW);
    DIO_WritePin(CONTROLPORT, EN, HIGH);
    delay_us(40);
    DIO_WritePin(CONTROLPORT, EN, LOW);
#elif MYMODE == MODE4BIT
    DIO_WritePort(LCDPort, (DIO_ReadPort(LCDPort) & 0x0F) | (cmd & 0xF0));
    DIO_WritePin(CONTROLPORT, RS, LOW);
    DIO_WritePin(CONTROLPORT, RW, LOW);
    DIO_WritePin(CONTROLPORT, EN, HIGH);
    delay_us(40);
    DIO_WritePin(CONTROLPORT, EN, LOW);
    DIO_WritePort(LCDPort, (DIO_ReadPort(LCDPort) & 0x0F) | (cmd << 4));
    DIO_WritePin(CONTROLPORT, RS, LOW);
    DIO_WritePin(CONTROLPORT, RW, LOW);
    DIO_WritePin(CONTROLPORT, EN, HIGH);
    delay_us(40);
    DIO_WritePin(CONTROLPORT, EN, LOW);
#endif
}

/************************************************************************************
* API Name: LCD_Cleat
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value:
* Description: Clear LCD
************************************************************************************/
void LCD_Clear(void){
    LCD_Cmd(CLEAR_DISPLAY);
}


/************************************************************************************
* API Name: LCD_Init
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value:
* Description: initialize LCD due to its mode
************************************************************************************/
void LCD_Init(void){
    DIO_Init();

#if MYMODE == MODE8BIT
    //delay_ms(20);
    //LCD_Cmd(FUNC_SET_8BIT_2LINE);
    //delay_us(5);
    //LCD_Cmd(FUNC_SET_8BIT_2LINE);
    //delay_us(100);
    //LCD_Cmd(FUNC_SET_8BIT_2LINE);
		delay_ms(40);
		LCD_Cmd(0x38);
		delay_us(50);
		LCD_Cmd(0x0E);
		delay_us(50);
		LCD_Cmd(0x01);
		delay_ms(2);
		LCD_Cmd(0x0F);
		delay_us(4);
		LCD_Cmd(0x02);
#elif MYMODE == MODE4BIT
    LCD_Cmd(0x02);
    LCD_Cmd(FUNC_SET_4BIT_2LINE);
    delay_us(5);
    LCD_Cmd(FUNC_SET_4BIT_2LINE);
    delay_us(100);
    LCD_Cmd(FUNC_SET_4BIT_2LINE);
#endif
    //LCD_Cmd(DISPLAY_OFF_CURSOR_OFF);
    //LCD_Cmd(CLEAR_DISPLAY);
    //LCD_Cmd(SHIFT_CURSOR_RIGHT);
    //LCD_Cmd(DISPLAY_ON_CURSOR_ON);
    //delay_us(5);
    //LCD_Cmd(HOME_POSITION);
}

/************************************************************************************
* API Name: LCD_SendChar
* Parameters (in): data
* Parameters (inout): None
* Parameters (out): None
* Return value:
* Description: Eend one Character to LCD
************************************************************************************/
void LCD_SendChar(char data){
#if MYMODE == MODE8BIT
    DIO_WritePin(CONTROLPORT, RS, HIGH);
    DIO_WritePin(CONTROLPORT, RW, LOW);
		DIO_WritePort(LCDPort, data);
    DIO_WritePin(CONTROLPORT, EN, HIGH);
    delay_us(1000);
    DIO_WritePin(CONTROLPORT, EN, LOW);
    delay_us(1000);
#elif MYMODE == MODE4BIT
    DIO_WritePort(LCDPort, (DIO_ReadPort(LCDPort) & 0x0F) | (data & 0xF0));
    DIO_WritePin(CONTROLPORT, RS, HIGH);
    DIO_WritePin(CONTROLPORT, RW, LOW);
    DIO_WritePin(CONTROLPORT, EN, HIGH);
    delay_ms(10);
    DIO_WritePin(CONTROLPORT, EN, LOW);
    DIO_WritePort(LCDPort, (DIO_ReadPort(LCDPort) & 0x0F) | (data << 4));
    DIO_WritePin(CONTROLPORT, RS, HIGH);
    DIO_WritePin(CONTROLPORT, RW, LOW);
    DIO_WritePin(CONTROLPORT, EN, HIGH);
    delay_ms(10);
    DIO_WritePin(CONTROLPORT, EN, LOW);

#endif
}

/************************************************************************************
* API Name: LCD_SendString
* Parameters (in): data
* Parameters (inout): None
* Parameters (out): None
* Return value:
* Description: Send whole String to LCD
************************************************************************************/
void LCD_SendString(uint8_t* data){
    int i = 0;
    while(data[i] != '\0'){
        LCD_SendChar(data[i]);
        i++;
        //delay_ms(1);
    }
}


/************************************************************************************
* API Name: LCD_GoToString
* Parameters (in): line, pos, string
* Parameters (inout): None
* Parameters (out): None
* Return value:
* Description: Send whole String to LCD starting for location
************************************************************************************/
void LCD_GoToString(uint8_t line, uint8_t pos, uint8_t string[]){
    //delay_ms(1);
    uint8_t cmd;
    switch(line){
    case 1:
        cmd = 0x80 | (pos & 0x0F);
        LCD_Cmd(cmd);
        break;
    case 2:
        cmd = 0xC0 | (pos & 0x0F);
        LCD_Cmd(cmd);
        break;
    }
    LCD_SendString(string);
}


/************************************************************************************
* API Name: LCD_Write_Int
* Parameters (in): num
* Parameters (inout): None
* Parameters (out): None
* Return value:
* Description: write integer to the LCD
************************************************************************************/
void LCD_Write_Int(int num){
    int j;
    char i = 0;
    char str[32];
    while(num != 0){
        str[i] = num % 10;
        num = num/10;
        i++;
    }
    for(j = i-1; j >=0 ; j--)
        LCD_SendChar('0' + str[j]);
}


/************************************************************************************
* API Name: LCD_GoTo
* Parameters (in): line, pos
* Parameters (inout): None
* Parameters (out): None
* Return value:
* Description: Move cursor to specific location
************************************************************************************/
void LCD_GoTo(int line, int pos){
    if(line == 1){
        LCD_Cmd(CURSOR_START_1ST_LINE+pos);
    }else if(line == 2){
        LCD_Cmd(CURSOR_START_2ND_LINE+pos);
    }
		else;
}
