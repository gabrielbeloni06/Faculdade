/*
Guia_11 - mealy_1101.v
Aluno: Gabriel Egídio Santos Beloni
Matrícula: 885080
*/
`define found 1'b1
`define notfound 1'b0

module mealy_1101 (output reg y, input x, clk, reset);
    parameter start = 2'b00, id1 = 2'b01, id11 = 2'b11, id110 = 2'b10;
    reg [1:0] current_state, next_state;
    always @(posedge clk or posedge reset)
    begin
        if (reset)
            current_state <= start;
        else
            current_state <= next_state;
    end
    always @*
    begin
        y = `notfound;
        case (current_state)
            start: if (x) next_state = id1; else next_state = start;
            id1:   if (x) next_state = id11; else next_state = start;
            id11:  if (x) next_state = id11; else next_state = id110;
            id110: begin
                if (x) begin
                    next_state = id1;
                    y = `found;
                end else begin
                    next_state = start;
                end
            end
            default: next_state = start;
        endcase
    end
endmodule