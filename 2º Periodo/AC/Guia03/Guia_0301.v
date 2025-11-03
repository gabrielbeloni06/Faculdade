/*
Guia_0301.v
Aluno: Gabriel Egídio Santos Beloni
Matrícula: 885080
*/
module Guia_0301;
// define data
reg [7:0] a = 8'b00110010;
reg [6:0] b = 7'b0;
reg [5:0] c = 6'b0;
reg [7:0] d = 0;
reg [6:0] e = 0;
reg [5:0] f = 0;

// actions
initial
begin: main
   $display ("Guia_0301 - Tests");
   d = ~a + 1;
   $display ("a = %8b -> C1(a) = %8b -> C2(a) = %8b", a, ~a, d);
end // main
endmodule // Guia_0301