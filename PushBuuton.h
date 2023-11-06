/*******************************************************************************
 *                                                                             *
 * [FILE NAME]:   PushBuuton.h                                                 *
 *                                                                             *
 * [AUTHOR]:      Ahmed Saeed, Mohamed Teleb, Hossam Mostafa,                  *
 *                Amr Hafez, Marco Ashraf, and Muhammed ALsahfie               *
 *                                                                             *
 * [Version]:     1.0.0                                                        *
 *                                                                             *
 * [DATE]:        28/09/2023                                                   *
 *                                                                             *
 * [DESCRIPTION]: header file for Push Button driver                           *
 *                                                                             *
 *******************************************************************************/

#ifndef PUSHBUUTON_H_
#define PUSHBUUTON_H_

/*******************************************************************************
 *                                 Includes                                    *
 *******************************************************************************/
#include"std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define GPIO_PIN0 0
#define GPIO_PIN4 4

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
void PushButton_INIT(void);
uint8_t GET_Start_Button(void);
uint8_t GET_STOP_Button(void);


#endif /* PUSHBUUTON_H_ */
