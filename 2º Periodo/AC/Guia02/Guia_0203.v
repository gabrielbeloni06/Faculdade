/*
Guia_0203.v
Aluno: Gabriel Egídio Santos Beloni
Matrícula: 885080
*/
module Guia_0203;
// define data
reg [7:0] b = 8'b10110000; // binary
// actions
initial
begin: main
   $display ("Guia_0203 - Tests");
   $display ("b = 0.%8b", b);
   $display ("b = 0.%h%h (16)", b[7:4], b[3:0]);
   $display ("b = 0.%o%o%o (8)", b[7:5], b[4:2], b[1:0]);
end // main
endmodule // Guia_0203