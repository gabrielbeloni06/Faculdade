#include <iostream>
using namespace std;
class Carro{
    private:
        string modelo;
        int ano;
        int velocidadeAtual;
    public:
        Carro(string m, int a, int v){
            modelo=m;
            ano=a;
            velocidadeAtual=v;
        }
        void acelerar(int aumento){
            velocidadeAtual+=aumento;
        }
        void frear(int decremento){
            velocidadeAtual-=decremento;
            if(velocidadeAtual<0) velocidadeAtual=0;
        }
        int getVelocidadeAtual(){
            return velocidadeAtual;
        }
};