#ifndef LISTA_DINAMICA_DOBLEMENTE_ENLAZADA
#define LISTA_DINAMICA_DOBLEMENTE_ENLAZADA

typedef int tDato;
typedef struct nodo
{
	tDato info;
	struct nodo *sig;
	struct nodo *ant;
} nodoL;

nodoL* crearNodo(tDato x);

typedef nodoL* lista;

typedef struct lista{
	lista cab;
	lista actual;
} tLista;

// ----------- Procedimientos y Funciones -------------- //

int lLlena(tLista *l){
    return 0;
}

void lCrear(tLista* l){
    l->cab= NULL;
    l->actual = NULL; // Según recuerdo, para el lCrear sólo hace falta asignar NULL a l->cab. Parece razonable ponerlo como está (así como los dos están asginados)
}                     // Habrá que preguntar..

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
    lista nuevo = crearNodo(n);
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
	    l->actual = NULL; // AGREGADO //
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
    else{                    // Cuando entras en el ELSE, hace lo que tiene que hacer. Luego sale y se dispone el aux, pero estarías borrando la cabecera no el ultimo.
        t = l->cab;	     // Se tiene que agregar que "aux = t" entre la linea 134 y 135, para luego pueda borrar el último cuando sale del ELSE.
        while (t->sig != NULL){
            t = t->sig;
        }
	aux = t;
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
            while(aux->sig != NULL && ((x > aux->sig->info && orden == 'A') || (x < aux->sig->info && orden == 'D'))){
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

void lBuscarOrdenado(tLista *l, tDato x, int *existe){ // "Ver que onda con la clave."
    lista aux;					       // "Podemos crear otro tipo de dato que sea tDatoLClave que tenga un campo clave de tipo tClave y tClave sea int.
    						       // Acá trabajamos con x de tipo tClave. Cuando vayamos a usar el procedimiento usamos lo que dije arriba, ya que 
    *existe = 0;                                       // es un registro que tiene un campo clave de tipo tClave."
    if(l->cab != NULL){
        if(l->cab->info == x){
            *existe = 1;
            l->actual = l->cab;
    	}
    	else {
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
         	else {
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

#endif
