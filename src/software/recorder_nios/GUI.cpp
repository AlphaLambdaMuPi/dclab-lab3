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
  Slider audio_slider, speed_slider;
  Button btn_pause, btn_speed_reset;
  Text audio_time, speed_text;
  StateButton btn_loop;
  Choicer bot_row;
  StateButton btn_inter0, btn_inter1;

  int cur_state = 0;
  bool loop = false;

  void pause_btn_handler() {
    if (cur_state == 1) {
      cur_state = 4;
      Audio::pause();
      btn_pause.set_text("Resume");
    }
    else if (cur_state == 4) {
      cur_state = 1;
      Audio::resume();
      btn_pause.set_text("Pause");
    }
  }

  void audio_stop_handler() {
    if (loop) {
      Audio::start_write(audio_buffer, audio_len);
    } else {
      cur_state = 0;
      top_row.value_change(0);
    }
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

  const int speeds[] = {4, 8, 16, 24, 32, 64, 96, 160, 320};
  const char * const speed_desc[] = {
    "1/8x", "1/4x", "1/2x", "2/3x", "1x",
    "2x", "3x", "4x", "5x"
  };

  void audio_set_speed(int v) {
    Audio::speed = speeds[v];
    speed_text.set_text(speed_desc[v]);
  }

  void speed_reset_btn_handler() {
    audio_set_speed(4);
    speed_slider.value = 0.5;
  }

  void time_slider_handler(double value) {
    printf("ts = %lf", value);
    Audio::write_ptr = audio_len * value;
  }

  void speed_slider_handler(double value) {
    printf("%lf", value);
    int v = (value * 9) + 0.5;
    audio_set_speed(v);
  }

  void loop_btn_handler() {
    loop = not loop;
    btn_loop.toggle_state();
  }

  void choicer_top_handler(int val) {
    if (cur_state == 1)
      Audio::stop_write();
    else if (cur_state == 2)
      audio_len = Audio::stop_read();

    if (val == 2) {
      Audio::start_read(audio_buffer, AUDIO_BUF_LEN);
    } else if (val == 1) {
      if (cur_state == 4)
        Audio::resume();
      else
        Audio::start_write(audio_buffer, audio_len);
    }
    cur_state = val;
  }

  void choicer_bot_handler(int val) {
    Audio::interp_type = val;
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

    Color dark_gray = {40, 40, 40};
    Color white = {255, 255, 255};

    btn_pause = Button(0, 100, 200, 100, "Pause", {255, 255, 255}, dark_gray);
    Root.add_child(&btn_pause);
    btn_pause.set_click_handler(&pause_btn_handler);

    audio_slider = Slider(200, 100, 400, 100);
    audio_slider.set_ball_color({254, 153, 0})
      .set_active_color({255, 0, 0}).set_color({180, 180, 180}).set_bgcolor(dark_gray);
    audio_slider.set_handler(time_slider_handler);
    Root.add_child(&audio_slider);

    audio_time = Text(600, 100, 200, 100, "0:00/0:00", white);
    audio_time.set_bgcolor(dark_gray);
    Root.add_child(&audio_time);

    btn_speed_reset = Button(0, 220, 200, 100, "Reset speed", white, dark_gray);
    Root.add_child(&btn_speed_reset);
    btn_speed_reset.set_click_handler(&speed_reset_btn_handler);

    speed_slider = Slider(200, 220, 400, 100);
    speed_slider.set_value(0.5).set_ball_color({254, 153, 0})
      .set_active_color({255, 0, 0}).set_color({180, 180, 180}).set_bgcolor(dark_gray);
    speed_slider.set_handler(&speed_slider_handler); Root.add_child(&speed_slider); 
    speed_text = Text(600, 220, 200, 100, "x1", white);
    speed_text.set_bgcolor(dark_gray);
    Root.add_child(&speed_text);

    btn_loop = StateButton(0, 320, 200, 100, "loop", white, dark_gray, {0, 80, 20});
    btn_loop.set_state(0).set_click_handler(loop_btn_handler);
    Root.add_child(&btn_loop);

    btn_inter0.set_bgcolor({255, 0, 0});

    bot_row = Choicer(200, 320, 600, 100);
    bot_row.add_child(&btn_inter0).add_child(&btn_inter1);
    bot_row.calc();
    btn_inter0.set_bgcolor_active({200, 200, 200})
      .set_bgcolor_inactive({120, 120, 120}).set_text("0th order Interp").set_bgcolor({120, 120, 120});
    btn_inter0.set_state(1);
    btn_inter1.set_bgcolor_active({200, 200, 200})
      .set_bgcolor_inactive({120, 120, 120}).set_text("1th order Interp").set_bgcolor({120, 120, 120});

    bot_row.set_handler(choicer_bot_handler);

    Root.add_child(&bot_row);
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


