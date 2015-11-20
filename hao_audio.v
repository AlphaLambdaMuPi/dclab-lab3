// (C) 2001-2015 Altera Corporation. All rights reserved.
// Your use of Altera Corporation's design tools, logic functions and other 
// software and tools, and its AMPP partner logic functions, and any output 
// files any of the foregoing (including device programming or simulation 
// files), and any associated documentation or information are expressly subject 
// to the terms and conditions of the Altera Program License Subscription 
// Agreement, Altera MegaCore Function License Agreement, or other applicable 
// license agreement, including, without limitation, that your use is for the 
// sole purpose of programming logic devices manufactured by Altera and sold by 
// Altera or its authorized distributors.  Please refer to the applicable 
// agreement for further details.


// THIS FILE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THIS FILE OR THE USE OR OTHER DEALINGS
// IN THIS FILE.

/******************************************************************************
 *                                                                            *
 * This module is a rom for auto initializing the on board audio chip.        *
 *                                                                            *
 ******************************************************************************/

module altera_up_av_config_auto_init_ob_audio (
	// Inputs
	rom_address,

	// Bidirectionals

	// Outputs
	rom_data
);

/*****************************************************************************
 *                           Parameter Declarations                          *
 *****************************************************************************/

parameter AUD_LINE_IN_LC	= 9'b010010111;
parameter AUD_LINE_IN_RC	= 9'b010010111;
parameter AUD_LINE_OUT_LC	= 9'b001111001;
parameter AUD_LINE_OUT_RC	= 9'b001111001;
parameter AUD_ADC_PATH		= 9'b000100101;
parameter AUD_DAC_PATH		= 9'b000000000;
parameter AUD_POWER			  = 9'b000000000;
parameter AUD_DATA_FORMAT	= 9'b001000010;
parameter AUD_SAMPLE_CTRL	= 9'b000011001;
parameter AUD_SET_ACTIVE	= 9'b000000001;

  // 15'b0000000010010111,
  // 15'b0000001010010111,
  // 15'b0000010001111001,
  // 15'b0000011001111001,
  // 15'b0000100000010101,
  // 15'b0000101000000000,
  // 15'b0000110000000000,
  // 15'b0000111001000010,
  // 15'b0001000000011001
  // 15'b0001001000000001, 
/*****************************************************************************
 *                             Port Declarations                             *
 *****************************************************************************/
// Inputs
input			[ 5: 0]	rom_address;

// Bidirectionals

// Outputs
output		[26: 0]	rom_data;

/*****************************************************************************
 *                           Constant Declarations                           *
 *****************************************************************************/

// States

/*****************************************************************************
 *                 Internal Wires and Registers Declarations                 *
 *****************************************************************************/
// Internal Wires
reg			[23: 0]	data;

// Internal Registers

// State Machine Registers

/*****************************************************************************
 *                         Finite State Machine(s)                           *
 *****************************************************************************/


/*****************************************************************************
 *                             Sequential Logic                              *
 *****************************************************************************/

// Output Registers

// Internal Registers

/*****************************************************************************
 *                            Combinational Logic                            *
 *****************************************************************************/

// Output Assignments
assign rom_data = {data[23:16], 1'b0, 
						data[15: 8], 1'b0, 
						data[ 7: 0], 1'b0};

// Internal Assignments
always @(*)
begin
	case (rom_address)
	//	Audio Config Data
	0		:	data	<=	{8'h34, 7'h0, AUD_LINE_IN_LC};
	1		:	data	<=	{8'h34, 7'h1, AUD_LINE_IN_RC};
	2		:	data	<=	{8'h34, 7'h2, AUD_LINE_OUT_LC};
	3		:	data	<=	{8'h34, 7'h3, AUD_LINE_OUT_RC};
	4		:	data	<=	{8'h34, 7'h4, AUD_ADC_PATH};
	5		:	data	<=	{8'h34, 7'h5, AUD_DAC_PATH};
	6		:	data	<=	{8'h34, 7'h6, AUD_POWER};
	7		:	data	<=	{8'h34, 7'h7, AUD_DATA_FORMAT};
	8		:	data	<=	{8'h34, 7'h8, AUD_SAMPLE_CTRL};
	9		:	data	<=	{8'h34, 7'h9, AUD_SET_ACTIVE};
	default	:	data	<=	{8'h00, 7'h0, 9'h000};
	endcase
end

/*****************************************************************************
 *                              Internal Modules                             *
 *****************************************************************************/


endmodule
