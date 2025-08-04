#include <iostream>
using namespace std;
class Pessoa{
    protected:
        int idade;
        string nome;
        string endereco;
        char genero;
        Pessoa(){};
    public:
        Pessoa(string n){
            nome=n;
        }
        string getNome(){return nome;}
        int getIdade(){return idade;}
        string getEndereco(){return endereco;}
        char getGenero(){return genero;}
        void setIdade(int i){idade=i;}
        void setNome(string n){nome=n;}
        void setEndereco(string e){endereco=e;}
        void setGenero(char g){genero=g;}
        ~Pessoa(){}
};
class Funcionario:public Pessoa{
    protected:
        float salario;
        string departamento;
        int matricula;
        Funcionario(){}
    public:
        Funcionario(string n, int m){
            matricula=m;
        }
        float getSalario(){return salario;}
        string getDepartamente(){return departamento;}
        int getMatricula(){return matricula;}
        void setSalario(float s){salario=s;}
        void setDeparatamento(string d){departamento=d;}
        void setMatricula(int m){matricula=m;}
        ~Funcionario(){}
};
class Aluno:public Pessoa{
    private:
        int ano;
        int qtdN;
        float notas;
        int matricula;
        Aluno(){}
    public:
        Aluno(int a, int qN,float *notas, int m){
            notas=new float[qN];
        }
        ~Aluno(){
            delete[]notas;
            notas=NULL;
        }
};
class Dependente:public Funcionario, public Pessoa{
    private:
        string nome;
        int idade;
        char genero;
};
