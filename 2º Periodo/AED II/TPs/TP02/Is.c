#include <stdio.h>
#include <string.h>
#include <stdbool.h>
bool vogais(char *str){
    int count=0;
    for(int i=0;i<strlen(str);i++){
        if(str[i]!='a' && str[i]!='e' && str[i]!='i' && str[i]!='o' && str[i]!='u' && str[i]!='A' && str[i]!='E' && str[i]!='I' && str[i]!='O' && str[i]!='U' && str[i]!='\n')count++;
    }
    if(count==0)return true;
    else return false;
}
bool consoantes(char *str){
    int count=0;
    for(int i=0;i<strlen(str);i++){
        if(str[i]!='\n'){
            if(str[i]<'a' || str[i]>'z' || str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u')count++;
        }
    }
    if(count==0)return true;
    else return false;
}
bool inteiro(char *str){
    int count=0;
    for(int i=0;i<strlen(str);i++){
        if(str[i]!='\n'){
            if(str[i]<'0'||str[i]>'9') count++;
        }
    }
    if(count==0)return true;
    else return false;
}
bool real(char *str){
    int op=0;
    for(int i=0;i<strlen(str);i++){
        if(str[i]!='\n'){
            if(str[i]<'0'||str[i]>'9'){
                if(str[i]=='.' || str[i]==','){
                    op++;
                }
                else return false;
            }
        }
    }
    if(op>1) return false;
    else return true;
}
int main(){
    char tag[]="FIM\n";
    char s[1000];
    while(fgets(s, sizeof(s), stdin) != NULL){
        if(strcmp(s, tag) == 0)break;
        const char* X1 = vogais(s) ? "SIM":"NAO";
        const char* X2 = consoantes(s) ? "SIM":"NAO";
        const char* X3 = inteiro(s) ? "SIM":"NAO";
        const char* X4 = real(s) ? "SIM":"NAO";
        printf("%s %s %s %s\n",X1,X2,X3,X4);
    }
    return 0;
}