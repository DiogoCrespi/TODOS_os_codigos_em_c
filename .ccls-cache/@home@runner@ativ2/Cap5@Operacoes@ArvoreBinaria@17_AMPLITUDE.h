#ifndef AMPLITUDE_H
#define AMPLITUDE_H

#include "../../ArvoreBinaria.h"
#include "../../../Cap3/Lista.h"
#include <stdio.h>
#include <stdlib.h>
//--------------------------------------------

int contarAltura(pNohArvore noAtual) {
    if (noAtual == NULL) {
        return -1;
    }
    int alturaEsquerda = contarAltura(noAtual->esquerda);
    int alturaDireita = contarAltura(noAtual->direita);
    return (alturaEsquerda > alturaDireita ? alturaEsquerda : alturaDireita) + 1;
}

//--------------------------------------------
int alturaArvore(pDArvore arv) {
    if (arvoreVazia(arv)) {
        return -1;
    }

    return contarAltura(arv->raiz);
}

//--------------------------------------------
int arvoreVazia(pDArvore arv) {
    return arv == NULL || arv->raiz == NULL;
}
//--------------------------------------------
void amplitude(pDArvore arv, FuncaoImpressao fi) {
    if (arvoreVazia(arv)) {
        return;
    }

    pDLista fila = criarLista();
    if (fila == NULL) {
        fprintf(stderr, "Erro ao criar a fila.\n");
        return;
    }

    incluirInfo_lista(fila, arv->raiz);

    while (fila->quantidade > 0) {
        pNoh nohAtual = fila->primeiro;
        if (nohAtual == NULL) {
            break;
        }

        fila->primeiro = nohAtual->prox;
        fila->quantidade--;

        pNohArvore noAtual = (pNohArvore)nohAtual->info;
        fi(noAtual->info);

        if (noAtual->esquerda != NULL) {
            incluirInfo_lista(fila, noAtual->esquerda);
        }

        if (noAtual->direita != NULL) {
            incluirInfo_lista(fila, noAtual->direita);
        }

        free(nohAtual);
    }

    destruirLista(fila);
}
//--------------------------------------------

void visitarNivel(pNohArvore noAtual, int nivel, FuncaoImpressao fi) {
    if (noAtual == NULL) {
        return;
    }
    if (nivel == 0) {
        fi(noAtual->info);
    } else {
        visitarNivel(noAtual->esquerda, nivel - 1, fi); 
        visitarNivel(noAtual->direita, nivel - 1, fi); 
    }
}

void amplitudeRecursiva(pDArvore arv, FuncaoImpressao fi) {
    if (arvoreVazia(arv)) {
        return; 
    }

    int altura = contarAltura(arv->raiz); 
    for (int i = 0; i <= altura; i++) {
        visitarNivel(arv->raiz, i, fi); 
    }
}
//--------------------------------------------

#endif
