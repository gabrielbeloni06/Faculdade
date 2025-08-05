#include <stdio.h>
#include <string.h>
int main(){
	char s[100];
	char tag[]={"FIM\n"};
	int count;
	fgets(s, 100, stdin);
	while (strcmp(s,tag)!=0){
		count=0;
		for(int i=0;s[i]!='\0';i++){
			if(s[i]>='A' && s[i]<='Z') count++;
		}
		printf("%d\n",count);
		fgets(s, 100, stdin);
	}
	return 0;
}
