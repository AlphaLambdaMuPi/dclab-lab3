	component Core is
		port (
			clk_clk         : in  std_logic := 'X'; -- clk
			reset_reset_n   : in  std_logic := 'X'; -- reset_n
			altpll_0_c0_clk : out std_logic         -- clk
		);
	end component Core;

	u0 : component Core
		port map (
			clk_clk         => CONNECTED_TO_clk_clk,         --         clk.clk
			reset_reset_n   => CONNECTED_TO_reset_reset_n,   --       reset.reset_n
			altpll_0_c0_clk => CONNECTED_TO_altpll_0_c0_clk  -- altpll_0_c0.clk
		);

