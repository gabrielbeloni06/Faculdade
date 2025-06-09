int soma(int num){
    if(num==0)
    return 0;
    else{ return (num % 10) + soma(num/10);
    }
}