#include <iostream>
#include <cmath>
using namespace std;
class Circulo{
    private:
        float raio, x, y;
        Circulo(){}
    public:
        Circulo(float r, float cx, float cy){
            raio = r;
            x=cx;
            y=cy;
        }
        ~Circulo(){}
        float area(){
            return M_PI * raio * raio;
        }
        float perimetro(){
            return 2*M_PI*raio;
        }
        void mover(float dx, float dy){
            x+=dx;
            y+=dy;
        }
        bool contemPonto(float px, float py){
            float cord = ((px-x) * (px-x)) + ((py-y) * (py-y));
            if(cord<=(raio*raio)) return true;
            else return false;
        }
        float getRaio(){return raio;}
        float getX(){return x;}
        float getY(){return y;}
        void setRaio(float r){raio=r;}
        void setX(float cx){x=cx;}
        void setY(float cy){y=cy;}
};