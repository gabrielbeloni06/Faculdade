//LAB05 - GABRIEL EGÍDIO SANTOS BELONI - 885080
//AED II - 2º PERÍODO
//FORAM IMPLEMENTADAS AS FUNÇÕES DO QUICKSORT COM A VARIAÇÃO NA ESCOLA DO PIVÔ DE 4 FORMAS DIFERENTES;
//SENDO AS 4 FORMAS: ESCOLHA DO PRIMEIRO ELEMENTO, ESCOLHA DO ÚLTIMO ELEMENTO, ESCOLHA DO ELEMENTO ALEATÓRIO E ESCOLHA DO ELEMENTO MEDIANA DE 3.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Protótipos
void swap(int *i, int *j);

//DECLARAÇÃO DE VARIÁVEIS GLOBAIS
long long comp;
long long mov;
//Usei long long para evitar que estoure o tamanho devido aos arrays de 10.000 elementos que vão ser usados nos testes

// quicksort com pivô sendo o primeiro elemento
void QuickSortFirstPivot(int *array, int left, int right){
    if (left >= right) return;
    int i=left, j = right;
    int pivo = array[left];
    while(comp++,i<=j){ //soma 1 a comp, devido a comparação feita no while.
        while(comp++,array[i]<pivo) i++; //usei comp++ para contar as comparações feitas a cada repitição do while
        while(comp++,array[j]>pivo) j--; //mesma lógica do de cima.
        if(comp++,i<=j){
            swap(array + i, array + j);
            i++;
            j--;
        }
    }
    if(comp++,left<j) QuickSortFirstPivot(array, left, j);
    if(comp++,i<right) QuickSortFirstPivot(array,i,right);
}

// quicksort com pivô sendo o último elemento
void QuickSortLastPivot(int *array, int left, int right){
    if (left >= right) return;
    int i = left, j = right;
    int pivo = array[right];
    while(comp++,i<=j){ //MESMA LÓGICA DO QuickSortFirstPivot, NÃO VAI SER NECESSÁRIO EXPLICAR NOVAMENTE.
        while(comp++,array[i]<pivo) i++;
        while(comp++,array[j]>pivo) j--;
        if(comp++,i<=j){
            swap(array + i, array +j);
            i++;
            j--;
        }
    }
    if(comp++,left<j) QuickSortLastPivot(array, left, j);
    if(comp++,i<right) QuickSortLastPivot(array, i, right);
}

// quicksort com pivô sendo um elemento aleatório
void QuickSortRandomPivot(int *array, int left, int right){
    if (left >= right) return;
    int i = left,j=right;
    int random = (rand() % (right-left+1)) + left; //ESSA LINHA GERA O NÚMERO ALEATÓRIO QUE PERTENCE AO INTERVALO ENTRE LEFT E RIGHT
    int pivo = array[random];
    while(comp++,i<=j){ //MESMA LÓGICA DO QuickSortFirstPivot, NÃO VAI SER NECESSÁRIO EXPLICAR NOVAMENTE.
        while(comp++,array[i]<pivo)i++;
        while(comp++,array[j]>pivo)j--;
        if(comp++,i<=j){
            swap(array + i, array + j);
            i++;
            j--;
        }
    }
    if(comp++,left<j) QuickSortRandomPivot(array, left, j);
    if(comp++,i<right) QuickSortRandomPivot(array, i, right);
}

// quicksort com pivô sendo a mediana de três elementos
void QuickSortMedianOfThree(int *array, int left, int right){
    if (left >= right) return;
    int i = left, j=right;
    //CÁLCULO DO ELEMENTO DO MEIO.
    int meio = (left+right) / 2;
    //ORDENAÇÃO DOS 3 ELEMENTOS (LEFT, MEIO E RIGHT) PARA ENCONTRAR A MEDIANA
    if(comp++, array[left]>array[meio]) swap(array+left, array+meio);
    if(comp++, array[left]>array[right]) swap(array+left, array+right);
    if(comp++, array[meio]>array[right]) swap(array+meio, array+right);
    int pivo = array[meio];
    //a partir daqui é a mesma lógica do QuickSortFirstPivot, não é necessário explicar novamente.
    while(comp++,i<=j){
        while(comp++,array[i]<pivo)i++;
        while(comp++,array[j]>pivo)j--;
        if(comp++,i<=j){
            swap(array+i, array+j);
            i++;
            j--;
        }
    }
    if(comp++,left<j) QuickSortMedianOfThree(array, left, j);
    if(comp++,i<right) QuickSortMedianOfThree(array, i, right);
}

