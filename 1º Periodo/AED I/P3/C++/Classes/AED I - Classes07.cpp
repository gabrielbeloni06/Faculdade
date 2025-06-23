#include <iostream>
using namespace std;
class Livro{
    private:
        string titulo;
        string autor;
        int pagLidas=0;
    public:
        Livro(string t, string a){
            titulo=t;
            autor=a;
        }
        void lerPag(int p){
            if(p>0) pagLidas+=p;
            else cout << "Valor inválido.";
        }
        void progresso(){
            cout << "Número de páginas lidas: " << pagLidas << endl;
        }
};