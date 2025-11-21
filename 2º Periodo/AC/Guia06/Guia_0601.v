/*
Guia_0601.v
Aluno: Gabriel Egídio Santos Beloni
Matrícula: 885080
*/
module f_01a(output s, input x,y,z); assign s = (~x & z) | (y & z);       endmodule
module f_01b(output s, input x,y,z); assign s = (~x & ~z) | (y & ~z);    endmodule
module f_01c(output s, input x,y,z); assign s = (~y & z) | (y & ~z);       endmodule
module f_01d(output s, input x,y,z); assign s = (y & ~z) | (~x & ~y & z) | (x & ~y & ~z); endmodule
module f_01e(output s, input x,y,z); assign s = (~x & ~z) | (y & z);       endmodule

module Guia_0601_tb;
  reg x,y,z;
  wire s1,s2,s3,s4,s5;
  f_01a d1(s1,x,y,z); f_01b d2(s2,x,y,z); f_01c d3(s3,x,y,z); f_01d d4(s4,x,y,z); f_01e d5(s5,x,y,z);
  initial begin
    $display("Guia_0601 - Simplificacao SoP");
    $display("xyz| a b c d e"); $display("---|-------");
    for(integer i=0;i<8;i=i+1)begin {x,y,z}=i; #1; $display("%b%b%b| %b %b %b %b %b",x,y,z,s1,s2,s3,s4,s5); end
  end
endmodule