//FUNÇÃO SWAP (TROCAR ELEMENTOS DE POSIÇÃO)
void swap(int *i, int *j){
    int tmp = *i;
    *i = *j;
    *j = tmp;
    mov+=3; //aumento do contador em 3 movimentações.
}

//FUNÇÃO PARA PREENCHER O ARRAY DE FORMA ALEATÓRIA
void preencherAleatorio(int *array, int n){
    for(int i=0;i<n;i++){
        array[i] = rand() % (n*10);
    }
}
//FUNÇÃO PARA PREENCHER O ARRAY DE FORMA ORDENADA
void preencherOrdenado(int *array, int n){
    for(int i=0;i<n;i++){
        array[i]=i;
    }
}

//FUNÇÃO PARA PREENCHER O ARRAY DE FORMA QUASE ORDENADA
void preencherQuaseOrdenado(int *array, int n){
    preencherOrdenado(array,n);
    //precisamos de uma base para considerar a margem de não ordenado, vamos considerar 10% para ser padrão.
    int margem=n*0.1; //o 0.1 é o indice de 10%.
    for(int i=0;i<margem;i++){
        int pos1 = rand() % n; //aqui pegamos um posição aleatória do array para trocar e desordenar um pouco.
        int pos2 = rand() % n; //mesma coisa da de cima.
        swap(array+pos1, array+pos2);
    }
    mov=0; //zeramos o contador, pois não devemos considerar esses swaps, visto que é feito apenas para desordenar.
}

//FUNÇÃO PARA IMPRIMIR O ARRAY
void imprimir(int *array, int n){
    for(int i=0;i<n;i++) printf("%d ", array[i]);
    printf("\n");
}

