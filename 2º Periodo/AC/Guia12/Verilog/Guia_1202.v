/*
Guia_1202.v
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
  ram_1bit_cell cell1 (d_out[1], d_in[1," 1 "], cs, rw, clk, rst);
  ram_1bit_cell cell2 (d_out[2], d_in[2], cs, rw, clk, rst);
  ram_1bit_cell cell3 (d_out[3], d_in[3], cs, rw, clk, rst);
endmodule

module ram_2x4 (
    output [3:0] d_out,
    input [3:0] d_in,
    input addr, cs, rw, clk, rst
);
  wire cs0, cs1;
  wire [3:0] out0, out1;
  
  assign cs0 = cs & ~addr;
  assign cs1 = cs & addr;
  
  ram_1x4 mem0 (out0, d_in, cs0, rw, clk, rst);
  ram_1x4 mem1 (out1, d_in, cs1, rw, clk, rst);
  
  assign d_out = (addr) ? out1 : out0;
endmodule

module Guia_1202_tb;
  reg [3:0] d_in;
  reg addr, cs, rw, clk, rst;
  wire [3:0] d_out;
  
  ram_2x4 dut (d_out, d_in, addr, cs, rw, clk, rst);
  
  initial begin
    clk=0; rst=1; cs=0; rw=0; d_in=4'hX; addr=0;
    #10 rst=0;
    #10 cs=1; rw=1; addr=0; d_in=4'h5;
    #10 rw=0; d_in=4'hX;
    #10 rw=1; addr=1; d_in=4'h9;
    #10 rw=0; d_in=4'hX;
    #10 addr=0; $display("T=%3d, Read Addr 0: %h", $time, d_out);
    #10 addr=1; $display("T=%3d, Read Addr 1: %h", $time, d_out);
    #10 $finish;
  end
  always #5 clk = ~clk;
endmodule