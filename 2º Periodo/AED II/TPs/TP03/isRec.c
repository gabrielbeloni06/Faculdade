#include <stdio.h>
#include <string.h>
#include <stdbool.h>
//VERIFICO SE É VOGAL
bool Vogal(char c){
    return c =='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c =='O'||c=='U';
}
//PROCESSO RECURSIVO PARA VOGAIS
bool vogalRec(const char *str){
    if(*str=='\n' || *str=='\0') return true;
    if(Vogal(*str)) return vogalRec(str+1);
    return false;
}
//PRIMEIRO VERIFICO SE É UMA LETRA MINÚSCULA, DEPOIS SE NÃO É VOGAL
bool consoante(char c){
    return(c>='a'&& c<='z'&& !Vogal(c));
}
//PROCESSO RECURSIVO PARA CONSOANTES
bool consoanteRec(const char *str) {
    if(*str=='\n' || *str=='\0') return true;
    if(consoante(*str)) return consoanteRec(str + 1);
    return false;
}
//PROCESSO RECURSIVO PARA NÚMEROS INTEIROS
bool inteiroRec(const char *str) {
    if(*str=='\n' || *str=='\0') return true;
    if(*str>='0' && *str<='9') return inteiroRec(str + 1);
    return false;
}
//PROCESSO RECURSIVO PARA NÚMEROS REAIS, CONTANDO A QUANTIDADE DE SEPARADORES (vírgula ou ponto)
bool realRec(const char *str,int sepCount) {
    if(*str=='\n' || *str=='\0') return sepCount <= 1;
    char c=*str;
    if(c>='0'&&c<='9') return realRec(str + 1, sepCount);
    else if (c == '.' || c == ',') return realRec(str + 1, sepCount + 1);
    else return false;
}
bool realResp(const char *str) {
    return realRec(str, 0);
}
//NA MAIN CRIO VARIÁVEIS PARA CADA RESPOSTA E IMPRIMO (da ultima vez havia usado operador ternário, mas aqui usei if/else para variar um pouco do outro código)
int main() {
    char tag[] = "FIM\n";
    char s[1000];
    while (fgets(s, sizeof(s), stdin) != NULL) {
        if (strcmp(s, tag) == 0) break;
        const char* X1;
        const char* X2;
        const char* X3;
        const char* X4;
        if(vogalRec(s)) X1="SIM";
        else X1 = "NAO";
        if(consoanteRec(s)) X2="SIM"; 
        else X2 = "NAO";
        if(inteiroRec(s)) X3="SIM";
        else X3 = "NAO";
        if (realResp(s)) X4="SIM";
        else X4 = "NAO";
        printf("%s %s %s %s\n", X1, X2, X3, X4);
    }
    return 0;
}