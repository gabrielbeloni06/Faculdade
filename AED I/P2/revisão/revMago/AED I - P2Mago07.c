/*Recursão para verificar se uma string está contida em outra string*/
int substring(char *s, char *sub){
    if(*sub=='\0'){
        return 1;
    }
    if(*s=='\0'){
        return 0;
    }
    if(*s==*sub){
        int i=1;
        while(sub[i]!='\0'&& s[i]!='\0'&& sub[i]==s[i]){
            i++;
        }
        if(sub=='\0'){
            return 1;
        }
    }
    return substring(s+1,sub);
}