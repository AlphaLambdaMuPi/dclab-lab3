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


bool Clickable::onMouseEvent(const MouseEvent &e) {
  // int ex = e.x, ey = e.y;
  // if (x <= ex and ex <= x+width and y <= ey and ey <= y+height) {
    // printf("%d\n", e.event_type);
  // }
  return false;
}

} /* namespace Window */
} /* namespace LCD */
