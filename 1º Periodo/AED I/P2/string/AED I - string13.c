/*Verificar se é palíndromo*/
int palindromo(int *s){
    int i=0;
    while(s[i]!='\0'){
        i++;
    }
    int j=i-1;
    i=0;
    while(i<j){
        if(s[i]!=s[j]){
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}