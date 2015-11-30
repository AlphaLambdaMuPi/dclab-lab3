module DE2_115(
	input CLOCK_50,
	input CLOCK2_50,
	input CLOCK3_50,
	input ENETCLK_25,
	input SMA_CLKIN,
	output SMA_CLKOUT,
	output [8:0] LEDG,
	output [17:0] LEDR,
	input [3:0] KEY,
	input [17:0] SW,
	output [6:0] HEX0,
	output [6:0] HEX1,
	output [6:0] HEX2,
	output [6:0] HEX3,
	output [6:0] HEX4,
	output [6:0] HEX5,
	output [6:0] HEX6,
	output [6:0] HEX7,
	output LCD_BLON,
	inout [7:0] LCD_DATA,
	output LCD_EN,
	output LCD_ON,
	output LCD_RS,
	output LCD_RW,
	output UART_CTS,
	input UART_RTS,
	input UART_RXD,
	output UART_TXD,
	inout PS2_CLK,
	inout PS2_DAT,
	inout PS2_CLK2,
	inout PS2_DAT2,
	output SD_CLK,
	inout SD_CMD,
	inout [3:0] SD_DAT,
	input SD_WP_N,
	output [7:0] VGA_B,
	output VGA_BLANK_N,
	output VGA_CLK,
	output [7:0] VGA_G,
	output VGA_HS,
	output [7:0] VGA_R,
	output VGA_SYNC_N,
	output VGA_VS,
	input AUD_ADCDAT,
	inout AUD_ADCLRCK,
	inout AUD_BCLK,
	output AUD_DACDAT,
	inout AUD_DACLRCK,
	output AUD_XCK,
	output EEP_I2C_SCLK,
	inout EEP_I2C_SDAT,
	output I2C_SCLK,
	inout I2C_SDAT,
	output ENET0_GTX_CLK,
	input ENET0_INT_N,
	output ENET0_MDC,
	input ENET0_MDIO,
	output ENET0_RST_N,
	input ENET0_RX_CLK,
	input ENET0_RX_COL,
	input ENET0_RX_CRS,
	input [3:0] ENET0_RX_DATA,
	input ENET0_RX_DV,
	input ENET0_RX_ER,
	input ENET0_TX_CLK,
	output [3:0] ENET0_TX_DATA,
	output ENET0_TX_EN,
	output ENET0_TX_ER,
	input ENET0_LINK100,
	output ENET1_GTX_CLK,
	input ENET1_INT_N,
	output ENET1_MDC,
	input ENET1_MDIO,
	output ENET1_RST_N,
	input ENET1_RX_CLK,
	input ENET1_RX_COL,
	input ENET1_RX_CRS,
	input [3:0] ENET1_RX_DATA,
	input ENET1_RX_DV,
	input ENET1_RX_ER,
	input ENET1_TX_CLK,
	output [3:0] ENET1_TX_DATA,
	output ENET1_TX_EN,
	output ENET1_TX_ER,
	input ENET1_LINK100,
	input TD_CLK27,
	input [7:0] TD_DATA,
	input TD_HS,
	output TD_RESET_N,
	input TD_VS,
	inout [15:0] OTG_DATA,
	output [1:0] OTG_ADDR,
	output OTG_CS_N,
	output OTG_WR_N,
	output OTG_RD_N,
	input OTG_INT,
	output OTG_RST_N,
	input IRDA_RXD,
	output [12:0] DRAM_ADDR,
	output [1:0] DRAM_BA,
	output DRAM_CAS_N,
	output DRAM_CKE,
	output DRAM_CLK,
	output DRAM_CS_N,
	inout [31:0] DRAM_DQ,
	output [3:0] DRAM_DQM,
	output DRAM_RAS_N,
	output DRAM_WE_N,
	output [19:0] SRAM_ADDR,
	output SRAM_CE_N,
	inout [15:0] SRAM_DQ,
	output SRAM_LB_N,
	output SRAM_OE_N,
	output SRAM_UB_N,
	output SRAM_WE_N,
	output [22:0] FL_ADDR,
	output FL_CE_N,
	inout [7:0] FL_DQ,
	output FL_OE_N,
	output FL_RST_N,
	input FL_RY,
	output FL_WE_N,
	output FL_WP_N,
	inout [35:0] GPIO,
	input HSMC_CLKIN_P1,
	input HSMC_CLKIN_P2,
	input HSMC_CLKIN0,
	output HSMC_CLKOUT_P1,
	output HSMC_CLKOUT_P2,
	output HSMC_CLKOUT0,
	inout [3:0] HSMC_D,
	input [16:0] HSMC_RX_D_P,
	output [16:0] HSMC_TX_D_P,
	inout [6:0] EX_IO
);
  // logic dt, ck;
  // logic _VGA_R, _VGA_G, _VGA_B;
  // logic _VGA_BLANK, _VGA_SYNC, _SRAM_DQ;
  // assign VGA_BLANK_N = _VGA_BLANK;
 // assign VGA_SYNC_N = ~_VGA_SYNC;
 wire adc_clk, adc_sel_n;
 wire clock100;
 wire [7:0] out_r, out_g, out_b;
 pll pll100(
	.inclk0(CLOCK_50),
	.c0(clock100)
);
 
 Core (
   .audio_and_video_config_external_interface_SDAT(I2C_SDAT), // audio_and_video_config_external_interface.SDAT
   .audio_and_video_config_external_interface_SCLK(I2C_SCLK), //                                          .SCLK
   .audio_external_interface_ADCLRCK(AUD_ADCLRCK),               //                                          .ADCLRCK
   .audio_external_interface_ADCDAT(AUD_ADCDAT),                //                  audio_external_interface.ADCDAT
   .audio_external_interface_BCLK(AUD_BCLK),                  //                                          .BCLK
   .audio_external_interface_DACDAT(AUD_DACDAT),                //                                          .DACDAT
   .audio_external_interface_DACLRCK(AUD_DACLRCK),               //     
   .clock_bridge_out_clk_clk(AUD_XCK),                       //                      clock_bridge_out_clk.clk


   .sdram_controller_wire_addr(DRAM_ADDR),                     //                     sdram_controller_wire.addr
   .sdram_controller_wire_ba(DRAM_BA),                       //                                          .ba
   .sdram_controller_wire_cas_n(DRAM_CAS_N),                    //                                          .cas_n
   .sdram_controller_wire_cke(DRAM_CKE),                      //                                          .cke
   .sdram_controller_wire_cs_n(DRAM_CS_N),                     //                                          .cs_n
   .sdram_controller_wire_dq(DRAM_DQ),                       //                                          .dq
   .sdram_controller_wire_dqm(DRAM_DQM),                      //                                          .dqm
   .sdram_controller_wire_ras_n(DRAM_RAS_N),                    //                                          .ras_n
   .sdram_controller_wire_we_n(DRAM_WE_N), 
   .sys_sdram_pll_sdram_clk_clk(DRAM_CLK),   		//                                          .we_n

   .clk_clk(CLOCK_50),  
.clk_0_clk(CLOCK_50),     	//                                       clk.clk
   .reset_reset_n(KEY[0]),                               //                                     reset.reset_n

   // LTM
   .video_vga_controller_external_interface_CLK(GPIO[9]),     //   video_vga_controller_external_interface.CLK
   .video_vga_controller_external_interface_HS(GPIO[11]),      //                                          .HS
   .video_vga_controller_external_interface_VS(GPIO[12]),      //                                          .VS
   .video_vga_controller_external_interface_DATA_EN(GPIO[10]), //                                          .DATA_EN
   .video_vga_controller_external_interface_R(out_r),       //                                          .R
   .video_vga_controller_external_interface_G(out_g),       //                                          .G
   .video_vga_controller_external_interface_B(out_b),     //                                          .B

     // MTL
     // .video_vga_controller_external_interface_CLK(GPIO[1]),     //   video_vga_controller_external_interface.CLK
       // .video_vga_controller_external_interface_HS(GPIO[30]),      //                                          .HS
       // .video_vga_controller_external_interface_VS(GPIO[31]),      //                                          .VS
       // // .video_vga_controller_external_interface_DATA_EN(GPIO[10]), //                                          .DATA_EN
       // .video_vga_controller_external_interface_R(GPIO[10:3]),       //                                          .R
       // .video_vga_controller_external_interface_G({GPIO[21], GPIO[19:18], GPIO[15:11]}),       //                                          .G
       // .video_vga_controller_external_interface_B({GPIO[28:22], GPIO[20]})     //                                          .B

       // .video_vga_controller_external_interface_CLK(VGA_CLK),     //   video_vga_controller_external_interface.CLK
         // .video_vga_controller_external_interface_HS(VGA_HS),      //                                          .HS
         // .video_vga_controller_external_interface_VS(VGA_VS),      //                                          .VS
         // .video_vga_controller_external_interface_BLANK(_VGA_BLANK),   //                                          .BLANK
         // .video_vga_controller_external_interface_SYNC(_VGA_SYNC),    //                                          .SYNC
         // .video_vga_controller_external_interface_R(VGA_R),       //                                          .R
         // .video_vga_controller_external_interface_G(VGA_G),       //                                          .G
         // .video_vga_controller_external_interface_B(VGA_B),     //                                          .B

     .sram_external_interface_DQ(SRAM_DQ),                     //                   sram_external_interface.DQ
     .sram_external_interface_ADDR(SRAM_ADDR),                   //                                          .ADDR
     .sram_external_interface_LB_N(SRAM_LB_N),                   //                                          .LB_N
     .sram_external_interface_UB_N(SRAM_UB_N),                   //                                          .UB_N
     .sram_external_interface_CE_N(SRAM_CE_N),                   //                                          .CE_N
     .sram_external_interface_OE_N(SRAM_OE_N),                   //                                          .OE_N
     .sram_external_interface_WE_N(SRAM_WE_N),                   //                                          .WE_N


     .spi_touch_external_MISO(GPIO[1]),                         //                        spi_touch_external.MISO
     .spi_touch_external_MOSI(GPIO[3]),                         //                                          .MOSI
     .spi_touch_external_SCLK(adc_clk),                         //                                          .SCLK
     .spi_touch_external_SS_n(adc_sel_n),
         // .spi_touch_external_SS_n(GPIO[34])                         //                                          .SS_n
         //
		  .pio_touch_external_connection_export(GPIO[0])            //             pio_touch_external_connection.export
   );

   wire [7:0] u_b, real_b;
   assign u_b = out_b >> 3;
   // assign real_b = !u_b ? 0 :
                   // u_b <= 8'd10 ? 8'd82 + 8'd7 * u_b : 
                   // u_b <= 8'd21 ? 8'd122 + 8'd3 * u_b :
                   // 8'd35 + 8'd7 * u_b;
   assign real_b = !u_b ? 0 :
                   u_b <= 8'd5 ? 8'd92 + 8'd8 * u_b : 
                   u_b <= 8'd22 ? 8'd117 + 8'd3 * u_b :
                   u_b <= 8'd25 ? 8'd10 * u_b - 8'd37:
                   8'd38 + 8'd7 * u_b;
                 
  assign GPIO[16:13] = real_b[7:4];
  assign GPIO[5] = real_b[3];
  assign GPIO[6] = real_b[2];
  assign GPIO[7] = real_b[1];
  assign GPIO[8] = real_b[0];

   wire [7:0] u_r, real_r;
   assign u_r = out_r >> 3;
   // assign real_r = u_r;
   assign real_r = !u_r ? 0 : u_r <= 8'd5 ? 8'd92 + 8'd8 * u_r : 
                   u_r <= 8'd22 ? 8'd117 + 8'd3 * u_r :
                   u_r <= 8'd25 ? 8'd10 * u_r - 8'd37:
                   8'd38 + 8'd7 * u_r;
  assign GPIO[32:25] = real_r;
  // assign real_b = out_b;
  //
   wire [7:0] u_g, real_g;
   assign u_g = out_g >> 3;
   assign real_g = !u_g ? 0 : u_g <= 8'd5 ? 8'd92 + 8'd8 * u_g : 
                   u_g <= 8'd22 ? 8'd117 + 8'd3 * u_g :
                   u_g <= 8'd25 ? 8'd10 * u_g - 8'd37:
                   8'd38 + 8'd7 * u_g;
  assign GPIO[24:17] = real_g;

  assign LCD_SPI_CLK = (adc_sel_n ? 1'bz : adc_clk);
  assign LEDR[0] = GPIO[0];
  assign GPIO[33] = KEY[0];
  assign GPIO[34] = ~adc_sel_n;
  assign GPIO[35] = 1'bz;
  assign GPIO[4] = LCD_SPI_CLK;
  // assign VGA_B = 8'd255;
  // assign _SRAM_DQ = 16'b0000011111100000;
  // logic [10:0] cnt;
  // logic z;
  // assign LEDR[0] = z;
  // assign UART_TXD = z;
  // assign LEDG[0] = AUD_DACLRCK;
  // assign AUD_DACDAT = dt;
  // always_ff @(posedge AUD_BCLK) begin
    // if (AUD_DACLRCK) begin
      // if (cnt < 1) begin
        // cnt <= cnt + 1;
      // end else if(cnt == 1) begin
        // z <= dt;
        // cnt <= cnt + 1;
      // end
    // end else begin
      // cnt <= 0;
    // end
  // end
endmodule
