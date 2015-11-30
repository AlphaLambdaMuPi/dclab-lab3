/*
 * Button.h
 *
 *  Created on: Nov 30, 2015
 *      Author: alpha
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include "Widget.h"
#include "../lcd_core.h"
#include <cstring>

namespace LCD {
namespace Window {

class Button: public Widget {
  void (*click_handler)(void);
public:
  char text[MAX_STRLEN];
  Color color, bgcolor;
	Button();
	Button(int, int, int, int, char*, Color bgcolor, Color color={0, 0, 0});
	virtual ~Button();
  virtual void render();
  virtual bool onMouseUp(int, int);
  void set_click_handler(void (*f)(void));
};

} /* namespace Window */
} /* namespace LCD */

#endif /* BUTTON_H_ */
