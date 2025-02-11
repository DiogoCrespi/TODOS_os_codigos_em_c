

#ifndef BUSCAR_INFO_B_MAIS_TREE_H
#define BUSCAR_INFO_B_MAIS_TREE_H
#include "../BTree.h"
#include "../Utils.h"
#include "../../Cap3/Operacoes/2_incluirInfo.h"

//pNohBTree buscarInfoBTreeRecursivo


//void* buscarInfoBTreevoid*

// Função de busca na árvore B+
void* buscarChaveBTree(pNohBTree raiz, void* chave, FuncaoComparacao pfc) {
    pNohBTree atual = raiz;
    while (atual != NULL) {
        // Se for folha, buscar diretamente
        if (ehFolha(atual)) {
            pNoh pAtual = atual->listaChavesValores->primeiro;
            while (pAtual != NULL) {
                pChaveValor pcv = (pChaveValor) pAtual->info;
                if (pfc(pcv->chave, chave) == 0) {
                    return pcv->valor; // Encontrei o valor correspondente
                }
                pAtual = pAtual->prox;
            }
            return NULL; // Não encontrado
        }

        // Se não for folha, buscar o filho adequado baseado na chave
        pChaveValor anterior = chaveAnterior(atual->listaChavesValores, chave, pfc);
        if (anterior == NULL) {
            atual = atual->primeiroFilho;  // A chave deve estar no primeiro filho
        } else {
            atual = anterior->filhoMaior;  // Chave anterior encontrada, buscar no próximo filho
        }
    }
    return NULL; // Não encontrado
}




 #endif