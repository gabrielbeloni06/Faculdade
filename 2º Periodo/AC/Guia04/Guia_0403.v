/*
Guia_0403.v
Aluno: Gabriel Egídio Santos Beloni
Matrícula: 885080
*/
/* Este foi o código que usei para testar a função da Atividade 03 */
module f_03_SoP(output s, input x, y, w, z);
  assign s = (~x&~y&~w&~z)  
           | (~x&~y&~w&z)   
           | (~x&y&w&~z)   
           | (x&~y&~w&z)   
           | (x&y&~w&z);    
endmodule
module Guia_0403_tb;
  reg x,y,w,z;
  wire s;
  f_03_SoP DUT(s, x,y,w,z);
  initial begin
    $display("Guia_0403 - Teste SoP Atividade 03: f=Σm(0,1,6,9,13)");
    $display("xywz | s");
    $display("---------");
    for(integer i=0; i<16; i=i+1) begin
      {x,y,w,z} = i;
      #1;
      $display("%b%b%b%b | %b", x,y,w,z,s);
    end
  end
endmodule