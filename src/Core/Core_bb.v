
module Core (
	audio_and_video_config_external_interface_SDAT,
	audio_and_video_config_external_interface_SCLK,
	audio_external_interface_ADCDAT,
	audio_external_interface_ADCLRCK,
	audio_external_interface_BCLK,
	audio_external_interface_DACDAT,
	audio_external_interface_DACLRCK,
	clk_clk,
	reset_reset_n);	

	inout		audio_and_video_config_external_interface_SDAT;
	output		audio_and_video_config_external_interface_SCLK;
	input		audio_external_interface_ADCDAT;
	input		audio_external_interface_ADCLRCK;
	input		audio_external_interface_BCLK;
	output		audio_external_interface_DACDAT;
	input		audio_external_interface_DACLRCK;
	input		clk_clk;
	input		reset_reset_n;
endmodule
