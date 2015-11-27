-- Core_alt_vip_gam_0_tb.vhd


library IEEE;
library altera;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;
use altera.alt_cusp151_package.all;

entity Core_alt_vip_gam_0_tb is
end entity Core_alt_vip_gam_0_tb;

architecture rtl of Core_alt_vip_gam_0_tb is
	component alt_cusp151_clock_reset is
		port (
			clock : out std_logic;
			reset : out std_logic
		);
	end component alt_cusp151_clock_reset;

	component Core_alt_vip_gam_0 is
		generic (
			PARAMETERISATION           : string := "<gammaParams><GAM_NAME>MyGammaCorrector</GAM_NAME><GAM_CHANNEL_COUNT>3</GAM_CHANNEL_COUNT><GAM_CHANNELS_ARE_IN_PAR>false</GAM_CHANNELS_ARE_IN_PAR><GAM_BPS>8</GAM_BPS><GAM_COMPILE_TIME>false</GAM_COMPILE_TIME><GAM_LUT></GAM_LUT></gammaParams>";
			AUTO_DEVICE_FAMILY         : string := "";
			AUTO_GAMMA_LUT_CLOCKS_SAME : string := "0"
		);
		port (
			clock                     : in  std_logic                     := 'X';
			din_data                  : in  std_logic_vector(29 downto 0) := (others => 'X');
			din_endofpacket           : in  std_logic                     := 'X';
			din_ready                 : out std_logic;
			din_startofpacket         : in  std_logic                     := 'X';
			din_valid                 : in  std_logic                     := 'X';
			dout_data                 : out std_logic_vector(29 downto 0);
			dout_endofpacket          : out std_logic;
			dout_ready                : in  std_logic                     := 'X';
			dout_startofpacket        : out std_logic;
			dout_valid                : out std_logic;
			gamma_lut_0_av_address    : in  std_logic_vector(10 downto 0) := (others => 'X');
			gamma_lut_0_av_chipselect : in  std_logic                     := 'X';
			gamma_lut_0_av_readdata   : out std_logic_vector(9 downto 0);
			gamma_lut_0_av_write      : in  std_logic                     := 'X';
			gamma_lut_0_av_writedata  : in  std_logic_vector(9 downto 0)  := (others => 'X');
			gamma_lut_1_av_address    : in  std_logic_vector(10 downto 0) := (others => 'X');
			gamma_lut_1_av_chipselect : in  std_logic                     := 'X';
			gamma_lut_1_av_readdata   : out std_logic_vector(9 downto 0);
			gamma_lut_1_av_write      : in  std_logic                     := 'X';
			gamma_lut_1_av_writedata  : in  std_logic_vector(9 downto 0)  := (others => 'X');
			gamma_lut_2_av_address    : in  std_logic_vector(10 downto 0) := (others => 'X');
			gamma_lut_2_av_chipselect : in  std_logic                     := 'X';
			gamma_lut_2_av_readdata   : out std_logic_vector(9 downto 0);
			gamma_lut_2_av_write      : in  std_logic                     := 'X';
			gamma_lut_2_av_writedata  : in  std_logic_vector(9 downto 0)  := (others => 'X');
			reset                     : in  std_logic                     := 'X'
		);
	end component Core_alt_vip_gam_0;

	signal dut_din_ready     : std_logic;                    -- dut:din_ready -> din_tester:data
	signal din_tester_q      : std_logic_vector(0 downto 0); -- din_tester:q -> dut:din_valid
	signal builtin_1_w1_q    : std_logic_vector(0 downto 0); -- ["1", builtin_1_w1:q, "1"] -> [din_tester:ena, dut:dout_ready]
	signal clocksource_clock : std_logic;                    -- clocksource:clock -> [dut:clock, din_tester:clock]
	signal clocksource_reset : std_logic;                    -- clocksource:reset -> din_tester:reset

begin

	builtin_1_w1_q <= "1";

	clocksource : component alt_cusp151_clock_reset
		port map (
			clock => clocksource_clock, -- clock.clk
			reset => clocksource_reset  --      .reset
		);

	dut : component Core_alt_vip_gam_0
		generic map (
			PARAMETERISATION           => "<gammaParams><GAM_NAME>MyGammaCorrector</GAM_NAME><GAM_CHANNEL_COUNT>3</GAM_CHANNEL_COUNT><GAM_CHANNELS_ARE_IN_PAR>true</GAM_CHANNELS_ARE_IN_PAR><GAM_BPS>10</GAM_BPS><GAM_COMPILE_TIME>false</GAM_COMPILE_TIME><GAM_LUT /></gammaParams>",
			AUTO_DEVICE_FAMILY         => "Cyclone IV E",
			AUTO_GAMMA_LUT_CLOCKS_SAME => "0,0,0"
		)
		port map (
			clock                     => clocksource_clock, --       clock.clk
			reset                     => open,              --       reset.reset
			din_ready                 => dut_din_ready,     --         din.ready
			din_valid                 => din_tester_q(0),   --            .valid
			din_data                  => open,              --            .data
			din_startofpacket         => open,              --            .startofpacket
			din_endofpacket           => open,              --            .endofpacket
			dout_ready                => '1',               --        dout.ready
			dout_valid                => open,              --            .valid
			dout_data                 => open,              --            .data
			dout_startofpacket        => open,              --            .startofpacket
			dout_endofpacket          => open,              --            .endofpacket
			gamma_lut_0_av_chipselect => open,              -- gamma_lut_0.chipselect
			gamma_lut_0_av_write      => open,              --            .write
			gamma_lut_0_av_address    => open,              --            .address
			gamma_lut_0_av_writedata  => open,              --            .writedata
			gamma_lut_0_av_readdata   => open,              --            .readdata
			gamma_lut_1_av_chipselect => open,              -- gamma_lut_1.chipselect
			gamma_lut_1_av_write      => open,              --            .write
			gamma_lut_1_av_address    => open,              --            .address
			gamma_lut_1_av_writedata  => open,              --            .writedata
			gamma_lut_1_av_readdata   => open,              --            .readdata
			gamma_lut_2_av_chipselect => open,              -- gamma_lut_2.chipselect
			gamma_lut_2_av_write      => open,              --            .write
			gamma_lut_2_av_address    => open,              --            .address
			gamma_lut_2_av_writedata  => open,              --            .writedata
			gamma_lut_2_av_readdata   => open               --            .readdata
		);

	din_tester : process (clocksource_clock, clocksource_reset)
	begin
		if clocksource_reset = '1' then
			din_tester_q(0) <= '0';
		elsif clocksource_clock'EVENT and clocksource_clock = '1' and builtin_1_w1_q(0) = '1' then
			din_tester_q(0) <= dut_din_ready;
		end if;
	end process;

end architecture rtl; -- of Core_alt_vip_gam_0_tb
