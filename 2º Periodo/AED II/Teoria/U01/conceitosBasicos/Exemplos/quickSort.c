void quicksort(){
    quicksort(0,n-1);
}
void quicksort(int esq, int dir){
    int i=esq,j=dir;
    pivo=a[(esq+dir)/2];
    while(i<=j){
        while(a[i<pivo]){
            i++;
        }
        while(a[j]>pivo){
            j--;
        }
        if(i<=j){
            swap(i,j);
            i++;
            j--;
        }
    }
    if(esq<j){
        quicksort(esq,j);
    }
    if(i<dir){
        quicksort(i,dir);
    }
}