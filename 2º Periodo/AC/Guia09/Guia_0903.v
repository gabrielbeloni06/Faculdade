/*
Guia_0903.v
Aluno: Gabriel Egídio Santos Beloni
Matrícula: 885080
*/
`include "clock.v"
module clock_div4 (output reg clk);
  initial clk = 1'b0;
  always #48 clk = ~clk;
endmodule
module Guia_0903;
  wire original_clock;
  clock clk_orig (original_clock);
  
  wire new_clock;
  clock_div4 clk_new (new_clock);

  initial begin
    $dumpfile ("Guia_0903.vcd");
    $dumpvars (1, original_clock, new_clock);
    #480 $finish;
  end
endmodule