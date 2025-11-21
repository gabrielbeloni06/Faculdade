/*
Guia_0604.v
Aluno: Gabriel Egídio Santos Beloni
Matrícula: 885080
*/
module f_04e(output s, input x,y,w,z); 
  assign s = (y | ~z) & (~y | ~z) & (~w | ~z);
endmodule
module Guia_0604_tb;
  reg x,y,w,z; wire s;
  f_04e dut(s,x,y,w,z);
  initial begin
    $display("Guia_0604 - Teste 04e: F=ΠM(2,3,6,7,11,12,14)");
    $display("xywz| s"); $display("----|--");
    for(integer i=0;i<16;i=i+1)begin {x,y,w,z}=i; #1; $display("%b%b%b%b| %b",x,y,w,z,s); end
  end
endmodule