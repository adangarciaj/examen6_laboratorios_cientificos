#ifndef PILA_DINAMICA_H
#define PILA_DINAMICA_H

#include "muestra.h"

// Definición del Nodo para la pila dinámica
typedef struct NodoPila {
    Muestra info;
    struct NodoPila *sig;
} NodoPila;

// Estructura de la Pila Dinámica
typedef struct {
    NodoPila *tope;
    int cantidad; // Nos ayudará a saber cuántos elementos hay
} PilaDinamica;

// Prototipos
void inicializarPila(PilaDinamica *pila);
void push(PilaDinamica *pila, Muestra m);
Muestra pop(PilaDinamica *pila);
int pilaVacia(PilaDinamica *pila);
void imprimirPila(PilaDinamica *pila);

#endif