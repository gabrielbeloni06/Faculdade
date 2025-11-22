/*
Guia_0703.v
Aluno: Gabriel Egídio Santos Beloni
Matrícula: 885080
*/
/* FORAM USADAS 4 OPERAÇÕES */
module LU_03(output s, input a, b, sel_porta, sel_grupo);
  wire and_res, nand_res, or_res, nor_res;
  wire mux_an_out, mux_on_out;
  and AND_gate(and_res, a, b);
  nand NAND_gate(nand_res, a, b);
  or OR_gate(or_res, a, b);
  nor NOR_gate(nor_res, a, b);
  wire not_sel_porta;
  not N1(not_sel_porta, sel_porta);
  wire term_nand, term_and, term_nor, term_or;
  and A1(term_nand, nand_res, not_sel_porta);
  and A2(term_and, and_res, sel_porta);
  or O1(mux_an_out, term_nand, term_and);
  and A3(term_nor, nor_res, not_sel_porta);
  and A4(term_or, or_res, sel_porta);
  or O2(mux_on_out, term_nor, term_or);
  wire not_sel_grupo;
  not N2(not_sel_grupo, sel_grupo);
  wire term_an, term_on;
  and A5(term_an, mux_an_out, not_sel_grupo);
  and A6(term_on, mux_on_out, sel_grupo);
  or O3(s, term_an, term_on);
endmodule
module Guia_0703_tb;
  reg a, b, sel_porta, sel_grupo;
  wire s;
  LU_03 dut(s, a, b, sel_porta, sel_grupo);
  initial begin
    $display("Guia_0703 - LU com 4 Ops");
    $display("sel_g sel_p | a b | s");
    $display("-----------------------");
    for(integer i=0; i<16; i=i+1) begin
      {sel_grupo, sel_porta, a, b} = i;
      #1;
      $display("   %b      %b   | %b %b | %b", sel_grupo, sel_porta, a, b, s);
    end
  end
endmodule