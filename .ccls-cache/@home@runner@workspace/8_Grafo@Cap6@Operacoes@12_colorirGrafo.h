#ifndef COLORIR_GRAFO_H
#define COLORIR_GRAFO_H

#include "0_structs.h"
#include "../Grafo.h"
//void imprimeVertice(void *info1);

/* --------------------------- */
void colorirGrafo(pDGrafo grafo, int (*compara)(void *, void *)) {
    if (!grafo || !grafo->listaVertices) return;

    pNoh atual = grafo->listaVertices->primeiro;
    int numVertices = grafo->listaVertices->quantidade;
    int cores[numVertices];

    for (int i = 0; i < numVertices; i++) {
        cores[i] = -1;
    }

    int corDisponivel[numVertices];

    while (atual) {
        pVertice v = (pVertice) atual->info;

        for (int i = 0; i < numVertices; i++) {
            corDisponivel[i] = 1;
        }

        pNoh adj = v->listaAdjacencias->primeiro;
        while (adj) {
            pVertice vAdj = (pVertice) adj->info;
            for (int i = 0; i < numVertices; i++) {
                if (compara(vAdj->info, grafo->listaVertices->primeiro->info + i) == 0 && cores[i] != -1) {
                    corDisponivel[cores[i]] = 0;
                }
            }
            adj = adj->prox;
        }

        for (int i = 0; i < numVertices; i++) {
            if (corDisponivel[i]) {
                cores[i] = i;
                v->grau = i;
                break;
            }
        }

        atual = atual->prox;
    }

    printf("\nColoracao do grafo:\n");
    mostrarGrafoColorido(grafo);
}

#endif
