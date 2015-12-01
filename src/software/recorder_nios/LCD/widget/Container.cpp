/*
 * Container.cpp
 *
 *  Created on: Dec 1, 2015
 *      Author: alpha
 */

#include "Container.h"

namespace LCD {
namespace Window {

Container::Container() {
	// TODO Auto-generated constructor stub

}
Container::Container(POS_INFO) : Renderable(x, y, width, height)
{
}

Container::~Container() {
	// TODO Auto-generated destructor stub
}

bool Container::onMouseEvent(MouseEvent e) {
  for (const auto child: children) {
    Clickable* cast = dynamic_cast<Clickable*>(child);
    if (cast) {
      if (cast->_onMouseEvent(e))
        return true;
    }
  }
  return true;
}

} /* namespace Window */
} /* namespace LCD */
