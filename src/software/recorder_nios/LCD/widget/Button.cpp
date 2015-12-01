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

Button::Button(POS_INFO, string s, Color _color, Color _bgcolor)
  : Renderable(x, y, width, height), text(s) {
	// TODO Auto-generated constructor stub
  bgcolor = _bgcolor;
  color = _color;
}

Button::~Button() {
	// TODO Auto-generated destructor stub
  click_handler = NULL;
}

void Button::render(int tx, int ty, Color parent_bgcolor) {
  Renderable::render(tx, ty, parent_bgcolor);
  // draw_box(tx+x, ty+y, tx+x+width, ty+y+height, bgcolor);
  int mdx = tx+x + width / 2, mdy = ty+y + height / 2;
  int stx = mdx - Window::get_string_width(text)/2,
      sty = mdy + Window::FONT_HEIGHT/2;
  draw_string(text, stx, sty, color, bgcolor);
}

bool Button::onMouseEvent(MouseEvent e) {
  if (e.event_type == MouseEvent::MouseUp) {
    if (click_handler) {
      click_handler();
    }
  }
  return true;
}

void Button::set_click_handler(void (*fun)(void)) {
  click_handler = fun;
}

} /* namespace Window */
} /* namespace LCD */
