#ifndef COLA_CIRCULAR_H
#define COLA_CIRCULAR_H

#include "muestra.h"

typedef struct NodoCir {
    Muestra muestra;
    struct NodoCir *sig;
} NodoCir;

typedef struct {
    NodoCir *h;
    NodoCir *t;
} ColaCircular;

void inicializarColaCircular(ColaCircular *cola);
void insertarColaCircular(ColaCircular *cola, Muestra m);
Muestra eliminarColaCircular(ColaCircular *cola);
int colaCircularVacia(ColaCircular *cola);
void imprimirColaCircular(ColaCircular *cola);

#endif