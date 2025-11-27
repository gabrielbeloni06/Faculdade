/*
Guia_0904.v
Aluno: Gabriel Egídio Santos Beloni
Matrícula: 885080
*/
`include "clock.v"

module clock_mul2 (output reg clk);
  initial clk = 1'b0;
  always #6 clk = ~clk;
endmodule

module Guia_0904;
  wire original_clock;
  clock clk_orig (original_clock);
  
  wire new_clock;
  clock_mul2 clk_new (new_clock);

  initial begin
    $dumpfile ("Guia_0904.vcd");
    $dumpvars (1, original_clock, new_clock);
    #240 $finish;
  end
endmodule