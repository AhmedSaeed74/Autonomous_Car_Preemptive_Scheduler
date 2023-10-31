/*******************************************************************************
 *                                                                             *
 * [FILE NAME]:   Delay.h                                                      *
 *                                                                             *
 * [AUTHOR]:      Ahmed Saeed, Mohamed Teleb, Hossam Mostafa,                  *
 *                Amr Hafez, Marco Ashraf, and Muhammed ALsahfie               *
 *                                                                             *
 * [Version]:     1.0.0                                                        *
 *                                                                             *
 * [DATE]:        28/09/2023                                                   *
 *                                                                             *
 * [DESCRIPTION]: header file for the delay driver                             *
 *                                                                             *
 *******************************************************************************/

/*******************************************************************************
 *                                 Includes                                    *
 *******************************************************************************/
#include "Delay.h"

/*
 * Description:
 * This function provides a blocking delay in milliseconds.
 * It loops for the specified number of milliseconds, causing
 * a time delay.
 * Parameters:
 * - m: The number of milliseconds to delay.
 * Returns: None.
 */
void delay_ms(int m){
    int i, j;
    /* Loop for the specified number of milliseconds */
    for(i = 0; i < m; i++){
        /* Nested loop to create a delay of approximately 1 millisecond */
        for(j = 0; j < 3180; j++);
    }
}

/*
 * Description:
 * This function provides a blocking delay in microseconds.
 * It loops for the specified number of microseconds, causing
 * a time delay.
 * Parameters:
 * - m: The number of microseconds to delay.
 * Returns: None.
 */
void delay_us(int m){
    int i, j;
    /* Loop for the specified number of microseconds */
    for(i = 0; i < m; i++){
        /* Nested loop to create a delay of approximately 1 microseconds */
        for(j = 0; j < 3; j++);
    }
}
