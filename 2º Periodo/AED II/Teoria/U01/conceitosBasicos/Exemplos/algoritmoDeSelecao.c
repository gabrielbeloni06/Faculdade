for(int i=0;i<(n-1);i++){
    int menor=i;
    for(int j=(i+1);j<n;j++){
        if(a[menor]>a[j]){
            menor=j;
        }
    }
    swap(mewnor,i);
}