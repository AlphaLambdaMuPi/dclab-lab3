/*
 * lcd_core.h
 *
 *  Created on: Nov 27, 2015
 *      Author: alpha
 */

#ifndef LCD_CORE_H_
#define LCD_CORE_H_

#include "global.h"
#include "altera_up_avalon_video_pixel_buffer_dma.h"
#include "typedef.h"
#include "altera_avalon_spi.h"

extern uchar arial22bm[];
extern int arial22cnt[];
extern int arial22pos[][5];

namespace LCD {
  struct Color{
    int r, g, b;
    bool unset;
    Color();
    Color(int _r, int _g, int _b);
    int toInt();
    operator int();
    Color operator | (const Color &c) const;
    Color blend(Color, int);
  };

  void init();
  void clear();
  int render(char, int, int);
  void renders(const char*, int, int);
  void test();
  void swap_buffer();
  void draw_pixel(int, int, int);
  void draw_box(int, int, int, int, int);
  void draw_line(int, int, int, int, int);
  bool check_cursor(int&, int&);

}



#endif /* LCD_CORE_H_ */
