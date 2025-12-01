/*
Guia_1703.v
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

module fsm_jk_toggle (output y_b, y_a, input c, clk, rst);
    wire a, b;
    wire da, db;
    wire ta, tb; 
    assign da = a | (~b & c);
    assign db = (~b & c) | (b & ~c) | (a & b);
    assign ta = a ^ da;
    assign tb = b ^ db;
    jk_ff ff_a (a, ta, ta, clk, rst);
    jk_ff ff_b (b, tb, tb, clk, rst);

    assign y_a = a;
    assign y_b = b;
endmodule

module Guia_1703_tb;
    reg c, clk, rst;
    wire y_b, y_a;
    fsm_jk_toggle dut (y_b, y_a, c, clk, rst);
    
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