//main para testes
int main(){
    srand(time(NULL)); //inicializa o rand
    int tam[]={100,1000,10000,50000}; //ARRAY COM OS TAMANHOS PARA OS TESTES.

    for (int i = 0; i < 4; i++) {
        int n = tam[i];
        //ALOCAMOS O 4 TIPOS DE ARRAYS QUE VAMOS USAR PARA CADA UM DOS TESTES.
        int *array1 = (int *) malloc(n * sizeof(int));
        int *array2 = (int *) malloc(n * sizeof(int));
        int *array3 = (int *) malloc(n * sizeof(int));
        int *array4 = (int *) malloc(n * sizeof(int));

        //funções para o cálculo de tempo, usando a biblioteca do código.
        clock_t start1, end1, start2, end2, start3, end3, start4, end4;
        double tempo1, tempo2, tempo3, tempo4;

        //TESTE COM O ARRAY ALEATORIO
        printf("\nAleatório\n");
        preencherAleatorio(array1, n);
        //fazemos a cópia do array1 para os outros arrays, para que todos comecem iguais.
        memcpy(array2, array1, n * sizeof(int));
        memcpy(array3, array1, n * sizeof(int));
        memcpy(array4, array1, n * sizeof(int));

        //zeramos os contadores antes de cada ordenação.
        //first
        comp = 0; mov = 0;
        //comando apenas para ver o tempo gasto em cada ordenação.
        start1 = clock();
        QuickSortFirstPivot(array1, 0, n - 1); //chamada da função do quicksort.
        //parar o relógio.
        end1 = clock();
        //cálculo do tempo gasto (em segundos, comandos retirados da internet -> no site da biblioteca).
        tempo1 = ((double)(end1 - start1)) / CLOCKS_PER_SEC;
        printf("First - Tempo: %f seg - Comp: %lld | Mov: %lld\n", tempo1, comp, mov);

        //A PARTIR DAQUI REPETIMOS O MESMO PROCESSO PARA OS OUTROS 3 TIPOS DE QUICKSORT, NÃO É NECESSÁRIO EXPLICAR NOVAMENTE.
        //last
        comp = 0; mov = 0;
        start2 = clock();
        QuickSortLastPivot(array2, 0, n - 1);
        end2 = clock();
        tempo2 = ((double)(end2 - start2)) / CLOCKS_PER_SEC;
        printf("Last - Tempo: %f seg | Comp: %lld | Mov: %lld\n", tempo2, comp, mov);

        //random
        comp = 0; mov = 0;
        start3 = clock();
        QuickSortRandomPivot(array3, 0, n - 1);
        end3 = clock();
        tempo3 = ((double)(end3 - start3)) / CLOCKS_PER_SEC;
        printf("Random - Tempo: %f seg | Comp: %lld | Mov: %lld\n", tempo3, comp, mov);

        //mediana
        comp = 0; mov = 0;
        start4 = clock();
        QuickSortMedianOfThree(array4, 0, n - 1);
        end4 = clock();
        tempo4 = ((double)(end4 - start4)) / CLOCKS_PER_SEC;
        printf("Median - Tempo: %f seg | Comp: %lld | Mov: %lld\n", tempo4, comp, mov);

        //TESTE COM O ARRAY ORDENADO
        printf("\n Array Ordenado \n");
        preencherOrdenado(array1, n);
        memcpy(array2, array1, n * sizeof(int));
        memcpy(array3, array1, n * sizeof(int));
        memcpy(array4, array1, n * sizeof(int));
        comp = 0; mov = 0;
        start1 = clock();
        QuickSortFirstPivot(array1, 0, n - 1);
        end1 = clock();
        tempo1 = ((double)(end1 - start1)) / CLOCKS_PER_SEC;
        printf("QuickSort First Pivot   - Tempo: %f seg | Comp: %lld | Mov: %lld\n", tempo1, comp, mov);

        comp = 0; mov = 0;
        start2 = clock();
        QuickSortLastPivot(array2, 0, n - 1);
        end2 = clock();
        tempo2 = ((double)(end2 - start2)) / CLOCKS_PER_SEC;
        printf("QuickSort Last Pivot    - Tempo: %f seg | Comp: %lld | Mov: %lld\n", tempo2, comp, mov);

        comp = 0; mov = 0;
        start3 = clock();
        QuickSortRandomPivot(array3, 0, n - 1);
        end3 = clock();
        tempo3 = ((double)(end3 - start3)) / CLOCKS_PER_SEC;
        printf("QuickSort Random Pivot  - Tempo: %f seg | Comp: %lld | Mov: %lld\n", tempo3, comp, mov);

        comp = 0; mov = 0;
        start4 = clock();
        QuickSortMedianOfThree(array4, 0, n - 1);
        end4 = clock();
        tempo4 = ((double)(end4 - start4)) / CLOCKS_PER_SEC;
        printf("QuickSort Median of 3   - Tempo: %f seg | Comp: %lld | Mov: %lld\n", tempo4, comp, mov);

        //ARRAY QUASE ORDENADO
        printf("\n Quase Ordenado \n");
        preencherQuaseOrdenado(array1, n);
        memcpy(array2, array1, n * sizeof(int));
        memcpy(array3, array1, n * sizeof(int));
        memcpy(array4, array1, n * sizeof(int));

        comp = 0; mov = 0;
        start1 = clock();
        QuickSortFirstPivot(array1, 0, n - 1);
        end1 = clock();
        tempo1 = ((double)(end1 - start1)) / CLOCKS_PER_SEC;
        printf("QuickSort First Pivot   - Tempo: %f seg | Comp: %lld | Mov: %lld\n", tempo1, comp, mov);

        comp = 0; mov = 0;
        start2 = clock();
        QuickSortLastPivot(array2, 0, n - 1);
        end2 = clock();
        tempo2 = ((double)(end2 - start2)) / CLOCKS_PER_SEC;
        printf("QuickSort Last Pivot    - Tempo: %f seg | Comp: %lld | Mov: %lld\n", tempo2, comp, mov);

        comp = 0; mov = 0;
        start3 = clock();
        QuickSortRandomPivot(array3, 0, n - 1);
        end3 = clock();
        tempo3 = ((double)(end3 - start3)) / CLOCKS_PER_SEC;
        printf("QuickSort Random Pivot  - Tempo: %f seg | Comp: %lld | Mov: %lld\n", tempo3, comp, mov);

        comp = 0; mov = 0;
        start4 = clock();
        QuickSortMedianOfThree(array4, 0, n - 1);
        end4 = clock();
        tempo4 = ((double)(end4 - start4)) / CLOCKS_PER_SEC;
        printf("QuickSort Median of 3   - Tempo: %f seg | Comp: %lld | Mov: %lld\n", tempo4, comp, mov);

        //APENAS LIBERANDO A MEMÓRIA ALOCADA
        free(array1);
        free(array2);
        free(array3);
        free(array4);
    }
    return 0;
}