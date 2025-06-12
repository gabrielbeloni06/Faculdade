/* Ex01 - Lista 1 CPP - Gabriel Egídio Santos Beloni*/
#include <iostream>
#include <string>
using namespace std;
class Livro{
    public:
        string titulo;
        string autor;
        void imprimir(){
            cout<< "Titulo: " << titulo <<endl;
            cout<< "Autor: " << autor <<endl;
        }
};
int main(){
    Livro a;
    getline(cin,a.titulo);
    getline(cin,a.autor);
    a.imprimir();
    return 0;
}