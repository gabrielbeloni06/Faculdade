/*
Guia_0807.v
Aluno: Gabriel Egídio Santos Beloni
Matrícula: 885080
*/
//Usando valores de 0=igual, 1=diferente.
module comparator_eq_neq_6bits(output s, input [5:0] a, b, input select);
  wire [5:0] xnor_res;
  xnor XN0(xnor_res[0],a[0],b[0]); xnor XN1(xnor_res[1],a[1],b[1]);
  xnor XN2(xnor_res[2],a[2],b[2]); xnor XN3(xnor_res[3],a[3],b[3]);
  xnor XN4(xnor_res[4],a[4],b[4]); xnor XN5(xnor_res[5],a[5],b[5]);
  
  wire equal_res, not_equal_res;
  and A_EQ(equal_res, xnor_res[0],xnor_res[1],xnor_res[2],xnor_res[3],xnor_res[4],xnor_res[5]);
  not N_NEQ(not_equal_res, equal_res);
  wire not_select, term_a, term_b;
  not N1(not_select, select);
  and MUX_A1(term_a, equal_res, not_select);
  and MUX_A2(term_b, not_equal_res, select);
  or O1(s, term_a, term_b);
endmodule

module Guia_0807_tb;
  reg [5:0] a,b; reg select; wire s;
  comparator_eq_neq_6bits dut(s, a, b, select);
  initial begin
    $display("Guia_0807 - Comparador EQ/NEQ 6 bits");
    $display("sel| a | b |s(0=EQ,1=NEQ)");
    $display("--------------------------");
    a=6'hF; b=6'hF; select=0; #1; $display(" %b | %h| %h| %b", select, a,b,s);
    a=6'hF; b=6'hF; select=1; #1; $display(" %b | %h| %h| %b", select, a,b,s);
    a=6'hF; b=6'hE; select=0; #1; $display(" %b | %h| %h| %b", select, a,b,s);
    a=6'hF; b=6'hE; select=1; #1; $display(" %b | %h| %h| %b", select, a,b,s);
  end
endmodule