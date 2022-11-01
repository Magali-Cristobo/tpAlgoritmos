#include <stdio.h>
#include <stdlib.h>
#include "pilaEstatica.h"
#include "lDDobleEnlazada.h"
#include "colaEstatica.h"

void moverYOrdenar(tPila *p, int *error, tCola *c); 
void revisarFinDatos(int *seguir);
void obtenerEntero(int *n);
void pasarACola(tLista *l, tCola *c, int *error);
void mostrarCola(tCola *c);

int main(){ 
    tPila p;
    tCola c;
    int error, seguir;
    tDato n;
    error = 0; 
    pCrear(&p);
    cCrear(&c);
    revisarFinDatos(&seguir);
    while (seguir && !pLlena(&p)){
        obtenerEntero(&n);
        pPoner(&p, n);
        revisarFinDatos(&seguir);
    }
    if (seguir){
        error = 1;
    }
    moverYOrdenar(&p,&error,&c);
    mostrarCola(&c);
    return 0;
}

void moverYOrdenar(tPila* p, int *error, tCola *c){ 
    tDato n;
    tLista lAux;
    tPila* pAux; 
    int existe;
    *error = 0;
    pAux = p;
    lCrear(&lAux);
    while (!pVacia(p) && !lLlena(&lAux)){
        pSacar(p, &n);
        lInsertarOrdenado(&lAux, n, 'A');
    }
    if (!pVacia(p)){
        *error = 1;
    }
    else{
        pasarACola(&lAux, c, error); 
        pAux = p;
    }
    }

void pasarACola(tLista *l, tCola *c, int *error){
    tDato n;
    lPpio(l);
    if (!lFin(l) && !cLlena(c)){
        lInfo(l, &n);
        cPoner(c, n);
        lSig(l);
    }
    else{
        if (lFin(l)){
            *error = 1;
        }
    }
}

void revisarFinDatos(int *seguir){
    char opcion;
    do{
        printf("Desea ingresar datos? Ingrese S/N: \n");
        scanf (" %c",&opcion);
    } while (opcion != 'S' && opcion != 'N');
    if (opcion == 'S'){
        *seguir = 1;        
    }
    else{
        *seguir = 0;
    }
}

void obtenerEntero(tDato *n){
    do{
        (printf("Ingrese un entero\n"));
        scanf("%i", n);
    }
    while (*n < 0);
}
void mostrarCola(tCola *c){
    tDato n;
    while (!cVacia(c)){
        cSacar(c, &n);
        printf("%i", n);
    }
    
}
 // no borrar porlas    
    //lCrear(&l);
    //lInsertarPpio(&l, 5);
    // lInsertarFin(&l, 6);
    // lBorrarPpio(&l);
    //lInsertarOrdenado(&l, n, 'D');
    //lPpio(&l);
    // lBuscarOrdenado(&l, numero, &existe);
    //lSig(&l);
    // lBorrarActual(&l);
    // lBorrarFin(&l);
    // lBorrarFin(&l);
    // lPpio(&l);
    //lInfo(&l,&numero);
    //printf("%i",numero);
    // cCrear(c);
    // cPoner(c, 4);
    // cPoner(c, 5);
    // cSacar(c, &numero);
    // pCrear(p);
    // pPoner(p, 4);
    // pPoner(p, 4);
    // pSacar(p, &numero);
    // printf("%i", pLlena(p));
