#ifndef LISTA_DINAMICA_DOBLEMENTE_ENLAZADA
#define LISTA_DINAMICA_DOBLEMENTE_ENLAZADA

typedef int tDato;

// typedef struct tNodo{
//     tDato info;
//     struct tNodo* sig;
//     struct tNodo* ant;
// }tNodo;

// typedef struct tLista{
//     tNodo* actual;
//     tNodo* cab;
// }tLista;



// void lCrear(tLista* l){
//     l->cab = NULL;
//     l->actual = NULL;
// }

// int lVacia(tLista* l){
//     return l->cab == NULL;
// }

// void crearNodo(tNodo* nodo,tDato x){ //esta bien asi?
//     nodo=(tNodo*)malloc(sizeof(tNodo));
//     nodo->info=x;
//     nodo->sig = NULL;
//     nodo->ant = NULL;
// }

// int lLlena(tLista *l){       //LISTO
//     return 0;
// }

// void lPpio(tLista* l){           //LISTO
//     l->actual = l->cab;
//     printf("%i en lppio\n", (l->cab)->info);
// }

// int lFin(tLista *l){             //LISTO
//     return l->actual == NULL;
// }

// void lInfo(tLista *l, tDato *x){ //probar
//     *x = (l->actual)->info;
//     printf("%i en linfo\n", (l->cab)->info);
//     // printf("%i\n sdsdsd", *x);
// }

// void lModificar(tLista *l, tDato x){         //LISTO
//     tNodo* aux = l->actual;
//     aux->info = x;
// }

// void lSig(tLista *l){                //LISTO
//     tNodo* aux = l->actual;
//     l->actual = aux->sig;
// }
// void lInsertarPpio(tLista *l, tDato x){ // el problema deberia estar aca         //LISTO
//     tNodo *nuevoNodo;
//     crearNodo(nuevoNodo,x);
//     nuevoNodo->info = x; // si ponemos esto aca fuciona pero no entiendo por que
//     // if (l->cab != NULL){
//     //     l->cab->ant = nuevoNodo;
//     //     nuevoNodo->sig = l->cab;
//     // }
//     // l->cab = nuevoNodo;
//     if (l->cab == NULL){
//        l->cab = nuevoNodo;
//     }
//     else{
//         nuevoNodo->sig = l->cab;
//         (l->cab)->ant = nuevoNodo;
//         l->cab = nuevoNodo;
//     }
    
//     printf("%i en insertar\n", &(l->cab)->info);
// }



//=================================================================================================================
//=================================================================================================================
typedef struct nodo
{
	tDato info;
	struct nodo *sig;
	struct nodo *ant;
} nodoL;

nodoL* crearNodo(tDato x);
// Alias para lista

typedef nodoL* lista;

typedef struct lista{
	lista cab;
	lista actual;
} tLista;

int lLlena(tLista *l){
    return 0;
}

void lCrear(tLista* l){
    l->cab= NULL;
    l->actual = NULL;
}

int lVacia(tLista* l){
    return l->cab == NULL;
}

nodoL* crearNodo(tDato x){ //esta bien asi?
    nodoL* nodo= NULL;
    nodo = malloc(sizeof(nodoL));
    nodo->info=x;
    nodo->sig = NULL;
    nodo->ant = NULL;
    return nodo;
}

void lInsertarPpio (tLista *l, tDato n){
    lista aux = crearNodo(n);
	if(l->cab!=NULL){
		aux->sig = l->cab;
		aux->sig->ant = aux;
	}
	l->cab=aux;
}

void lPpio(tLista* l){
    l->actual = l->cab;
}

void lSig(tLista *l){
    l->actual = l->actual->sig;
}

void lInfo(tLista *l, tDato *x){ 
    *x = l->actual->info;
}

void lModificar(tLista *l, tDato x){
    l->actual->info = x;
}

int lFin(tLista *l){
    return l->actual == NULL;
}

void lBorrarPpio(tLista *l){
    lista aux;
    aux = l->cab;
    if (l->cab->sig == NULL){
        l->cab = NULL;
    }
    else{
        l->cab-> sig-> ant = NULL;
        l->cab = l->cab-> sig;
    }
    free(aux);
}

void lInsertarFin(tLista *l, tDato x){
    lista nuevoNodo, aux;
    nuevoNodo = crearNodo(x);
    if (l->cab == NULL){
        l->cab = nuevoNodo;
    }
    else{
        aux = l->cab;
        while (aux->sig != NULL){
            aux = aux->sig;
        }
        nuevoNodo->ant = aux;
        aux->sig = nuevoNodo;   
    }
}

void lBorrarActual(tLista *l){
    lista aux;
    aux = l->actual;
    if (l->cab == l->actual){
        if (l->cab->sig == NULL){
            l->cab = NULL;
        }
        else{
            l->cab->sig->ant = NULL;
            l->cab = l->cab->sig;
        }
    }
    else{
        if (l->actual->sig != NULL){
            l->actual->sig->ant = l->actual->ant;
        }
        l->actual->ant->sig = l->actual->sig;
    }
    l->actual = l->actual->sig;
    free(aux);
}

void lBorrarFin(tLista *l){
    lista aux;
    lista t;
    if (l->cab->sig == NULL){
        aux = l->cab;
        l->cab = NULL;
    }
    else{
        t = l->cab;
        while (t->sig != NULL){
            t = t->sig;
        }
        t->ant->sig = NULL;
    }
    free(aux);
}

void lInsertarOrdenado(tLista *l, tDato x, char orden){
    lista aux, nuevo;
    nuevo = crearNodo(x);
    if(l->cab == NULL){
        l->cab = nuevo;
    }
    else{
        if(x > l->cab->info && orden == 'D' || x < l->cab->info && orden == 'A'){
            nuevo->sig = l->cab;
            l->cab = nuevo;
            l->cab->ant = nuevo;
        }
        else{
            aux = l->cab;
            while(aux->sig != NULL && ((x < aux->sig->info && orden == 'A') || (x > aux->sig->info && orden == 'D'))){
                aux = aux->sig;
            }
            nuevo->sig = aux->sig;
            nuevo->ant = aux;
            if (aux->sig != NULL){
                aux->sig->ant = nuevo;
            }
            aux->sig = nuevo;
        }
    }
}

void lBuscarOrdenado(tLista *l, tDato x, int *existe){// ver que onda con la clave, FUNCIONAAAAA
    lista aux;
    *existe = 0;
    if(l->cab != NULL){
        if(l->cab->info == x){
            *existe = 1;
            l->actual = l->cab;
        }
        else{
            aux = l->cab;
            while (aux != NULL && l->cab->info == aux->info){
                aux = aux->sig;
            }
            if(aux != NULL){
                if(l->cab->info < aux->info){
                    while (aux !=NULL && aux->info < x){
                        aux = aux->sig;
                    }
                }
                else{
                    while (aux != NULL && aux->info > x){
                        aux = aux->sig;
                    }
                }
                if(aux != NULL && aux->info == x){
                    *existe = 1;
                    l->actual = aux;
                }
            }
        }
    }
}
// insertarOrdenado, buscarOrdenado
#endif