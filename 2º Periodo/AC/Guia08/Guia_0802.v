/*
Guia_0802.v
Aluno: Gabriel Egídio Santos Beloni
Matrícula: 885080
*/
// Reutilizando os módulos do Guia_0801.v presente nos arquivos enviados.
module halfAdder(output cout, output sum, input a, b);
  xor X1(sum, a, b);
  and A1(cout, a, b);
endmodule

module fullAdder(output cout, output sum, input a, b, cin);
  wire s0, c0, c1;
  halfAdder HA1(c0, s0, a, b);
  halfAdder HA2(c1, sum, s0, cin);
  or O1(cout, c0, c1);
endmodule

module subtractor_5bits(output overflow, output [4:0] diff, input [4:0] a, b);
  wire [4:0] b_inv;
  xor X0(b_inv[0], b[0], 1'b1);
  xor X1(b_inv[1], b[1], 1'b1);
  xor X2(b_inv[2], b[2], 1'b1);
  xor X3(b_inv[3], b[3], 1'b1);
  xor X4(b_inv[4], b[4], 1'b1);
  
  wire [4:0] carries;
  fullAdder FA0(carries[0], diff[0], a[0], b_inv[0], 1'b1);
  fullAdder FA1(carries[1], diff[1], a[1], b_inv[1], carries[0]);
  fullAdder FA2(carries[2], diff[2], a[2], b_inv[2], carries[1]);
  fullAdder FA3(carries[3], diff[3], a[3], b_inv[3], carries[2]);
  fullAdder FA4(overflow,   diff[4], a[4], b_inv[4], carries[3]);
endmodule

module Guia_0802_tb;
  reg [4:0] a, b;
  wire [4:0] diff;
  subtractor_5bits dut( , diff, a, b);
  initial begin
    $display("Guia_0802 - Subtrator 5 bits");
    $display("   a    -    b    = diff");
    $display("--------------------------");
    a = 5'd10; b = 5'd7; #1; $display("%5d - %5d = %5d", a, b, diff);
    a = 5'd20; b = 5'd5; #1; $display("%5d - %5d = %5d", a, b, diff);
    a = 5'd7;  b = 5'd10;#1; $display("%5d - %5d = %5d (C2)", a, b, diff);
  end
endmodule