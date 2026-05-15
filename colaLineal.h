#ifndef COLA_LINEAL_H
#define COLA_LINEAL_H

#include "muestra.h"

typedef struct Nodo {
    Muestra muestra; //en lugar de un int dato, es un typedef muestra
    struct Nodo *sig;
} Nodo;

typedef struct {
    Nodo *h;
    Nodo *t;
} ColaLineal; //la cola linel es normal

void inicializar_cola(ColaLineal *cola);
void insertarColaLineal(ColaLineal *cola, Muestra m);
Muestra eliminarColaLineal(ColaLineal *cola);
int colaVaciaLineal(ColaLineal *cola);
void imprimirColaLineal(ColaLineal *cola);

#endif