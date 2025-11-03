/*
Guia_0302.v
Aluno: Gabriel Egídio Santos Beloni
Matrícula: 885080
*/
module Guia_0302;
// define data
reg [7:0] a = 8'h9F; 
reg [6:0] b = 7'd0;
reg [5:0] c = 6'd0;
reg [7:0] d = 0;
reg [6:0] e = 0;
reg [5:0] f = 0;

// actions
initial
begin: main
   $display ("Guia_0302 - Tests");
   d = ~a + 1;
   $display ("a = %h = %8b -> C1(a) = %8b -> C2(a) = %8b", a, a, ~a, d);
end // main
endmodule // Guia_0302