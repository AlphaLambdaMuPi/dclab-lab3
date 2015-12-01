/*
 * window.h
 *
 *  Created on: Dec 1, 2015
 *      Author: alpha
 */

#ifndef WINDOW_H_
#define WINDOW_H_

#include "global.h"
#include "LCD/lcd_core.h"
#include "LCD/widget/Widget.h"
#include "LCD/widget/Container.h"

namespace LCD {
  namespace Window {
    extern Container Root;
    extern const int FONT_HEIGHT;
    void root_render();
    int draw_char(char, int, int,
        Color fgcolor={0, 0, 0}, Color bgcolor={255, 255, 255});
    void draw_string(char*, int, int,
        Color fgcolor={0, 0, 0}, Color bgcolor={255, 255, 255});
    void draw_string(string, int, int,
        Color fgcolor={0, 0, 0}, Color bgcolor={255, 255, 255});
    int get_char_width(char);
    int get_string_width(char*);
    int get_string_width(string);
  }
}
#endif /* WINDOW_H_ */
