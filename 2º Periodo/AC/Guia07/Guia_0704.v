/*
Guia_0704.v
Aluno: Gabriel Egídio Santos Beloni
Matrícula: 885080
*/
module LU_04(output s, input a, b, input [1:0] select);
  wire or_res, nor_res, xor_res, xnor_res;
  /* OPERAÇÕES USADAS */
  or OR_gate(or_res, a, b);
  nor NOR_gate(nor_res, a, b);
  xor XOR_gate(xor_res, a, b);
  xnor XNOR_gate(xnor_res, a, b);
  wire s0_n, s1_n;
  wire t0, t1, t2, t3;
  not N0(s0_n, select[0]);
  not N1(s1_n, select[1]);
  and A0(t0, nor_res, s1_n, s0_n);
  and A1(t1, or_res, s1_n, select[0]);
  and A2(t2, xor_res, select[1], s0_n);
  and A3(t3, xnor_res, select[1], select[0]);
  or O_final(s, t0, t1, t2, t3);
endmodule
module Guia_0704_tb;
  reg a, b;
  reg [1:0] select;
  wire s;
  LU_04 dut(s, a, b, select);
  initial begin
    $display("Guia_0704 - MUX 4x1");
    $display("select | a b | s (00:NOR,01:OR,10:XOR,11:XNOR)");
    $display("--------------------------------------------");
    for(integer i=0; i<16; i=i+1) begin
      {select, a, b} = i;
      #1;
      $display("  %b%b   | %b %b | %b", select[1],select[0], a, b, s);
    end
  end
endmodule