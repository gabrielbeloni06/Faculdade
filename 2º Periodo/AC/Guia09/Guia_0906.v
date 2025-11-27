/*
Guia_0906.v
Aluno: Gabriel Egídio Santos Beloni
Matrícula: 885080
*/
`include "clock.v"

module pulse_negedge (output reg signal, input clk);
  initial signal = 1'b0;
  always @(negedge clk)
  begin
    signal = 1'b1;
    #3 signal = 1'b0;
  end
endmodule

module Guia_0906;
  wire clock_signal;
  clock main_clock(clock_signal);
  
  wire pulse_signal;
  pulse_negedge pulser(pulse_signal, clock_signal);
  
  initial begin
    $dumpfile ("Guia_0906.vcd");
    $dumpvars (1, clock_signal, pulse_signal);
    #240 $finish;
  end
endmodule