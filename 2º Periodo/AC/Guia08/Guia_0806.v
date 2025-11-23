/*
Guia_0806.v
Aluno: Gabriel Egídio Santos Beloni
Matrícula: 885080
*/
// Reutilizando o modulo novamente nessa questão.
module fullAdder(output cout, output sum, input a, b, cin);
  wire s0, c0, c1;
  xor X1(s0, a, b); and A1(c0, a, b);
  xor X2(sum, s0, cin); and A2(c1, s0, cin);
  or O1(cout, c0, c1);
endmodule

module adder_subtractor_6bits(output [5:0] s, input [5:0] a, b, input subtract);
  wire [5:0] b_mod;
  xor X0(b_mod[0], b[0], subtract); xor X1(b_mod[1], b[1], subtract);
  xor X2(b_mod[2], b[2], subtract); xor X3(b_mod[3], b[3], subtract);
  xor X4(b_mod[4], b[4], subtract); xor X5(b_mod[5], b[5], subtract);
  
  wire [5:0] carries;
  fullAdder FA0(carries[0], s[0], a[0], b_mod[0], subtract);
  fullAdder FA1(carries[1], s[1], a[1], b_mod[1], carries[0]);
  fullAdder FA2(carries[2], s[2], a[2], b_mod[2], carries[1]);
  fullAdder FA3(carries[3], s[3], a[3], b_mod[3], carries[2]);
  fullAdder FA4(carries[4], s[4], a[4], b_mod[4], carries[3]);
  fullAdder FA5(           , s[5], a[5], b_mod[5], carries[4]);
endmodule

module Guia_0806_tb;
  reg [5:0] a, b;
  reg sub;
  wire [5:0] s;
  adder_subtractor_6bits dut(s, a, b, sub);
  initial begin
    $display("Guia_0806 - Somador/Subtrator 6 bits");
    $display("sub | a  | b  |  s");
    $display("---------------------");
    a=6'd20; b=6'd10; sub=0; #1; $display(" %b  |%2d|%2d|%3d (soma)", sub, a,b,s);
    a=6'd20; b=6'd10; sub=1; #1; $display(" %b  |%2d|%2d|%3d (sub)", sub, a,b,s);
  end
endmodule