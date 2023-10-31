/*******************************************************************************
 *                                                                             *
 * [FILE NAME]:   Motor.h                                                      *
 *                                                                             *
 * [AUTHOR]:      Ahmed Saeed, Mohamed Teleb, Hossam Mostafa,                  *
 *                Amr Hafez, Marco Ashraf, and Muhammed ALsahfie               *
 *                                                                             *
 * [Version]:     1.0.0                                                        *
 *                                                                             *
 * [DATE]:        28/09/2023                                                   *
 *                                                                             *
 * [DESCRIPTION]: header file for Motor driver                                 *
 *                                                                             *
 *******************************************************************************/

#ifndef MOTOR_H_
#define MOTOR_H_

/*******************************************************************************
 *                                 Includes                                    *
 *******************************************************************************/
#include "PWM.h"

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
/*
 * Description :
 * Enum for defining different directions and actions
 * (STOP, BACKWARD, FORWARD, LEFTT, RIGHTT, SPIN).
 */
typedef enum
{
    STOP = 0,
    BACKWARD,
    FORWARD,
    LEFTT,
    RIGHTT,
    SPIN
}dir;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
/*
 * Description:
 * This function initializes the motors, configuring GPIO pins and PWM for motor control.
 * It sets the motor duty cycle to 70%.
 * Parameters: None
 * Returns: None
 */
void Motors_Init(void);

/*
 * Description:
 * This function sets the direction of the motors based on the provided enum value.
 * It configures GPIO pins to control motor direction.
 * Parameters:
 * - d: The direction to set (STOP, FORWARD, BACKWARD, LEFTT, RIGHTT, SPIN).
 * Returns: None
 */
void Motors_set_direction(dir d);

dir Motors_get_direction();

#endif /* MOTOR_H_ */
