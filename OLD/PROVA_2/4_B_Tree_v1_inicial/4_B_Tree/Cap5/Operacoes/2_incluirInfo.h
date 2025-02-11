#ifndef INCLUIR_INFO_BTREE_H
#define INCLUIR_INFO_BTREE_H
#include "../BTree.h"
#include "../Utils.h"
#include "../../Cap3/Operacoes/2_incluirInfo.h"

void incluirInfoPos(pDLista lista, int pos, void *info) {
    if (lista == NULL || pos < 1 || pos > lista->quantidade + 1) return;

    pNoh novoElemento = (pNoh)malloc(sizeof(Noh));
    novoElemento->info = info;
    novoElemento->prox = NULL;

    if (pos == 1) {
        novoElemento->prox = lista->primeiro;
        lista->primeiro = novoElemento;
        if (lista->ultimo == NULL) lista->ultimo = novoElemento;
    } else {
        pNoh atual = lista->primeiro;
        for (int i = 1; i < pos - 1; i++) {
            if (atual->prox != NULL) atual = atual->prox;
        }
        novoElemento->prox = atual->prox;
        atual->prox = novoElemento;
        if (novoElemento->prox == NULL) lista->ultimo = novoElemento;
    }

    lista->quantidade++;
}

int comparaChaveValor(void *info1, void *info2) {
    pChaveValor p1 = (pChaveValor)info1;
    pChaveValor p2 = (pChaveValor)info2;
    return *((int *)(p2->chave)) - *((int *)(p1->chave));
}

pNohBTree criaNoh() {
    pNohBTree pNovo = (pNohBTree)malloc(sizeof(NohBTree));
    pNovo->listaChavesValores = criarLista();
    pNovo->primeiroFilho = NULL;
    pNovo->pai = NULL;
    return pNovo;
}

pChaveValor criaChaveValor(void *chave, void *valor, pNohBTree filhoMaior) {
    pChaveValor pcv = (pChaveValor)malloc(sizeof(ChaveValor));
    pcv->chave = chave;
    pcv->valor = valor;
    pcv->filhoMaior = filhoMaior;
    return pcv;
}

int ehFolha(pNohBTree raiz) {
    if (raiz == NULL) return 0;
    if (raiz->primeiroFilho != NULL) return 0;

    int i = 1;
    while (i <= raiz->listaChavesValores->quantidade) {
        pChaveValor pcv = (pChaveValor)buscarInfoPos(raiz->listaChavesValores, i);
        if (pcv->filhoMaior != NULL) return 0;
        i++;
    }
    return 1;
}

void incluirInfoOrdenada(pDLista lista, pChaveValor info, FuncaoComparacao compara) {
    int i;
    for (i = 1; i <= lista->quantidade; i++) {
        pChaveValor atual = (pChaveValor)buscarInfoPos(lista, i);
        if (compara(info, atual) > 0) break;
    }
    incluirInfoPos(lista, i, info);
}

pNohBTree incluirInfoBTreeRecursivo(pNohBTree raiz, int ordem, void *chave, void *valor, FuncaoComparacao pfc) {
    if (raiz == NULL) {
        pNohBTree novo = criaNoh();
        pChaveValor pcv = criaChaveValor(chave, valor, NULL);
        incluirInfoOrdenada(novo->listaChavesValores, pcv, comparaChaveValor);
        return novo;
    }

    pNohBTree novaRaiz = raiz;
    if (ehFolha(raiz)) {
        if (contemInfo(raiz->listaChavesValores, chave, pfc)) return NULL;

        pChaveValor pcv = criaChaveValor(chave, valor, NULL);
        incluirInfoOrdenada(raiz->listaChavesValores, pcv, comparaChaveValor);
    } else {
        pChaveValor pcvAtual, pcvAnt = NULL;
        int i = 1;
        while (i <= raiz->listaChavesValores->quantidade) {
            pcvAnt = pcvAtual;
            pcvAtual = (pChaveValor)buscarInfoPos(raiz->listaChavesValores, i);

            int r = pfc(pcvAtual, chave);
            if (r == 0) return NULL;

            if (r < 0 && i == 1) {
                novaRaiz = incluirInfoBTreeRecursivo(raiz->primeiroFilho, ordem, chave, valor, pfc);
                break;
            }
            if (r < 0 && i > 1 && i < raiz->listaChavesValores->quantidade) {
                novaRaiz = incluirInfoBTreeRecursivo(pcvAnt->filhoMaior, ordem, chave, valor, pfc);
                break;
            }
            if (i == raiz->listaChavesValores->quantidade) {
                novaRaiz = incluirInfoBTreeRecursivo(pcvAtual->filhoMaior, ordem, chave, valor, pfc);
                break;
            }
            i++;
        }
    }

    if (novaRaiz == NULL) return NULL;

    if (raiz->listaChavesValores->quantidade > 2 * ordem) {
        pNohBTree novaPagina = criaNoh();
        pDLista d1 = dividirLista(raiz->listaChavesValores, ordem);

        novaPagina->listaChavesValores = d1;

        pChaveValor pcvD1 = (pChaveValor)excluirInfoPos(d1, 1);
        pcvD1->filhoMaior = novaPagina;

        pNohBTree pai = raiz->pai;
        if (pai == NULL) {
            pai = criaNoh();
            pai->primeiroFilho = raiz;
        }

        raiz->pai = pai;
        novaPagina->pai = pai;

        incluirInfoOrdenada(pai->listaChavesValores, pcvD1, comparaChaveValor);
        return pai;
    }

    if (novaRaiz->pai == NULL) return novaRaiz;

    return novaRaiz->pai;
}

int incluirInfoBTree(pDBTree arvore, void *chave, void *valor, FuncaoComparacao pfc) {
    desenhaArvore(arvore, imprimeInt);
    printf("\n ---> Incluindo ....: %d [ ", *((int *)chave));

    pNohBTree novaRaiz = incluirInfoBTreeRecursivo(arvore->raiz, arvore->ordem, chave, valor, pfc);
    if (novaRaiz == NULL) {
        printf(" -->> Erro! Chave informada já existe na árvore!!! <<--");
    } else {
        arvore->raiz = novaRaiz;
    }

    printf(" ] \n\n");
    return 1;
}

#endif
