/*Atividade passada em sala 23/06/2025 - AED I*/
#include <iostream>
#include <math.h>
using namespace std;
class Parabola{
    private:
        float a,b,c;
        Parabola (){}
    public:
        Parabola(float ca,float cb, float cc){}
        ~Parabola(){}
        bool raizes(float& x1, float& x2){
            float delta =b*b-4*a*c;
            if(delta<0) return false;
            else{
                x1=(-b + sqrt (delta))/(2*a);
                x2=(-b + sqrt (delta))/(2*a);
                return true;
            }
        }
        void vertice(float& xv, float& yv){
            xv = -b/(2*a);
            yv = a*xv*xv+b*xv+c;
        }
        float intersecao(){
            return c;
        }
        bool existeRaiz(){
            if(b*b-4*a*c<0){
                return false;
            }else{
                return true;
            }
        }
        int direcao(){
            if(a<0){
                return -1;
            }
            else{
                return 1;
            }
        }
        float getA(){return a;}
        float getB(){return b;}
        float getC(){return c;}
        void setA(float valor){a=valor;}
        void setB(float valor){b=valor;}
        void setC(float valor){c=valor;}
};