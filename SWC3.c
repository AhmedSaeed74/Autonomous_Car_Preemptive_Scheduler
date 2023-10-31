/*******************************************************************************
 *                                                                             *
 * [FILE NAME]:   SWC3.c                                                       *
 *                                                                             *
 * [AUTHOR]:      Ahmed Saeed, Mohamed Teleb, Hossam Mostafa,                  *
 *                Amr Hafez, Marco Ashraf, and Muhammed ALsahfie               *
 *                                                                             *
 * [Version]:     1.0.0                                                        *
 *                                                                             *
 * [DATE]:        28/09/2023                                                   *
 *                                                                             *
 * [DESCRIPTION]: source file for The third software component                 *
 *                                                                             *
 *******************************************************************************/

/*******************************************************************************
 *                                 Includes                                    *
 *******************************************************************************/
#include "SWC3.h"
#include "SWCsIncludes.h"
#include "Motor.h"
#include "Delay.h"
#include "LCD.h"


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
/* Threshold value for LDR comparison */
#define ldrCompVal 200

/* STOP_DISTANCE defines the distance threshold for stopping the vehicle. */
#define STOP_DISTANCE 10

/* Declare an external queues handlers */
extern QueueHandle_t xQueue1;
extern QueueHandle_t xQueue2;
extern QueueHandle_t xQueue3;
extern QueueHandle_t xQueue4;
extern QueueHandle_t xQueue5;

/* Declare an external semaphore handler */
extern SemaphoreHandle_t xSemaphore;

/* External reference to the TaskHandle for LDR Task */
extern TaskHandle_t LDRHandle;

/*
 * Description:
 * This task continuously gathers data from the ultrasonic sensor and processes it. If the
 * measured distance falls below a predefined threshold, it temporarily suspends the
 * LDR task to perform specific actions. The processed data is then sent to a queue for
 * further analysis and control decisions.
 */
void Ultrasonic_Update(void * pvParameters){
    /* Initialize the tick count variables */
    TickType_t xLastWakeTime;

    /* Ultrasonic sensor value */
    uint16_t usVal = 0;

    uint8_t counter = 0;

    while(1){
        /* Get the current system tick count */
        xLastWakeTime = xTaskGetTickCount();

        uint16_t x1 = xTaskGetTickCount();

        /* Receive ultrasonic sensor value from the queue */
        xQueueReceive( xQueue3, &( usVal ),( TickType_t ) portMAX_DELAY );

        /* Check if usVal is smaller than and replace it with 99 */
        if(usVal < 2){
            usVal = 99;
        }

        /* Send the gathered data to the queue */
        xQueueSend(xQueue5, (void *)&usVal, 0);

        /* If the motors are moving backward, check the counter and change direction to SPIN if needed. */
        if (Motors_get_direction() == BACKWARD) {
            if (counter < 10) {
                counter++;
            } else {
                Motors_set_direction(SPIN);
                counter++;
            }
        }

        /* If the motors are spinning, check the counter and stop them if needed. */
        else if (Motors_get_direction() == SPIN) {
            if (counter < 20) {
                counter++;
            } else {
                Motors_set_direction(STOP);
            }
        }

        /* If the ultrasonic distance is below the threshold, control motor direction and counter. */
        else if (usVal < STOP_DISTANCE) {
            if (counter == 0) {
                xSemaphoreTake(xSemaphore, portMAX_DELAY);
                Motors_set_direction(BACKWARD);
                counter++;
            } else if (counter == 20) {
                counter = 0;
                Motors_set_direction(BACKWARD);
                counter++;
            }
        }

        /* If none of the above conditions are met, manage the counter and motor direction. */
        else {
            if (counter == 20) {
                xSemaphoreGive(xSemaphore);
                counter = 0;
                Motors_set_direction(FORWARD);
            }
        }

        uint16_t x2 = xTaskGetTickCount();
        uint16_t res = (x2 * portTICK_PERIOD_MS) - (x1 * portTICK_PERIOD_MS);

        /* Delay until the specified time interval has passed */
        vTaskDelayUntil(&xLastWakeTime, 10);
    }

}

