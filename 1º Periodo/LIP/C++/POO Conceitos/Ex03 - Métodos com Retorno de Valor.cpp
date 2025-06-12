/* Ex03 - Lista 1 CPP - Gabriel Egídio Santos Beloni*/
#include <iostream>
using namespace std;
class Retangulo{
    private:
        int largura;
        int altura;
    public:
        Retangulo(int h,int l){
            largura=l;
            altura=h;
        }
        void calcularArea(){
            int area = largura * altura;
            cout << area << endl;
        }
};
int main(){
    int h,l;
    cin >> l;
    cin >> h;
    Retangulo a(h,l);
    a.calcularArea();
    return 0;
}