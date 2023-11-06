/*******************************************************************************
 *                                                                             *
 * [FILE NAME]:   SWC4.h                                                       *
 *                                                                             *
 * [AUTHOR]:      Ahmed Saeed, Mohamed Teleb, Hossam Mostafa,                  *
 *                Amr Hafez, Marco Ashraf, and Muhammed ALsahfie               *
 *                                                                             *
 * [Version]:     1.0.0                                                        *
 *                                                                             *
 * [DATE]:        28/09/2023                                                   *
 *                                                                             *
 * [DESCRIPTION]: header file for The fourth software component                *
 *                                                                             *
 *******************************************************************************/

#ifndef SWC4_H__
#define SWC4_H__

/*******************************************************************************
 *                                 Includes                                    *
 *******************************************************************************/
#include "std_types.h"


/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
/*
 * Description:
 * The LCD_Print task continuously retrieves sensor data from queues 
 * and displays it on an LCD screen.
 * It shows the distance, direction, and temperature on the screen.
 */
void LCD_Print(void * pvParameters);

#endif
