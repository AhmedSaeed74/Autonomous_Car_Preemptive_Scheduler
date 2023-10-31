/*******************************************************************************
 *                                                                             *
 * [FILE NAME]:   ultrasonic.h                                                 *
 *                                                                             *
 * [AUTHOR]:      Ahmed Saeed, Mohamed Teleb, Hossam Mostafa,                  *
 *                Amr Hafez, Marco Ashraf, and Muhammed ALsahfie               *
 *                                                                             *
 * [Version]:     1.0.0                                                        *
 *                                                                             *
 * [DATE]:        28/09/2023                                                   *
 *                                                                             *
 * [DESCRIPTION]: header file for Ultrasonic sensor driver                     *
 *                                                                             *
 *******************************************************************************/

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

/*******************************************************************************
 *                                 Includes                                    *
 *******************************************************************************/
#include "std_types.h"

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description:
 * This function initializes the ultrasonic sensor.
 * It configures the pin as output based on the provided direction,
 * and sets up the necessary GPIO settings including pull-up/pull-down resistors.
 * Parameters: None.
 * Returns: None.
 */
void ultarsonic_init(void);

/*
 * Description:
 * This function gets the ultrasonic sensor reading (distance from obstacle).
 * It configures the pin as output based on the provided direction,
 * and sets up the necessary GPIO settings including pull-up/pull-down resistors or PWM signal to control speed.
 * Parameters:
 * - carSide: pointer to the ultrasonic sensor configuration (PORT_ID , ECHO_PIN , TRIGGER_PIN).
 * Returns: None.
 */
uint32_t ultarsonic_get_value(void);

#endif /* ULTRASONIC_H_ */
