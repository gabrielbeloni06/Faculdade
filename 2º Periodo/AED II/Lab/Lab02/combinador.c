#include <stdio.h>
#include <string.h>
int main() {
    char strA[100],strB[100],final[200];
    while (scanf("%s %s", strA, strB) != EOF){
        int compA=strlen(strA);
        int compB=strlen(strB);
        int a=0,b=0,count=0;
        while(a<compA && b<compB) {
            final[count++]=strA[a++];
            final[count++]=strB[b++];
        }
        while(a< compA){
            final[count++]=strA[a++];
        }
        while(b<compB){
            final[count++]=strB[b++];
        }
        final[count]='\0';
        printf("%s\n",final);
    }
    return 0;
}
