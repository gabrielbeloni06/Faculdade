/*
Guia_0801.v
Aluno: Gabriel Egídio Santos Beloni
Matrícula: 885080
*/
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

module adder_5bits(output cout, output [4:0] sum, input [4:0] a, b);
  wire [4:0] carries;
  fullAdder FA0(carries[0], sum[0], a[0], b[0], 1'b0);
  fullAdder FA1(carries[1], sum[1], a[1], b[1], carries[0]);
  fullAdder FA2(carries[2], sum[2], a[2], b[2], carries[1]);
  fullAdder FA3(carries[3], sum[3], a[3], b[3], carries[2]);
  fullAdder FA4(cout,       sum[4], a[4], b[4], carries[3]);
endmodule

module Guia_0801_tb;
  reg [4:0] a, b;
  wire [4:0] sum;
  wire cout;
  adder_5bits dut(cout, sum, a, b);
  initial begin
    $display("Guia_0801 - Somador 5 bits");
    $display("   a    +    b    = cout sum");
    $display("--------------------------------");
    a = 5'd7;  b = 5'd4; #1; $display("%5d + %5d = %b %5d", a, b, cout, sum);
    a = 5'd15; b = 5'd2; #1; $display("%5d + %5d = %b %5d", a, b, cout, sum);
    a = 5'd16; b = 5'd15;#1; $display("%5d + %5d = %b %5d", a, b, cout, sum);
  end
endmodule