/*
Guia_1100.v
Aluno: Gabriel Egídio Santos Beloni
Matrícula: 885080
*/
`include "mealy_1101.v"
`include "moore_1101.v"
module Guia_1100;
    reg clk, reset, x;
    wire m1, m2;
    mealy_1101 mealy1 (m1, x, clk, reset);
    moore_1101 moore1 (m2, x, clk, reset);
    initial begin
        $dumpfile("Guia_1100.vcd");
        $dumpvars(0, Guia_1100);
        clk = 0;
        reset = 1;
        x = 0;
        #5 reset = 0;
        #10 x = 1;
        #10 x = 1;
        #10 x = 0;
        #10 x = 1;
        #20 $finish;
    end
    always #5 clk = ~clk;
    initial begin
        $display("Time  X  Mealy  Moore");
        $monitor("%3d   %b    %b      %b", $time, x, m1, m2);
    end
endmodule