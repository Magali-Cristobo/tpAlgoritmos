#ifndef PILA_ESTATICA_ENTEROS_H
#define PILA_ESTATICA_ENTEROS_H
#define CMAX 3

typedef int tDato;

typedef struct tPila{
    int cima;
    tDato elem[CMAX];
}tPila;

void pCrear(tPila* p){
    p->cima = -1;
}

int pVacia (tPila* p){
    return p->cima == -1;
}

int pLlena(tPila* p){
    return p->cima == CMAX - 1;
}

void pPoner(tPila* p, tDato dato){
    p->cima++;
    p->elem[p->cima]=dato;
}

void pSacar(tPila* p, tDato* dato){
    *dato = p->elem[p->cima];
    p->cima--;
}

#endif
