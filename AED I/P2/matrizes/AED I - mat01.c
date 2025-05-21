/*Apresentação de Matriz estática*/
#include <stdio.h>
int main(){
    int n,m;
    int mat[3][3]={1,2,3,4,5,6,7,8,9};
    /* | c0  | c1  | c2  |
    l0 |  1  |  2  |  3  |
    l1 |  4  |  5  |  6  |
    l2 |  7  |  8  |  9  |
    */
   for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
   }
   return 0;
}