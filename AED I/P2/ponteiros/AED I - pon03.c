#include <stdio.h>
void troca(float *a, float *b){
    float copy;
    copy = *a;
    *a = *b;
    *b = copy;
}
float main(){
    float a,b;
    scanf("%f %f",&a,&b);
    troca(&a,&b);
    printf("%.2f %.2f\n",a,b);
    return 0;
}