/*******************************************************************************
 *                                                                             *
 * [FILE NAME]:   Sensor.c                                                     *
 *                                                                             *
 * [AUTHOR]:      Ahmed Saeed, Mohamed Teleb, Hossam Mostafa,                  *
 *                Amr Hafez, Marco Ashraf, and Muhammed ALsahfie               *
 *                                                                             *
 * [Version]:     1.0.0                                                        *
 *                                                                             *
 * [DATE]:        28/09/2023                                                   *
 *                                                                             *
 * [DESCRIPTION]: source file for Sensor driver                                *
 *                                                                             *
 *******************************************************************************/

/*******************************************************************************
 *                                 Includes                                    *
 *******************************************************************************/
#include "Sensor.h"

/**
 * @brief Initializes the ADC module for the temperature sensor on the specified channel.
 */

void TS_Init(void)
{
    ADC_Init_TS(ADC_Base_0, CH_0);
}
/**
 * @brief Reads the temperature value from the specified channel.
 *
 * @return The temperature value read from the ADC.
 */

uint16_t TS_Read()
{
    uint16_t result = ADC_Read_TS(CH_0);

    return result;
}

/**
 * @brief Initializes the right LDR sensor.
 */


void LdrRight_Init(void)
{
    /* Initialize the right LDR sensor using ADC_Init function*/
    ADC_Init( ADC_Base_0, ADC_Module_0, CH_1, ADC_sequencer_1);
}


/**
 * @brief Initializes the left LDR sensor.
 */

void LdrLeft_Init(void)
{
    /* Initialize the left LDR sensor using ADC_Init function*/
    ADC_Init(ADC_Base_0, ADC_Module_0, CH_2, ADC_sequencer_2);
}

/**
 * @brief Reads the value from the right LDR sensor.
 *
 * @return The value read from the right LDR sensor.
 */

uint16_t LdrRight_Read(void)
{
    /* Use ADC_Read function to read the value from the right LDR sensor */
    return ADC_Read(ADC_Base_0, CH_1, ADC_sequencer_1);
}

/**
 * @brief Reads the value from the left LDR sensor.
 *
 * @return The value read from the left LDR sensor.
 */

uint16_t LdrLeft_Read(void)
{
    /* Use ADC_Read function to read the value from the left LDR sensor*/
    return ADC_Read(ADC_Base_0, CH_2, ADC_sequencer_2);
}



