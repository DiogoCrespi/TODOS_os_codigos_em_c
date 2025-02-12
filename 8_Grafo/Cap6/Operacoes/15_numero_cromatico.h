#ifndef COLORIR_GRAFO_H
#define COLORIR_GRAFO_H

#include "0_structs.h"
#include "../Grafo.h"
#include "13_mostrarGrafoColorido.h"
#include <stdbool.h>

void colorirGrafo(pDGrafo grafo, int (*compara)(void *, void *)) {
    if (!grafo || !grafo->listaVertices) {
        fprintf(stderr, "Erro: Grafo não inicializado.\n");
        return;
    }

    pNoh atual = grafo->listaVertices->primeiro;
    int numVertices = grafo->listaVertices->quantidade;

    int cores[] = {31, 32, 33, 34, 35, 36};
    int numCores = sizeof(cores) / sizeof(cores[0]);

    while (atual) {
        pVertice v = (pVertice)atual->info;
        if (!v || !v->info) {
            fprintf(stderr, "Erro: Vértice inválido encontrado.\n");
            atual = atual->prox;
            continue;
        }

        printf("Processando Vértice: %d\n", *((int *)v->info));

        bool corDisponivel[numCores];
        for (int i = 0; i < numCores; i++) {
            corDisponivel[i] = true;
        }

        pNoh adj = v->listaAdjacencias->primeiro;
        while (adj) {
            pVertice vAdj = (pVertice)adj->info;
            if (!vAdj || !vAdj->info) {
                adj = adj->prox;
                continue;
            }

            printf(" Verificando adjacente: %d\n", *((int *)vAdj->info));

            if (vAdj->cor != -1) {
                for (int i = 0; i < numCores; i++) {
                    if (cores[i] == vAdj->cor) {
                        corDisponivel[i] = false;
                        break;
                    }
                }
            }

            adj = adj->prox;
        }

        for (int i = 0; i < numCores; i++) {
            if (corDisponivel[i]) {
                v->cor = cores[i];
                printf(" Atribuindo cor %d ao vértice %d\n", cores[i], *((int *)v->info));
                break;
            }
        }

        atual = atual->prox;
    }

    printf("\nColoração do grafo concluída:\n");
    fflush(stdout);
    mostrarGrafoColorido(grafo);
}

#endif