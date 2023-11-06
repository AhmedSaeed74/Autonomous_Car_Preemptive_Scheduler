/*******************************************************************************
 *                                                                             *
 * [FILE NAME]:   SWC2.c                                                       *
 *                                                                             *
 * [AUTHOR]:      Ahmed Saeed, Mohamed Teleb, Hossam Mostafa,                  *
 *                Amr Hafez, Marco Ashraf, and Muhammed ALsahfie               *
 *                                                                             *
 * [Version]:     1.0.0                                                        *
 *                                                                             *
 * [DATE]:        28/09/2023                                                   *
 *                                                                             *
 * [DESCRIPTION]: source file for The second software component                *
 *                                                                             *
 *******************************************************************************/

/*******************************************************************************
 *                                 Includes                                    *
 *******************************************************************************/
#include "SWC2.h"
#include "SWCsIncludes.h"
#include "Sensor.h"
#include "ultrasonic.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
/* Declare an external queue handle */
extern QueueHandle_t xQueue1;

/* Declare an external queue handle */
extern QueueHandle_t xQueue2;

/* Declare an external queue handle */
extern QueueHandle_t xQueue3;

/* External reference to the TaskHandle for TempSensor Task */
extern TaskHandle_t TSHandle;


/*
 * Description:
 * The Ultrasonic_Read task reads data from an ultrasonic sensor 
 * and sends it to a queue for further processing.
 */
void Ultrasonic_Read(void * pvParameters){
    /* Initialize the tick count variables */
    TickType_t xLastWakeTime;

    /* Ultrasonic sensor value */
    uint16_t usVal = 0;

    while(1){
        /* Get the current system tick count */
        xLastWakeTime = xTaskGetTickCount();

        uint16_t x1 = xTaskGetTickCount();

        /* Read sensors values */
        usVal = ultarsonic_get_value();


        /* Send the gathered data to the queue */
        xQueueSend(xQueue3, (void *)&usVal, 0);

        uint16_t x2 = xTaskGetTickCount();
        uint16_t res = (x2 * portTICK_PERIOD_MS) - (x1 * portTICK_PERIOD_MS);
			 
			  while(res < 4)
				{
				  res = (xTaskGetTickCount() * portTICK_PERIOD_MS) - (x1 * portTICK_PERIOD_MS);
				}

        /* Delay until the specified time interval has passed */
        vTaskDelayUntil(&xLastWakeTime, 25);

    }
}

/*
 * Description:
 * The LDR_Read task continuously gathers data from both left and 
 * right Light Dependent Resistors (LDRs).
 * It reads sensor values, assigns them to a data structure, 
 * and sends the data to a queue for further processing.
 */
void LDR_Read(void * pvParameters){
    /* Initialize the tick count variables */
    TickType_t xLastWakeTime;

    /* Data structure to store gathered data */
    ldr_val ldr_data;

    /* Left LDR value */
    uint16_t ldrLeftVal = 0;

    /* Right LDR value */
    uint16_t ldrRightVal = 0;

    while(1){
        /* Get the current system tick count */
        xLastWakeTime = xTaskGetTickCount();

        uint16_t x1 = xTaskGetTickCount();

        /* Read sensors values */
        ldrRightVal = LdrRight_Read();
        ldrLeftVal = LdrLeft_Read();

        /* Assign the left and right LDR values to the respective fields in the ldr_data structure */
        ldr_data.LEFT = ldrLeftVal;
        ldr_data.RIGHT = ldrRightVal;


        /* Send the gathered data to the queue */
        xQueueSend(xQueue1, (void *)&ldr_data, 0);


        uint16_t x2 = xTaskGetTickCount();
        uint16_t res = (x2 * portTICK_PERIOD_MS) - (x1 * portTICK_PERIOD_MS);

        /* Delay until the specified time interval has passed */
        vTaskDelayUntil(&xLastWakeTime, 50);

    }
}

/*
 * Description:
 * The TempSensor_Read task continuously gathers data from the temperature 
 * sensor. It reads temperature values,
 * checks if the value exceeds a threshold, and resumes 
 * another task (TSHandle) if the condition is met.
 * The temperature data is also sent to a queue for further processing.
 */
void TempSensor_Read(void * pvParameters){
    /* Initialize the tick count variables */
    TickType_t xLastWakeTime;

    /* Temperature sensor value */
    uint16_t tempVal = 0;

    while(1){
        /* Get the current system tick count */
        xLastWakeTime = xTaskGetTickCount();

        uint16_t x1 = xTaskGetTickCount();

        /* Read sensors values */
        tempVal = TS_Read();

        if(tempVal > 50)
        {
            vTaskResume(TSHandle);
        }

        /* Send the gathered data to the queue */
        xQueueSend(xQueue2, (void *)&tempVal, 0);

        uint16_t x2 = xTaskGetTickCount();
        uint16_t res = (x2 * portTICK_PERIOD_MS) - (x1 * portTICK_PERIOD_MS);

        /* Delay until the specified time interval has passed */
        vTaskDelayUntil(&xLastWakeTime, 50);

    }
}



