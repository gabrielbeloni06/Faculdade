/*Inversão de string*/
void inverter(char *s){
    int i=0;
    while(s[i]!='\0'){
        i++;
    }
    int j=i-1;
    i=0;
    while(i<j){
        char copy=s[i];
        s[i]=s[j];
        s[j]=copy;
        i++;
        j--;
    }
}