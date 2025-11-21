/*
Guia_0605.v
Aluno: Gabriel Egídio Santos Beloni
Matrícula: 885080
*/
module f_05_orig(output s, input x,y,z);
  wire w1,w2,w3,w4,w5,w6,w7,w8,w9,w10,w11;
  assign w8 = ~x; assign w9 = ~y;
  assign w5 = w8 | w9;
  assign w3 = ~w5;
  assign w6 = x & z;
  assign w4 = ~w6;
  assign w1 = w3 & w4;
  assign w10 = y & z;
  assign w11 = ~z;
  assign w7 = (~w10) | w11;
  assign w2 = ~w7;
  assign s = w1 | w2;
endmodule
module f_05_simp(output s, input x,y,z);
  assign s = (y & z) | (x & y);
endmodule
module Guia_0605_tb;
  reg x,y,z; wire s_orig, s_simp;
  f_05_orig d_orig(s_orig,x,y,z);
  f_05_simp d_simp(s_simp,x,y,z);
  initial begin
    $display("Guia_0605 - Teste Circuito 05");
    $display("xyz| Original | Simplificado"); $display("---|----------|-------------");
    for(integer i=0;i<8;i=i+1)begin {x,y,z}=i; #1; $display("%b%b%b|    %b     |      %b",x,y,z,s_orig,s_simp); end
  end
endmodule