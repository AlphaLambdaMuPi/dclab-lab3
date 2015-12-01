/*
 * global.h
 *
 *  Created on: Dec 1, 2015
 *      Author: alpha
 */

#ifndef GLOBAL_H_
#define GLOBAL_H_

#include <cstdio>
#include <cstdlib>
#include "io.h"
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;
using std::swap;

#define SETTER(type, name)  \
  type name; \
  auto& set_##name (type a) { name = a; return (*this); };

#endif /* GLOBAL_H_ */
