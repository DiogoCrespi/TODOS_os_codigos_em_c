
#ifndef COLORIR_GRAFO_H
#define COLORIR_GRAFO_H

#include "0_structs.h"
#include "../Grafo.h"
#include "13_mostrarGrafoColorido.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_CORES 10  // Número máximo de cores suportadas

// Estrutura de cores para exibição
const char *cores[MAX_CORES] = {"Azul", "Verde", "Vermelho", "Amarelo", "Laranja", "Roxo", "Ciano", "Rosa", "Marrom", "Cinza"};

/* ------------------------------------------ */
/* Função para encontrar a menor cor disponível */
int encontrarMenorCorDisponivel(int corUsada[], int numVertices) {
    for (int cor = 0; cor < numVertices; cor++) {
        if (corUsada[cor] == 0) {
            return cor; // Retorna a primeira cor disponível
        }
    }
    return -1; // Se não encontrar, retorna erro
}

/* ------------------------------------------ */
/* Função para colorir o grafo */
void colorirGrafo(pDGrafo grafo, FuncaoComparacao fc) {
    if (grafo == NULL || grafo->listaVertices == NULL || grafo->listaVertices->quantidade == 0) {
        printf("Grafo vazio! Não há como colorir.\n");
        return;
    }

    int numVertices = grafo->listaVertices->quantidade;
    int corVertices[numVertices];   // Armazena as cores atribuídas aos vértices
    int corUsada[numVertices];      // Armazena as cores já utilizadas por vértices adjacentes

    for (int i = 0; i < numVertices; i++) {
        corVertices[i] = -1;  // Inicializa sem cor
    }

    pNoh atual = grafo->listaVertices->primeiro;
    int index = 0;

    // Percorre todos os vértices do grafo
    while (atual != NULL) {
        pVertice v = (pVertice)atual->info;

        // Reseta a lista de cores usadas
        for (int i = 0; i < numVertices; i++) {
            corUsada[i] = 0;
        }

        // Marca as cores já usadas pelos vizinhos
        pNoh adjacente = v->listaAdjacencias->primeiro;
        while (adjacente != NULL) {
            pVertice vAdj = (pVertice)adjacente->info;
            int posAdj = buscarInfoPos(grafo->listaVertices, fc(vAdj, v));
            if (posAdj >= 0 && corVertices[posAdj] != -1) {
                corUsada[corVertices[posAdj]] = 1;
            }
            adjacente = adjacente->prox;
        }

        // Atribui a menor cor disponível ao vértice atual
        int cor = encontrarMenorCorDisponivel(corUsada, numVertices);
        corVertices[index] = cor;

        printf("Vértice %d -> Cor: %s\n", *((int *)v->info), cores[cor]);

        atual = atual->prox;
        index++;
    }
}

#endif // COLORIR_GRAFO_H
