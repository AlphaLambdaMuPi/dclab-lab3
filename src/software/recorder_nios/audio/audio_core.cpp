/* Audio core for de2-115 */

#include "audio_core.h"

namespace Audio {
  alt_up_audio_dev* dev;
  
  ushort *read_buffer, *write_buffer;
  int read_max_len, write_len;
  int read_ptr;
  int write_ptr, write_rm;
  int interp_type = 0;
  int mode = 3;
  int speed = 32;

  int max_lat = 0;

  void (*stop_handler)(void) = NULL;

  /* Fix the audio ju ma kai men & 8 wave problem */
  static int alt_read_wrapper(uint *buf, int len) {
    alt_up_audio_read_fifo(dev, buf, len, 0);
    alt_up_audio_read_fifo(dev, buf, len, 1);
    for (int i=0; i<len; i++) {
      buf[i] ^= 1<<15;
    }
  }

  static int rspace() {
    return alt_up_audio_read_fifo_avail(dev, 0);
  }

  static int wspace() {
    return alt_up_audio_write_fifo_space(dev, 0);
  }

  ushort get_data(double t) {
    // int t1 = t, t2 = t+1;
    // return write_buffer[t1] * (t - t1) + write_buffer[t2] * (t2 - t);
    return write_buffer[(int)t];
  }

  uint _tmp_buffer[BUFFER_SIZE];
  void audio_handler(void *dt, unsigned long id) {
    alt_up_audio_disable_read_interrupt(dev);
    int avail = rspace();
    alt_read_wrapper(_tmp_buffer, avail);
    

    if (mode == 1) {
      // Read Only.
      for (int i=0; i<avail; i++) {
        if (read_ptr == read_max_len) break;
        read_buffer[read_ptr++] = _tmp_buffer[i];
      }
      alt_up_audio_write_fifo(dev, _tmp_buffer, avail, 0);
      alt_up_audio_write_fifo(dev, _tmp_buffer, avail, 1);
    } else if (mode == 2) {
      //Write Only
      int wavail = wspace(), _av = 0;

      for (int i=0; (i < wavail) and (write_ptr < write_len); i++) {

        _tmp_buffer[i] = (interp_type == 0) ? write_buffer[write_ptr] :
          (write_buffer[write_ptr] * (32 - write_rm) 
           + write_buffer[write_ptr+1] * write_rm) >> 5;

        write_rm += speed;

        if (write_rm >= 32) {
          write_ptr += (write_rm >> 5);
          write_rm &= (31);
        }
        _av ++;
      }
      alt_up_audio_write_fifo(dev, _tmp_buffer, _av, 0);
      alt_up_audio_write_fifo(dev, _tmp_buffer, _av, 1);
      if (write_ptr >= write_len)
        stop();
    } else if (mode == 3) {
      alt_up_audio_write_fifo(dev, _tmp_buffer, avail, 0);
      alt_up_audio_write_fifo(dev, _tmp_buffer, avail, 1);
    }
    alt_up_audio_enable_read_interrupt(dev);
  }

  void init() {
    dev = alt_up_audio_open_dev("/dev/audio");
    alt_irq_register(AUDIO_IRQ, NULL, audio_handler);
    alt_up_audio_enable_read_interrupt(dev);
    printf("Audio init ok!\n");
  }

  void start_read(ushort *buf, int max_len) {
    mode = 1;
    read_buffer = buf;
    read_max_len = max_len;
    read_ptr = 0;
  }

  int stop_read() {
    mode = 0;
    return read_ptr;
  }

  int get_current_read() {
    return read_ptr;
  }

  void start_write(ushort *buf, int max_len) {
    mode = 2;
    write_buffer = buf;
    write_len = max_len;
    write_ptr = write_rm = 0;
  }

  int stop_write() {
    mode = 0;
    return write_ptr;
  }

  void start_echo() {
    mode = 3;
  }

  void pause() {
    mode = 0;
  }

  void resume() {
    mode = 2;
  }

  void stop() {
    mode = 0;
    if (stop_handler)
      stop_handler();
  }

  void reset() {
    alt_up_audio_reset_audio_core(dev);
  }
}
