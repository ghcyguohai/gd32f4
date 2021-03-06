#include "gd32f403.h"

#include "FreeRTOS.h"
#include "task.h"

#define START_TASK_PRIO		1
#define START_STK_SIZE 		256  

TaskHandle_t StartTask_Handler;
void start_task(void *pvParameters);



int main(void)
{
    //systick_config();
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
      vTaskDelay(10 / portTICK_PERIOD_MS);
		  /*test file */
		  /*feature 1 */
		  /*feature 2 */
		  /*feature 3 */
		  /*feature 4 */
		  /*this is a release version*/
		  /*this is a remote branch test */ 
		  /*this is a remote branch test2*/ 
		  /*this is a remote develop branch test2*/ 

		  /*this is a cooradinate test */ 
		  /*this is a cooradinate develop release test */ 



		  /*feature merge test 1*/
		  /*feature merge test 2*/
		  /*this is a coordinate develop release 2*/

  }
}








