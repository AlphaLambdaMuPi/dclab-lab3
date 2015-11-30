/*
 * Button.cpp
 *
 *  Created on: Nov 30, 2015
 *      Author: alpha
 */

#include "Button.h"

namespace LCD {
namespace Window {

Button::Button() {
	// TODO Auto-generated constructor stub

}

Button::Button(int x, int y, int width, int height, char *label, 
    Color _bgcolor, Color _color)
  : Widget(x, y, width, height), bgcolor(_bgcolor), color(_color)  {
	// TODO Auto-generated constructor stub
  strcpy(text, label);
}

Button::~Button() {
	// TODO Auto-generated destructor stub
}

void Button::render() {
  draw_box(x, y, x+width, y+height, bgcolor);
  int mdx = x + width / 2, mdy = y + height / 2;
  int stx = mdx - Window::get_string_width(text)/2,
      sty = mdy + Window::FONT_HEIGHT/2;
  draw_string(text, stx, sty, color, bgcolor);
}

bool Button::onMouseUp(int x, int y) {
  if (click_handler) {
    click_handler();
  }
  return true;
}

void Button::set_click_handler(void (*fun)(void)) {
  click_handler = fun;
}

} /* namespace Window */
} /* namespace LCD */
