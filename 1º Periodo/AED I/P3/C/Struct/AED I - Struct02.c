#include <stdio.h>
#include <stdbool.h>
#define PI 3.14f
typedef struct {
    float raio,x,y;
}Circulo;
Circulo criarCirculo(float raio, float x, float y){
    Circulo c;
    c.raio = raio;
    c.x=x;
    c.y=y;
    return c;
}
float area(Circulo c){
    return PI * c.raio * c.raio;
}
float perimetro(Circulo c){
    return 2*PI*c.raio;
}
void mover(Circulo* c, float dx, float dy){
    c->y+=dy;
    c->x+=dx;
}
bool contemPonto(Circulo c, float px, float py){
    float ref= ((px-c.x)*(px-c.x)) + ((py-c.y)*(py-c.y));
    if(ref<=c.raio*c.raio) return true;
    else return false;
};