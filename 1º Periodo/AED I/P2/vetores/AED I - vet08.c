#include <stdio.h>
int main(){
    int n;
    int v[10];
    for(int i=0;i<10;i++){
        scanf("%d",&v[i]);
    }
    for(int i=0; i<10;i++){
        n += v[i];
    }
    printf("%d\n",n);
    return 0;
}





/*Maneira reduzida, juntar n += v[i] no primeiro for*/
#include <stdio.h>
int main(){
    int n;
    int v[10];
    for(int i=0;i<10;i++){
        scanf("%d",&v[i]);
        n += v[i];
    }
    printf("%d\n",n);
    return 0;
}