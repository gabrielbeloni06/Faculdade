#include <iostream>
using namespace std;
class Pessoa{
    private:
        string nome;
        int idade;
    public:
        Pessoa(string s,int i){
            nome = s;
            idade = i;
        }
        void imprimir(){
            cout << "Name: "<< nome<<",Idade: "<<idade<<endl;
        }
        int getIdade(){
            return idade;
        }
        void setIdade(int nv){
            idade = nv;
        }
};