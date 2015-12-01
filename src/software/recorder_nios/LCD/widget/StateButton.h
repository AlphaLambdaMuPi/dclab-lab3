/*
 * StateButton.h
 *
 *  Created on: Dec 1, 2015
 *      Author: alpha
 */

#ifndef STATEBUTTON_H_
#define STATEBUTTON_H_

#include "Button.h"

namespace LCD {
namespace Window {

class StateButton: public Button {
  int state;
public:
  SETTER(Color, bgcolor_active);
  SETTER(Color, bgcolor_inactive);
	StateButton();
	StateButton(POS_INFO, string, Color color={0, 0, 0}, 
      Color bgcolor = {180, 180, 180}, Color bgcolor2={120, 120, 120});
  StateButton& set_state(int);
  void toggle_state();
  bool onMouseEvent(MouseEvent);
	virtual ~StateButton();
};

} /* namespace Window */
} /* namespace LCD */

#endif /* STATEBUTTON_H_ */
