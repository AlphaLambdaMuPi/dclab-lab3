/*
 * window.cpp
 *
 *  Created on: Dec 1, 2015
 *      Author: alpha
 */

#include "LCD/window.h"

#define font_buffer comic32bm
#define font_cnt comic32cnt
#define font_pos comic32pos


namespace LCD {
  namespace Window {

    Container Root(0, 0, 800, 480);
    bool last_click = false;
    int last_x, last_y;

    void handle_cursor() {
      typedef Clickable::MouseEvent MouseEvent;
      int x, y;
      bool res = check_cursor(x, y);
      if (not last_click and not res)
        return;
      else if (not last_click)
        Root.onMouseEvent(MouseEvent{x, y, MouseEvent::MouseDown});
      else if (not res) {
        Root.onMouseEvent(MouseEvent{last_x, last_y, MouseEvent::MouseUp});
      } else
        Root.onMouseEvent(MouseEvent{x, y, MouseEvent::MouseMove});
      last_click = res;
      last_x = x; last_y = y;
    }

    void root_render() {
      handle_cursor();
      Root.render(0, 0, Color{255, 255, 255});
      swap_buffer();
    }

    const int FONT_HEIGHT = 20;
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

    int get_string_width(string s) {
      int ret = 0;
      for (auto c: s) {
        ret += get_char_width(c);
      }
      return ret;
    }

    int draw_circle(int x, int y, int r, int c) {
      int r2 = r * r;
      int tx = r;
      for (int i=0; i<=r; i++) {
        while (tx > 0 and tx * tx + i * i >= r2)
          tx --;

        draw_line(x - tx, y+i, x + tx, y+i, c);
        draw_line(x - tx, y-i, x + tx, y-i, c);
      }
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
    void draw_string(string s, int x, int y, Color fgcolor, Color bgcolor) {
      for (auto c: s)
        x += draw_char(c, x, y, fgcolor, bgcolor);
    }
  }
}
