/*
Guia_0602.v
Aluno: Gabriel Egídio Santos Beloni
Matrícula: 885080
*/
module f_02a(output s, input x,y,z); assign s = (x | ~z) & (y | ~z); endmodule
module f_02b(output s, input x,y,z); assign s = (x | z) & (~y | z);  endmodule
module f_02c(output s, input x,y,z); assign s = (y | ~z) & (~y | z);  endmodule
module f_02d(output s, input x,y,z); assign s = (x | y) & (x | ~z) & (~y | ~z); endmodule
module f_02e(output s, input x,y,z); assign s = (x | z) & (~x | ~z); endmodule
module Guia_0602_tb;
  reg x,y,z;
  wire s1,s2,s3,s4,s5;
  f_02a d1(s1,x,y,z); f_02b d2(s2,x,y,z); f_02c d3(s3,x,y,z); f_02d d4(s4,x,y,z); f_02e d5(s5,x,y,z);
  initial begin
    $display("Guia_0602 - Simplificacao PoS");
    $display("xyz| a b c d e"); $display("---|-------");
    for(integer i=0;i<8;i=i+1)begin {x,y,z}=i; #1; $display("%b%b%b| %b %b %b %b %b",x,y,z,s1,s2,s3,s4,s5); end
  end
endmodule