// Exercicio 8 - Gabriel Egídio Santos Beloni
#include <stdio.h>
#include <string.h>

void mensagemOraculo(char dataNascimento[], int diaA, int mesA, int anoA, int *idade) {
    int dN, mN, aN;
    sscanf(dataNascimento, "%d/%d/%d", &dN, &mN, &aN);
    *idade = anoA - aN;
    if (mesA < mN || (mesA == mN && diaA < dN)) {
        (*idade)--;
    }
    printf("Estou no procedimento!\n");
    printf("saindo do procedimento!\n");
}

int main() {
    int diaA, mesA, anoA;
    int qtd, idade;
    char nome[51], dataNascimento[11];


    printf("Digite a data atual no formato dd/mm/aaaa:\n");
    scanf("%d/%d/%d", &diaA, &mesA, &anoA);


    printf("Quantas mensagens deseja enviar?:\n");
    scanf("%d", &qtd);
    getchar(); 

    for (int i = 1; i <= qtd; i++) {

        printf("conjunto %d:\n", i);

        printf("Digite o nome:\n");
        fgets(nome, sizeof(nome), stdin);
        nome[strcspn(nome, "\n")] = '\0';


        printf("Digite a data de nascimento formato dd/mm/aaaa:\n");
        scanf("%s", dataNascimento);
        getchar();


        printf("Chamando o procedimento!\n");
        mensagemOraculo(dataNascimento, diaA, mesA, anoA, &idade);
    
        printf("Voltou do procedimento!\n");


        printf("Ola %s! Voce tem %d anos!\n", nome, idade);
    }

    return 0;
}