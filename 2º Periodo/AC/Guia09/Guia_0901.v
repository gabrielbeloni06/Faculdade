/*
Guia_0901.v
Aluno: Gabriel Egídio Santos Beloni
Matrícula: 885080
*/
module clock (output clk);
  reg clk;
  initial begin
    clk = 1'b0;
  end
  always begin
    #12 clk = ~clk; //acho q deveria ter o ~, visto que no guia nao estava
  end
endmodule

module pulse (output signal, input clock);
  reg signal;
  always @ (clock)
  begin
    signal = 1'b1;
    #3 signal = 1'b0;
    #3 signal = 1'b1;
    #3 signal = 1'b0;
  end
endmodule

module trigger (output signal, input on, clock);
  reg signal;
  begin
    if(on) begin
      #60 signal = 1'b1;
      #60 signal = 1'b0;
    end
  end
endmodule

module Guia_0901;
  wire clock;
  clock clk (clock);
  
  reg p;
  wire p1, t1;
  pulse pulse1 (p1, clock);
  trigger trigger1 (t1, p, clock);
  
  initial begin
    $dumpfile ("Guia_0901.vcd");
    $dumpvars (1, clock, p1, p, t1);
    p = 1'b0;
    #60 p = 1'b1;
    #120 p = 1'b0;
    #180 p = 1'b1;
    #240 p = 1'b0;
    #300 p = 1'b1;
    #360 p = 1'b0;
    #376 $finish;
  end
endmodule