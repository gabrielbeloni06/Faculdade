for(int i=1;i<n;i++){
    int tmp=a[i];
    int j=i-1;
    while((j>=0)&&(a[j]>tmp){
        a[j+1]=a[j];
        j--;
    }
    a[j+1]=tmp;
}