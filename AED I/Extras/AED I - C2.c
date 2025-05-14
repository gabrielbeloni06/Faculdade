#include <stdio.h>
int soma(int num){
    if (num==0){
        return 0;
    }
    else{
        return num + soma(num-1);
    }
}