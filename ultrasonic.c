/*******************************************************************************
 *                                                                             *
 * [FILE NAME]:   ultrasonic.c                                                 *
 *                                                                             *
 * [AUTHOR]:      Ahmed Saeed, Mohamed Teleb, Hossam Mostafa,                  *
 *                Amr Hafez, Marco Ashraf, and Muhammed ALsahfie               *
 *                                                                             *
 * [Version]:     1.0.0                                                        *
 *                                                                             *
 * [DATE]:        28/09/2023                                                   *
 *                                                                             *
 * [DESCRIPTION]: source file for ultrasonic sensor driver                     *
 *                                                                             *
 *******************************************************************************/

/*******************************************************************************
 *                                 Includes                                    *
 *******************************************************************************/
#include "ultrasonic.h"
#include "DIO.h"
#include "gptm.h"
#include "bitwise_operation.h"
#include "Delay.h"
#include <stdio.h>
#include <stdlib.h>
#include "tm4c123gh6pm.h"

extern uint32_t SystemCoreClock;
/*
 * Description:
 * This function initializes the ultrasonic sensor.
 * It configures the pin as output based on the provided direction,
 * and sets up the necessary GPIO settings including pull-up/pull-down resistors.
 * Parameters: None.
 * Returns: None.
 */
void ultarsonic_init()
{
    /* Initialize Digital I/O for the ultrasonic sensor */
    DIO_Init();

    /* Initialize Timer0 in one-shot mode for ultrasonic measurements */
    gptm_init(ONE_SHOT);

    /* Load Timer0 with an initial value of 0xFFFF (maximum value) */
    gptm_set_value_ticks(0xFFFF);
}

/*
 * Description:
 * This function measures the distance using an ultrasonic sensor and returns the distance in centimeters.
 * Parameters: None.
 * Returns:
 * - reading: The calculated distance in centimeters.
 */
uint32_t ultarsonic_get_value()
{
    /* Variable to store time of ultrasonic */
    uint32_t duration = 0U;

    /* Variable to store distance */
    uint32_t reading = 0U;

    /* Variable to store the state of echo pin */
    uint32_t pinValue = 0U;

    /* Sending 10uS pulse on trigger pin to enable ultrasonic sensor */
    DIO_WritePin(DIO_PortC, 4, HIGH);

    /* Delay 10 microseconds */
    delay_us(10U);

    /* Disable the trigger pulse */
    DIO_WritePin(DIO_PortC, 4, LOW);

    /* Read the state of the echo pin */
    pinValue = DIO_ReadPin(DIO_PortC, 5);

    /* Waiting for the echo pin to go high */
    while (pinValue == 0)
    {
        pinValue = DIO_ReadPin(DIO_PortC, 5);
    }

    /* Start calculating time by setting Timer0-A to its maximum value */
    gptm_set_value_ticks(0xFFFF);
      /*enable timer*/
       gptm_enable();
    /* Waiting for the echo pin to go low */
    pinValue = DIO_ReadPin(DIO_PortC, 5);

    while (pinValue == 1)
    {
        pinValue = DIO_ReadPin(DIO_PortC, 5);
    }

    /* Getting the time value from Timer0-A */
    duration = gptm_get_value();

    /* Calculate the actual time */
    duration = 0xFFFF - duration;

    /* Disable Timer0-A */
    gptm_deinit();

    /* Calculate the distance in centimeters using the ultrasonic formula */
    reading = (duration * 340.0 * 100) / (2.0 * /*SYSTEM_FREQUENCY*/SystemCoreClock);

    /* Returning the calculated distance in centimeters */
    return reading;
}

