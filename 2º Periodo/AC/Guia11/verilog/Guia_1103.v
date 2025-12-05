/*
Guia_1103.v
Aluno: Gabriel Egídio Santos Beloni
Matrícula: 885080
*/
module moore_0101_overlap(output y, input x, clk, reset);
    parameter S_IDLE=0, S_0=1, S_01=2, S_010=3, S_0101=4;
    reg [2:0] state, next_state;
    always @(posedge clk or posedge reset)
        if (reset) state <= S_IDLE;
        else state <= next_state;
    always @*
        case(state)
            S_IDLE: next_state = x ? S_IDLE : S_0;
            S_0:    next_state = x ? S_01   : S_0;
            S_01:   next_state = x ? S_IDLE : S_010;
            S_010:  next_state = x ? S_0101 : S_0;
            S_0101: next_state = x ? S_IDLE : S_010;
            default: next_state = S_IDLE;
        endcase

    assign y = (state == S_0101);
endmodule

module Guia_1103_tb;
    reg x, clk, reset; wire y;
    moore_0101_overlap dut(y, x, clk, reset);
    initial begin
        clk=0; reset=1; #5 reset=0;
        #10 x=0;#10 x=1;#10 x=0;#10 x=1;
        #10 x=0;#10 x=1;
        #10 $finish;
    end
    always #5 clk=~clk;
    initial $monitor("T=%2d x=%b y=%b", $time, x, y);
endmodule