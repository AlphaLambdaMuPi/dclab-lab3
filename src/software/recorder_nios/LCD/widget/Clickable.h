/*
 * Clickable.h
 *
 *  Created on: Dec 1, 2015
 *      Author: alpha
 */

#ifndef CLICKABLE_H_
#define CLICKABLE_H_

#include "LCD/lcd_include.h"
#include "Renderable.h"

namespace LCD {
namespace Window {

class Clickable: public virtual Renderable {
public:
  struct MouseEvent {
    int x, y;
    enum MouseEventType {
      MouseDown,
      MouseMove,
      MouseUp,
    } event_type;
  };
	Clickable();
  Clickable(POS_INFO);
  virtual bool _onMouseEvent(MouseEvent e);
  virtual bool onMouseEvent(MouseEvent e) = 0;
  virtual ~Clickable();
};

} /* namespace Window */
} /* namespace LCD */

#endif /* CLICKABLE_H_ */
