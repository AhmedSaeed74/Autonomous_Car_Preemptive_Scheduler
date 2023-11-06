/*******************************************************************************
 *                                                                             *
 * [FILE NAME]:   SWC4.c                                                       *
 *                                                                             *
 * [AUTHOR]:      Ahmed Saeed, Mohamed Teleb, Hossam Mostafa,                  *
 *                Amr Hafez, Marco Ashraf, and Muhammed ALsahfie               *
 *                                                                             *
 * [Version]:     1.0.0                                                        *
 *                                                                             *
 * [DATE]:        28/09/2023                                                   *
 *                                                                             *
 * [DESCRIPTION]: source file for The fourth software component                *
 *                                                                             *
 *******************************************************************************/

/*******************************************************************************
 *                                 Includes                                    *
 *******************************************************************************/
#include "SWC4.h"
#include "SWCsIncludes.h"
#include "LCD.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
/* Declare an external queues handlers */
extern QueueHandle_t xQueue4;
extern QueueHandle_t xQueue2;
extern QueueHandle_t xQueue5;

/* Declare an external task handler */
extern TaskHandle_t LCDHandle;

/*
 * Description:
 * The LCD_Print task continuously retrieves sensor data from queues 
 * and displays it on an LCD screen.
 * It shows the distance, direction, and temperature on the screen.
 */
void LCD_Print(void * pvParameters){
    /* Initialize the tick count variables */
    TickType_t xLastWakeTime;

    /* Initialize variables to hold sensor data */
    uint16_t distance = 0;

    uint8_t myDir;

    uint16_t temp = 0;

    while(1){
        /* Get the current system tick count */
        xLastWakeTime = xTaskGetTickCount();

        uint16_t x1 = xTaskGetTickCount();
        
        //vTaskPrioritySet(LCDHandle, 8);
        /* Receive data from the queues */
        xQueueReceive( xQueue5, &( distance ),( TickType_t ) portMAX_DELAY );

        if(distance < 10)
        {
            myDir = CENTER;
        }

        else
        {
            xQueueReceive( xQueue4, &( myDir ),( TickType_t ) portMAX_DELAY );
        }

        xQueueReceive( xQueue2, &( temp ),( TickType_t ) portMAX_DELAY );

        /* Display distance value */
        LCD_GoTo(1, 9);
        LCD_SendString("     ");
        LCD_GoTo(1, 9);
        if(distance == 99)
        {
            LCD_SendString("CLEAR");
        }

        else
        {
            LCD_Write_Int(distance);
        }

        /* Display direction based on myDir value */
        LCD_GoTo(2, 4);
        LCD_SendString("      ");
        LCD_GoTo(2, 4);

        if(myDir == CENTER){
            LCD_SendString("CENTER");
        }else if(myDir == RIGHT){
            LCD_SendString("RIGHT");
        }else if(myDir == LEFT){
            LCD_SendString("LEFT");
        }


        uint16_t x2 = xTaskGetTickCount();
        uint16_t res = (x2 * portTICK_PERIOD_MS) - (x1 * portTICK_PERIOD_MS);
        //vTaskPrioritySet(LCDHandle, 2);
				
				while(res < 111)
				{
				  res = (xTaskGetTickCount() * portTICK_PERIOD_MS) - (x1 * portTICK_PERIOD_MS);
				}

        /* Delay until the specified time interval has passed */
        vTaskDelayUntil(&xLastWakeTime, 200);
    }
}
