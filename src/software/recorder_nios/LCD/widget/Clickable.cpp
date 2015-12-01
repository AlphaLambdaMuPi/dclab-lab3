/*
 * Clickable.cpp
 *
 *  Created on: Dec 1, 2015
 *      Author: alpha
 */

#include "Clickable.h"

namespace LCD {
namespace Window {

Clickable::Clickable() {
	// TODO Auto-generated constructor stub

}

Clickable::~Clickable() {
	// TODO Auto-generated destructor stub
}


bool Clickable::_onMouseEvent(MouseEvent e) {
  if (x <= e.x and e.x <= x+width and y <= e.y and e.y <= y+height) {
    e.x -= x; e.y -= y;
    return onMouseEvent(e);
  }
  return false;
}

} /* namespace Window */
} /* namespace LCD */
