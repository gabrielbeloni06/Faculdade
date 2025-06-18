/*Ex01 - Lista02 - Gabriel Egídio Santos Beloni*/
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
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
        void imprimir(){
            cout << fixed << setprecision(2);
            cout << "Produto criado: " << nome << " - Preco: " << preco << endl;
        }
    ~Produto(){
        cout << "Produto destruido: " << nome << endl;
    }
};
int main(){
    string n;
    float p;
    getline(cin, n);
    n.erase(std::remove(n.begin(), n.end(), '\r'), n.end());
    cin>>p;
    Produto a(n,p);
    a.imprimir();
    return 0;
}