/*******************************************************************************
 *                                                                             *
 * [FILE NAME]:   Sensor.h                                                     *
 *                                                                             *
 * [AUTHOR]:      Ahmed Saeed, Mohamed Teleb, Hossam Mostafa,                  *
 *                Amr Hafez, Marco Ashraf, and Muhammed ALsahfie               *
 *                                                                             *
 * [Version]:     1.0.0                                                        *
 *                                                                             *
 * [DATE]:        28/09/2023                                                   *
 *                                                                             *
 * [DESCRIPTION]: header file for Sensor driver                                *
 *                                                                             *
 *******************************************************************************/

#ifndef TIVA_SENSOR_H
#define TIVA_SENSOR_H

/*******************************************************************************
 *                                 Includes                                    *
 *******************************************************************************/
#include "bitwise_operation.h"
#include "std_types.h"
#include "ADC.h"

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
/**
 * @brief Initializes the ADC for temperature sensor on the specified base and channel.
 */
void TS_Init(void);

/**
 * @brief Reads the temperature value from the specified channel.
 *
 * @return The temperature value read from the ADC. (uint16_t)
 */
uint16_t TS_Read(); //ch0 ->E3

/**
 * @brief Initializes the left LDR sensor.
 */
void LdrLeft_Init(void);

/**
 * @brief Initializes the right LDR sensor.
 */
void LdrRight_Init(void); //ch2 ->E2

/**
 * @brief Reads the value from the left LDR sensor.
 *
 * @return The value read from the left LDR sensor. (uint16_t)
 */
uint16_t LdrLeft_Read(void);//ch1 ->E1

/**
 * @brief Reads the value from the right LDR sensor.
 *
 * @return The value read from the right LDR sensor. (uint16_t)
 */
uint16_t LdrRight_Read(void);

#endif /* TIVA_SENSOR_H */
