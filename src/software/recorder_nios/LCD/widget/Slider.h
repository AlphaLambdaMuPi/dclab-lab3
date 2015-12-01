/*
 * Slider.h
 *
 *  Created on: Dec 1, 2015
 *      Author: alpha
 */

#ifndef SLIDER_H_
#define SLIDER_H_

#include "Clickable.h"
#include "Widget.h"
#include "LCD/window.h"

namespace LCD {
namespace Window {

class Slider: public Widget, public Clickable {
  void (*change_handler)(double);
public:
  SETTER(double, value);
  SETTER(Color, active_color);
  SETTER(Color, ball_color);
	Slider();
	Slider(POS_INFO);
	virtual ~Slider();
  void render(int, int, Color);
  void set_handler(void (*fun)(double));
  bool onMouseEvent(MouseEvent);
};

} /* namespace Window */
} /* namespace LCD */

#endif /* SLIDER_H_ */
