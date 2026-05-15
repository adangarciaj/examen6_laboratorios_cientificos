#ifndef PILA_ESTATICA_H
#define PILA_ESTATICA_H

#include "muestra.h"

#define MAX_PILA 100

typedef struct {
    Muestra muestras[MAX_PILA]; //define el maximo de nombre en la pila
    int tope;
} PilaEstatica;

void inicializarPila(PilaEstatica *pila);
void push(PilaEstatica *pila, Muestra m);
Muestra pop(PilaEstatica *pila);
int pilaVacia(PilaEstatica *pila);
int pilaLlena(PilaEstatica *pila);
void imprimirPila(PilaEstatica *pila);

#endif