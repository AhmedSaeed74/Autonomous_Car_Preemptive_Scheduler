/*******************************************************************************
 *                                                                             *
 * [FILE NAME]:   PushButton.c                                                 *
 *                                                                             *
 * [AUTHOR]:      Ahmed Saeed, Mohamed Teleb, Hossam Mostafa,                  *
 *                Amr Hafez, Marco Ashraf, and Muhammed ALsahfie               *
 *                                                                             *
 * [Version]:     1.0.0                                                        *
 *                                                                             *
 * [DATE]:        28/09/2023                                                   *
 *                                                                             *
 * [DESCRIPTION]: source file for Push Button driver                           *
 *                                                                             *
 *******************************************************************************/

/*******************************************************************************
 *                                 Includes                                    *
 *******************************************************************************/
#include "bitwise_operation.h"
#include"std_types.h"
#include"DIO.h"
#include"PushBuuton.h"

/*************************************************************************************************************************************/
/*************************************************************************************************************************************/
/*PUSHBUTTON initialization function*/
/*INPUTS: NONE*/
/*OUTPUTS: NONE*/
/*Description: Initializes the GPIO PIN F0   F4 For TWO switch*/
/*************************************************************************************************************************************/
/*************************************************************************************************************************************/

void PushButton_INIT(void)
{
    /*function initialization of two push button make them pullup*/
    DIO_Init();
}
/*************************************************************************************************************************************/
/*************************************************************************************************************************************/
/*GET State Of StartButton function*/
/*INPUTS: NONE*/
/*OUTPUTS: Uint8_t*/
/*Description: FUnction Return 1 if button is pressed else 0*/
/*************************************************************************************************************************************/
/*************************************************************************************************************************************/
uint8_t GET_Start_Button(void)
{
    uint8_t state=0;
    /*READ if Button is Pressed or not*/
    if(DIO_ReadPin(DIO_PortF, DIO_ChannelF0)==0)
    {

        state=1;
    }
    else
    {
        state=0;
    }
    return state;
}
/*************************************************************************************************************************************/
/*************************************************************************************************************************************/
/*GET State Of STOPButton function*/
/*INPUTS: NONE*/
/*OUTPUTS: Uint8_t*/
/*Description: Function Return 1 if button is pressed else 0*/
/*************************************************************************************************************************************/
/*************************************************************************************************************************************/
uint8_t GET_STOP_Button(void)
{
    uint8_t state=0;
    /*READ if Button is Pressed or not*/
    if(DIO_ReadPin(DIO_PortF, DIO_ChannelF4)==0)
    {
        state=1;
    }
    else
    {
        state=0;
    }
    return state;
}

