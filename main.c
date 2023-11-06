/*******************************************************************************
 *                                                                             *
 * [FILE NAME]:   main.c                                                       *
 *                                                                             *
 * [AUTHOR]:      Ahmed Saeed, Mohamed Teleb, Hossam Mostafa,                  *
 *                Amr Hafez, Marco Ashraf, and Muhammed ALsahfie               *
 *                                                                             *
 * [Version]:     1.0.0                                                        *
 *                                                                             *
 * [DATE]:        28/09/2023                                                   *
 *                                                                             *
 * [DESCRIPTION]: source file for the Application                              *
 *                                                                             *
 *******************************************************************************/

/*******************************************************************************
 *                                 Includes                                    *
 *******************************************************************************/
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "queue.h"
#include "SWCsIncludes.h"
#include "SWC1.h"
#include "SWC2.h"
#include "SWC3.h"
#include "SWC4.h"

/* Queue handlers */
QueueHandle_t xQueue1;
QueueHandle_t xQueue2;
QueueHandle_t xQueue3;
QueueHandle_t xQueue4;
QueueHandle_t xQueue5;

/* Semaphore handler */
SemaphoreHandle_t xSemaphore;

/* Task handlers */
TaskHandle_t LDRHandle;
TaskHandle_t TSHandle;
TaskHandle_t LCDHandle;

int main()
{
    /* Create queues */
    xQueue1 = xQueueCreate( 2, sizeof(ldr_val) );
    xQueue2 = xQueueCreate( 2, sizeof(uint16_t) );
    xQueue3 = xQueueCreate( 2, sizeof(uint16_t) );
    xQueue4 = xQueueCreate( 2, sizeof(uint8_t) );
    xQueue5 = xQueueCreate( 2, sizeof(uint16_t) );

    /* Create semaphore */
    vSemaphoreCreateBinary(xSemaphore);

    /* Task to initialize the modules then suspend itself */
    xTaskCreate(&ModulesInit, "ModulesInit", 128, NULL, 9, NULL);

    /* Task to check if switch is pressed or not */
    xTaskCreate(&SwitchCheck, "SwitchCheck", 128, NULL, 7, NULL);

    /* Task to read the ultrasonic value */
    xTaskCreate(&Ultrasonic_Read, "Ultrasonic_Read", 128, NULL, 6, NULL);

    /* Task to read the LDR value */
    xTaskCreate(&LDR_Read, "LDR_Read", 128, NULL, 4, NULL);

    /* Task to read the temperature sensor value */
    xTaskCreate(&TempSensor_Read, "TempSensor_Read", 128, NULL, 2, NULL);

    /* Task to take action based on ultrasonic readings */
    xTaskCreate(&Ultrasonic_Update, "Ultrasonic_Update", 128, NULL,5, NULL);

    /* Task to take action based on LDR readings */
    xTaskCreate(&LDR_Update, "LDR_Update", 128, NULL, 3, &LDRHandle);

    /* Task to take action based on temperature sensor readings */
    xTaskCreate(&TS_Update, "TS_Update", 128, NULL, 8, &TSHandle);
		
    /* Suspend the task from the beggining */
    vTaskSuspend(TSHandle);

    /* Task to print the readings on LCD */
    xTaskCreate(&LCD_Print, "LCD_Print", 128, NULL, 1, &LCDHandle);

    /* Start the FreeRTOS scheduler */
    vTaskStartScheduler();

    while (1) {
        /* The scheduler handles tasks, so this loop should be empty */
    }
}

