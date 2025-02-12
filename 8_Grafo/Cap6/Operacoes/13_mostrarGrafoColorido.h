#ifndef MOSTRAR_GRAFO_COLORIDO_H
#define MOSTRAR_GRAFO_COLORIDO_H

#include "0_structs.h"
#include "12_colorirGrafo.h"
#include "14_buscarVertice.h"
#include <stdio.h>
#include <stdlib.h>

extern const char *cores[];

void mostrarGrafoColorido(pDGrafo grafo) {
    if (!grafo || !grafo->listaVertices) {
        printf("Erro: Grafo não inicializado.\n");
        return;
    }

    printf("\n=== Representação Visual do Grafo Colorido ===\n");

    pNoh atual = grafo->listaVertices->primeiro;
    while (atual) {
        pVertice v = (pVertice) atual->info;
        int corIndex = v->cor % 6;

        // Imprime o vértice colorido
        printf("\033[1;%dm", 31 + corIndex);
        printf("Vértice %d - Adjacências: [", *((int *)v->info));

        pNoh adj = v->listaAdjacencias->primeiro;
        while (adj) {
            pVertice vAdj = (pVertice) adj->info;
            printf("%d ", *((int *)vAdj->info));
            adj = adj->prox;
        }
        printf("]\033[0m - %s\n", cores[corIndex]);

        atual = atual->prox;
    }

    // Criação da matriz de adjacência para visualização
    int numVertices = grafo->listaVertices->quantidade;
    if (numVertices == 0) {
        printf("Grafo vazio.\n");
        return;
    }

    int **matriz = (int **)malloc(numVertices * sizeof(int *));
    for (int i = 0; i < numVertices; i++) {
        matriz[i] = (int *)malloc(numVertices * sizeof(int));
        for (int j = 0; j < numVertices; j++) {
            matriz[i][j] = 0;
        }
    }

    pNoh verticeAtual = grafo->listaVertices->primeiro;
    int indiceVertice = 0;
    while (verticeAtual) {
        pVertice v = (pVertice)verticeAtual->info;
        pNoh adjacenteAtual = v->listaAdjacencias->primeiro;
        while (adjacenteAtual) {
            pVertice vAdj = (pVertice)adjacenteAtual->info;
            int indiceAdjacente = 0;
            pNoh verticeBusca = grafo->listaVertices->primeiro;
            while (verticeBusca) {
                if (comparaVertice(vAdj, verticeBusca->info) == 0) {
                    matriz[indiceVertice][indiceAdjacente] = 1;
                    break;
                }
                verticeBusca = verticeBusca->prox;
                indiceAdjacente++;
            }
            adjacenteAtual = adjacenteAtual->prox;
        }
        verticeAtual = verticeAtual->prox;
        indiceVertice++;
    }

    // Exibir matriz de adjacência com cores
    printf("\nMatriz de Adjacência Colorida:\n  ");

    pNoh nohVerticeColuna = grafo->listaVertices->primeiro;
    for (int i = 0; i < numVertices; i++) {
        pVertice v = (pVertice)nohVerticeColuna->info;
        printf("\033[1;%dm", 31 + v->cor % 6);
        printf("%d ", *((int *)v->info));
        printf("\033[0m");
        nohVerticeColuna = nohVerticeColuna->prox;
    }
    printf("\n");

    pNoh nohVerticeLinha = grafo->listaVertices->primeiro;
    for (int i = 0; i < numVertices; i++) {
        pVertice v = (pVertice)nohVerticeLinha->info;
        printf("\033[1;%dm", 31 + v->cor % 6);
        printf("%d ", *((int *)v->info));
        printf("\033[0m");
        for (int j = 0; j < numVertices; j++) {
            printf(matriz[i][j] ? "* " : ". ");
        }
        printf("\n");
        nohVerticeLinha = nohVerticeLinha->prox;
    }

    for (int i = 0; i < numVertices; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

#endif // MOSTRAR_GRAFO_COLORIDO_H
