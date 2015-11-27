#include <stdio.h>
#include "includes.h"
#include "audio/audio_core.h"

/* Definition of Task Stacks */
#define   TASK_STACKSIZE       2048
OS_STK    task1_stk[TASK_STACKSIZE];
OS_STK    task2_stk[TASK_STACKSIZE];

/* Definition of Task Priorities */

#define TASK1_PRIORITY      1
#define TASK2_PRIORITY      2

/* Prints "Hello World" and sleeps for three seconds */
void task1(void* pdata)
{
  while (1)
  { 
    printf("Hello from task1\n");
    OSTimeDlyHMSM(0, 0, 2, 0);
  }
}
/* Prints "Hello World" and sleeps for three seconds */
void task2(void* pdata)
{
  while (1)
  { 
    printf("Hello from task2\n");
    OSTimeDlyHMSM(0, 0, 3, 0);
  }
}
/* The main function creates two task and starts multi-tasking */
int main(void)
{
  Audio::init();
  // OSTaskCreateExt(task1,
                  // NULL,
                  // (OS_STK *)&task1_stk[TASK_STACKSIZE-1],
                  // TASK1_PRIORITY,
                  // TASK1_PRIORITY,
                  // task1_stk,
                  // TASK_STACKSIZE,
                  // NULL,
                  // 0);
              
               
  // OSTaskCreateExt(task2,
                  // NULL,
                  // (OS_STK *)&task2_stk[TASK_STACKSIZE-1],
                  // TASK2_PRIORITY,
                  // TASK2_PRIORITY,
                  // task2_stk,
                  // TASK_STACKSIZE,
                  // NULL,
                  // 0);
  // OSStart();
  return 0;
}