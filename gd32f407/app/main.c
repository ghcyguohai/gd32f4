#include "gd32f4xx.h"
#include "FreeRTOS.h"
#include "task.h"

#define START_TASK_PRIO		1
#define START_STK_SIZE 		128  

TaskHandle_t StartTask_Handler;
void start_task(void *pvParameters);



int main(void)
{
   // systick_config();
    xTaskCreate((TaskFunction_t )start_task,            
                (const char*    )"start_task",        
                (uint16_t       )START_STK_SIZE,       
                (void*          )NULL,                  
                (UBaseType_t    )START_TASK_PRIO,       
                (TaskHandle_t*  )&StartTask_Handler);          
    vTaskStartScheduler();      
}

void start_task(void *pvParameters)
{
  while(1)
  {
  
  }
}








