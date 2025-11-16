/*
Guia_0401.v
Aluno: Gabriel Egídio Santos Beloni
Matrícula: 885080
*/
/* Este foi o código que usei para testar as funções da Atividade 01 */
module f_01a(output s, input x, y, z);
  assign s = x & (~( ~y | z ));
endmodule
module f_01b(output s, input x, y, z);
  assign s = (~( x | ~y )) & ~z;
endmodule
module f_01c(output s, input x, y, z);
  assign s = (~( ~x & y )) & z;
endmodule
module f_01d(output s, input x, y, z);
  assign s = (~( ~x & ~y )) & ~z;
endmodule
module f_01e(output s, input x, y, z);
  assign s = ( ~x | y ) & (~( ~y | ~z ));
endmodule
module Guia_0401_tb;
  reg x, y, z;
  wire s1, s2, s3, s4, s5;
  f_01a DUT1(s1, x, y, z);
  f_01b DUT2(s2, x, y, z);
  f_01c DUT3(s3, x, y, z);
  f_01d DUT4(s4, x, y, z);
  f_01e DUT5(s5, x, y, z);
  initial begin
    $display("Guia_0401 - Tabela Verdade Atividade 01");
    $display("x y z |  a  b  c  d  e");
    $display("----------------------");
    for (integer i=0; i<8; i=i+1) begin
      {x, y, z} = i;
      #1;
      $display("%b %b %b |  %b  %b  %b  %b  %b", x, y, z, s1, s2, s3, s4, s5);
    end
  end
endmodule