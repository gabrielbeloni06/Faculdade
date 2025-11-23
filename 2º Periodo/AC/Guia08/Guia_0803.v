/*
Guia_0803.v
Aluno: Gabriel Egídio Santos Beloni
Matrícula: 885080
*/
module comparator_eq_6bits(output s, input [5:0] a, b);
  wire [5:0] xnor_res;
  xnor XN0(xnor_res[0], a[0], b[0]);
  xnor XN1(xnor_res[1], a[1], b[1]);
  xnor XN2(xnor_res[2], a[2], b[2]);
  xnor XN3(xnor_res[3], a[3], b[3]);
  xnor XN4(xnor_res[4], a[4], b[4]);
  xnor XN5(xnor_res[5], a[5], b[5]);
  
  and A_FINAL(s, xnor_res[0], xnor_res[1], xnor_res[2], xnor_res[3], xnor_res[4], xnor_res[5]);
endmodule
module Guia_0803_tb;
  reg [5:0] a, b;
  wire s;
  comparator_eq_6bits dut(s, a, b);
  initial begin
    $display("Guia_0803 - Comparador de Igualdade 6 bits");
    $display("    a     ==     b    ? %b", "s");
    $display("---------------------------");
    a=6'hA; b=6'hA; #1; $display(" %h == %h ? %b", a, b, s);
    a=6'hA; b=6'hB; #1; $display(" %h == %h ? %b", a, b, s);
    a=6'h2F; b=6'h2F; #1; $display("%h == %h ? %b", a, b, s);
  end
endmodule