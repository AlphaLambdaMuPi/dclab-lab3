
module Core (
	audio_and_video_config_external_interface_SDAT,
	audio_and_video_config_external_interface_SCLK,
	audio_external_interface_ADCDAT,
	audio_external_interface_ADCLRCK,
	audio_external_interface_BCLK,
	audio_external_interface_DACDAT,
	audio_external_interface_DACLRCK,
	clk_clk,
	clock_bridge_out_clk_clk,
	reset_reset_n,
	sdram_controller_wire_addr,
	sdram_controller_wire_ba,
	sdram_controller_wire_cas_n,
	sdram_controller_wire_cke,
	sdram_controller_wire_cs_n,
	sdram_controller_wire_dq,
	sdram_controller_wire_dqm,
	sdram_controller_wire_ras_n,
	sdram_controller_wire_we_n,
	sram_external_interface_DQ,
	sram_external_interface_ADDR,
	sram_external_interface_LB_N,
	sram_external_interface_UB_N,
	sram_external_interface_CE_N,
	sram_external_interface_OE_N,
	sram_external_interface_WE_N,
	sys_sdram_pll_sdram_clk_clk,
	video_vga_controller_external_interface_CLK,
	video_vga_controller_external_interface_HS,
	video_vga_controller_external_interface_VS,
	video_vga_controller_external_interface_BLANK,
	video_vga_controller_external_interface_SYNC,
	video_vga_controller_external_interface_DATA_EN,
	video_vga_controller_external_interface_R,
	video_vga_controller_external_interface_G,
	video_vga_controller_external_interface_B);	

	inout		audio_and_video_config_external_interface_SDAT;
	output		audio_and_video_config_external_interface_SCLK;
	input		audio_external_interface_ADCDAT;
	input		audio_external_interface_ADCLRCK;
	input		audio_external_interface_BCLK;
	output		audio_external_interface_DACDAT;
	input		audio_external_interface_DACLRCK;
	input		clk_clk;
	output		clock_bridge_out_clk_clk;
	input		reset_reset_n;
	output	[12:0]	sdram_controller_wire_addr;
	output	[1:0]	sdram_controller_wire_ba;
	output		sdram_controller_wire_cas_n;
	output		sdram_controller_wire_cke;
	output		sdram_controller_wire_cs_n;
	inout	[31:0]	sdram_controller_wire_dq;
	output	[3:0]	sdram_controller_wire_dqm;
	output		sdram_controller_wire_ras_n;
	output		sdram_controller_wire_we_n;
	inout	[15:0]	sram_external_interface_DQ;
	output	[19:0]	sram_external_interface_ADDR;
	output		sram_external_interface_LB_N;
	output		sram_external_interface_UB_N;
	output		sram_external_interface_CE_N;
	output		sram_external_interface_OE_N;
	output		sram_external_interface_WE_N;
	output		sys_sdram_pll_sdram_clk_clk;
	output		video_vga_controller_external_interface_CLK;
	output		video_vga_controller_external_interface_HS;
	output		video_vga_controller_external_interface_VS;
	output		video_vga_controller_external_interface_BLANK;
	output		video_vga_controller_external_interface_SYNC;
	output		video_vga_controller_external_interface_DATA_EN;
	output	[7:0]	video_vga_controller_external_interface_R;
	output	[7:0]	video_vga_controller_external_interface_G;
	output	[7:0]	video_vga_controller_external_interface_B;
endmodule
