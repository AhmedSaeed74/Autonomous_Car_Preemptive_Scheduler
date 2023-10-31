/*******************************************************************************
 *                                                                             *
 * [FILE NAME]:   SWC1.h                                                       *
 *                                                                             *
 * [AUTHOR]:      Ahmed Saeed, Mohamed Teleb, Hossam Mostafa,                  *
 *                Amr Hafez, Marco Ashraf, and Muhammed ALsahfie               *
 *                                                                             *
 * [Version]:     1.0.0                                                        *
 *                                                                             *
 * [DATE]:        28/09/2023                                                   *
 *                                                                             *
 * [DESCRIPTION]: header file for The first software component                 *
 *                                                                             *
 *******************************************************************************/

#ifndef SWC1_H__
#define SWC1_H__

/*******************************************************************************
 *                                 Includes                                    *
 *******************************************************************************/
#include "std_types.h"

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
/*
 * Description:
 * ModulesInit task initializes various hardware modules, including the PushButton,
 * LCD, Motors, Temperature Sensor, Left LDR, Right LDR, and Ultrasonic Sensor.
 * Once initialization is complete, it suspends itself.
 */
void ModulesInit(void * pvParameters);

/*
 * Description:
 * The SwitchCheck task monitors the Start Button and displays status on an LCD screen.
 * If the Start Button is pressed, it clears the LCD screen, resets the counter, and waits for a specified interval.
 * If the Start Button is not pressed, it displays "I am OFF" on the LCD, stops motors, and increments the counter.
 */
void SwitchCheck(void * pvParameters);

#endif
