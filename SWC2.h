/*******************************************************************************
 *                                                                             *
 * [FILE NAME]:   SWC2.h                                                       *
 *                                                                             *
 * [AUTHOR]:      Ahmed Saeed, Mohamed Teleb, Hossam Mostafa,                  *
 *                Amr Hafez, Marco Ashraf, and Muhammed ALsahfie               *
 *                                                                             *
 * [Version]:     1.0.0                                                        *
 *                                                                             *
 * [DATE]:        28/09/2023                                                   *
 *                                                                             *
 * [DESCRIPTION]: header file for The second software component                *
 *                                                                             *
 *******************************************************************************/

#ifndef SWC2_H__
#define SWC2_H__

/*******************************************************************************
 *                                 Includes                                    *
 *******************************************************************************/
#include "std_types.h"


/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
 /*
 * Description:
 * The Ultrasonic_Read task reads data from an ultrasonic sensor 
 * and sends it to a queue for further processing.
 */
void Ultrasonic_Read(void * pvParameters);

/*
 * Description:
 * The LDR_Read task continuously gathers data from both left and 
 * right Light Dependent Resistors (LDRs).
 * It reads sensor values, assigns them to a data structure, 
 * and sends the data to a queue for further processing.
 */
void LDR_Read(void * pvParameters);

/*
 * Description:
 * The TempSensor_Read task continuously gathers data from the temperature 
 * sensor. It reads temperature values,
 * checks if the value exceeds a threshold, and resumes 
 * another task (TSHandle) if the condition is met.
 * The temperature data is also sent to a queue for further processing.
 */
void TempSensor_Read(void * pvParameters);

#endif
