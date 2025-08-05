#include <stdio.h>
#include <string.h>
void recursao(){
	char s[100];
	int count=0;
	char tag[]={"FIM\n"};
	fgets(s,100,stdin);
	if(strcmp (s,tag)==0) return;
	for(int i=0;s[i]!='\0';i++){
		if(s[i]>='A'&&s[i]<='Z')count++;
	}
	printf("%d\n",count);
	recursao();
}
int main(){
	recursao();
}
