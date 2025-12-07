/*
Guia_1201.v
Aluno: Gabriel Egídio Santos Beloni
Matrícula: 885080
*/
module jk_ff (output reg q, input j, k, clk, rst);
  always @(posedge clk or posedge rst) begin
    if (rst)
      q <= 1'b0;
    else
      case ({j, k})
        2'b00: q <= q;
        2'b01: q <= 1'b0;
        2'b10: q <= 1'b1;
        2'b11: q <= ~q;
      endcase
  end
endmodule
module ram_1bit_cell (output q, input d, cs, rw, clk, rst);
  wire j, k, enable;
  assign j = d;
  assign k = ~d;
  assign enable = cs & rw;
  
  reg q_reg;
  jk_ff ff (.q(q_reg), .j(j), .k(k), .clk(clk), .rst(rst));
  always @(posedge clk) begin
    if (enable)
      q_reg <= (j & ~k) ? 1'b1 : ((~j & k) ? 1'b0 : q_reg);
  end
  assign q = (cs) ? q_reg : 1'bz;
endmodule

module ram_1x4 (output [3:0] d_out, input [3:0] d_in, input cs, rw, clk, rst);
  ram_1bit_cell cell0 (d_out[0], d_in[0], cs, rw, clk, rst);
  ram_1bit_cell cell1 (d_out[1], d_in[1], cs, rw, clk, rst);
  ram_1bit_cell cell2 (d_out[2], d_in[2], cs, rw, clk, rst);
  ram_1bit_cell cell3 (d_out[3], d_in[3], cs, rw, clk, rst);
endmodule
module Guia_1201_tb;
  reg [3:0] d_in;
  reg cs, rw, clk, rst;
  wire [3:0] d_out;
  
  ram_1x4 dut (d_out, d_in, cs, rw, clk, rst);
  
  initial begin
    clk=0; rst=1; cs=0; rw=0; d_in=4'hX;
    #10 rst=0;
    #10 cs=1; rw=1; d_in=4'h5;
    #10 rw=0; d_in=4'hX;
    #10 $display("T=%3d, Read (CS=1): %h", $time, d_out);
    #10 cs=0;
    #10 $display("T=%3d, Read (CS=0): %z", $time, d_out);
    #10 $finish;
  end
  always #5 clk = ~clk;
endmodule