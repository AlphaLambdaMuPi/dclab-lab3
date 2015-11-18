	Core u0 (
		.audio_and_video_config_external_interface_SDAT (<connected-to-audio_and_video_config_external_interface_SDAT>), // audio_and_video_config_external_interface.SDAT
		.audio_and_video_config_external_interface_SCLK (<connected-to-audio_and_video_config_external_interface_SCLK>), //                                          .SCLK
		.audio_external_interface_ADCDAT                (<connected-to-audio_external_interface_ADCDAT>),                //                  audio_external_interface.ADCDAT
		.audio_external_interface_ADCLRCK               (<connected-to-audio_external_interface_ADCLRCK>),               //                                          .ADCLRCK
		.audio_external_interface_BCLK                  (<connected-to-audio_external_interface_BCLK>),                  //                                          .BCLK
		.audio_external_interface_DACDAT                (<connected-to-audio_external_interface_DACDAT>),                //                                          .DACDAT
		.audio_external_interface_DACLRCK               (<connected-to-audio_external_interface_DACLRCK>),               //                                          .DACLRCK
		.clk_clk                                        (<connected-to-clk_clk>),                                        //                                       clk.clk
		.nios2_cpu_debug_reset_request_reset            (<connected-to-nios2_cpu_debug_reset_request_reset>),            //             nios2_cpu_debug_reset_request.reset
		.reset_reset_n                                  (<connected-to-reset_reset_n>),                                  //                                     reset.reset_n
		.clock_bridge_out_clk_clk                       (<connected-to-clock_bridge_out_clk_clk>)                        //                      clock_bridge_out_clk.clk
	);

