/*
Guia_0603.v
Aluno: Gabriel Egídio Santos Beloni
Matrícula: 885080
*/
module f_03e(output s, input x,y,w,z); 
  assign s = (~w & z) | (y & z) | (~x & ~y & ~w); 
endmodule
module Guia_0603_tb;
  reg x,y,w,z; wire s;
  f_03e dut(s,x,y,w,z);
  initial begin
    $display("Guia_0603 - Teste 03e: f=Σm(0,1,3,5,7,9,11,13)");
    $display("xywz| s"); $display("----|--");
    for(integer i=0;i<16;i=i+1)begin {x,y,w,z}=i; #1; $display("%b%b%b%b| %b",x,y,w,z,s); end
  end
endmodule