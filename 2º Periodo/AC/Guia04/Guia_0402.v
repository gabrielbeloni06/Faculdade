/*
Guia_0402.v
Aluno: Gabriel Egídio Santos Beloni
Matrícula: 885080
*/
/* Este foi o código que usei para testar a simplificação das funções da Atividade 02 */
module f_02a_orig(output s, input x, y); assign s = ~x & (~(x | ~y)); endmodule
module f_02a_simp(output s, input x, y); assign s = ~x & y; endmodule
module f_02b_orig(output s, input x, y); assign s = (x | y) | (~x & y); endmodule
module f_02b_simp(output s, input x, y); assign s = 1'b1; endmodule
module f_02c_orig(output s, input x, y); assign s = (~(~x & y)) & (x | y); endmodule
module f_02c_simp(output s, input x, y); assign s = x; endmodule
module f_02d_orig(output s, input x, y); assign s = (~(x & ~y)) | (~(x | y)); endmodule
module f_02d_simp(output s, input x, y); assign s = ~x | y; endmodule
module f_02e_orig(output s, input x, y); assign s = (~y | ~x) & (~(y | x)); endmodule
module f_02e_simp(output s, input x, y); assign s = ~x & ~y; endmodule
module Guia_0402_tb;
  reg x, y;
  wire ao, as, bo, bs, co, cs, do, ds, eo, es;
  f_02a_orig O_a(ao, x, y); f_02a_simp S_a(as, x, y);
  f_02b_orig O_b(bo, x, y); f_02b_simp S_b(bs, x, y);
  f_02c_orig O_c(co, x, y); f_02c_simp S_c(cs, x, y);
  f_02d_orig O_d(do, x, y); f_02d_simp S_d(ds, x, y);
  f_02e_orig O_e(eo, x, y); f_02e_simp S_e(es, x, y);
  initial begin
    $display("Guia_0402 - Teste de Simplificacao Atividade 02");
    $display("x y | a(o)==a(s) | b(o)==b(s) | c(o)==c(s) | d(o)==d(s) | e(o)==e(s)");
    $display("------------------------------------------------------------------");
    for (integer i=0; i<4; i=i+1) begin
      {x, y} = i;
      #1;
      $display("%b %b |    %b == %b    |    %b == %b    |    %b == %b    |    %b == %b    |    %b == %b", 
               x, y, ao, as, bo, bs, co, cs, do, ds, eo, es);
    end
  end
endmodule