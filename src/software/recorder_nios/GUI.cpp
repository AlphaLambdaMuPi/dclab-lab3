/*
 * GUI.cpp
 *
 *  Created on: Dec 1, 2015
 *      Author: alpha
 */

#include "GUI.h"


namespace GUI {

  const int AUDIO_BUF_LEN = 48000 * 120;
  ushort audio_buffer[AUDIO_BUF_LEN];
  int audio_len;

  Choicer top_row;
  StateButton btn_stop, btn_play, btn_record;
  Slider audio_slider;
  Button btn_pause, btn_reset;
  Text audio_time;

  void btn_b1_handler() {
    printf("Button #1\n");
  }

  int cur_state = 0;
  void audio_stop_handler() {
    cur_state = 0;
    top_row.value_change(0);
  }

  void set_audio_time(int s1, int s2) {
    double r = 1.0 * s1 / s2;
    audio_slider.set_value(r);
    int m1 = s1 / 60; s1 %= 60;
    int m2 = s2 / 60; s2 %= 60;
    char t[20];
    sprintf(t, "%d:%02d/%d:%02d", m1, s1, m2, s2);
    audio_time.set_text(t);
  }

  void choicer_top_handler(int val) {
    if (cur_state == 1)
      Audio::stop_write();
    else if (cur_state == 2)
      audio_len = Audio::stop_read();

    if (val == 2) {
      Audio::start_read(audio_buffer, AUDIO_BUF_LEN);
    } else if (val == 1) {
      Audio::start_write(audio_buffer, audio_len);
    }
    cur_state = val;
  }

  void init() {
    Root.set_bgcolor({200, 220, 255});
    btn_stop.set_bgcolor_active({255, 0, 0})
      .set_bgcolor_inactive({230, 180, 180}).set_text("Stop").set_bgcolor({230, 180, 180});
    btn_stop.set_state(1);
    btn_play.set_bgcolor_active({0, 255, 0})
      .set_bgcolor_inactive({180, 230, 180}).set_text("Play").set_bgcolor({180, 230, 180});
    btn_record.set_bgcolor_active({0, 0, 255})
      .set_bgcolor_inactive({180, 180, 230}).set_text("Record").set_bgcolor({180, 180, 230});
    top_row = Choicer(0, 0, 800, 100);
    top_row.add_child(&btn_stop).add_child(&btn_play).add_child(&btn_record);
    top_row.calc();
    top_row.set_handler(choicer_top_handler);
    Audio::stop_handler = audio_stop_handler;
    Root.add_child(&top_row);

    btn_pause = Button(0, 100, 200, 100, "Pause", {255, 255, 255}, {60, 60, 60});
    Root.add_child(&btn_pause);

    audio_slider = Slider(200, 100, 400, 100);
    audio_slider.set_ball_color({254, 153, 0})
      .set_active_color({255, 0, 0}).set_color({180, 180, 180}).set_bgcolor({60, 60, 60});
    Root.add_child(&audio_slider);

    audio_time = Text(600, 100, 200, 100, "0:00/0:00", {255, 255, 255});
    audio_time.set_bgcolor({60, 60, 60});
    Root.add_child(&audio_time);
  }

  void task() {
    if (cur_state == 1) {
      set_audio_time(Audio::write_ptr/48000, audio_len/48000);
    } else if (cur_state == 2) {
      set_audio_time(Audio::read_ptr/48000, AUDIO_BUF_LEN/48000);
    }
    LCD::Window::root_render();
  }
}


