#ifndef MOSTRAR_GRAFO_COLORIDO_H
#define MOSTRAR_GRAFO_COLORIDO_H
#include "../Grafo.h"
#include <stdio.h>
#include "12_colorirGrafo.h"

void mostrarGrafoColorido(pDGrafo grafo) {
    if (!grafo || !grafo->listaVertices) return;

    printf("\nRepresentacao visual do grafo:\n");
    pNoh atual = grafo->listaVertices->primeiro;

    while (atual) {
        pVertice v = (pVertice) atual->info;
        printf("\033[1;%dm", 31 + v->cor % 6); // Usa a cor do vértice
        printf("Vertice %d - Adjacencias: [", *((int *)v->info));

        pNoh adj = v->listaAdjacencias->primeiro;
        while (adj) {
            pVertice vAdj = (pVertice) adj->info;
            printf("%d ", *((int *)vAdj->info));
            adj = adj->prox;
        }
        printf("]\033[0m\n"); // Reseta a cor
        atual = atual->prox;
    }
}

#endif