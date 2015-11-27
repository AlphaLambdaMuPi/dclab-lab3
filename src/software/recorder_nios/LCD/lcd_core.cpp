/*
 * lcd_core.cpp
 *
 *  Created on: Nov 27, 2015
 *      Author: alpha
 */

#include "lcd_core.h"

namespace LCD {
  alt_up_pixel_buffer_dma_dev *dev;
  void init() {
    dev = alt_up_pixel_buffer_dma_open_dev("/dev/video_pixel_buffer_dma");
    clear();
  }

  void clear() {
    alt_up_pixel_buffer_dma_clear_screen(dev, 0);
  }

  int rgb2color(uchar r, uchar g, uchar b) {
    return ((r >> 3) << 11) +
      ((g >> 3) << 6) +
      ((b >> 3));
  }

  static int draw_pixel(int x, int y, int color) {
    alt_up_pixel_buffer_dma_draw(dev, color, x, y);
  }

#define font_buffer arial22bm
#define font_cnt arial22cnt
#define font_pos arial22pos
  int render(char c, int x, int y) {
    if (c == ' ') return 8;
    int id = c - 33;
    int l = font_cnt[id];
    int *pos = font_pos[id];
    int width = pos[0], height = pos[1], 
        xshift = pos[2], yshift = pos[3], adv = pos[4];
    int sx = x + xshift, sy = y - yshift;
    for (int i=0; i<height; i++) {
      for (int j=0; j<width; j++) {
        uchar d = font_buffer[l + i*width + j];
        draw_pixel(sx+j, sy+i, rgb2color(d, d, d));
      }
    }
    return adv;
  }

  void test() {
    for (int i=0; i<100; i++) {
      for (int j=0; j<100; j++) {
        draw_pixel(i, j, 65535);
      }
    }
  }

  void renders(const char *s, int x, int y) {
    int i = 0;
    while (s[i])
      x += render(s[i++], x, y);
  }
};


