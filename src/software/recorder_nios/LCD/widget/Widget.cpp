/*
 * Widget.cpp
 *
 *  Created on: Dec 1, 2015
 *      Author: alpha
 */

#include "Widget.h"

namespace LCD {
namespace Window {

Widget::Widget() {
	// TODO Auto-generated constructor stub

}

Widget::Widget(POS_INFO) : Renderable(x, y, width, height) {
}

Widget& Widget::add_child(Renderable* c) {
  children.push_back(c);
}

void Widget::render(int tx, int ty, Color parent_bgcolor) {
  if (not bgcolor.unset) {
    draw_box(tx+x, ty+y, tx+x+width, ty+y+height, bgcolor);
  }
  for (auto child: children) {
    child->render(tx+x, ty+y, bgcolor | parent_bgcolor);
  }
}

Widget::~Widget() {
	// TODO Auto-generated destructor stub
}

} /* namespace Window */
} /* namespace LCD */
