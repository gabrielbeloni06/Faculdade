/*
Guia_0103.v
Aluno: Gabriel Egídio Santos Beloni
Matrícula: 885080
*/
module Guia_0103;
// define data
integer x = 781; // decimal
reg [7:0] b = 0; // binary
// actions
initial
begin: main
   $display ("Guia_0103 - Tests");
   $display ("x = %d", x);
   $display ("b = %8b", b);
   b = x;
   $display ("b = %b (2) = %o (8) = %h (16) = %H (16)", b, b, b, b);
end // main
endmodule // Guia_0103