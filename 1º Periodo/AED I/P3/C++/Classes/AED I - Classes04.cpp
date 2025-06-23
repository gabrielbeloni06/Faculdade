#include <iostream>
using namespace std;
class Retangulo{
    private:
        int base;
        int altura;
    public:
        Retangulo(int b,int a){
            base=b;
            altura=a;
        }
        int area(){
            return base*altura;
        }
        int Perimetro(){
            return 2*(base+altura);
        }
};