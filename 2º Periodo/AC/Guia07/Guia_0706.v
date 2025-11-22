/*
Guia_0706.v
Aluno: Gabriel Egídio Santos Beloni
Matrícula: 885080
*/
module Comparator_06(output s, input [3:0] a, b, input select);
  wire [3:0] xnor_res;
  wire equal_res, not_equal_res;
  /* COMPARAÇÕES DE BITS */
  xnor XN0(xnor_res[0], a[0], b[0]);
  xnor XN1(xnor_res[1], a[1], b[1]);
  xnor XN2(xnor_res[2], a[2], b[2]);
  xnor XN3(xnor_res[3], a[3], b[3]);
  /*LOGICA DE IGUALDADE*/
  and AND_EQ(equal_res, xnor_res[0], xnor_res[1], xnor_res[2], xnor_res[3]);
  not NOT_NEQ(not_equal_res, equal_res);
  wire not_select, term_a, term_b;
  not N1(not_select, select);
  and A1(term_a, equal_res, not_select);
  and A2(term_b, not_equal_res, select);
  or O1(s, term_a, term_b);
endmodule
module Guia_0706_tb;
  reg [3:0] a, b;
  reg select;
  wire s;
  Comparator_06 dut(s, a, b, select);
  initial begin
    $display("Guia_0706 - Comparador 4 bits");
    $display("sel |   a    |   b    | s (0=EQ, 1=NEQ)");
    $display("--------------------------------------");
    a=4'hA; b=4'hA; select=0; #1; $display(" %b  | %b | %b | %b", select, a, b, s);
    a=4'hA; b=4'hA; select=1; #1; $display(" %b  | %b | %b | %b", select, a, b, s);
    a=4'hA; b=4'hB; select=0; #1; $display(" %b  | %b | %b | %b", select, a, b, s);
    a=4'hA; b=4'hB; select=1; #1; $display(" %b  | %b | %b | %b", select, a, b, s);
  end
endmodule