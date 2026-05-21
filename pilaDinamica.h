#ifndef PILA_DINAMICA_H
#define PILA_DINAMICA_H

#include "muestra.h"


typedef struct NodoPila {
    Muestra info;
    struct NodoPila *sig;
} NodoPila;


typedef struct {
    NodoPila *tope;
    int cantidad; 
} PilaDinamica;


void inicializarPila(PilaDinamica *pila);
void push(PilaDinamica *pila, Muestra m);
Muestra pop(PilaDinamica *pila);
int pilaVacia(PilaDinamica *pila);
void imprimirPila(PilaDinamica *pila);

#endif