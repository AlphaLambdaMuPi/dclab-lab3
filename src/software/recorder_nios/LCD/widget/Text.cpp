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

Text::Text(int x, int y, int width, int height, char *s, Color _color)
  : Widget(x, y, width, height), color(_color) {
	// TODO Auto-generated constructor stub
    strcpy(text, s);
}

void Text::render() {
  draw_string(text, x, y+22, color);
}

Text::~Text() {
	// TODO Auto-generated destructor stub
}

void Text::set_text(char *s) {
  strcpy(text, s);
}

} /* namespace Window */
} /* namespace LCD */
