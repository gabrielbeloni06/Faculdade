/*
Guia_0805.v
Aluno: Gabriel Egídio Santos Beloni
Matrícula: 885080
*/
// Reutilizando os módulos.
module halfAdder(output cout, output sum, input a, b);
  xor X1(sum, a, b); and A1(cout, a, b);
endmodule
module fullAdder(output cout, output sum, input a, b, cin);
  wire s0, c0, c1; halfAdder HA1(c0, s0, a, b);
  halfAdder HA2(c1, sum, s0, cin); or O1(cout, c0, c1);
endmodule

module complement2_5bits(output [4:0] c2, input [4:0] a);
  wire [4:0] a_inv;
  not N0(a_inv[0], a[0]); not N1(a_inv[1], a[1]);
  not N2(a_inv[2], a[2]); not N3(a_inv[3], a[3]);
  not N4(a_inv[4], a[4]);
  
  wire [4:0] carries; // Adder para somar 1
  halfAdder HA0(carries[0], c2[0], a_inv[0], 1'b1);
  halfAdder HA1(carries[1], c2[1], a_inv[1], carries[0]);
  halfAdder HA2(carries[2], c2[2], a_inv[2], carries[1]);
  halfAdder HA3(carries[3], c2[3], a_inv[3], carries[2]);
  halfAdder HA4(           , c2[4], a_inv[4], carries[3]);
endmodule

module Guia_0805_tb;
  reg [4:0] a;
  wire [4:0] c2;
  complement2_5bits dut(c2, a);
  initial begin
    $display("Guia_0805 - Complemento de 2 de 5 bits");
    $display("   a    |    C2(a)");
    $display("-------------------");
    a=5'd7; #1; $display("%b | %b", a, c2);
    a=5'd10; #1; $display("%b | %b", a, c2);
    a=5'd15; #1; $display("%b | %b", a, c2);
  end
endmodule