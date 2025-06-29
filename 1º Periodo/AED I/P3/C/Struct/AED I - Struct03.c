/*Atividade passada em sala 25/06*/
#include <stdio.h>
#include <stdlib.h>
typedef enum{
    MAT_INT, MAT_FLT
}TipoMat;
typedef union{
    int i; float f;
}NumMat;
typedef struct{
    int nLin, nCol;
    NumMat **m; TipoMat t;
}Mat;
Mat* criarMat(int nl,int nc, int t){
    if(nl<=0||nc<=0||t<0||t>1) return NULL;
    Mat* nova = malloc (sizeof(Mat));
    nova->t=(t==0)? MAT_INT:MAT_FLT;
    nova->nLin=nl; nova->nCol =nc;
    nova->m=malloc (nl*sizeof(NumMat*));
    for(int i=0;i<nl;i++){
        nova->m[i]=malloc(nc*sizeof(NumMat));
        for(int j=0;j<nc;j++){
            if(nova->t==MAT_INT) nova->m[i][j].i=0;
            else nova->m[i][j].f=0.0;
        }
    }
    return nova;
}
void freeMat(Mat **mat){
    if(mat!=NULL && (*mat)!=NULL){
        for(int i=0;i<(*mat)->m[i];i++){
            free ((*mat)->m[i]);
        }
        free((*mat)->m); free((*mat)); (*mat)=NULL;
    }
}
Mat* lerMatUsuario(){
    int nl, nc, t;
    scanf("%d %d %d", &nl, &nc, &t);
    Mat *mat= criarMat(nl,nc,t);
    if(mat==NULL)return mat;
    for(int i=0;i<nl;i++){
        for(int j=0;j<nc;j++){
            if(mat->t==MAT_INT) scanf("%d",&(mat->m[i][j].i));
            else scanf("%f", &(mat->m[i][j].f));
        }
    }
    return mat;
}
void imprimir(Mat *mat){
    if(mat==NULL){
        printf("NULL");
    }
    else{
        for(int i=0;i<mat->nLin;i++){
            for(int j=0;mat->nCol;j++){
                if(mat->t==MAT_INT) printf("%d ", mat->m[i][j].i);
                else printf("%f ", mat->m[i][j].f);
            }
            printf("\n");
        }
    }
}
void escreverArquivo(Mat *mat, char *arq){
    if(mat==NULL || arq==NULL) return NULL;
    FILE *f = fopen(arq, "w");
    if(f==NULL) return NULL;
    fprintf(f, "%d %d %d\n", mat->nLin, mat->nCol, mat->t);
    for(int i=0;i<mat->nLin;i++){
        for(int j=0;j<mat->nCol;j++){
            if(mat->t==MAT_INT) fprintf(f, "%d ", mat->m[i][j].i);
            else fprint(f, "%f ",mat->m[i][j].f);
        }
        fprintf(f,"\n");
    }
    fclose(f);
}
Mat* somaMat(Mat *mat1, Mat *mat2){
    if(mat1==NULL || mat2==NULL) return NULL;
    if(mat1->nLin != mat2->nLin || mat1->nCol != mat2->nCol) return NULL; 
    if(mat1->t != mat2->t) return NULL;
    Mat* res=criarMat(mat1->nLin, mat1->nCol, mat1->t);
    for(int i=0;i<mat1->nLin;i++){
        for(int j=0;j<mat1->nCol;j++){
            if(mat1->t == MAT_INT) res->m[i][j].i=mat1->m[i][j].i + mat2->m[i][j].i;
            else res->m[i][j].f = mat1->m[i][j].f + mat2->m[i][j].f;
        }
    }
    return res;
}
Mat* subMat(Mat *mat1, Mat *mat2){
    if(mat1==NULL || mat2==NULL) return NULL;
    if(mat1->nLin != mat2->nLin || mat1->nCol != mat2->nCol) return NULL;
    if(mat1->t != mat2->t) return NULL;
    Mat* res=criarMat(mat1->nLin, mat1->nCol, mat1->t);
    for(int i=0;i<mat1->nLin;i++){
        for(int j=0;j<mat1->nCol;j++){
            if(mat1->t==MAT_INT) res->m[i][j].i= mat1->m[i][j].i - mat2->m[i][j].i;
            else res->m[i][j].f = mat1->m[i][j].f - mat2->m[i][j].f;
        }
    }
    return res;
}
Mat* multMat(Mat *mat1, Mat *mat2){
    if(mat1 == NULL || mat2==NULL) return NULL;
    if(mat1->nCol != mat2 ->nLin) return NULL;
    if(mat1->nLin != mat2->t) return NULL;
    Mat* res=criarMat(mat1->nLin,mat2->nCol,mat1->t);
    for(int i=0;i<res->nLin;i++){
        for(int j=0;j<res->nCol;j++){
            if(mat1->t == MAT_INT){
                int soma=0;
                for(int k=0;k<mat1->nCol;k++){
                    soma +=mat1->m[i][k].i * mat2->m[k][j].i;
                }
                res->m[i][j].i = soma;
            }
            else{
                float soma=0.0;
                for(int k=0;k<mat1->nCol;k++){
                    soma += mat1->m[i][k].f * mat2->m[k][j].f;
                }
                res->m[i][j].f = soma;
            }

        }
    }
    return res;
}
Mat* espelharXmat(Mat *mat){
    if(mat == NULL) return NULL;
    Mat* res=criarMat(mat->nLin, mat->nCol, mat->t);
    for(int i=0;i<mat->nLin;i++){
        for(int j=0;j<mat->nCol;j++){
            if(mat->t==MAT_INT) res->m[i][j].i=mat->m[mat->nLin-1-i][j].i;
            else res->m[i][j].f = mat->m[mat->nLin-1-i][j].f;
        }
    }
    return res;
}
Mat* espelharYmat(Mat *mat){
    if(mat==NULL) return NULL;
    Mat* res=criarMat(mat->nLin, mat-> nCol, mat->t);
    for(int i=0; i<mat->nLin;i++){
        for(int j=0;j<mat->nCol;i++){
            if(mat->t==MAT_INT) res->m[i][j].i=mat->m[i][mat->nCol-1-j].i;
            else res->m[i][j].f=mat->m[i][mat->nCol - 1- i].f;
        }
    }
    return res;
}
Mat* espelharDiagMat(Mat *mat){
    if(mat==NULL) return NULL;
    Mat* res=criarMat(mat->nLin,mat->nCol,mat->t);
    for(int i=0;i<mat->nLin;i++){
        for(int j=0;j<mat->nCol;j++){
            if(mat->t==MAT_INT) res->m[j][i].i=mat->m[i][j].i;
            else res->m[j][i].f=mat->m[i][j].f;
            }
        }
    return res;
}
Mat* somaEscalar(Mat *mat, NumMat escalar){
    if(mat==NULL) return NULL;
    Mat* res=copiar(mat);
    for(int i=0;i<mat->nLin;i++){
        for(int j=0;j<mat->nCol;j++){
            if(res->t==MAT_INT) res->m[i][j].i+=escalar.i;
            else res->m[i][j].f+=escalar.f;
        }
    }
    return res;
}
Mat* subEscalar(Mat *mat, NumMat escalar){
    if(mat==NULL) return NULL;
    Mat* res=copiarMat(mat);
    for(int i=0;i<mat->nCol;i++){
        for(int j=0;j<mat->nCol;j++){
            if(res->t==MAT_INT) res->m[i][j].i-=escalar.i;
        }
    }
    return res;
}
Mat* multEscalar(Mat *mat, NumMat escalar){
    if(mat==NULL) return NULL;
    Mat* res = copiarMat(mat);
    for(int i=0;i<mat->nLin;i++){
        for(int j=0;j<mat->nCol;j++){
            if(res->t==MAT_INT) res->m[i][j].i *= escalar.i;
            else res->m[i][j].f *= escalar.f;
        }
    }
    return res;
}
Mat* divEscalar(Mat *mat, NumMat escalar){
    if(mat==NULL) return NULL;
    Mat* res = copiarMat(mat);
    for(int i=0;i<mat->nLin;i++){
        for(int j=0;j<mat->nCol;j++){
            if(res->t==MAT_INT) res->m[i][j].i /= escalar.i;
            else res->m[i][j].f /= escalar.f;
        }
    }
    return res;
}
Mat* copiarMat(Mat *mat){
    if(mat==NULL) return NULL;
    Mat *nova=criarMat(mat->nLin, mat->nCol,mat->t);
    for(int i=0;i<mat->nLin;i++){
        for(int j=0;j<mat->nCol;j++){
            nova->m[i][j]=mat->m[i][j];
        }
    }
}

NumMat* linearizar(Mat *mat, int *v){
    if(mat==NULL) return NULL;
    int total=mat->nLin*mat->nCol;
    NumMat* linear=malloc(total*sizeof(NumMat));
    int count=0;
    for(int i=0;i<mat->nLin;i++){
        for(int j=0;j<mat->nCol;j++){
            if(mat->t==MAT_INT) linear[count].i=mat->m[i][j].i;
            else linear[count].f=mat->m[i][j].f;
            count++;
        }
    }
    return linear;
}
Mat* reshape(Mat *mat, int nL, int nC){
    if(mat==NULL) return NULL;
    if(nL<=0 || nC<=0) return NULL;
    if((mat->nLin*mat->nCol)!=(nL*nC)) return NULL;
    Mat* nova=criarMat(nL,nC,mat->t);
    int total;
    NumMat* x= linearizar(mat, &total);
    int k=0;
    for(int i=0;i<nL;i++){
        for(int j=0;j<nC;j++){
            if(nova->t==MAT_INT) nova->m[i][j].i=x[k].i;
            else nova->m[i][j].f=x[k].f; 
            k++;
        }
    }
    free(x);
    return nova;
}
