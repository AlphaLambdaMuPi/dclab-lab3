/*
 * Choicer.h
 *
 *  Created on: Dec 1, 2015
 *      Author: alpha
 */

#ifndef CHOICER_H_
#define CHOICER_H_

#include "RowDivider.h"

namespace LCD {
namespace Window {

class Choicer: public RowDivider {
  void (*change_handler)(int);
public:
  SETTER(int, value);
	Choicer();
  Choicer(POS_INFO);
  void set_handler(void (*f)(int));
  bool onMouseEvent(MouseEvent e);
  void value_change(int);
	virtual ~Choicer();
};

} /* namespace Window */
} /* namespace LCD */

#endif /* CHOICER_H_ */
