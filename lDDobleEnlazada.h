#ifndef LISTA_DINAMICA_DOBLEMENTE_ENLAZADA
#define LISTA_DINAMICA_DOBLEMENTE_ENLAZADA
#define CMAX 3

typedef int tDato;

typedef struct tNodo{
    tDato info;
    struct tNodo* sig;
    struct tNodo* ant;
}tNodo;

typedef struct tLista{
    tNodo* actual;
    tNodo* cab;
}tLista;



void lCrear(tLista* l){
    l->cab = NULL;
}

int lVacia(tLista* l){
    return l->cab == NULL;
}

void crearNodo(tNodo* nodo,tDato x){ //esta bien asi?
    nodo=(tNodo*)malloc(sizeof(tNodo));
    nodo->info=x;
    nodo->sig = NULL;
    nodo->ant = NULL;
}

int lLlena(tLista *l){
    return 0;
}

void lPpio(tLista *l){
    l->actual = l->cab;
}

int lFin(tLista *l){
    return l->actual == NULL;
}

void lInfo(tLista *l, tDato *x){ //probar
    // tNodo* aux = l->actual;
    *x = l->actual->info;
    // x = l->actual->info;
}

void lModificar(tLista *l, tDato x){
    tNodo* aux = l->actual;
    aux->info = x;
}

void lSig(tLista *l){
    tNodo* aux = l->actual;
    l->actual = aux->sig;
}
void lInsertarPpio(tLista *l, tDato x){ // el problema deberia estar aca
    tNodo *nuevoNodo;
    crearNodo(nuevoNodo,x);
    printf("%i\n", nuevoNodo->info); //este print da cualquier cosa
    tNodo* aux = l->cab;
    if (l->cab != NULL){
        aux->ant = nuevoNodo;
        nuevoNodo->sig = l->cab;
    }
    l->cab = nuevoNodo;
}

#endif
