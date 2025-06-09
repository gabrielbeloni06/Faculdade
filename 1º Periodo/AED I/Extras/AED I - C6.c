int dig(int num){
    if(num<10)
        return 1;
    else
        return 1 + dig(num/10);
}