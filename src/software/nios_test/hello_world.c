/*
 * "Hello World" example.
 *
 * This example prints 'Hello from Nios II' to the STDOUT stream. It runs on
 * the Nios II 'standard', 'full_featured', 'fast', and 'low_cost' example
 * designs. It runs with or without the MicroC/OS-II RTOS and requires a STDOUT
 * device in your system's hardware.
 * The memory footprint of this hosted application is ~69 kbytes by default
 * using the standard reference design.
 *
 * For a reduced footprint version of this template, and an explanation of how
 * to reduce the memory footprint for a given application, see the
 * "small_hello_world" template.
 *
 */

#include <stdio.h>
#include "altera_up_avalon_audio_and_video_config.h"
#include "altera_up_avalon_audio.h"
#include "altera_up_avalon_video_pixel_buffer_dma.h"
#include <stdlib.h>
#include <io.h>

int bid;

void sleep_ms(int milisec)
{
  int i;
  int k;
  for (i = 0; i < milisec; i++) {
    for (k = 0; k < 2500; k++) {
      __asm("nop");
    }
  }
}

int next_color(int color) {
  int bms = 31;
  int gms = 31 << 6;
  int rms = gms << 5;
  int r = color & rms, g = color & gms, b = color & bms;
  /* if ((color & bms) { */
    /* color --; */
    /* color += 1<<6; */
  /* } else if (color & gms) { */
    /* color -= 1<<6; */
    /* color += 1<<11; */
  /* } else { */
    /* color -= 1<<11; */
    /* color ++; */
  /* } */
  return color;
}
 

char buff[420000];
int main()
{
  printf("Hello from Nios 234568!\n\n");

  /* alt_up_av_config_dev* a = alt_up_av_config_open_dev("/dev/audio_and_video_config"); */
  /* printf("%d\n", alt_up_av_config_reset(a)); */
  /* int res; */
  /* int b = (0x34), c = 0b0000100000010101; */
  /* res = alt_up_av_config_write_audio_cfg_register(a, 4, 0b010101); */
  //res = alt_up_av_config_write_audio_cfg_register(a, 5, 0b000110);
  /* res = alt_up_av_config_write_audio_cfg_register(a, 7, 65); */
  //res = alt_up_av_config_write_audio_cfg_register(a, 7, (1<<6)+1);
  /* res = alt_up_av_config_write_audio_cfg_register(a, 8, 0); */

  alt_up_pixel_buffer_dma_dev *buf = alt_up_pixel_buffer_dma_open_dev("/dev/video_pixel_buffer_dma");
  alt_up_pixel_buffer_dma_clear_screen(buf, 0);
  printf("%d\n", buf->x_resolution);

  /* int hao123 = 123; */
  /* while (1) { */
    /* int i, j; */
    /* for (i=0; i<480; i++) { */
      /* for (j=0; j<800; j++) { */
        /* hao123 = hao123 * 123 + 123; */
       /* alt_up_pixel_buffer_dma_draw_box(buf, j*1, i*1, j*1+1, i*1+1, 123, 1); */
      /* } */
    /* } */
    /* printf("Hao %d\n", hao123); */
  /* } */
  /* return 0; */

 /* int x = 0, hx = 200, y = 0; */
 /* int color = 31; */
 /* alt_up_pixel_buffer_dma_draw_box(buf, x, 0, x+200, 200, 31, 1); */
 /* while (1) { */
   /* alt_up_pixel_buffer_dma_draw_line(buf, x, 0, x, 200, 0, 1); */
   /* x += 1; */
   /* hx += 1; */
   /* if (x >= 800) x = 0; */
   /* if (hx >= 800) hx = 0; */
   /* sleep_ms(1000); */
   /* color = next_color(color); */
   /* alt_up_pixel_buffer_dma_draw_line(buf, hx, 0, hx, 200, color, 1); */
 /* } */


  /* return 0; */

  alt_up_audio_dev *audio_dev;
  /* used for audio record/playback */
  unsigned int l_buf;
  unsigned int r_buf;

  // open the Audio port
  audio_dev = alt_up_audio_open_dev ("/dev/audio");
  if ( audio_dev == NULL)
    alt_printf ("Error: could not open audio device \n");
  else
    alt_printf ("Opened audio device \n");
    /* read and echo audio data */
  alt_up_audio_reset_audio_core(audio_dev);
  int readmode = 1;
  int cnt = 0;
  bid = 0;
  while(1)
  {
    cnt ++;

    int fifospace = alt_up_audio_read_fifo_avail (audio_dev, ALT_UP_AUDIO_RIGHT);
    int fifospacew = alt_up_audio_write_fifo_space (audio_dev, ALT_UP_AUDIO_LEFT);

    if (readmode) {
      if ( fifospace > 0 ) // check if data is available
      {
        // read audio buffer
        alt_up_audio_read_fifo (audio_dev, &(r_buf), 1, ALT_UP_AUDIO_RIGHT);
        alt_up_audio_read_fifo (audio_dev, &(l_buf), 1, ALT_UP_AUDIO_LEFT);
      
        
        l_buf ^= (1<<15);
        r_buf ^= (1<<15);
        alt_up_audio_write_fifo (audio_dev, &(r_buf), 1, ALT_UP_AUDIO_RIGHT);
        alt_up_audio_write_fifo (audio_dev, &(l_buf), 1, ALT_UP_AUDIO_LEFT);
        buff[bid++] = l_buf >> 8;
        if (bid == 400000){
          readmode = 0;
          bid = 0;
        }
      }
    } else {
      if ( fifospace > 0 ) // check if data is available
      {
        // read audio buffer
        alt_up_audio_read_fifo (audio_dev, &(r_buf), 1, ALT_UP_AUDIO_RIGHT);
        alt_up_audio_read_fifo (audio_dev, &(l_buf), 1, ALT_UP_AUDIO_LEFT);
      }
      if ( fifospacew > 0 ) // check if data is available
      {
        // read audio buffer
        r_buf = l_buf = buff[bid] << 8;
      
        alt_up_audio_write_fifo (audio_dev, &(r_buf), 1, ALT_UP_AUDIO_RIGHT);
        alt_up_audio_write_fifo (audio_dev, &(l_buf), 1, ALT_UP_AUDIO_LEFT);
        bid ++;
        if (bid == 400000) {
          readmode = 1;
          bid = 0;
        }
      }
    }
  }
}
