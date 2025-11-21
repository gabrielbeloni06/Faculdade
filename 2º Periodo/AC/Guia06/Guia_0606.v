/*
Guia_0606.v
Aluno: Gabriel Egídio Santos Beloni
Matrícula: 885080
*/
module f_06_orig(output s, input x,y,w,z);
  wire w1,w2,w3,w4,w5,w6,w7,w8,w9,w10,w11,w12;
  assign w8 = ~x; assign w9 = ~y;
  assign w5 = w8 | w9;
  assign w3 = ~w5;
  assign w6 = w & z;
  assign w4 = ~w6;
  assign w1 = w3 & w4;
  assign w11 = y & w;
  assign w10 = ~w11;
  assign w12 = ~z;
  assign w7 = w10 | w12;
  assign w2 = ~w7;
  assign s = w1 | w2;
endmodule
module f_06_simp(output s, input x,y,w,z);
  assign s = (x & y & ~w) | (y & w & z) | (x & y & ~z);
endmodule
module Guia_0606_tb;
  reg x,y,w,z; wire s_orig, s_simp;
  f_06_orig d_orig(s_orig,x,y,w,z);
  f_06_simp d_simp(s_simp,x,y,w,z);
  initial begin
    $display("Guia_0606 - Teste Circuito 06");
    $display("xywz| Original | Simplificado"); $display("----|----------|-------------");
    for(integer i=0;i<16;i=i+1)begin {x,y,w,z}=i; #1; $display("%b%b%b%b|    %b     |      %b",x,y,w,z,s_orig,s_simp); end
  end
endmodule