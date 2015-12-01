/*
 * GUI.cpp
 *
 *  Created on: Dec 1, 2015
 *      Author: alpha
 */

#include "GUI.h"


namespace GUI {

  Renderable c1, c2, c3;
  Container c4;
  Text t5;
  void init() {
    Root.set_bgcolor({200, 220, 255});
    c1 = Renderable(0, 0, 266, 100).set_bgcolor({255, 180, 180});
    // c2 = Renderable(10, 10, 30, 30).set_bgcolor({0, 255, 0});
    c4 = Container(20, 20, 140, 140);
    printf("addr [gui] = %d %d %d %d %d\n", &c4, &c4.x, &c4.y, c4.x, c4.y);
    c4.set_bgcolor({0, 255, 0});
    t5 = Text(0, 0, 100, 100, "hao123");
    c4.add_child(&t5);
    Root.add_child(&c1);
    Root.add_child(&c4);
    printf("%d %d\n", &Root, &c4);
  }

  void task() {
    LCD::Window::root_render();
  }
}


