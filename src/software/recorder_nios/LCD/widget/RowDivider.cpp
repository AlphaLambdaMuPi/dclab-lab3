/*
 * RowDivider.cpp
 *
 *  Created on: Dec 1, 2015
 *      Author: alpha
 */

#include "RowDivider.h"

namespace LCD {
namespace Window {

RowDivider::RowDivider() {
	// TODO Auto-generated constructor stub
  margin = 0;
}

RowDivider::RowDivider(POS_INFO) : Renderable(x, y, width, height) {
	// TODO Auto-generated constructor stub
  margin = 0;
}

RowDivider::~RowDivider() {
	// TODO Auto-generated destructor stub
}

RowDivider& RowDivider::add_child(Renderable* child) {
  add_child(child, 1.0);
  return (*this);
}

RowDivider& RowDivider::add_child(Renderable* child, double _per) {
  children.push_back(child);
  pers.push_back(_per);
  return (*this);
}

RowDivider& RowDivider::calc() {
  int cc = children.size();
  if (not cc) return (*this);
  double w = width - margin * cc;
  double total = 0.0;
  for (auto x: pers)
    total += x;
  if (total <= 1e-6) return (*this);
  double curx = 0.0 + margin;
  for (int i=0; i<cc; i++) {
    double tw = w * pers[i] / total;
    children[i]->set_x((int)curx);
    children[i]->set_y(0);
    children[i]->set_width((int)tw);
    printf("tw = %.6f\n", tw);
    children[i]->set_height(height);
    curx += tw + margin;
  }
  return (*this);
}

void RowDivider::render(int tx, int ty, Color parent_bgcolor) {
  Renderable::render(tx, ty, parent_bgcolor);
  int rx = rx + x, ry = ty + y;
  for (auto child: children)
    child->render(rx, ry, bgcolor | parent_bgcolor);
}

} /* namespace Window */
} /* namespace LCD */
