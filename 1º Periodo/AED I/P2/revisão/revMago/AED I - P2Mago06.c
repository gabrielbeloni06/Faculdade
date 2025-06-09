/*Funcão para verificar se uma string é anagrama de outra string*/
int anagrama(char *s, char *s2){
    int i=0;
    for(i=0;s[i]!='\0';i++){
        if(s[i]>='A' && s[i]<='Z'){
            s[i]=s[i]+32;
        }
        if(s2[i]>='A' && s2[i]<='Z'){
            s2[i]=s2[i]+32;
        }
    }
    int *letras=malloc(26*sizeof(int));
    for(i=0;i<26;i++){
        letras[i]=0;
    }
    for(i=0;s[i]!='\0';i++){
        letras[s[i]-'a']++;
    }
    for(i=0;s2[i]!='\0';i++){
        letras[s2[i]-'a']--;
    }
    for(i=0;i<26;i++){
        if(letras[i]!=0){
            free(letras);
            return 0;
        }
    }
    free(letras);
    return 1;
}