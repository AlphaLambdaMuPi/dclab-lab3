/*
 * GUI.h
 *
 *  Created on: Dec 1, 2015
 *      Author: alpha
 */

#ifndef GUI_H_
#define GUI_H_

#include "global.h"
#include "audio/audio_core.h"
#include "LCD/lcd_core.h"
#include "LCD/window.h"

#include "LCD/widget/Container.h"
#include "LCD/widget/Text.h"
#include "LCD/widget/Button.h"
#include "LCD/widget/RowDivider.h"
#include "LCD/widget/StateButton.h"
#include "LCD/widget/Choicer.h"
#include "LCD/widget/Slider.h"

using LCD::Window::Renderable;
using LCD::Window::Widget;
using LCD::Window::Root;
using LCD::Window::Container;
using LCD::Window::Text;
using LCD::Window::Button;
using LCD::Window::RowDivider;
using LCD::Window::StateButton;
using LCD::Window::Choicer;
using LCD::Window::Slider;

using LCD::Color;

namespace GUI {
  void init();
  void task();
}


#endif /* GUI_H_ */
