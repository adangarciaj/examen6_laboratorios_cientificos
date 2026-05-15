#include <stdio.h>
#include <stdlib.h>
#include "colaCircular.h"

void inicializarColaCircular(ColaCircular *cola) {
    cola->h = NULL;
    cola->t = NULL;
}

void insertarColaCircular(ColaCircular *cola, Muestra m) {
    NodoCir *nuevo = (NodoCir *)malloc(sizeof(NodoCir));
    nuevo->muestra = m;

    if (cola->h == NULL) {
        cola->h = nuevo;
        cola->t = nuevo;
        nuevo->sig = cola->h;
    } else {
        nuevo->sig = cola->h;
        cola->t->sig = nuevo;
        cola->t = nuevo;
    }
}

Muestra eliminarColaCircular(ColaCircular *cola) {
    NodoCir *q = cola->h;
    Muestra m = q->muestra;

    if (cola->h == cola->t) {
        // Solo había un nodo
        cola->h = NULL;
        cola->t = NULL;
    } else {
        cola->h = cola->h->sig;
        cola->t->sig = cola->h;
    }

    free(q);
    return m;
}

int colaCircularVacia(ColaCircular *cola) {
    return cola->h == NULL;
}

void imprimirColaCircular(ColaCircular *cola) {
    printf("\n=== Muestras analizadas ===\n");
    if (colaCircularVacia(cola)) {
        printf("La cola está vacía.\n");
    } else {
        NodoCir *a = cola->h;
        do {
            imprimirMuestra(a->muestra);
            a = a->sig;
        } while (a!= cola->h);
    }
}