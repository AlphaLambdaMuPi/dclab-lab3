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

  Color::Color() : unset(true) { }
  Color::Color(int _r, int _g, int _b) : r(_r), g(_g), b(_b), unset(false) {}

  int Color::toInt() {
    return ((r >> 3) << 11) +
      ((g >> 3) << 6) +
      ((b >> 3));
  }
  Color::operator int() {
    return toInt();
  }
  Color Color::operator | (const Color &c) const {
    if (unset) return (c.unset ? Color(255, 255, 255) : c);
    return (*this);
  }

  Color Color::blend(Color bgcolor, int alpha) {
    int bga = 255 - alpha;
    int _r = (r*alpha + bgcolor.r*bga) / 255;
    int _g = (g*alpha + bgcolor.g*bga) / 255;
    int _b = (b*alpha + bgcolor.b*bga) / 255;
    return {_r, _g, _b};
  }

  void draw_pixel(int x, int y, int color) {
    if (x < 0 or x >= 800 or y < 0 or y >= 480) return;
    alt_up_pixel_buffer_dma_draw(dev, color, x, y);
  }

  void draw_box(int x1, int y1, int x2, int y2, int color) {
    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);
    alt_up_pixel_buffer_dma_draw_box(dev, x1, y1, x2, y2, color, 1);
  }

  void draw_line(int x1, int y1, int x2, int y2, int color) {
    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);
    alt_up_pixel_buffer_dma_draw_line(dev, x1, y1, x2, y2, color, 1);
  }

  void test() {
    for (int i=0; i<10; i++) {
      for (int j=0; j<10; j++) {
        draw_pixel(i, j, 65535);
      }
    }
  }


  void swap_buffer() {
    alt_up_pixel_buffer_dma_swap_buffers(dev);
  }

  const int screen_width = 800;
  const int screen_height = 480;
  bool check_cursor(int &x, int &y) {
    bool res = IORD(PIO_TOUCH_BASE, 0); 
    if (res) return false;
    uchar tx = 0x92, ty = 0xD2;
    alt_avalon_spi_command(SPI_TOUCH_BASE, 0, 1, &tx, 0, 0, 1);
    alt_avalon_spi_command(SPI_TOUCH_BASE, 0, 0, 0, 1, &tx, 0);
    alt_avalon_spi_command(SPI_TOUCH_BASE, 0, 1, &ty, 0, 0, 1);
    alt_avalon_spi_command(SPI_TOUCH_BASE, 0, 0, 0, 1, &ty, 0);
    x = (ty - 4) * screen_width / 119;
    y = screen_height - (tx - 7) * screen_height / 112;
    return true;
  }

}


