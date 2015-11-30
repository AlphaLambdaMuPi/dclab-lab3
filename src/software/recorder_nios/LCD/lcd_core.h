/*
 * lcd_core.h
 *
 *  Created on: Nov 27, 2015
 *      Author: alpha
 */

#ifndef LCD_CORE_H_
#define LCD_CORE_H_

#include <cstdio>
#include <algorithm>
#include "altera_up_avalon_video_pixel_buffer_dma.h"
#include "typedef.h"
#include "io.h"
#include "widget/Widget.h"

using std::swap;

extern uchar arial22bm[];
extern int arial22cnt[];
extern int arial22pos[][5];

namespace LCD {
  struct Color{
    int r, g, b;
    Color();
    Color(int _r, int _g, int _b);
    int toInt();
    operator int();
    Color blend(Color, int);
  };

  void init();
  void clear();
  int render(char, int, int);
  void renders(const char*, int, int);
  void test();
  void swap_buffer();
  void draw_box(int, int, int, int, int);
  bool check_click(int&, int&);

  namespace Window {
    extern Color bgcolor;
    extern const int FONT_HEIGHT;
    void push_widget(Widget*);
    void set_bgcolor(Color);
    void render();
    int draw_char(char, int, int,
        Color fgcolor={0, 0, 0}, Color bgcolor={255, 255, 255});
    void draw_string(char*, int, int,
        Color fgcolor={0, 0, 0}, Color bgcolor={255, 255, 255});
    int get_char_width(char);
    int get_string_width(char*);
  }
}



#endif /* LCD_CORE_H_ */
