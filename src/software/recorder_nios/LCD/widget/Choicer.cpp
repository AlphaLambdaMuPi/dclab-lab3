/*
 * Choicer.cpp
 *
 *  Created on: Dec 1, 2015
 *      Author: alpha
 */

#include "Choicer.h"

namespace LCD {
namespace Window {

Choicer::Choicer() {
	// TODO Auto-generated constructor stub
  value = 0;
  change_handler = NULL;
}

Choicer::Choicer(POS_INFO) 
  : Renderable(x, y, width, height), RowDivider(x, y, width, height) {
	// TODO Auto-generated constructor stub
  value = 0;
  change_handler = NULL;
}

void Choicer::set_handler(void (*f)(int)) {
  change_handler = f;
}

void Choicer::value_change(int v) {
  if (value == v) return;
  value = v;
  for (int i=0; i<(int)children.size(); i++) {
    StateButton* cast = dynamic_cast<StateButton*>(children[i]);
    if (cast) 
      cast->set_state(i == v);
  }
  if (change_handler)
    change_handler(v);
}

bool Choicer::onMouseEvent(MouseEvent e) {
  for (int i=0; i<(int)children.size(); i++) {
    Clickable* cast = dynamic_cast<Clickable*>(children[i]);
    if (cast) {
      if (cast->_onMouseEvent(e)) {
        value_change(i);
        return true;
      }
    }
  }
}

Choicer::~Choicer() {
	// TODO Auto-generated destructor stub
}

} /* namespace Window */
} /* namespace LCD */
