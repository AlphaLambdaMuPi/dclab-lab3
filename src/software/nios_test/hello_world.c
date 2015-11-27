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
#include "altera_avalon_pio_regs.h"
#include "sys/alt_irq.h"
#include "altera_avalon_spi.h"
#include "alt_types.h"
#include <stdlib.h>
#include <io.h>


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
unsigned int tk = 0;
unsigned int gettk() {
  return tk++;
}

unsigned int lstk = -1;
void touch_handler(void *context, alt_u32 id) {
  IOWR_ALTERA_AVALON_PIO_EDGE_CAP(PIO_TOUCH_BASE, 0x0);
  unsigned int t = gettk();
  unsigned int dt = t - lstk;
  printf("Button touched = %d\n", gettk());
  if (dt > 10000) {
      char rx = 0x92, ry = 0xD2;
      alt_avalon_spi_command(SPI_TOUCH_BASE, 0, 1, &rx, 0, 0, 1);
      alt_avalon_spi_command(SPI_TOUCH_BASE, 0, 0, 0, 1, &rx, 0);

      alt_avalon_spi_command(SPI_TOUCH_BASE, 0, 1, &ry, 0, 0, 1);
      alt_avalon_spi_command(SPI_TOUCH_BASE, 0, 0, 0, 1, &ry, 0);
      if (rx > 30 && rx < 80 && ry > 30 && ry < 80) {
        toggle_rm();
      }
  }
  lstk = t;
  /* draw(); */
  return;
}

void draw() {
    int i, j;
  alt_up_pixel_buffer_dma_dev *buf = alt_up_pixel_buffer_dma_open_dev("/dev/video_pixel_buffer_dma");
    for (i=0; i<48; i++) {
      for (j=0; j<80; j++) {
       alt_up_pixel_buffer_dma_draw_box(buf, j*10, i*10, j*10+10, i*10+10, rand(), 1);
      }
    }
}

int readmode = 0;

int bid;
int cnt = 0;
int toggle_rm() {
  readmode = 1 - readmode;
  alt_up_pixel_buffer_dma_dev *buf = alt_up_pixel_buffer_dma_open_dev("/dev/video_pixel_buffer_dma");
  if (readmode) {
    bid = 0;
    alt_up_pixel_buffer_dma_draw_box(buf, 200, 120, 600, 360, 31, 0);
  } else {
    cnt = 0;
    alt_up_pixel_buffer_dma_draw_box(buf, 200, 120, 600, 360, 31<<6, 0);
  }
}
 

char buff[1000000];
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

  alt_irq_register(PIO_TOUCH_IRQ, NULL, touch_handler);
  IOWR_ALTERA_AVALON_PIO_IRQ_MASK(PIO_TOUCH_BASE, 0x01);
  IOWR_ALTERA_AVALON_PIO_EDGE_CAP(PIO_TOUCH_BASE, 0x0);
  /* IOWR_ALTERA_AVALON_PIO_IRQ_MASK(PIO_TOUCH_BASE, 0x01); */

  alt_up_pixel_buffer_dma_dev *buf = alt_up_pixel_buffer_dma_open_dev("/dev/video_pixel_buffer_dma");
  alt_up_pixel_buffer_dma_clear_screen(buf, 1);

  /* int z = (1 + (1<<6) + (1<<11)); */
  /* int i, j; */
  /* for (i=0; i<10; i++) { */
    /* for (j=0; j<10; j++) { */
      /* int t = i*10 + j; */
      /* if (t >= 31) break; */

      /* int x = j * 80, y = i * 48; */
      /* alt_up_pixel_buffer_dma_draw_box(buf, x, y, x+80, y+48, z*t, 0); */
      /* alt_up_pixel_buffer_dma_draw_box(buf, x+30, y+20, x+50, y+28, z*(t+1), 0); */
    /* } */
  /* } */


  /* for (i=0; i<31; i++) { */
    /* alt_up_pixel_buffer_dma_draw_box(buf, i*20, 240, i*20+20, 480, (, 0); */
  /* } */
  /* alt_up_pixel_buffer_dma_draw_box(buf, 0, 0, 0, 0, 65535, 0); */

  /* alt_up_pixel_buffer_dma_draw_box(buf, 0, 0, 400, 480, 10<<5, 0); */
  /* while(1); */
  /* return 0; */
  /* int i; */
  /* alt_up_pixel_buffer_dma_draw_box(buf, 0, 0, 400, 480, (31<<11)+(31<<6)+31, 1); */
  /* alt_up_pixel_buffer_dma_draw_box(buf, 100, 100, 200, 200, (30<<11)+(30<<6)+30, 1); */

  /* alt_up_pixel_buffer_dma_draw_box(buf, 400, 0, 800, 480, (10<<11)+(10<<6)+10, 1); */
  /* alt_up_pixel_buffer_dma_draw_box(buf, 500, 100, 600, 200, (11<<11)+(11<<6)+11, 1); */
  /* while(1); */
  /* return 0; */

  /* int hao123 = 123; */

  /* draw(); */

    /* while (1) { */
      /* hao123 = IORD(PIO_TOUCH_BASE, 0x00); */
      /* char rx = 0x92, ry = 0xD2; */
      /* alt_avalon_spi_command(SPI_TOUCH_BASE, 0, 1, &rx, 0, 0, 1); */
      /* alt_avalon_spi_command(SPI_TOUCH_BASE, 0, 0, 0, 1, &rx, 0); */

      /* alt_avalon_spi_command(SPI_TOUCH_BASE, 0, 1, &ry, 0, 0, 1); */
      /* alt_avalon_spi_command(SPI_TOUCH_BASE, 0, 0, 0, 1, &ry, 0); */
      /* sleep_ms(100); */
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
  //alt_up_audio_reset_audio_core(audio_dev);
  toggle_rm();
  while(1)
  {

    gettk();
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
        if (bid >= 900000){
          toggle_rm();
        }
      }
    } else {

      if ( fifospacew > 0 ) // check if data is available
      {
        // read audio buffer
        r_buf = l_buf = buff[cnt++] << 8;
      
        alt_up_audio_write_fifo (audio_dev, &(r_buf), 1, ALT_UP_AUDIO_RIGHT);
        alt_up_audio_write_fifo (audio_dev, &(l_buf), 1, ALT_UP_AUDIO_LEFT);
        if (cnt >= bid) {
          cnt = 0;
        }
      }
    }
  }
}
