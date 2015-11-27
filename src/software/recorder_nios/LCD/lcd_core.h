/*
 * lcd_core.h
 *
 *  Created on: Nov 27, 2015
 *      Author: alpha
 */

#ifndef LCD_CORE_H_
#define LCD_CORE_H_

#include <cstdio>
#include "altera_up_avalon_video_pixel_buffer_dma.h"
#include "typedef.h"

extern uchar arial22bm[];
extern int arial22cnt[];
extern int arial22pos[][5];

namespace LCD {
  void init();
  void clear();
  int render(char, int, int);
  void renders(const char*, int, int);
  void test();
};



#endif /* LCD_CORE_H_ */
