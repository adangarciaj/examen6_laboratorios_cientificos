#include <stdio.h>
#include <stdlib.h>
#include "pilaDinamica.h"

void inicializarPila(PilaDinamica *pila) {
    pila->tope = NULL;
    pila->cantidad = 0;
}

void push(PilaDinamica *pila, Muestra m) {
    NodoPila *nuevoNodo = (NodoPila *)malloc(sizeof(NodoPila));
    if (nuevoNodo == NULL) {
        printf("  Error: Memoria insuficiente para apilar\n");
        return;
    }
    nuevoNodo->info = m;
    nuevoNodo->sig = pila->tope;
    pila->tope = nuevoNodo;
    pila->cantidad++;
}

Muestra pop(PilaDinamica *pila) {
    // Inicialización segura por defecto (clave 0 y cadenas vacías)
    Muestra m = {0, "", ""}; 
    
    if (pilaVacia(pila)) {
        return m; // Retorna la muestra vacía si no hay nada
    }
    
    NodoPila *nodoABorrar = pila->tope;
    m = nodoABorrar->info; // Respaldamos la info
    pila->tope = nodoABorrar->sig; // Movemos el tope al siguiente
    
    free(nodoABorrar); // Liberamos la memoria del nodo
    pila->cantidad--;
    
    return m;
}

int pilaVacia(PilaDinamica *pila) {
    return pila->tope == NULL;
}

void imprimirPila(PilaDinamica *pila) {
    printf("\n---- Muestras por entregar ----\n");
    if (pilaVacia(pila)) {
        printf("Pila vacia\n");
        return;
    }
    
    // Recorremos la pila dinámica para imprimir
    NodoPila *actual = pila->tope;
    while (actual != NULL) {
        printf("  Clave: %d | Nombre: %s | Depto: %s\n",
               actual->info.clave,
               actual->info.nombre,
               actual->info.departamento);
        actual = actual->sig;
    }
}