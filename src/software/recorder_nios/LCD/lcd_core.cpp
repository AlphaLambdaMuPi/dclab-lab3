/*
 * lcd_core.cpp
 *
 *  Created on: Nov 27, 2015
 *      Author: alpha
 */

#include "lcd_core.h"
#include "widget/Widget.h"
#include "io.h"
#include "altera_avalon_spi.h"

namespace LCD {
  alt_up_pixel_buffer_dma_dev *dev;

  void init() {
    dev = alt_up_pixel_buffer_dma_open_dev("/dev/video_pixel_buffer_dma");
    clear();
  }

  void clear() {
    alt_up_pixel_buffer_dma_clear_screen(dev, 0);
  }

  Color::Color() {}
  Color::Color(int _r, int _g, int _b) : r(_r), g(_g), b(_b) {}
  int Color::toInt() {
    return ((r >> 3) << 11) +
      ((g >> 3) << 6) +
      ((b >> 3));
  }

  Color::operator int() {
    return toInt();
  }

  Color Color::blend(Color bgcolor, int alpha) {
    int bga = 255 - alpha;
    int _r = (r*alpha + bgcolor.r*bga) / 255;
    int _g = (g*alpha + bgcolor.g*bga) / 255;
    int _b = (b*alpha + bgcolor.b*bga) / 255;
    return {_r, _g, _b};
  }

  static int draw_pixel(int x, int y, int color) {
    alt_up_pixel_buffer_dma_draw(dev, color, x, y);
  }

  void draw_box(int x1, int y1, int x2, int y2, int color) {
    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);
    alt_up_pixel_buffer_dma_draw_box(dev, x1, y1, x2, y2, color, 1);
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
  bool check_click(int &x, int &y) {
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

  namespace Window {
    Color bgcolor;
    const int MAX_WIDGET = 10;
    int widget_count = 0;
    Widget* widgets[MAX_WIDGET];

    void set_bgcolor(Color c) {
      bgcolor = c;
    }

    bool cursor_down = false;
    int cursor_x, cursor_y;
    static void handle_cursor() {
      bool res = LCD::check_click(cursor_x, cursor_y);
      if (cursor_down == res and (not res)) return;

      int type = (!res ? 3 :
          cursor_down ? 2 : 1);

      cursor_down = res;
      int x = cursor_x, y = cursor_y;
      draw_box(x-5, y-5, x+5, y+5, Color{255, 0, 0});

      for (int i=0; i<widget_count; i++) {
        Widget *w = widgets[i];
        int x1 = w->x, y1 = w->y, x2 = x1 + w->width, y2 = y1 + w->height;
        if (x1 <= x and x <= x2 and y1 <= y and y <= y2) {
          int tx = x - x1, ty = y - y1;
          if (type == 1) {
            if (w->onMouseDown(tx, ty)) break;
          } else if (type == 2) {
            if (w->onMouseMove(tx, ty)) break;
          } else {
            if (w->onMouseUp(tx, ty)) break;
          }
        }
      }
    }

    void render() {
      // Draw bgcolor
      draw_box(0, 0, 800, 480, bgcolor);
      draw_box(0, 0, 10, 10, Color{255, 0, 0});
      draw_box(790, 470, 800, 480, Color{255, 0, 0});
      handle_cursor();

      for (int i=0; i<widget_count; i++) {
        widgets[i]->render();
      }
      swap_buffer();
    }

    void push_widget(Widget *w) {
      widgets[widget_count++] = w;
    }

    const int FONT_HEIGHT = 20;
#define font_buffer arial22bm
#define font_cnt arial22cnt
#define font_pos arial22pos
    int get_char_width(char c) {
      if (c == ' ') return 8;
      int id = c - 33;
      int *pos = font_pos[id];
      int adv = pos[4];
      return adv;
    }

    int get_string_width(char *s) {
      int i = 0, ret = 0;
      while (s[i]) {
        ret += get_char_width(s[i++]);
      }
      return ret;
    }

    int draw_char(char c, int x, int y, Color fgcolor, Color bgcolor) {
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
          draw_pixel(sx+j, sy+i, fgcolor.blend(bgcolor, d));
        }
      }
      return adv;
    }

    void draw_string(char *s, int x, int y, Color fgcolor, Color bgcolor) {
      int i = 0;
      while (s[i])
        x += draw_char(s[i++], x, y, fgcolor, bgcolor);
    }
  }
}


