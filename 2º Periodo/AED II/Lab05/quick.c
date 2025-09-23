#include <stdio.h>
#include <stdlib.h>
int *array;
int countM=0;
int countC=0;
int preencher() {
   int n;
   scanf("%d", &n);
   array = (int*) malloc(n*sizeof(int));  
   for (int i = 0; i < n; i++) {
      scanf("%d", &array[i]);
   }
   return n;
}
void swap(int *i, int*j){
	int temp=*i;
	*i = *j;
	*j = temp;
}
void QuickSortFirstPivot(int left, int right){
	countM=0;
	countC=0;
	int i = left;
	int j = right;
	int pivo = array[0];
	countC++;
	while(i<=j){
		countC+=3;
		while(array[i]<pivo){i++; countC++;}
		while(array[j]>pivo){j--; countC++;}
		if(i<=j){
			swap(array + i, array + j);
			countM++;
			i++;
			j--;
		}
	}
	if(left<j)QuickSortFirstPivot(left,j);
	if(i<right)QuickSortFirstPivot(i,right);
	countC+=2;
	printf("mov = %d, comp =  %d",countM,countC);
}
void QuickSortLastPivot(){
	countM=0;
	countC=0;
	int tam = sizeof(array) / sizeof(int);
	int i = left;
	int j = right;
	int pivo = array[tam-1];
	countC++;
	while(i<=j){
		countC+=3;
		while(array[i]<pivo){i++; countC++;}
		while(array[j]>pivo){j--; countC++;}
		if(i<=j){
			swap(array + i, array + j);
			countM++;
			i++;
			j--;
		}
	}
	if(left<j)QuickSortLastPivot
	if(i<right)QuickSortLastPivot

}

void QuickSortRandomPivot(){

}

void QuickSortMedianOfThree(){

}

int main(){

}
