/*
 * Slider.cpp
 *
 *  Created on: Dec 1, 2015
 *      Author: alpha
 */

#include "Slider.h"

namespace LCD {
namespace Window {

Slider::Slider() {
	// TODO Auto-generated constructor stub
  change_handler = NULL;
}

Slider::Slider(POS_INFO) : Renderable(x, y, width, height) {
	// TODO Auto-generated constructor stub
  change_handler = NULL;
}

Slider::~Slider() {
	// TODO Auto-generated destructor stub
}

bool Slider::onMouseEvent(MouseEvent e) {
  if (e.event_type == MouseEvent::MouseUp)
    return true;
  int x = e.x;
  set_value((0.0 + x) / width);
  return true;
}

void Slider::render(int tx, int ty, Color parent_bgcolor) {
  Renderable::render(tx, ty, bgcolor | parent_bgcolor);
  int rx = tx + x, ry = ty + y;
  int h2 = height / 2, h4 = height / 4;
  int cir_x = rx + (int)(value * width);
  draw_box(rx, ry + h4, cir_x, ry + h4+h2, active_color);
  draw_box(cir_x, ry + h4, rx + width, ry + h4+h2, color);
  draw_circle(cir_x, ry+h2, height/3, ball_color);
}

void Slider::set_handler(void (*fun)(double)) {
  change_handler = fun;
}

} /* namespace Window */
} /* namespace LCD */
