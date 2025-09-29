/*
Guia_0102.v
Aluno: Gabriel Egídio Santos Beloni
Matrícula: 885080
*/
999999 - Xxx Yyy Zzz
module Guia_0102;
// define data
integer x = 0;
// decimal
reg [7:0] b = 8'b00110011; // binary (bits little endian)
// actions
initial
begin: main
   $display ("Guia_0102 - Tests");
   $display ("x = %d", x);
   $display ("b = %8b", b);
   x = b;
   $display ("x = %d", x); 
end // main
endmodule // Guia_0102