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
#include "LCD/widget/Text.h"
#include "LCD/widget/Button.h"


using LCD::Window::Text;
using LCD::Window::Button;

/* Definition of Task Stacks */
#define   TASK_STACKSIZE       2048
OS_STK    task1_stk[TASK_STACKSIZE];
OS_STK    task2_stk[TASK_STACKSIZE];

/* Definition of Task Priorities */

#define TASK1_PRIORITY      2
#define TASK2_PRIORITY      1

/* Prints "Hello World" and sleeps for three seconds */
const int MAX_AUDIO_BUF = 2000000;
ushort buf[MAX_AUDIO_BUF];
int buf_len;
void task1(void* pdata)
{
}
/* Prints "Hello World" and sleeps for three seconds */

Button *btn_play, *btn_rec;
Text *text_time;
bool is_recording = false;

void task2(void* pdata)
{
  using LCD::Color;
  while (1)
  { 
    LCD::Window::render();
    if (is_recording) {
      char s[20];
      sprintf(s, "%d", Audio::get_current_read() / 48000);
      text_time->set_text(s);
    }
    OSTimeDlyHMSM(0, 0, 0, 10);
  }
}


void play_btn_handler() {
  printf("start to play\n");
  Audio::start_write(buf, buf_len);
}

void rec_btn_handler() {
  if (not is_recording) {
    is_recording = true;
    printf("start to record\n");
    Audio::start_read(buf, MAX_AUDIO_BUF);
    btn_rec->bgcolor = {30, 180, 70};
  } else {
    is_recording = false;
    printf("stop record\n");
    buf_len = Audio::stop_read();
    btn_rec->bgcolor = {180, 180, 240};
    printf("recorded = %d\n", buf_len);
  }
}

int main()
{
  printf("Hello Nios!\n");
  Audio::init();
  Audio::speed = 5;
  LCD::init();
  LCD::test();
  LCD::Window::set_bgcolor({200, 200, 240});
  LCD::Window::push_widget(new Text(100, 50, 100, 400, "Hao123 a day!"));
  btn_play = new Button(100, 100, 50, 150, "Play", {180, 180, 240});
  btn_play->set_click_handler(play_btn_handler);
  LCD::Window::push_widget(btn_play);
  btn_rec = new Button(270, 100, 50, 150, "Record", {180, 180, 240});
  btn_rec->set_click_handler(rec_btn_handler);
  LCD::Window::push_widget(btn_rec);
  LCD::Window::push_widget(new Button(440, 100, 50, 150, "Settings", {180, 180, 240}));
  text_time = new Text(380, 230, 420, 250, "0:00");
  LCD::Window::push_widget(text_time);
  // OSTaskCreateExt(task1,
                  // NULL,
                  // (OS_STK *)&task1_stk[TASK_STACKSIZE-1],
                  // TASK1_PRIORITY,
                  // TASK1_PRIORITY,
                  // task1_stk,
                  // TASK_STACKSIZE,
                  // NULL,
                  // 0);
              
               
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


