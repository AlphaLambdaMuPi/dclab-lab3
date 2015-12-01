/*
 * Widget.h
 *
 *  Created on: Dec 1, 2015
 *      Author: alpha
 */

#ifndef WIDGET_H_
#define WIDGET_H_

#include "LCD/widget/Renderable.h"
#include "LCD/lcd_include.h"

namespace LCD {
namespace Window {

class Widget: public virtual Renderable {
public:
  vector<Renderable*> children;
	Widget();
  Widget(POS_INFO);
  Widget& add_child(Renderable*);
  virtual void render(int, int, Color);
	virtual ~Widget();
};

} /* namespace Window */
} /* namespace LCD */

#endif /* WIDGET_H_ */
