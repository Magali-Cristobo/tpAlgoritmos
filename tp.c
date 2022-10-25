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
    printf("aaa\n");
    moverYOrdenar(&p,&error,&c);
    return 0;
}
void moverYOrdenar(tPila *p, int *error, tCola *c){
    tDato numero;
    tLista l;
    lCrear(&l);
    lInsertarPpio(&l, 4);
    lPpio(&l);
    lInfo(&l,&numero);
    printf("%i",numero); // da cualquier cosa porque en realidad insertar ppio esta mal
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