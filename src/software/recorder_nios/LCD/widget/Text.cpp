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
  draw_string(text, tx+x, ty+y-Window::FONT_HEIGHT, color, bgcolor | parent_bgcolor);
}

Text::~Text() {
	// TODO Auto-generated destructor stub
}

} /* namespace Window */
} /* namespace LCD */
