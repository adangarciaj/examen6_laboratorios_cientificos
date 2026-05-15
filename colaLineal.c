#include <stdio.h>
#include <stdlib.h>
#include "colaLineal.h"

void inicializarColaLineal(ColaLineal *cola) {
    cola->h = NULL;
    cola->t = NULL;
}

void insertarColaLineal(ColaLineal *cola, Muestra m) { //devuekve una muestra no un dato
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    nuevo->muestra = m; //es lo mismo que int->dato = dato
    nuevo->sig = NULL;

    if (cola->t == NULL) {
        cola->h = nuevo;
        cola->t = nuevo;
    } else {
        cola->t->sig = nuevo;
        cola->t = nuevo;
    }
}

Muestra eliminarColaLineal(ColaLineal *cola) {
    Nodo *q = cola->h;
    Muestra m = q->muestra;
    cola->h = cola->h->sig;
    if (cola->h == NULL)
        cola->t = NULL;
    free(q);
    return m;
}

int colaVaciaLineal(ColaLineal *cola) {
    return cola->h == NULL;
}

void imprimirColaLineal(ColaLineal *cola) {
    printf("\n---- Muestras de entrada ----\n");
    if (colaVaciaLineal(cola)) {
        printf("  Cola vacia\n");
        return;
    }
    Nodo *a = cola->h;
    while (a!= NULL) {
        printf("  Clave: %d | Nombre: %s | Depto: %s\n",
               a->muestra.clave,
               a->muestra.nombre,
               a->muestra.departamento);
        a = a->sig;
    }
}