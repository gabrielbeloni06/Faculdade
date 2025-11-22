/*
Guia_0705.v
Aluno: Gabriel Egídio Santos Beloni
Matrícula: 885080
*/
module LU_05(output s, input a, b, input [2:0] select);
    wire not_a, and_ab, nand_ab, or_ab, nor_ab, xor_ab, xnor_ab, extra;
    not  G_NOT(not_a, a);
    and  G_AND(and_ab, a, b);
    nand G_NAND(nand_ab, a, b);
    or   G_OR(or_ab, a, b);
    nor  G_NOR(nor_ab, a, b);
    xor  G_XOR(xor_ab, a, b);
    xnor G_XNOR(xnor_ab, a, b);
    assign extra = 1'b0;
    wire [7:0] terms;
    wire [2:0] s_n;
    not N0(s_n[0], select[0]);
    not N1(s_n[1], select[1]);
    not N2(s_n[2], select[2]);
    and A0(terms[0], not_a,   s_n[2], s_n[1], s_n[0]);
    and A1(terms[1], and_ab,  s_n[2], s_n[1], select[0]);
    and A2(terms[2], nand_ab, s_n[2], select[1], s_n[0]);
    and A3(terms[3], or_ab,   s_n[2], select[1], select[0]);
    and A4(terms[4], nor_ab,  select[2], s_n[1], s_n[0]);
    and A5(terms[5], xor_ab,  select[2], s_n[1], select[0]);
    and A6(terms[6], xnor_ab, select[2], select[1], s_n[0]);
    and A7(terms[7], extra,   select[2], select[1], select[0]);
    or  O_final(s, terms[0],terms[1],terms[2],terms[3],terms[4],terms[5],terms[6],terms[7]);
endmodule
module Guia_0705_tb;
  reg a,b; reg[2:0] select; wire s;
  LU_05 dut(s, a, b, select);
  initial begin
    $display("Guia_0705 - MUX 8x1");
    $display("sel | a b | s"); $display("----|-----|--");
    a=1'b1; b=1'b0;
    for(integer i=0; i<8; i=i+1) begin
      select = i; #1; $display("%b%b%b | %b %b | %b", select[2],select[1],select[0], a,b,s);
    end
  end
endmodule