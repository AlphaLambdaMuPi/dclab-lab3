/*
 * Container.h
 *
 *  Created on: Dec 1, 2015
 *      Author: alpha
 */

#ifndef CONTAINER_H_
#define CONTAINER_H_

#include "Clickable.h"
#include "Widget.h"

namespace LCD {
namespace Window {

class Container: public Widget, public Clickable {
public:
	Container();
  Container(POS_INFO);
	virtual ~Container();
  virtual void render(int x, int y, Color c) {
    Widget::render(x, y, c);
  }
};

} /* namespace Window */
} /* namespace LCD */

#endif /* CONTAINER_H_ */
