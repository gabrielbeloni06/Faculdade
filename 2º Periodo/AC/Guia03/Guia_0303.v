/*
Guia_0303.v
Aluno: Gabriel Egídio Santos Beloni
Matrícula: 885080
*/
module Guia_0303;
// define data
reg signed [7:0] a = 8'b0;
reg signed [6:0] b = 7'b1111011; 
reg signed [5:0] c = 6'b0;
reg signed [7:0] d;
reg signed [6:0] e;

// actions
initial
begin: main
   $display ("Guia_0303 - Tests" );
   e = ~(b - 1);
   $display ("b (C2) = %7b = %d", b, b);
   $display ("Valor positivo de b = %7b = %d", e, e);
end // main
endmodule // Guia_0303