/*
 * Widget.h
 *
 *  Created on: Nov 30, 2015
 *      Author: alpha
 */

#ifndef RENDERABLE_H_
#define RENDERABLE_H_

#include "global.h"
#include "LCD/lcd_core.h"
#include "LCD/lcd_include.h"

const int MAX_STRLEN = 200;

namespace LCD {
namespace Window {

class Renderable {
public:
  SETTER(int, x);
  SETTER(int, y);
  SETTER(int, width);
  SETTER(int, height);
  SETTER(Color, color);
  SETTER(Color, bgcolor);
	Renderable();
  Renderable(int, int, int, int);
	virtual ~Renderable();
  virtual void render(int, int, Color);
};

} /* namespace Window */
} /* namespace LCD */

#endif /* RENDERABLE_H_ */
