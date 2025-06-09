#include <stdio.h>
int main(){
    int v[10], *p;
    for(int i =0;i<10;i++){
        scanf("%d",&v[i]);
        p=&v[i];
        printf("%d ",v[i]);
        printf("%p ",p);
    }
    return 0;
}