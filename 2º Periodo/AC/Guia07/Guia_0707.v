/*
Guia_0707.v
Aluno: Gabriel Egídio Santos Beloni
Matrícula: 885080
*/
module Comparator_07(output s, input [3:0] a, b, input select);
  wire a_maior_b, a_menor_b;
/* LÓGICA USADA PARA A > B */
  wire [3:0] eq;
  xnor XN0(eq[0],a[0],b[0]); xnor XN1(eq[1],a[1],b[1]);
  xnor XN2(eq[2],a[2],b[2]); xnor XN3(eq[3],a[3],b[3]);
  wire g3, g2, g1, g0;
  and G3(g3, a[3], ~b[3]);
  and G2(g2, eq[3], a[2], ~b[2]);
  and G1(g1, eq[3], eq[2], a[1], ~b[1]);
  and G0(g0, eq[3], eq[2], eq[1], a[0], ~b[0]);
  or  O_GT(a_maior_b, g3, g2, g1, g0);
/* LÓGICA PARA A < B */
  wire l3, l2, l1, l0;
  and L3(l3, b[3], ~a[3]);
  and L2(l2, eq[3], b[2], ~a[2]);
  and L1(l1, eq[3], eq[2], b[1], ~a[1]);
  and L0(l0, eq[3], eq[2], eq[1], b[0], ~a[0]);
  or  O_LT(a_menor_b, l3, l2, l1, l0);
  wire not_select, term_a, term_b;
  not N1(not_select, select);
  and A1(term_a, a_maior_b, not_select);
  and A2(term_b, a_menor_b, select);
  or O1(s, term_a, term_b);
endmodule
module Guia_0707_tb;
  reg [3:0] a, b;
  reg select;
  wire s;
  Comparator_07 dut(s, a, b, select);
  initial begin
    $display("Guia_0707 - Comparador Magnitude 4 bits");
    $display("sel|   a    |   b    | s (1=<, 0=>)");
    $display("-----------------------------------");
    a=4'hA; b=4'h5; select=0; #1; $display(" %b | %b | %b | %b", select, a, b, s);
    a=4'hA; b=4'h5; select=1; #1; $display(" %b | %b | %b | %b", select, a, b, s);
    a=4'h5; b=4'hA; select=0; #1; $display(" %b | %b | %b | %b", select, a, b, s);
    a=4'h5; b=4'hA; select=1; #1; $display(" %b | %b | %b | %b", select, a, b, s);
    a=4'hA; b=4'hA; select=0; #1; $display(" %b | %b | %b | %b", select, a, b, s);
    a=4'hA; b=4'hA; select=1; #1; $display(" %b | %b | %b | %b", select, a, b, s);
  end
endmodule