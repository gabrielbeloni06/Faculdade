/*
Guia_11 - moore_1101.v
Aluno: Gabriel Egídio Santos Beloni
Matrícula: 885080
*/
`define found 1'b1
`define notfound 1'b0
module moore_1101 (output y, input x, clk, reset);
    parameter start = 3'b000, id1 = 3'b001, id11 = 3'b011, id110 = 3'b010, id1101 = 3'b110; // State 'id1101' will have output 1
    reg [2:0] current_state, next_state;
    always @(posedge clk or posedge reset)
    begin
        if (reset)
            current_state <= start;
        else
            current_state <= next_state;
    end
    always @*
    begin
        case(current_state)
            start:   if (x) next_state = id1;    else next_state = start;
            id1:     if (x) next_state = id11;   else next_state = start;
            id11:    if (x) next_state = id11;   else next_state = id110;
            id110:   if (x) next_state = id1101; else next_state = start;
            id1101:  if (x) next_state = id11;   else next_state = start;
            default: next_state = start;
        endcase
    end
    assign y = (current_state == id1101) ? `found : `notfound;
endmodule