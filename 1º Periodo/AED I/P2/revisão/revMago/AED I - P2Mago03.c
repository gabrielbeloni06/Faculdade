/*Recursão para verificar se uma string é palindroma*/
char* final(char *str){
    if(*str=='\0'){
        return str-1;
    }
    return final(str+1);
}
int palindroma (int *inicio, int *fim){
    if(inicio>=fim){
        return 1;
    }
    if(*inicio!=*fim){
        return 0;
    }
    return palindroma(inicio+1,fim+1);
}
int result (char *str){
    char *fim=final(str);
    return palindroma(str,final);
}