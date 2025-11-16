/*
Guia_0405.v
Aluno: Gabriel Egídio Santos Beloni
Matrícula: 885080
*/
/*Este fi o código que usei para testar a função da Atividade 05*/
module a_05_SoP(output s, input x, y, w, z);
  assign s = (~x&~y&~w&~z) 
           | (~x&~y&~w&z)   
           | (~x&~y&w&z)    
           | (~x&y&~w&z)    
           | (~x&y&w&~z)    
           | (x&~y&w&~z)
           | (x&~y&w&z)  
           | (x&y&w&z);    
endmodule
module Guia_0405_tb;
  reg x,y,w,z;
  wire s;
  a_05_SoP DUT(s, x,y,w,z);
  initial begin
    $display("Guia_0405 - Teste SoP Atividade 05");
    $display("xywz | s (esperado)");
    $display("--------------------");
    for(integer i=0; i<16; i=i+1) begin
      {x,y,w,z} = i;
      #1;
      $display("%b%b%b%b | %b", x,y,w,z,s);
    end
  end
endmodule