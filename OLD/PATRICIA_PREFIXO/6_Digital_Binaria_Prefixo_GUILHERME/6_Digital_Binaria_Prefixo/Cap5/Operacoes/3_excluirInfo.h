#ifndef EXCLUIR_ARVORE_PATRICIA_H
#define EXCLUIR_ARVORE_PATRICIA_H
#include "../ArvorePrefixo.h"
#include "../Utils.h"
#include <stdlib.h>
#include <string.h>

NohPatricia* excluirChaveRecursivo(NohPatricia* raiz, const char* chave, int nivel, int* chaveRemovida) {
    if (raiz == NULL) {
        return NULL;
    }

    if (raiz->ehFolha) {
        if (strcmp(raiz->chave, chave) == 0) {
            *chaveRemovida = 1;
            free(raiz->chave);
            free(raiz);
            return NULL;
        }
        return raiz;
    }

    int bit = obterBit(chave, raiz->bitIndex);
    if (bit == 0) {
        raiz->esquerda = excluirChaveRecursivo(raiz->esquerda, chave, nivel + 1, chaveRemovida);
    } else {
        raiz->direita = excluirChaveRecursivo(raiz->direita, chave, nivel + 1, chaveRemovida);
    }

    if (!raiz->ehFolha) {
        if (raiz->esquerda == NULL || raiz->direita == NULL) {
            NohPatricia* filhoRestante = (raiz->esquerda != NULL) ? raiz->esquerda : raiz->direita;
            free(raiz);
            return filhoRestante;
        }
    }

    return raiz;
}

int excluirChave(DPatricia* arvore, const char* chave) {
    if (arvore->raiz == NULL) {
        return 0;
    }

    int chaveRemovida = 0;
    arvore->raiz = excluirChaveRecursivo(arvore->raiz, chave, 0, &chaveRemovida);
    return chaveRemovida;
}

#endif
