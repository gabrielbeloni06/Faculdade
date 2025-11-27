/*
Guia_0907.v
Aluno: Gabriel Egídio Santos Beloni
Matrícula: 885080
*/
`include "clock.v"

module pulse_level (output reg signal, input clk);
  initial signal = 1'b0;
  always @(clk)
  begin
    if (clk == 1'b1) begin
      signal = 1'b1;
      #6 signal = 1'b0;
    end
  end
endmodule

module Guia_0907;
  wire clock_signal;
  clock main_clock(clock_signal);
  
  wire pulse_signal;
  pulse_level pulser(pulse_signal, clock_signal);
  
  initial begin
    $dumpfile ("Guia_0907.vcd");
    $dumpvars (1, clock_signal, pulse_signal);
    #240 $finish;
  end
endmodule