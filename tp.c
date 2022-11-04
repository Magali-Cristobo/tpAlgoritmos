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
    // mostrarPila(&p);
    if (seguir){
        error = 1; // significa que se lleno la pila y se querian insertar mas datos
    }
    moverYOrdenar(&p,&error,&c);
    mostrarCola(&c); // esto es para verificar
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
    // Abajo no valida que no se repitan los numeros. Habría que hacer un lBuscarOrdenado del dato, si no está entonces lo agregamos, si está, no se hace nada, porque 
    // ya existe y no queremos repetidos. Hay que ver que onda con el tClave, digo que hagamos otro tipo de dato, por ejemplo:
    /*
    typedef int tClave;
    tDatoClave = regsitro
        clave: tClave
    FinReg
    
    tDatoClave datoClave;
    datoClave.clave = n;
    lBuscarOrdenado(&lAux, datoClave.clave, &existe);
    if (existe){
        if (!lLlena(&lAux)){
            lInsertarOrdenado(&lAux, datoClave, 'A');
        }
    }
    */
    while (!pVacia(p) && !lLlena(&lAux)){ //sacamos los elementos de la pila y los ponemos de forma ordenada en una lista
        pSacar(p, &n);
        lBuscarOrdenado(&lAux, n, &existe);
        if (!existe){
            lInsertarOrdenado(&lAux, n, 'A');
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
    tDato n;
    lPpio(l);
    if (!lFin(l) && !cLlena(c)){ //recorremos la lista ordenada asc y la agregamos a la cola
        lInfo(l, &n);
        cPoner(c, n);
        lSig(l);
        while(!lFin(l) && !cLlena(c)){
            lInfo(l, &n);
            cPoner(c, n);
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
        printf("%i", n);
    }
    printf("\n");
}
