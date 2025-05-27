int pot(int n, int x){
    if(n==0) return 1;
    return x * pot(x,n-1);
}
int main(){
        int n,x;
        scanf("%d %d",&n,&x);
        printf("%d\n",pot(n,x));
        return 0;    
}

