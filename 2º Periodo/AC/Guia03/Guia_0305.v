/*
Guia_0305.v
Aluno: Gabriel Egídio Santos Beloni
Matrícula: 885080
*/
module Guia_0305;
// define data
reg [3:0] a = 0; 
reg [4:0] b = 0; 
reg [5:0] c = 0;

// actions
initial
begin: main
   $display ("Guia_0305 - Testes de Overflow");
   a = 4'd10 + 4'd7;
   $display("a (4 bits) = 10+7 = %d (valor esperado 17, valor no registrador %d)", a, a);
   b = 5'd15 - 5'd20;
   $display("b (5 bits) = 15-20 = %d", b);
   c = 5'd15 - 5'd30;
   $display("c (5 bits) = 15-30 = %d", c);

end // main
endmodule // Guia_0305