#ifndef INCLUIR_ARVORE_PATRICIA_H
#define INCLUIR_ARVORE_PATRICIA_H

#include "../ArvorePatricia.h"
#include "../Utils.h"


int encontrarPrimeiroBitDiferente(char *chave1, char *chave2) {
    int i = 0;
    while (obterBit(chave1, i) == obterBit(chave2, i)) {
        i++;
    }
    return i;
}

pNohPatricia adicionarChavePatriciaRecursivo(pNohPatricia raiz, char *chave) {
    if (raiz == NULL) {
        pNohPatricia novo = criarNohPatricia(1, -1);
        novo->chave = strdup(chave);
        return novo;
    }

    if (raiz->ehFolha) {
        if (strcmp(raiz->chave, chave) == 0) {
            return raiz; 
        }

        int bitIndex = encontrarPrimeiroBitDiferente(raiz->chave, chave);

        pNohPatricia novoInterno = criarNohPatricia(0, bitIndex);
        pNohPatricia novaFolha = criarNohPatricia(1, -1);
        novaFolha->chave = strdup(chave);

        if (obterBit(chave, bitIndex) == 0) {
            novoInterno->esquerda = novaFolha;
            novoInterno->direita = raiz;
        } else {
            novoInterno->direita = novaFolha;
            novoInterno->esquerda = raiz;
        }

        return novoInterno;
    }

    if (obterBit(chave, raiz->indice) == 0) {
        raiz->esquerda = adicionarChavePatriciaRecursivo(raiz->esquerda, chave);
    } else {
        raiz->direita = adicionarChavePatriciaRecursivo(raiz->direita, chave);
    }

    return raiz;
}

int adicionarChavePatricia(pDPatricia arvore, char *chave) {
    if (arvore == NULL || chave == NULL) {
        return 0;
    }

    arvore->raiz = adicionarChavePatriciaRecursivo(arvore->raiz, chave);
    arvore->quantidadeChaves++;
    return 1;
}

#endif