/* Audio core for de2-115 */

#include "audio_core.h"

namespace Audio {
  alt_up_audio_dev* dev;

  uint buffer[BUFFER_SIZE];
  uint buf_head, buf_tail;

  int max_lat = 0;

  void init() {
     dev = alt_up_audio_open_dev("/dev/audio");
  }

  int rspace() {
    return alt_up_audio_read_fifo_avail(dev, 0);
  }

  int wspace() {
    return alt_up_audio_write_fifo_space(dev, 0);
  }

  inline void buf_push(uint dt) {
    buffer[buf_head++] = dt;
    buf_head = buf_head > BUFFER_SIZE ? 0 : buf_head;
  }

  inline int buf_pop() {
    uint res = buffer[buf_tail++];
    buf_tail = buf_tail > BUFFER_SIZE ? 0 : buf_tail;
    return res;
  }

  /* Fix the audio ju ma kai men & 8 wave problem */
  static int alt_read_wrapper(uint *buf, int len) {
    alt_up_audio_read_fifo(dev, buf, len, 0);
    alt_up_audio_read_fifo(dev, buf, len, 1);
    for (int i=0; i<len; i++) {
      buf[i] ^= 1<<15;
    }
  }

  uint _tmp_buf[BUFFER_SIZE];
  void read() {
    int avail = rspace();
    max_lat = max(max_lat, wspace());
    if (avail) {
      alt_read_wrapper(_tmp_buf, avail);
      alt_up_audio_write_fifo(dev, _tmp_buf, avail, 0);
      alt_up_audio_write_fifo(dev, _tmp_buf, avail, 1);
    }
    for (int i=0; i<avail; i++) {
      buf_push(_tmp_buf[i]);
    }
  }
}
