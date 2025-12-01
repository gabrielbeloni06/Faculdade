/*
Guia_1705.v
Aluno: Gabriel Egídio Santos Beloni
Matrícula: 885080
*/
module t_ff_n (output reg q, output q_n, input t, clk, rst);
    assign q_n = ~q;
    always @(posedge clk or posedge rst)
        if (rst) q <= 0;
        else if (t) q <= ~q;
endmodule

module async_up_counter (output [2:0] q, input clk, rst);
    wire q0_n, q1_n, q2_n;
    t_ff_n ff1 (q[0], q0_n, 1'b1, clk, rst);
    t_ff_n ff2 (q[1], q1_n, 1'b1, q0_n, rst);
    t_ff_n ff3 (q[2], q2_n, 1'b1, q1_n, rst);
endmodule

module Guia_1705_tb;
    reg clk, rst; wire [2:0] q;
    async_up_counter dut (q, clk, rst);
    initial begin
        clk=0; rst=1; #10 rst=0;
        #150 $finish;
    end
    always #5 clk = ~clk;
    initial $monitor("T=%3d q=%b", $time, q);
endmodule