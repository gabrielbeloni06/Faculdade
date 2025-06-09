int mdc(int a, int b){
    if(b==0)
    return mdc(b, a % b);
}