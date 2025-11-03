/*
Guia_0304.v
Aluno: Gabriel Egídio Santos Beloni
Matrícula: 885080
*/
module Guia_0304;
// define data
// 654(8) = 428(10), 375(8) = 253(10)
reg signed [15:0] a = 428; 
reg signed [15:0] b = 253;
reg signed [15:0] c;

// actions
initial
begin: main
   $display ("Guia_0304 - Tests");
   $display ("a = %d = %b", a, a);
   $display ("b = %d = %b", b, b);
   c = a - b;
   $display ("c = a - b = %d = %b", c, c);
end // main
endmodule // Guia_0304