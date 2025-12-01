/*
Guia_1702.v
Aluno: Gabriel Egídio Santos Beloni
Matrícula: 885080
*/
module jk_ff (output reg q, input j, k, clk, rst);
    always @(posedge clk or posedge rst) begin
        if (rst) q <= 0;
        else case({j,k})
            2'b00: q <= q;
            2'b01: q <= 0;
            2'b10: q <= 1;
            2'b11: q <= ~q;
        endcase
    end
endmodule

module fsm_jk (output y_b, y_a, input c, clk, rst);
    wire a, b;
    wire ja, ka, jb, kb;
    assign ja = c;
    assign ka = b & c;
    assign jb = c | a;
    assign kb = a & c;

    jk_ff ff_a (a, ja, ka, clk, rst);
    jk_ff ff_b (b, jb, kb, clk, rst);

    assign y_a = a;
    assign y_b = b;
endmodule

module Guia_1702_tb;
    reg c, clk, rst;
    wire y_b, y_a;
    fsm_jk dut (y_b, y_a, c, clk, rst);
    initial begin
        clk=0; rst=1; c=0; #10 rst=0;
        #10 c=1; #10 c=0; #10 c=1; #10 $finish;
    end
    always #5 clk = ~clk;
endmodule