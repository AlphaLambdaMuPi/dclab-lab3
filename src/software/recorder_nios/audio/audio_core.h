#ifndef AUDIO_CORE_H
#define AUDIO_CORE_H

#include <cstdio>
#include <algorithm>
#include "typedef.h"
#include "altera_up_avalon_audio.h"
#include "sys/alt_irq.h"

using std::max;

namespace Audio 
{
  const int BUFFER_SIZE = 256;
  extern int max_lat;
  extern int mode;
  extern int speed;
  extern int read_ptr, write_ptr;
  extern void (*stop_handler)(void);
  void init();
  void start_read(ushort*, int);
  int get_current_read();
  int stop_read();
  void start_write(ushort*, int);
  int stop_write();
  void start_echo();
  void stop();
  void reset();
}

#endif
