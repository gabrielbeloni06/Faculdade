#include <iostream>
using namespace std;
class Aluno{
    private:
        string nome;
        int matricula;
        float notaFinal;
    public:
        Aluno(int m,string s,float nota){
            nome=s;
            matricula=m;
            notaFinal=nota;
        }
        void mostrarDados(){
            cout<<"Nome do aluno: "<< nome << "Matricula " << matricula << "Nota final: " << notaFinal <<endl;
        }
};