/*******************************************************************************
 *                                                                             *
 * [FILE NAME]:   gptm.c                                                       *
 *                                                                             *
 * [AUTHOR]:      Ahmed Saeed, Mohamed Teleb, Hossam Mostafa,                  *
 *                Amr Hafez, Marco Ashraf, and Muhammed ALsahfie               *
 *                                                                             *
 * [Version]:     1.0.0                                                        *
 *                                                                             *
 * [DATE]:        28/09/2023                                                   *
 *                                                                             *
 * [DESCRIPTION]: source file for GPTM driver                                  *
 *                                                                             *
 *******************************************************************************/

/*******************************************************************************
 *                                 Includes                                    *
 *******************************************************************************/
#include "gptm.h"
#include "tm4c123gh6pm.h"
#include "bitwise_operation.h"
#include "DIO.h"

/*
 * Description:
 * This function initializes a timer module, configures its settings, and enables the timer.
 * Parameters:
 * - timer_mode: The mode of operation for TimerA0 (one-shot, periodic, or capture).
 * Returns: None.
 */
void gptm_init(GPTM_TimerMode timer_mode)
{
    /*enable clock Timer in run mode */
    SET_BIT(SYSCTL_RCGCTIMER_R,0);

    /* disable timer0 output */
    CLEAR_BIT(TIMER0_CTL_R,0);

    /*To stop timer during debugging*/
    SET_BIT(TIMER0_CTL_R , 1);

    /*assign the global operation configuration option */
    TIMER0_CFG_R = 0x04;

    /*assign the mode of timerA0 */
    TIMER0_TAMR_R |= timer_mode;

    /* Enable Timer0 module */

    //TIMER0_TAILR_R = 0xFFFF;
}

/*
 * Description:
 * This function disables the Timer 0 output by clearing the corresponding bit
 * in the TIMER0_CTL_R register.
 * Parameters: None.
 * Returns: None.
 */
void gptm_deinit(void)
{
    /* disable timer0 output */
    CLEAR_BIT(TIMER0_CTL_R,0);
}

/*
 * Description:
 * This function sets the Timer A0 value for a specified duration in milliseconds.
 * Parameters:
 * - milliSeconds: The duration in milliseconds for which the timer should count.
 * Returns: None.
 */
void gptm_set_value_ms(uint32_t milliSeconds)
{
    /* TimerA0 prescaler value */
    TIMER0_TAPR_R = (int)((float)(milliSeconds - 1) / 4);

    /* TimerA0 counter starting count down value  */
    TIMER0_TAILR_R = (((SYSTEM_FREQUENCY - 1) / 1000) * 4);
}

/*
 * Description:
 * This function sets the Timer A0 value in ticks and enables the Timer0 module.
 * Parameters:
 * - value: The value to set the TimerA0 countdown value to in ticks.
 * Returns: None.
 */
void gptm_set_value_ticks(uint32_t value)
{
    /* TimerA0 counter starting count down value  */
    TIMER0_TAILR_R = value;

    /* Enable Timer0 module */
    SET_BIT(TIMER0_CTL_R,0);
}

/*
 * Description:
 * This function reads and returns the current value of Timer A0.
 * Parameters: None.
 * Returns:
 * - duration: The current value of Timer A0.
 */
uint32_t gptm_get_value(void)
{
    /* Getting the time value */
    uint32_t duration = TIMER0_TAR_R;

    /* Return that time value */
    return duration;
}
void gptm_enable(void)
{
    SET_BIT(TIMER0_CTL_R,0);
}
