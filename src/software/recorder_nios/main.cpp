/*
 * main.cpp
 *
 *  Created on: Nov 27, 2015
 *      Author: alpha
 */

#include <stdio.h>
#include "includes.h"
#include "audio/audio_core.h"
#include "LCD/lcd_core.h"

/* Definition of Task Stacks */
#define   TASK_STACKSIZE       2048
OS_STK    task1_stk[TASK_STACKSIZE];
OS_STK    task2_stk[TASK_STACKSIZE];

/* Definition of Task Priorities */

#define TASK1_PRIORITY      2
#define TASK2_PRIORITY      1

/* Prints "Hello World" and sleeps for three seconds */
void task1(void* pdata)
{
  while (1)
  { 
    Audio::read();
    OSTimeDlyHMSM(0, 0, 0, 0);
  }
}
/* Prints "Hello World" and sleeps for three seconds */
void task2(void* pdata)
{
  while (1)
  { 
    //LCD::renders("Hao123 a day keeps your homepage away.", 100, 100);
    OSTimeDlyHMSM(0, 0, 1, 0);
  }
}
/* The main function creates two task and starts multi-tasking */
int main(void)
{
  printf("%s\n", "Hello Nios!\n");
  Audio::init();
  LCD::init();
  LCD::test();
  LCD::renders("Hao123 a day keeps your homepage away.", 100, 100);
  OSTaskCreateExt(task1,
                  NULL,
                  (OS_STK *)&task1_stk[TASK_STACKSIZE-1],
                  TASK1_PRIORITY,
                  TASK1_PRIORITY,
                  task1_stk,
                  TASK_STACKSIZE,
                  NULL,
                  0);
              
               
  OSTaskCreateExt(task2,
                  NULL,
                  (OS_STK *)&task2_stk[TASK_STACKSIZE-1],
                  TASK2_PRIORITY,
                  TASK2_PRIORITY,
                  task2_stk,
                  TASK_STACKSIZE,
                  NULL,
                  0);
  OSStart();
  return 0;
}


