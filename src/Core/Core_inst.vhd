	component Core is
		port (
			audio_and_video_config_external_interface_SDAT : inout std_logic := 'X'; -- SDAT
			audio_and_video_config_external_interface_SCLK : out   std_logic;        -- SCLK
			audio_external_interface_ADCDAT                : in    std_logic := 'X'; -- ADCDAT
			audio_external_interface_ADCLRCK               : in    std_logic := 'X'; -- ADCLRCK
			audio_external_interface_BCLK                  : in    std_logic := 'X'; -- BCLK
			audio_external_interface_DACDAT                : out   std_logic;        -- DACDAT
			audio_external_interface_DACLRCK               : in    std_logic := 'X'; -- DACLRCK
			clk_clk                                        : in    std_logic := 'X'; -- clk
			reset_reset_n                                  : in    std_logic := 'X'  -- reset_n
		);
	end component Core;

	u0 : component Core
		port map (
			audio_and_video_config_external_interface_SDAT => CONNECTED_TO_audio_and_video_config_external_interface_SDAT, -- audio_and_video_config_external_interface.SDAT
			audio_and_video_config_external_interface_SCLK => CONNECTED_TO_audio_and_video_config_external_interface_SCLK, --                                          .SCLK
			audio_external_interface_ADCDAT                => CONNECTED_TO_audio_external_interface_ADCDAT,                --                  audio_external_interface.ADCDAT
			audio_external_interface_ADCLRCK               => CONNECTED_TO_audio_external_interface_ADCLRCK,               --                                          .ADCLRCK
			audio_external_interface_BCLK                  => CONNECTED_TO_audio_external_interface_BCLK,                  --                                          .BCLK
			audio_external_interface_DACDAT                => CONNECTED_TO_audio_external_interface_DACDAT,                --                                          .DACDAT
			audio_external_interface_DACLRCK               => CONNECTED_TO_audio_external_interface_DACLRCK,               --                                          .DACLRCK
			clk_clk                                        => CONNECTED_TO_clk_clk,                                        --                                       clk.clk
			reset_reset_n                                  => CONNECTED_TO_reset_reset_n                                   --                                     reset.reset_n
		);

