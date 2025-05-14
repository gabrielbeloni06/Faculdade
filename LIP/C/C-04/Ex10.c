//Exercicio 10 - Gabriel Egídio Santos Beloni
#include <stdio.h>
#include <string.h>
void separaPalavras(char frase[]) {
    printf("Estou no procedimento!\n");
    char *token = strtok(frase, " ,.;!?");
    while (token) {
        printf("%s\n", token);
        token = strtok(NULL, " ,.;!?");
    }
    printf("saindo do procedimento!\n");
}
int main() {
    int n;
    char frase[151];
    printf("Quantas mensagens deseja decifrar?:\n");
    scanf("%d", &n);
    getchar(); 

    for (int i = 1; i <= n; i++) {
     
        printf("conjunto %d:\n", i);
       
        printf("Digite a %d mensagem secreta:\n", i);
        scanf(" %150[^\n]", frase);
        getchar();

     
        printf("Chamando o procediemnto!\n");
        separaPalavras(frase);
        
        printf("Voltou do procedimento\n");
    }

    return 0;
}