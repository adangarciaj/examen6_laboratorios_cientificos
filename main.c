#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "muestra.h"
#include "colaLineal.h"
#include "colaCircular.h"
#include "pilaDinamica.h" 

const char *nombres[] = {"Muestra Quimica", "Muestra Biologica", "Muestra Organica",
                          "Muestra Toxica", "Muestra Acuosa"};
const char *deptos[] = {"Quimica", "Biologia", "Fisica", "Farmacia", "Ingenieria"};


void imprimirEstado(ColaLineal *entrada, ColaCircular *analizadas, PilaDinamica *entrega) {
    imprimirColaLineal(entrada);
    imprimirColaCircular(analizadas);
    imprimirPila(entrega);
    printf("\n----------------------------------\n");
}

Muestra generarMuestra(int clave) {
    Muestra m;
    m.clave = clave;
    strcpy(m.nombre, nombres[rand() % 5]);
    strcpy(m.departamento, deptos[rand() % 5]);
    return m;
}

int contarColaLineal(ColaLineal *cola) {
    int count = 0;
    Nodo *actual = cola->h;
    while (actual != NULL) {
        count++;
        actual = actual->sig;
    }
    return count;
}

int contarColaCircular(ColaCircular *cola) {
    if (colaCircularVacia(cola)) return 0;
    int count = 1;
    NodoCir *actual = cola->h;
    while (actual->sig != cola->h) {
        count++;
        actual = actual->sig;
    }
    return count;
}

int main() {
    srand(time(NULL));

    ColaLineal entrada;
    ColaCircular analizadas;
    PilaDinamica entrega; 

    inicializarColaLineal(&entrada);
    inicializarColaCircular(&analizadas);
    inicializarPila(&entrega);

    int claveActual = 100;

    while (1) {
        printf("\n==========================================\n");
        printf("       LABORATORIO CIENTIFICO UNAM        \n");
        printf("==========================================\n");

        
        printf("\n--- FASE 1: Recepcion de muestras ---\n");
        int aleatorio = rand() % 101;
        if (aleatorio <= 50) {
            Muestra nueva = generarMuestra(claveActual++);
            printf("  Llego muestra: Clave %d | %s | Depto: %s\n",
                   nueva.clave, nueva.nombre, nueva.departamento);
            insertarColaLineal(&entrada, nueva);
        } else {
            printf("  No llego ninguna muestra.\n");
        }
        imprimirEstado(&entrada, &analizadas, &entrega);

        
        printf("\n--- FASE 2: Procesado y analisis ---\n");
        int totalEntrada = contarColaLineal(&entrada);
        if (totalEntrada == 0) {
            printf("  No hay muestras para analizar.\n");
        } else {
            int aAnalizar = rand() % (totalEntrada + 1);
            printf("  Muestras a analizar: %d\n", aAnalizar);
            for (int i = 0; i < aAnalizar; i++) {
                if (!colaVaciaLineal(&entrada)) {
                    Muestra m = eliminarColaLineal(&entrada);
                    printf("  Procesando muestra %d ...\n", m.clave);
                    insertarColaCircular(&analizadas, m);
                    imprimirEstado(&entrada, &analizadas, &entrega);
                }
            }
        }

        
        printf("\n--- FASE 3: Reporte y entrega ---\n");
        int totalAnalizadas = contarColaCircular(&analizadas);
        if (totalAnalizadas == 0) {
            printf("  No hay muestras analizadas para entregar.\n");
        } else {
            int aEntregar = rand() % (totalAnalizadas + 1);
            printf("  Muestras a entregar: %d\n", aEntregar);
            for (int i = 0; i < aEntregar; i++) {
                if (!colaCircularVacia(&analizadas)) {
                    Muestra m = eliminarColaCircular(&analizadas);
                    push(&entrega, m);
                }
            }
            
            
            int totalPila = entrega.cantidad; 
            
            if (totalPila > 0) {
                int aRepartir = rand() % (totalPila + 1);
                printf("  Repartidores entregando %d muestras:\n", aRepartir);
                for (int i = 0; i < aRepartir; i++) {
                    if (!pilaVacia(&entrega)) {
                        Muestra m = pop(&entrega);
                        printf("  La muestra %d se entrego al departamento %s\n",
                               m.clave, m.departamento);
                    }
                }
            }
        }
        imprimirEstado(&entrada, &analizadas, &entrega);

        printf("\nPresiona ENTER para continuar...\n");
        getchar();
    }

    return 0;
}