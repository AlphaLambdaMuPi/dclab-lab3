/*
 * StateButton.cpp
 *
 *  Created on: Dec 1, 2015
 *      Author: alpha
 */

#include "StateButton.h"

namespace LCD {
namespace Window {

StateButton::StateButton() {
	// TODO Auto-generated constructor stub

}

StateButton::~StateButton() {
	// TODO Auto-generated destructor stub
}

StateButton::StateButton(POS_INFO, string s, Color color, Color bgcolor, Color bgcolor2)
  : Renderable(x, y, width, height), Button(x, y, width, height, s, color, bgcolor),
  bgcolor_inactive(bgcolor), bgcolor_active(bgcolor2) {
	// TODO Auto-generated destructor stub
}

StateButton& StateButton::set_state(int st) {
  state = st;
  if (st) {
    set_bgcolor(bgcolor_active);
  } else {
    set_bgcolor(bgcolor_inactive);
  }
  return (*this);
}

void StateButton::toggle_state() {
  set_state(!state);
}

bool StateButton::onMouseEvent(MouseEvent e) {
  // printf("%d\n", e.event_type);
  if(e.event_type == 2) {
    Button::onMouseEvent(e);
    return true;
    // toggle_state();
  }
}

} /* namespace Window */
} /* namespace LCD */
