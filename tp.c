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
        error = 1; // significa que se lleno la pila y se querian insertar mas datos
    }
    moverYOrdenar(&p,&error,&c);
    mostrarCola(&c); // esto es para verificar
    return 0;
}

void moverYOrdenar(tPila* p, int *error, tCola *c){ 
    tDato n;
    tDatoLista elemento;
    tLista lAux;
    tPila* pAux; 
    int existe;
    *error = 0;
    pAux = p;
    lCrear(&lAux);
    while (!pVacia(p) && !lLlena(&lAux)){ //sacamos los elementos de la pila y los ponemos de forma ordenada en una lista
        pSacar(p, &n);
        elemento.clave = n;
        lBuscarOrdenado(&lAux, elemento.clave, &existe);
        if (!existe){
            lInsertarOrdenado(&lAux, elemento, 'A');
        }
    }
    if (!pVacia(p)){ // quedaron elementos por sacar y se lleno la lista
        *error = 1;
    }
    else{
        pasarACola(&lAux, c, error); 
        pAux = p;
    }
}

void pasarACola(tLista *l, tCola *c, int *error){
    tDatoLista n;
    tDato datoPila;
    lPpio(l);
    if (!lFin(l) && !cLlena(c)){ //recorremos la lista ordenada asc y la agregamos a la cola
        lInfo(l, &n);
        datoPila = n.clave;
        cPoner(c, datoPila);
        lSig(l);
        while(!lFin(l) && !cLlena(c)){
            lInfo(l, &n);
            datoPila = n.clave;
            cPoner(c, datoPila);
            lSig(l);
        }
    }
    if (!lFin(l)){
        *error = 1;
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
    printf("elementos de la cola: ");
    while (!cVacia(c)){
        cSacar(c, &n);
        printf("%i ", n);
    }
    printf("\n");
}
