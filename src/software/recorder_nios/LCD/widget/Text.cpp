/*
 * Text.cpp
 *
 *  Created on: Nov 30, 2015
 *      Author: alpha
 */

#include "Text.h"

namespace LCD {
namespace Window {

Text::Text() {
	// TODO Auto-generated constructor stub

}

Text::Text(int x, int y, int width, int height, string s, Color _color)
  : Renderable(x, y, width, height), color(_color), text(s) {
}

void Text::render(int tx, int ty, Color parent_bgcolor) {
  Renderable::render(tx, ty, parent_bgcolor);
  // draw_box(tx+x, ty+y, tx+x+width, ty+y+height, bgcolor);
  int mdx = tx+x + width / 2, mdy = ty+y + height / 2;
  int stx = mdx - Window::get_string_width(text)/2,
      sty = mdy + Window::FONT_HEIGHT/2;
  draw_string(text, stx, sty, color, bgcolor);
}

Text::~Text() {
	// TODO Auto-generated destructor stub
}

} /* namespace Window */
} /* namespace LCD */
