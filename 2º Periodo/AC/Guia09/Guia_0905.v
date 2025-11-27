/*
Guia_0905.v
Aluno: Gabriel Egídio Santos Beloni
Matrícula: 885080
*/
`include "clock.v"

module pulse_posedge (output reg signal, input clk);
  initial signal = 1'b0;
  always @(posedge clk)
  begin
    signal = 1'b1;
    #4 signal = 1'b0;
  end
endmodule

module Guia_0905;
  wire clock_signal;
  clock main_clock(clock_signal);
  
  wire pulse_signal;
  pulse_posedge pulser(pulse_signal, clock_signal);
  
  initial begin
    $dumpfile ("Guia_0905.vcd");
    $dumpvars (1, clock_signal, pulse_signal);
    #240 $finish;
  end
endmodule