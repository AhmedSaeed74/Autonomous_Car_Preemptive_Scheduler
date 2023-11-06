/*******************************************************************************
 *                                                                             *
 * [FILE NAME]:   PWM.h                                                        *
 *                                                                             *
 * [AUTHOR]:      Ahmed Saeed, Mohamed Teleb, Hossam Mostafa,                  *
 *                Amr Hafez, Marco Ashraf, and Muhammed ALsahfie               *
 *                                                                             *
 * [Version]:     1.0.0                                                        *
 *                                                                             *
 * [DATE]:        28/09/2023                                                   *
 *                                                                             *
 * [DESCRIPTION]: Header file for PWM module                                   *
 *                                                                             *
 *******************************************************************************/

#ifndef PWM_H_
#define PWM_H_

/*******************************************************************************
 *                                 Includes                                    *
 *******************************************************************************/
#include "std_types.h"

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
 
void PWM_INIT(void);

void PWM_set_DC(uint8_t value);

uint8_t PWM_get_DC();


#endif /* PWM_H_ */
