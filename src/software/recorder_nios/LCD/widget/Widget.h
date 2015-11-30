/*
 * Widget.h
 *
 *  Created on: Nov 30, 2015
 *      Author: alpha
 */

#ifndef WIDGET_H_
#define WIDGET_H_

const int MAX_STRLEN = 200;

namespace LCD {
namespace Window {

class Widget {
public:
  int x, y;
  int width, height;
	Widget();
  Widget(int, int, int, int);
	virtual ~Widget();
  virtual void render() = 0;
  virtual bool onMouseDown(int x, int y) {
    return false;
  };
  virtual bool onMouseMove(int x, int y) {
    return false;
  }; 
  virtual bool onMouseUp(int x, int y) {
    return false;
  };
};

} /* namespace Window */
} /* namespace LCD */

#endif /* WIDGET_H_ */
