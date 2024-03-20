#include <DAVE.h>  //Declarations from DAVE Code Generation (includes SFR declaration)

/* Kernel includes. */
#include "FREERTOS/task.h"

static void LED_Task0(void *pvParameters);
static void LED_Task1(void *pvParameters);
static void LED_Task2(void *pvParameters);

int main(void)
{
  DAVE_STATUS_t status;

  status = DAVE_Init();           /* Initialization of DAVE APPs  */

  if(status != DAVE_STATUS_SUCCESS)
  {
    while(1U)
    {
    }
  }


  /* Creating tasks defined within main.c */
  xTaskCreate(LED_Task0, "Task0", configMINIMAL_STACK_SIZE, NULL, (tskIDLE_PRIORITY + 1), NULL);
  xTaskCreate(LED_Task1, "Task1", configMINIMAL_STACK_SIZE, NULL, (tskIDLE_PRIORITY + 1), NULL);
  xTaskCreate(LED_Task2, "Task2", configMINIMAL_STACK_SIZE, NULL, (tskIDLE_PRIORITY + 1), NULL);

  /* Start the RTOS scheduler, this function should not return as it causes the execution
  context to change from main() to one of the created tasks. */
  vTaskStartScheduler();

  /* Should never reach here */
  return 0;
}



/* Task 1 to toggle LED0, ensure DIGITAL_IO_0 is configured and connected to LED0 */
static void LED_Task0(void *pvParameters)
{
  while(1)
  {
    DIGITAL_IO_ToggleOutput(&DIGITAL_IO_0);
    vTaskDelay(pdMS_TO_TICKS(1000)); // Delay for 1 second
    //one_minute_delay();
  }
}

/* Task 2 to toggle LED1, ensure DIGITAL_IO_1 is configured and connected to LED1 */
static void LED_Task1(void *pvParameters)
{
  while(1)
  {
    DIGITAL_IO_ToggleOutput(&DIGITAL_IO_1);
    vTaskDelay(pdMS_TO_TICKS(1000)); // Delay for 1 second
  }
}
static void LED_Task2(void *pvParameters)
{
  while(1)
  {
    DIGITAL_IO_ToggleOutput(&DIGITAL_IO_2);
    vTaskDelay(pdMS_TO_TICKS(1000)); // Delay for 1 second
  }
}
