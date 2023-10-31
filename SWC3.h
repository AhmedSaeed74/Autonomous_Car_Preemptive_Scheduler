/*******************************************************************************
 *                                                                             *
 * [FILE NAME]:   SWC3.h                                                       *
 *                                                                             *
 * [AUTHOR]:      Ahmed Saeed, Mohamed Teleb, Hossam Mostafa,                  *
 *                Amr Hafez, Marco Ashraf, and Muhammed ALsahfie               *
 *                                                                             *
 * [Version]:     1.0.0                                                        *
 *                                                                             *
 * [DATE]:        28/09/2023                                                   *
 *                                                                             *
 * [DESCRIPTION]: header file for The third software component                 *
 *                                                                             *
 *******************************************************************************/

#ifndef SWC3_H__
#define SWC3_H__

/*******************************************************************************
 *                                 Includes                                    *
 *******************************************************************************/
#include "std_types.h"


/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
/*
 * Description:
 * This task continuously gathers data from the ultrasonic sensor and processes it. If the
 * measured distance falls below a predefined threshold, it temporarily suspends the
 * LDR task to perform specific actions. The processed data is then sent to a queue for
 * further analysis and control decisions.
 */
void Ultrasonic_Update(void * pvParameters);

/*
 * Description:
 * This task continuously receives data from the LDR sensors and calculates the car's direction based
 * on the difference between the left and right LDR readings. If the absolute difference falls within
 * a specified threshold, it considers the car moving straight. Otherwise, it determines whether the car
 * is turning left or right. The calculated direction is sent to a queue for further processing, and the
 * motors are controlled accordingly.
 */
void LDR_Update(void * pvParameters);

/*
 * Description:
 * This task is intentionally empty, only calling vTaskSuspendAll(). to stop the system 
 * when the temperature exceeds a predefined threshold.
 */
void TS_Update(void * pvParameters);

#endif
