/*
Guia_0702.v
Aluno: Gabriel Egídio Santos Beloni
Matrícula: 885080
*/
module LU_02(output s, input a, b, select);
  wire or_res, nor_res;
  wire not_select, term_a, term_b;
  /* OPERAÇÕES USADAS */
  or OR_gate(or_res, a, b);
  nor NOR_gate(nor_res, a, b);
  not NOT_gate(not_select, select);
  and MUX_AND1(term_a, nor_res, not_select); /* S=0-> NOR*/
  and MUX_AND2(term_b, or_res, select);     /* S=1-> OR*/
  or  MUX_OR(s, term_a, term_b);
endmodule
module Guia_0702_tb;
  reg a, b, select;
  wire s;
  LU_02 dut(s, a, b, select);
  initial begin
    $display("Guia_0702 - LU com OR/NOR");
    $display("select | a b | s (0=NOR, 1=OR)");
    $display("---------------------------");
    for(integer i=0; i<8; i=i+1) begin
      {select, a, b} = i;
      #1;
      $display("   %b   | %b %b | %b", select, a, b, s);
    end
  end
endmodule