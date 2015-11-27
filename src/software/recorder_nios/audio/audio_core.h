#ifndef AUDIO_CORE_H
#define AUDIO_CORE_H

#include <cstdio>
#include <algorithm>
#include "typedef.h"
#include "altera_up_avalon_audio.h"

using std::max;

namespace Audio 
{
  const int BUFFER_SIZE = 256;
  extern int max_lat;
  void init();
  int rspace();
  void read();
}

#endif
