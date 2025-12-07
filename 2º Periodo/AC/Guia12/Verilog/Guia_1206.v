/*
Guia_1206.v
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

module ram_2x8 (
    output [7:0] d_out,
    input [7:0] d_in,
    input addr, cs, rw, clk, rst
);
  wire cs0, cs1;
  wire [3:0] outL0, outH0, outL1, outH1;

  assign cs0 = cs & ~addr;
  assign cs1 = cs & addr;

  ram_1x4 memL0 (outL0, d_in[3:0], cs0, rw, clk, rst);
  ram_1x4 memH0 (outH0, d_in[7:4], cs0, rw, clk, rst);
  
  ram_1x4 memL1 (outL1, d_in[3:0], cs1, rw, clk, rst);
  ram_1x4 memH1 (outH1, d_in[7:4], cs1, rw, clk, rst);
  
  assign d_out[3:0] = (addr) ? outL1 : outL0;
  assign d_out[7:4] = (addr) ? outH1 : outH0;
endmodule

module ram_4x8 (
    output [7:0] d_out,
    input [7:0] d_in,
    input [1:0] addr, 
    input cs, rw, clk, rst
);
  wire cs0, cs1;
  wire [7:0] out0, out1;

  assign cs0 = cs & ~addr[1];
  assign cs1 = cs & addr[1];
  
  ram_2x8 mem0 (out0, d_in, addr[0], cs0, rw, clk, rst);
  ram_2x8 mem1 (out1, d_in, addr[0], cs1, rw, clk, rst);
  
  assign d_out = (addr[1]) ? out1 : out0;
endmodule

module ram_4x16 (
    output [15:0] d_out,
    input [15:0] d_in,
    input [1:0] addr, 
    input cs, rw, clk, rst
);
  wire [7:0] out_L, out_H;
  
  ram_4x8 mem_L (out_L, d_in[7:0],   addr, cs, rw, clk, rst);
  ram_4x8 mem_H (out_H, d_in[15:8], addr, cs, rw, clk, rst);
  
  assign d_out = {out_H, out_L};
endmodule

module Guia_1206_tb;
  reg [15:0] d_in; reg [1:0] addr;
  reg cs, rw, clk, rst;
  wire [15:0] d_out;
  
  ram_4x16 dut (d_out, d_in, addr, cs, rw, clk, rst);
  
  initial begin
    clk=0; rst=1; cs=0; rw=0;
    #10 rst=0;
    #10 cs=1; rw=1; addr=2'b11; d_in=16'h1234;
    #10 rw=0;
    #10 addr=2'b11; $display("T=%3d, Read Addr 3: %h", $time, d_out);
    #10 $finish;
  end
  always #5 clk = ~clk;
endmodule