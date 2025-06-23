#include <iostream>
using namespace std;
class ContaBancaria{
    private:
        string titular;
        double saldo;
    public:
        ContaBancaria(string t, double s){
            titular=t;
            saldo=s;
        }
        void depositar(double valor){
            if(valor>=0) saldo+=valor;
        }
        void sacar(double valor){
            if(valor>=0 && valor<=saldo){
                saldo-=valor;
            }
            else cout << "Saldo Insuficiente";
        }
        void mostrarSaldo(){
            cout << "Titular " << titular << " Saldo: R$ " << saldo << endl; 
        }
};