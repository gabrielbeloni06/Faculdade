/*
Guia_0701.v
Aluno: Gabriel Egídio Santos Beloni
Matrícula: 885080
*/
module LU_01(output s, input a, b, select);
  wire and_res, nand_res;
  wire not_select, term_a, term_b;
  /* OPERAÇÕES USADAS */
  and AND_gate(and_res, a, b);
  nand NAND_gate(nand_res, a, b);
  not NOT_gate(not_select, select);
  and MUX_AND1(term_a, nand_res, not_select); /* S=0-> NAND*/
  and MUX_AND2(term_b, and_res, select);     /*  S=1-> AND */
  or  MUX_OR(s, term_a, term_b);
endmodule
module Guia_0701_tb;
  reg a, b, select;
  wire s;
  LU_01 dut(s, a, b, select);
  initial begin
    $display("Guia_0701 - LU com AND/NAND");
    $display("select | a b | s (0=NAND, 1=AND)");
    $display("------------------------------");
    for(integer i=0; i<8; i=i+1) begin
      {select, a, b} = i;
      #1;
      $display("   %b   | %b %b | %b", select, a, b, s);
    end
  end
endmodule