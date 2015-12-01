/*
 * RowDivider.h
 *
 *  Created on: Dec 1, 2015
 *      Author: alpha
 */

#ifndef ROWDIVIDER_H_
#define ROWDIVIDER_H_

#include "Container.h"
#include "StateButton.h"

namespace LCD {
namespace Window {

class RowDivider: public Container {
public:
  SETTER(int, margin);
  vector<double> pers;
	RowDivider();
	RowDivider(POS_INFO);
	virtual ~RowDivider();
  RowDivider& add_child(Renderable*);
  RowDivider& add_child(Renderable*, double);
  void render(int, int, Color);
  RowDivider& calc();
};

} /* namespace Window */
} /* namespace LCD */

#endif /* ROWDIVIDER_H_ */
