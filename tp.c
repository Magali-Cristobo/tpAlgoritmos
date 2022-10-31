#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pilaEstatica.h"
#include "lDDobleEnlazada.h"
#include "colaEstatica.h"

void moverYOrdenar(tPila *p, int *error, tCola *c); 

int main(){
    tPila p;
    tCola c;
    int error;
    moverYOrdenar(&p,&error,&c);
    return 0;
}
void moverYOrdenar(tPila *p, int *error, tCola *c){
    tDato numero;
    tLista l;
    lCrear(&l);
    lInsertarPpio(&l, 7);
    // lInsertarFin(&l, 6);
    // lBorrarPpio(&l);
    lPpio(&l);
    // lSig(&l);
    // lBorrarActual(&l);
    // lBorrarFin(&l);
    lBorrarFin(&l);
    // lPpio(&l);
    // lInfo(&l,&numero);
    printf("%i",lVacia(&l));
    // cCrear(c);
    // cPoner(c, 4);
    // cPoner(c, 5);
    // cSacar(c, &numero);
   

    // pCrear(p);
    // pPoner(p, 4);
    // pPoner(p, 4);
    // pSacar(p, &numero);
    // printf("%i", pLlena(p));
// cosas locas
}