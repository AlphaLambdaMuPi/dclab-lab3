/*
 * Button.h
 *
 *  Created on: Nov 30, 2015
 *      Author: alpha
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include "LCD/widget/Renderable.h"
#include "LCD/widget/Clickable.h"
#include "LCD/window.h"
#include "LCD/lcd_include.h"
#include <cstring>

namespace LCD {
namespace Window {

class Button: public Widget, public Clickable {
  void (*click_handler)(void);
public:
  SETTER(string, text);
	Button();
	Button(int, int, int, int, string, Color bgcolor, Color color={160, 160, 160});
	virtual ~Button();
  virtual void render(int, int, Color);
  virtual bool onMouseEvent(MouseEvent e);
  void set_click_handler(void (*f)(void));
};

} /* namespace Window */
} /* namespace LCD */

#endif /* BUTTON_H_ */
