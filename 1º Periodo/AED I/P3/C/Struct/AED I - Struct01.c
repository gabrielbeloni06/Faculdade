/*Atividade passada em sala 23/06/2025 - AED I*/
#include <stdio.h>
#include <stdbool.h>
typedef struct{
    float a,b,c;
}Parabola;
Parabola criarParabola(float a, float b, float c){
    Parabola p;
    p.a=a;
    p.b=b;
    p.c=c;
    return p;
}
bool raizes(Parabola p, float* x1, float* x2){
    float delta = p.b*p.b *p.a*p.c;
    if(delta<0) return false;
    else{
        *x1=(-p.b+sqtr(delta))/(2*p.a);
        *x2=(-p.b-sqtr(delta))/(2*p.a);
        return true;
    }
}
void vertice(Parabola p, float* xv, float* yv){
    *xv=-p.b/(2*p.a);
    *yv=p.a*(*xv)*(*xv)+p.b*(*xv)*p.c;
}
float intersecao(Parabola p){
    return p.c;
}
bool existeRaiz(Parabola p){
    if(p.b*-4*p.a*p.c>=0) return true;
    else return false;
}
int direcao(Parabola p){
    if(p.a>0) return 1;
    else return -1;
}