/*
 * Description:
 * This task continuously receives data from the LDR sensors and calculates the car's direction based
 * on the difference between the left and right LDR readings. If the absolute difference falls within
 * a specified threshold, it considers the car moving straight. Otherwise, it determines whether the car
 * is turning left or right. The calculated direction is sent to a queue for further processing, and the
 * motors are controlled accordingly.
 */
void LDR_Update(void * pvParameters){
    /* Initialize the tick count variables */
    TickType_t xLastWakeTime;

    /* Data structure to store gathered data */
    ldr_val ldr_data;
    uint8_t myDir;

    while(1){
        /* Get the current system tick count */
        xLastWakeTime = xTaskGetTickCount();

        uint16_t x1 = xTaskGetTickCount();
        /* Wait for data from the queue indefinitely */
        xQueueReceive( xQueue1, &( ldr_data ),( TickType_t ) portMAX_DELAY );
        /* Determine the direction based on LDR values */
        if(((uint16_t)(ldr_data.LEFT - ldr_data.RIGHT) < ldrCompVal)){
            /* If the absolute difference between LDR values is within a threshold (ldrCompVal),
                             consider it as the CENTER direction when the car moves straight. */
            myDir = CENTER;
        }else if(((uint16_t)(ldr_data.RIGHT - ldr_data.LEFT) < ldrCompVal)){
            /* If the absolute difference between LDR values is within a threshold (ldrCompVal),
                             consider it as the CENTER direction when the car moves straight. */
            myDir = CENTER;
        }else if(ldr_data.LEFT < ldr_data.RIGHT){
            /* If the right LDR reading is less than the left LDR reading, consider it as LEFT direction
                             when the car turns left. */
            myDir = LEFT;
        }else if(ldr_data.RIGHT < ldr_data.LEFT){
            /* If the left LDR reading is less than the right LDR reading, consider it as RIGHT direction
                             when the car turns right. */
            myDir = RIGHT;
        }

        /* Send the gathered data to the queue */
        xQueueSend(xQueue4, (void *)&myDir, 0);

        /* If the distance is above the threshold, move according to the direction */
        if(myDir == CENTER){
            /* forward */
            xSemaphoreTake(xSemaphore,portMAX_DELAY);
            Motors_set_direction(FORWARD);
            xSemaphoreGive(xSemaphore);

        }else if(myDir == RIGHT){
            /* right */
            xSemaphoreTake(xSemaphore,portMAX_DELAY);
            Motors_set_direction(RIGHTT);
            xSemaphoreGive(xSemaphore);

        }else if(myDir == LEFT){
            /* left */
            xSemaphoreTake(xSemaphore,portMAX_DELAY);
            Motors_set_direction(LEFTT);
            xSemaphoreGive(xSemaphore);
        }

        uint16_t x2 = xTaskGetTickCount();
        uint16_t res = (x2 * portTICK_PERIOD_MS) - (x1 * portTICK_PERIOD_MS);

        /* Delay until the specified time interval has passed */
        vTaskDelayUntil(&xLastWakeTime, 20);

    }
}

/*
 * Description:
 * This task is intentionally empty, only calling vTaskSuspendAll(). to stop the system
 * when the temperature exceeds a predefined threshold.
 */
void TS_Update(void * pvParameters)
{
    while(1)
    {

        /* stop the motors */
        Motors_set_direction(STOP);

        /* Clear the LCD screen */
        LCD_Clear();

        /* Print warning message */
        LCD_GoToString(1,0, "High Temp Alert");

        /* Show the message for 3 seconds */
        delay_ms(3000);

        /* Clear the LCD screen */
        LCD_Clear();

        /* Stop the system */
        vTaskSuspendAll();
    }
}
