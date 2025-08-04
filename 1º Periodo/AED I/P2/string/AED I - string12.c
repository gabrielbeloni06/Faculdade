/*Ordenar string*/
void ordenar(char *s){
    int i=0;
    while(s[i]!='\0'){
        i++;
    }
    int n=i;
    for(i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(s[i]>s[j]){
                char copy=s[i];
                s[i]=s[j];
                s[j]=copy;
            }
        }
    }
}