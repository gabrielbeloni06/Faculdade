/*
Guia_1102.v
Aluno: Gabriel Egídio Santos Beloni
Matrícula: 885080
*/
module mealy_0101_no_overlap(output reg y, input x, clk, reset);
    parameter S_IDLE=0, S_0=1, S_01=2, S_010=3;
    reg [1:0] state, next_state;
    always @(posedge clk or posedge reset)
        if (reset) state <= S_IDLE;
        else state <= next_state;
    always @* begin
        y = 1'b0;
        case(state)
            S_IDLE: next_state = x ? S_IDLE : S_0;
            S_0:    next_state = x ? S_01 : S_0;
            S_01:   next_state = x ? S_IDLE : S_010;
            S_010:  if (x) begin
                        next_state = S_IDLE;
                        y = 1'b1;
                    end else
                        next_state = S_0;
            default: next_state = S_IDLE;
        endcase
    end
endmodule

module Guia_1102_tb;
    reg x, clk, reset; wire y;
    mealy_0101_no_overlap dut(y, x, clk, reset);
    initial begin
        clk=0; reset=1; #5 reset=0;
        #10 x=0;#10 x=1;#10 x=0;#10 x=1;
        #10 x=0;#10 x=1;#10 x=0;#10 x=1;
        #10 $finish;
    end
    always #5 clk=~clk;
    initial $monitor("T=%2d x=%b y=%b", $time, x, y);
endmodule