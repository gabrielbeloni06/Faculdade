/*
Guia_0205.v
Aluno: Gabriel Egídio Santos Beloni
Matrícula: 885080
*/
module Guia_0205;
// define data
reg [7:0] a = 8'b01100101; // 101 em decimal
reg [7:0] b = 8'b00001101; // 13 em decimal
reg [7:0] c;
// actions
initial
begin: main
   $display ("Guia_0205 - Tests");
   $display ("a = %8b", a);
   $display ("b = %8b", b);
   c = a + b;
   $display ("c = a + b = %8b", c);
   c = a - b;
   $display ("c = a - b = %8b", c);
   c = a * b;
   $display ("c = a * b = %8b", c);
   c = a / b;
   $display ("c = a / b = %8b", c);
   c = a % b;
   $display ("c = a %% b = %8b", c);
end // main
endmodule // Guia_0205
