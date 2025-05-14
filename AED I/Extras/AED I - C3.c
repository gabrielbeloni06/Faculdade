#include <stdio.h>
int pot(int num, int x){
    if(x==0){
        return 1;
    }
    if(x==1){
        return num;
    }
    return num * pot(num, x - 1);
}