/*
Guia_0804.v
Aluno: Gabriel Egídio Santos Beloni
Matrícula: 885080
*/
module comparator_neq_5bits(output s, input [4:0] a, b);
  wire [4:0] xor_res;
  xor X0(xor_res[0], a[0], b[0]);
  xor X1(xor_res[1], a[1], b[1]);
  xor X2(xor_res[2], a[2], b[2]);
  xor X3(xor_res[3], a[3], b[3]);
  xor X4(xor_res[4], a[4], b[4]);
  
  or O_FINAL(s, xor_res[0], xor_res[1], xor_res[2], xor_res[3], xor_res[4]);
endmodule

module Guia_0804_tb;
  reg [4:0] a, b;
  wire s;
  comparator_neq_5bits dut(s, a, b);
  initial begin
    $display("Guia_0804 - Comparador de Desigualdade 5 bits");
    $display("    a     !=     b    ? %b", "s");
    $display("---------------------------");
    a=5'hA; b=5'hA; #1; $display(" %h != %h ? %b", a, b, s);
    a=5'hA; b=5'hB; #1; $display(" %h != %h ? %b", a, b, s);
    a=5'h1F; b=5'h0F; #1; $display("%h != %h ? %b", a, b, s);
  end
endmodule