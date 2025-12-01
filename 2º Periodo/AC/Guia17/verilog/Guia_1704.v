/*
Guia_1704.v
Aluno: Gabriel Egídio Santos Beloni
Matrícula: 885080
*/
module t_ff (output reg q, input t, clk, rst);
    always @(posedge clk or posedge rst)
        if (rst) q <= 0;
        else if (t) q <= ~q;
endmodule

module async_down_counter (output [2:0] q, input clk, rst);
    t_ff ff1 (q[0], 1'b1, clk, rst);
    t_ff ff2 (q[1], 1'b1, q[0], rst);
    t_ff ff3 (q[2], 1'b1, q[1], rst);
endmodule

module Guia_1704_tb;
    reg clk, rst; wire [2:0] q;
    async_down_counter dut (q, clk, rst);
    initial begin
        clk=0; rst=1; #10 rst=0;
        #150 $finish;
    end
    always #5 clk = ~clk;
    initial $monitor("T=%3d q=%b", $time, q);
endmodule