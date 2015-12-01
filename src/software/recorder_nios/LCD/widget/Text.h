/*
 * Text.h
 *
 *  Created on: Nov 30, 2015
 *      Author: alpha
 */

#ifndef TEXT_H_
#define TEXT_H_

#include "Renderable.h"
#include "LCD/window.h"
#include <cstring>

namespace LCD {
namespace Window {

class Text: public Renderable {
public:
  SETTER(string, text)
  Color color;
	Text();
  Text(POS_INFO, string, Color color={0, 0, 0});
	virtual ~Text();
  virtual void render(int, int, Color);
};
#undef MAX_CHAR

} /* namespace Window */
} /* namespace LCD */

#endif /* TEXT_H_ */
