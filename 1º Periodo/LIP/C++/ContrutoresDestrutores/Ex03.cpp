/*Ex03 - Lista02 - Gabriel Egídio Santos Beloni*/
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <limits>
using namespace std;
class Produto{
    private:
        string nome;
        float preco;
    public:
        Produto(string n, float p){
            nome=n;
            preco=p;
        }
        Produto(string n){
            nome=n;
            preco=0.0f;
        }
        void imprimir(){
            cout << fixed << setprecision(2);
            cout << "Produto criado: " << nome << endl;
            cout << "Preco: " << preco <<endl;
        }
        void setPreco(float p2){
            preco=p2;
        }
        ~Produto(){
            cout << "Produto destruido: " << nome << endl;
        }
};
int main(){
    string n,n2;
    float p,p2;
    getline(cin,n);
    cin>>p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin,n2);
    cin>>p2;
    Produto a(n,p);
    Produto b(n2);
    b.setPreco(p2);
    a.imprimir();
    b.imprimir();
    return 0;
}