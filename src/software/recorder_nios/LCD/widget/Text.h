/*
 * Text.h
 *
 *  Created on: Nov 30, 2015
 *      Author: alpha
 */

#ifndef TEXT_H_
#define TEXT_H_

#include "Widget.h"
#include "../lcd_core.h"
#include <cstring>

namespace LCD {
namespace Window {

class Text: public Widget {
public:
  char text[MAX_STRLEN];
  Color color;
	Text();
  Text(int, int, int, int, char*, Color color={0, 0, 0});
	virtual ~Text();
  virtual void render();
  void set_text(char*);
};
#undef MAX_CHAR

} /* namespace Window */
} /* namespace LCD */

#endif /* TEXT_H_ */
