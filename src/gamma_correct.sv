module Gamma_Correct(
  input [4:0] in_color,
  output [7:0] out_color
);
  wire [7:0] res;
  always_comb begin
    case (in_color)
      8'd0: res = 8'd0;
      8'd1: res = 8'd110;
      8'd2: res = 8'd122;
      8'd3: res = 8'd132;
      8'd4: res = 8'd135;
      8'd5: res = 8'd139;
      8'd6: res = 8'd142;
      8'd7: res = 8'd145;
      8'd8: res = 8'd148;
      8'd9: res = 8'd151;
      8'd10: res = 8'd153;
      8'd11: res = 8'd154;
      8'd12: res = 8'd155;
      8'd13: res = 8'd159;
      8'd14: res = 8'd162;
      8'd15: res = 8'd164;
      8'd16: res = 8'd167;
      8'd17: res = 8'd169;
      8'd18: res = 8'd172;
      8'd19: res = 8'd174;
      8'd20: res = 8'd177;
      8'd21: res = 8'd180;
      8'd22: res = 8'd184;
      8'd23: res = 8'd195;
      8'd24: res = 8'd207;
      8'd25: res = 8'd215;
      8'd26: res = 8'd220;
      8'd27: res = 8'd225;
      8'd28: res = 8'd230;
      8'd29: res = 8'd237;
      8'd30: res = 8'd244;
      8'd31: res = 8'd255;
    endcase
  end
  assign out_color = res;
endmodule
