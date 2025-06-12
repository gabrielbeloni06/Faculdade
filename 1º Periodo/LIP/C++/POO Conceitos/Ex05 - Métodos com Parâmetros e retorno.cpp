/* Ex05 - Lista 1 CPP - Gabriel Egídio Santos Beloni*/
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
class Circulo{
    private:
        float raio;
        float circunferencia;
        float pi;
    public:
        void lerRaio(){
            cin >> raio;
        }
        double calcularCircunferencia(double p){
            circunferencia= 2*p*raio;
        }
        void imprimir(){
            cout << fixed<<setprecision(2);
            cout << "Raio:" << raio << endl;
            cout << "Circunferencia do circulo: " << circunferencia;
        }
};
int main(){
    float r;
    double p;
    Circulo a;
    a.lerRaio();
    a.calcularCircunferencia(M_PI);
    a.imprimir();
    return 0;
}