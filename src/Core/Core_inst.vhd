	component Core is
		port (
			audio_and_video_config_external_interface_SDAT  : inout std_logic                     := 'X';             -- SDAT
			audio_and_video_config_external_interface_SCLK  : out   std_logic;                                        -- SCLK
			audio_external_interface_ADCDAT                 : in    std_logic                     := 'X';             -- ADCDAT
			audio_external_interface_ADCLRCK                : in    std_logic                     := 'X';             -- ADCLRCK
			audio_external_interface_BCLK                   : in    std_logic                     := 'X';             -- BCLK
			audio_external_interface_DACDAT                 : out   std_logic;                                        -- DACDAT
			audio_external_interface_DACLRCK                : in    std_logic                     := 'X';             -- DACLRCK
			clk_clk                                         : in    std_logic                     := 'X';             -- clk
			clock_bridge_out_clk_clk                        : out   std_logic;                                        -- clk
			reset_reset_n                                   : in    std_logic                     := 'X';             -- reset_n
			sdram_controller_wire_addr                      : out   std_logic_vector(12 downto 0);                    -- addr
			sdram_controller_wire_ba                        : out   std_logic_vector(1 downto 0);                     -- ba
			sdram_controller_wire_cas_n                     : out   std_logic;                                        -- cas_n
			sdram_controller_wire_cke                       : out   std_logic;                                        -- cke
			sdram_controller_wire_cs_n                      : out   std_logic;                                        -- cs_n
			sdram_controller_wire_dq                        : inout std_logic_vector(31 downto 0) := (others => 'X'); -- dq
			sdram_controller_wire_dqm                       : out   std_logic_vector(3 downto 0);                     -- dqm
			sdram_controller_wire_ras_n                     : out   std_logic;                                        -- ras_n
			sdram_controller_wire_we_n                      : out   std_logic;                                        -- we_n
			sram_external_interface_DQ                      : inout std_logic_vector(15 downto 0) := (others => 'X'); -- DQ
			sram_external_interface_ADDR                    : out   std_logic_vector(19 downto 0);                    -- ADDR
			sram_external_interface_LB_N                    : out   std_logic;                                        -- LB_N
			sram_external_interface_UB_N                    : out   std_logic;                                        -- UB_N
			sram_external_interface_CE_N                    : out   std_logic;                                        -- CE_N
			sram_external_interface_OE_N                    : out   std_logic;                                        -- OE_N
			sram_external_interface_WE_N                    : out   std_logic;                                        -- WE_N
			sys_sdram_pll_sdram_clk_clk                     : out   std_logic;                                        -- clk
			video_vga_controller_external_interface_CLK     : out   std_logic;                                        -- CLK
			video_vga_controller_external_interface_HS      : out   std_logic;                                        -- HS
			video_vga_controller_external_interface_VS      : out   std_logic;                                        -- VS
			video_vga_controller_external_interface_BLANK   : out   std_logic;                                        -- BLANK
			video_vga_controller_external_interface_SYNC    : out   std_logic;                                        -- SYNC
			video_vga_controller_external_interface_DATA_EN : out   std_logic;                                        -- DATA_EN
			video_vga_controller_external_interface_R       : out   std_logic_vector(7 downto 0);                     -- R
			video_vga_controller_external_interface_G       : out   std_logic_vector(7 downto 0);                     -- G
			video_vga_controller_external_interface_B       : out   std_logic_vector(7 downto 0)                      -- B
		);
	end component Core;

	u0 : component Core
		port map (
			audio_and_video_config_external_interface_SDAT  => CONNECTED_TO_audio_and_video_config_external_interface_SDAT,  -- audio_and_video_config_external_interface.SDAT
			audio_and_video_config_external_interface_SCLK  => CONNECTED_TO_audio_and_video_config_external_interface_SCLK,  --                                          .SCLK
			audio_external_interface_ADCDAT                 => CONNECTED_TO_audio_external_interface_ADCDAT,                 --                  audio_external_interface.ADCDAT
			audio_external_interface_ADCLRCK                => CONNECTED_TO_audio_external_interface_ADCLRCK,                --                                          .ADCLRCK
			audio_external_interface_BCLK                   => CONNECTED_TO_audio_external_interface_BCLK,                   --                                          .BCLK
			audio_external_interface_DACDAT                 => CONNECTED_TO_audio_external_interface_DACDAT,                 --                                          .DACDAT
			audio_external_interface_DACLRCK                => CONNECTED_TO_audio_external_interface_DACLRCK,                --                                          .DACLRCK
			clk_clk                                         => CONNECTED_TO_clk_clk,                                         --                                       clk.clk
			clock_bridge_out_clk_clk                        => CONNECTED_TO_clock_bridge_out_clk_clk,                        --                      clock_bridge_out_clk.clk
			reset_reset_n                                   => CONNECTED_TO_reset_reset_n,                                   --                                     reset.reset_n
			sdram_controller_wire_addr                      => CONNECTED_TO_sdram_controller_wire_addr,                      --                     sdram_controller_wire.addr
			sdram_controller_wire_ba                        => CONNECTED_TO_sdram_controller_wire_ba,                        --                                          .ba
			sdram_controller_wire_cas_n                     => CONNECTED_TO_sdram_controller_wire_cas_n,                     --                                          .cas_n
			sdram_controller_wire_cke                       => CONNECTED_TO_sdram_controller_wire_cke,                       --                                          .cke
			sdram_controller_wire_cs_n                      => CONNECTED_TO_sdram_controller_wire_cs_n,                      --                                          .cs_n
			sdram_controller_wire_dq                        => CONNECTED_TO_sdram_controller_wire_dq,                        --                                          .dq
			sdram_controller_wire_dqm                       => CONNECTED_TO_sdram_controller_wire_dqm,                       --                                          .dqm
			sdram_controller_wire_ras_n                     => CONNECTED_TO_sdram_controller_wire_ras_n,                     --                                          .ras_n
			sdram_controller_wire_we_n                      => CONNECTED_TO_sdram_controller_wire_we_n,                      --                                          .we_n
			sram_external_interface_DQ                      => CONNECTED_TO_sram_external_interface_DQ,                      --                   sram_external_interface.DQ
			sram_external_interface_ADDR                    => CONNECTED_TO_sram_external_interface_ADDR,                    --                                          .ADDR
			sram_external_interface_LB_N                    => CONNECTED_TO_sram_external_interface_LB_N,                    --                                          .LB_N
			sram_external_interface_UB_N                    => CONNECTED_TO_sram_external_interface_UB_N,                    --                                          .UB_N
			sram_external_interface_CE_N                    => CONNECTED_TO_sram_external_interface_CE_N,                    --                                          .CE_N
			sram_external_interface_OE_N                    => CONNECTED_TO_sram_external_interface_OE_N,                    --                                          .OE_N
			sram_external_interface_WE_N                    => CONNECTED_TO_sram_external_interface_WE_N,                    --                                          .WE_N
			sys_sdram_pll_sdram_clk_clk                     => CONNECTED_TO_sys_sdram_pll_sdram_clk_clk,                     --                   sys_sdram_pll_sdram_clk.clk
			video_vga_controller_external_interface_CLK     => CONNECTED_TO_video_vga_controller_external_interface_CLK,     --   video_vga_controller_external_interface.CLK
			video_vga_controller_external_interface_HS      => CONNECTED_TO_video_vga_controller_external_interface_HS,      --                                          .HS
			video_vga_controller_external_interface_VS      => CONNECTED_TO_video_vga_controller_external_interface_VS,      --                                          .VS
			video_vga_controller_external_interface_BLANK   => CONNECTED_TO_video_vga_controller_external_interface_BLANK,   --                                          .BLANK
			video_vga_controller_external_interface_SYNC    => CONNECTED_TO_video_vga_controller_external_interface_SYNC,    --                                          .SYNC
			video_vga_controller_external_interface_DATA_EN => CONNECTED_TO_video_vga_controller_external_interface_DATA_EN, --                                          .DATA_EN
			video_vga_controller_external_interface_R       => CONNECTED_TO_video_vga_controller_external_interface_R,       --                                          .R
			video_vga_controller_external_interface_G       => CONNECTED_TO_video_vga_controller_external_interface_G,       --                                          .G
			video_vga_controller_external_interface_B       => CONNECTED_TO_video_vga_controller_external_interface_B        --                                          .B
		);

