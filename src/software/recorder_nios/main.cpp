/*
 * main.cpp
 *
 *  Created on: Nov 27, 2015
 *      Author: alpha
 */

#include "includes.h"
#include "global.h"
#include "audio/audio_core.h"
#include "GUI.h"
#include "LCD/lcd_core.h"

/* Definition of Task Stacks */
const int TASK_STACKSIZE = 2048;
/* GUI Task */
OS_STK    GUI_stack[TASK_STACKSIZE];
const int GUI_TASK_PRIORITY = 1;

void GUITask(void* pdata)
{
  while (1) { 
    GUI::task();
    OSTimeDlyHMSM(0, 0, 0, 10);
  }
}

int main()
{
  printf("Hello Nios\n");
  Audio::init();
  LCD::init();
  GUI::init();
               
  OSTaskCreateExt(GUITask, NULL,
      (OS_STK*) &GUI_stack[TASK_STACKSIZE-1],
      GUI_TASK_PRIORITY, GUI_TASK_PRIORITY,
      GUI_stack, TASK_STACKSIZE,
      NULL, 0);
  OSStart();
  return 0;
}


