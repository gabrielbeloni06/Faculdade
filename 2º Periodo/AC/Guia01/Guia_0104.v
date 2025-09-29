/*
Guia_0104.v
Aluno: Gabriel Egídio Santos Beloni
Matrícula: 885080
*/
module Guia_0104;
// define data
integer x = 37; // decimal
reg [7:0] b = 0; // binary
// actions
initial
begin: main
   $display ("Guia_0104 - Tests");
   $display ("x = %d", x);
   $display ("b = %8b", b);
   b = x;
   $display ("b = [%4b] [%4b] = %h %h", b[7:4], b[3:0], b[7:4], b[3:0]); // agrupamento
end // main
endmodule // Guia_0104