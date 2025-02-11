#ifndef DESENHA_ARVORE_B_MAIS_TREE_H
#define DESENHA_ARVORE_B_MAIS_TREE_H

#include "../BTree.h"
#include "../Utils.h"
#include "../../Cap3/Operacoes/2_incluirInfo.h"

// Função recursiva para desenhar a árvore B+
void desenhaArvoreBMaisRecursivo(pNohBTree noh, int nivel, FuncaoImpressao impressao) {
    if (noh == NULL) return;

    // Imprimir recuo para representar o nível
    for (int i = 0; i < nivel; i++) printf("  ");

    // Imprimir as chaves do nó atual
    printf("[ ");
    for (int i = 1; i <= noh->listaChavesValores->quantidade; i++) {
        pChaveValor pcv = (pChaveValor)buscarInfoPos(noh->listaChavesValores, i);
        impressao(pcv->chave); // Chama a função para imprimir a chave

        // Adiciona separadores entre chaves
        if (i < noh->listaChavesValores->quantidade) printf(" - ");
    }
    printf(" ]\n");

    // Se não for folha, desenhar os filhos
    if (!ehFolha(noh)) {
        // Desenha o primeiro filho
        if (noh->primeiroFilho != NULL) 
            desenhaArvoreBMaisRecursivo(noh->primeiroFilho, nivel + 1, impressao);

        // Desenha os filhos maiores associados às chaves
        for (int i = 1; i <= noh->listaChavesValores->quantidade; i++) {
            pChaveValor pcv = (pChaveValor)buscarInfoPos(noh->listaChavesValores, i);
            if (pcv->filhoMaior != NULL) 
                desenhaArvoreBMaisRecursivo(pcv->filhoMaior, nivel + 1, impressao);
        }
    }

    // Exibir ligação entre folhas, se aplicável
    if (ehFolha(noh) && noh->proxFolha != NULL) {
        printf("Folha ligada a próxima: [ ");
        pNoh folhaAtual = noh->proxFolha->listaChavesValores->primeiro;
        while (folhaAtual != NULL) {
            pChaveValor pcv = (pChaveValor)folhaAtual->info;
            impressao(pcv->chave);
            if (folhaAtual->prox != NULL) printf(" - ");
            folhaAtual = folhaAtual->prox;
        }
        printf(" ]\n");
    }
}

// Função principal para desenhar a árvore B+
void desenhaArvore(pDBTree arvore, FuncaoImpressao fi) {
    printf("\n--- Representação da Árvore B+ ---\n");
    if (arvore->raiz != NULL) {
        desenhaArvoreBMaisRecursivo(arvore->raiz, 0, fi);
    } else {
        printf("Árvore vazia.\n");
    }
    printf("\n---------------------------------\n");
}

#endif
