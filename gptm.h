/*******************************************************************************
 *                                                                             *
 * [FILE NAME]:   gptm.h                                                       *
 *                                                                             *
 * [AUTHOR]:      Ahmed Saeed, Mohamed Teleb, Hossam Mostafa,                  *
 *                Amr Hafez, Marco Ashraf, and Muhammed ALsahfie               *
 *                                                                             *
 * [Version]:     1.0.0                                                        *
 *                                                                             *
 * [DATE]:        28/09/2023                                                   *
 *                                                                             *
 * [DESCRIPTION]: header file for GPTM driver                                  *
 *                                                                             *
 *******************************************************************************/

#ifndef GPTM_H_
#define GPTM_H_

/*******************************************************************************
 *                                 Includes                                    *
 *******************************************************************************/
#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define SYSTEM_FREQUENCY 16000000

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

/*
 * Description :
 * Enum responsible for configuring the timer mode for GPTM driver.
 */
typedef enum
{
    ONE_SHOT = 1,PERIODIC,CAPTURE
}GPTM_TimerMode;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
/*
 * Description:
 * This function initializes a timer module, configures its settings, and enables the timer.
 * Parameters:
 * - timer_mode: The mode of operation for TimerA0 (one-shot, periodic, or capture).
 * Returns: None.
 */
void gptm_init(GPTM_TimerMode timer_mode);

/*
 * Description:
 * This function disables the Timer 0 output by clearing the corresponding bit
 * in the TIMER0_CTL_R register.
 * Parameters: None.
 * Returns: None.
 */
void gptm_deinit(void);

/*
 * Description:
 * This function sets the Timer A0 value for a specified duration in milliseconds.
 * Parameters:
 * - milliSeconds: The duration in milliseconds for which the timer should count.
 * Returns: None.
 */
void gptm_set_value(uint32_t milliSeconds);

/*
 * Description:
 * This function sets the Timer A0 value in ticks and enables the Timer0 module.
 * Parameters:
 * - value: The value to set the TimerA0 countdown value to in ticks.
 * Returns: None.
 */
void gptm_set_value_ticks(uint32_t value);

/*
 * Description:
 * This function reads and returns the current value of Timer A0.
 * Parameters: None.
 * Returns:
 * - duration: The current value of Timer A0.
 */
uint32_t gptm_get_value(void);

void gptm_enable(void);

#endif /* GPTM_H_ */
