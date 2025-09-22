#include <stdio.h>
#include <stdbool.h>
bool resp=false;
int main(){
    int dir=n-1, esq=0, meio, dif;
    while(esq<=dir){
        meio=(esq+dir)/2;
        dif=(x-a[meio]);
        if(dif==0){
            resp=true;
            esq=n;
        }else if(dif>0){
            esq=meio+1;
        }
        else{
            dir=meio-1;
        }
    }
}