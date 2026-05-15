#include <stdio.h>
#include "pilaEstatica.h"

void inicializarPila(PilaEstatica *pila) {
    pila->tope = -1;
}

void push(PilaEstatica *pila, Muestra m) {
    if (pilaLlena(pila)) {
        printf("  Pila llena, no se puede apilar\n");
        return;
    }
    pila->tope++;
    pila->muestras[pila->tope] = m;
}

Muestra pop(PilaEstatica *pila) {
    Muestra m = pila->muestras[pila->tope];
    pila->tope--;
    return m;
}

int pilaVacia(PilaEstatica *pila) {
    return pila->tope == -1;
}

int pilaLlena(PilaEstatica *pila) {
    return pila->tope == MAX_PILA - 1;
}

void imprimirPila(PilaEstatica *pila) {
    printf("\n---- Muestras por entregar ----\n");
    if (pilaVacia(pila)) {
        printf("Pila vacia\n");
        return;
    }
    for (int i = pila->tope; i >= 0; i--) {
        printf("  Clave: %d | Nombre: %s | Depto: %s\n",
               pila->muestras[i].clave,
               pila->muestras[i].nombre,
               pila->muestras[i].departamento);
    }
}