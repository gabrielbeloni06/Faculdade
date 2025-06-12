/* Ex04 - Lista 1 CPP - Gabriel Egídio Santos Beloni*/
#include <iostream>
#include <iomanip>
using namespace std;
class Retangulo{
    private:
        float altura;
        float largura;
        float area;
    public:
        Retangulo(float l, float h){
            largura=l;
            altura=h;
        }
        void calcularArea(){
            area=largura*altura;
        }
        void imprimir(){
            cout << fixed<<setprecision(2);
            cout << "Largura: " << largura << ", " << "Altura: " << altura << endl;
            cout << "Area do retangulo: " << area << endl;
        }
};
int main(){
    float h, l;
    cin>>l;
    cin>>h;
    Retangulo a(l,h);
    a.calcularArea();
    a.imprimir();
    return 0;

}