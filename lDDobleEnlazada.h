#ifndef LISTA_DINAMICA_DOBLEMENTE_ENLAZADA
#define LISTA_DINAMICA_DOBLEMENTE_ENLAZADA

typedef int tClave;

typedef struct tDatoLista{
    tClave clave;
} tDatoLista;
 
typedef struct nodo
{
	struct tDatoLista info;
	struct nodo *sig;
	struct nodo *ant;
} nodoL;

typedef nodoL* puntero;

typedef struct lista{
	puntero cab;
	puntero actual;
} tLista;

// ----------- Procedimientos y Funciones -------------- //

int lLlena(tLista *l){
    return 0;
}

void lCrear(tLista* l){
    l->cab= NULL;
}

int lVacia(tLista* l){
    return l->cab == NULL;
}

nodoL* crearNodo(tDatoLista x){ 
    nodoL* nodo= NULL;
    nodo = malloc(sizeof(nodoL));
    nodo->info = x;
    nodo->sig = NULL;
    nodo->ant = NULL;
    return nodo;
}

void lInsertarPpio (tLista *l, tDatoLista n){
    puntero nuevo = crearNodo(n);
	if(l->cab!=NULL){
		nuevo->sig = l->cab;
		nuevo->sig->ant = nuevo;
	}
	l->cab=nuevo;
}

void lPpio(tLista* l){
    l->actual = l->cab;
}

void lSig(tLista *l){
    l->actual = l->actual->sig;
}

void lInfo(tLista *l, tDatoLista *x){ 
    *x = l->actual->info;
}

void lModificar(tLista *l, tDatoLista x){
    l->actual->info = x;
}

int lFin(tLista *l){
    return l->actual == NULL;
}

void lBorrarPpio(tLista *l){
    puntero aux;
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

void lInsertarFin(tLista *l, tDatoLista x){
    puntero nuevoNodo, aux;
	
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
    puntero aux;
    aux = l->actual;
    if (l->cab == l->actual){
        if (l->cab->sig == NULL){
            l->cab = NULL;
	        l->actual = NULL;
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
    puntero aux, t;
    if (l->cab->sig == NULL){
        aux = l->cab;
        l->cab = NULL;
    }
    else{                    
        t = l->cab;	    
        while (t->sig != NULL){
            t = t->sig;
        }
	    aux = t;
        t->ant->sig = NULL;
    }
    free(aux);
}

void lInsertarOrdenado(tLista *l, tDatoLista x, char orden){
    puntero aux, nuevo;
	
    nuevo = crearNodo(x);
    if(l->cab == NULL){
        l->cab = nuevo;
    }
    else{
        if(x.clave > l->cab->info.clave && orden == 'D' || x.clave < l->cab->info.clave && orden == 'A'){
            nuevo->sig = l->cab;
            l->cab = nuevo;
            l->cab->ant = nuevo;
        }
        else{
            aux = l->cab;
            while(aux->sig != NULL && ((x.clave > aux->sig->info.clave && orden == 'A') || (x.clave < aux->sig->info.clave && orden == 'D'))){
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

void lBuscarOrdenado(tLista *l, tClave x, int *existe){ 
    puntero aux;					     				       
    *existe = 0;                                       
    if(l->cab != NULL){
        if(l->cab->info.clave == x){
            *existe = 1;
            l->actual = l->cab;
    	}
    	else {
        	aux = l->cab;
        	while (aux != NULL && l->cab->info.clave == aux->info.clave){
        	    aux = aux->sig;
        	}
        	if(aux != NULL){
        	    if(l->cab->info.clave < aux->info.clave){
        	        while (aux !=NULL && aux->info.clave < x){
        	             aux = aux->sig;
                	}
         	}
         	else {
             		while (aux != NULL && aux->info.clave > x){
                 		aux = aux->sig;
             		}
         	}
         	if(aux != NULL && aux->info.clave == x){
              		*existe = 1;
              		l->actual = aux;
         	}
   	     }
    	}
    }
}

#endif
