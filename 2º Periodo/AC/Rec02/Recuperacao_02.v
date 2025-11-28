/*
Recuperacao_02.v
Aluno: Gabriel Egídio Santos Beloni
Matrícula: 885080
Descrição: Implementação das equações lógicas derivadas da Tabela de Transição.
Entradas: a, b, c, d
Saídas: Da, Db, Dc
*/

module excitation_logic (
    output Da, Db, Dc,
    input a, b, c, d
);

    // 02.) Equação para Da (Next State A)
    // Da = c.d' + b.c + a.c + a'.b'.c'.d
    assign Da = (c & ~d) | (b & c) | (a & c) | (~a & ~b & ~c & d);

    // 03.) Equação para Db (Next State B)
    // Db = a.b.c + a.c.d' + a'.b'.c'.d
    assign Db = (a & b & c) | (a & c & ~d) | (~a & ~b & ~c & d);

    // 04.) Equação para Dc (Next State C)
    // Dc = a'.b'.c'.d + a'.b.c.d' + a.b'.c.d + a.b.c.d'
    assign Dc = (~a & ~b & ~c & d) | 
                (~a & b & c & ~d) | 
                (a & ~b & c & d) | 
                (a & b & c & ~d);

endmodule
module test_excitation;
    reg a, b, c, d;
    wire Da, Db, Dc;

    excitation_logic dut (Da, Db, Dc, a, b, c, d);

    initial begin
        $display("m (abcd) | Db Dc Da (Next State)");
        $display("---------|---------------------");
        for (integer i = 0; i < 16; i = i + 1) begin
            {a, b, c, d} = i;
            #10;
            $display("%b %b %b %b |  %b  %b  %b", a, b, c, d, Db, Dc, Da);
        end
        $finish;
    end
endmodule