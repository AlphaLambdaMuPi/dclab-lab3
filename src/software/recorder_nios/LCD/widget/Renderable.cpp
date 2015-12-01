/*
 * Widget.cpp
 *
 *  Created on: Nov 30, 2015
 *      Author: alpha
 */

#include "Renderable.h"

namespace LCD {
namespace Window {

Renderable::Renderable() {
	// TODO Auto-generated constructor stub

}

Renderable::Renderable(int _x, int _y, int _width, int _height)
  : x(_x), y(_y), width(_width), height(_height)
{
	// TODO Auto-generated constructor stub

}

Renderable::~Renderable() {
	// TODO Auto-generated destructor stub
}

void Renderable::render(int tx, int ty, Color parent_bgcolor) {
  if (bgcolor.unset) return;
  draw_box(tx+x, ty+y, tx+x+width, ty+y+height, bgcolor);
}

} /* namespace Window */
} /* namespace LCD */
