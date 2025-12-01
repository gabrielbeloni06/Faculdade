/*
Guia_1701.v
Aluno: Gabriel Egídio Santos Beloni
Matrícula: 885080
*/
module d_ff (output reg q, input d, clk, rst);
    always @(posedge clk or posedge rst)
        if (rst) q <= 0; else q <= d;
endmodule

module fsm_d (
    output y_b, y_a,
    input c, clk, rst
);
    wire a, b;
    wire da, db;
    assign da = a | (~b & c);
    assign db = (~b & c) | (b & ~c) | (a & b);

    d_ff ff_a (a, da, clk, rst);
    d_ff ff_b (b, db, clk, rst);

    assign y_a = a;
    assign y_b = b;
endmodule

module Guia_1701_tb;
    reg c, clk, rst;
    wire y_b, y_a;
    fsm_d dut (y_b, y_a, c, clk, rst);
    
    initial begin
        $display("Time Clk Rst C | B A");
        clk=0; rst=1; c=0;
        #10 rst=0;
        #10 c=0;
        #10 c=1;
        #10 c=0;
        #10 c=1;
        #10 c=0;
        #10 $finish;
    end
    always #5 clk = ~clk;
    always @(posedge clk) $display("%3d  %b   %b   %b | %b %b", $time, clk, rst, c, y_b, y_a);
endmodule