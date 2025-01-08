#ifndef INCLUIR_INFO_B_MAIS_TREE_H
#define INCLUIR_INFO_B_MAIS_TREE_H
#include "../BTree.h"
#include "../Utils.h"
#include "../../Cap3/Operacoes/2_incluirInfo.h"
#include "../../Cap3/Operacoes/2_3_incluirInfoOrdenada.h"
#include "12_desenhaArvore.h"

#define CAPACIDADE_MAXIMA_NOH 4 // Defina o valor da capacidade máxima de um nó conforme necessário

int comparaChaveValor(void *info1, void *info2) {
    pChaveValor p1 = (pChaveValor)info1;
    pChaveValor p2 = (pChaveValor)info2;
    return *((int *)(p1->chave)) - *((int *)(p2->chave));
}

pNohBTree criaNoh() {
    pNohBTree pNovo = (pNohBTree)malloc(sizeof(NohBTree));
    pNovo->listaChavesValores = criarLista();
    pNovo->primeiroFilho = NULL;
    pNovo->pai = NULL;
    pNovo->proximo = NULL; // Encadeamento de folhas
    return pNovo;
}

ChaveValor* criaChaveValor(void* chave, void* valor, pNohBTree filhoMaior) {
    ChaveValor* pcv = (ChaveValor*)malloc(sizeof(struct chaveValor));
    pcv->chave = chave;
    pcv->filhoMaior = filhoMaior;
    pcv->valor = NULL;
    if (filhoMaior == NULL) {
        pcv->valor = valor; // Associa valor apenas nas folhas
    }
    return pcv;
}


int ehFolha(pNohBTree raiz) {
    return raiz->primeiroFilho == NULL;
}

pChaveValor chaveAnterior(pDLista lista, void* chave, FuncaoComparacao pfc) {
    pNoh atual = lista->primeiro;
    pNoh ant = NULL;
    while (atual != NULL) {
        pChaveValor pcv = (pChaveValor)atual->info;
        if (pfc(pcv->chave, chave) < 0) {
            if (ant != NULL)
                return (pChaveValor)ant->info;
            return NULL;
        }
        ant = atual;
        atual = atual->prox;
    }
    return NULL;
}

int verificarChaveExistente(pNohBTree raiz, void* chave, FuncaoComparacao pfc) {
    if (raiz == NULL) return 0;

    for (int i = 0; i < raiz->listaChavesValores->quantidade; i++) {
        pChaveValor pcv = (pChaveValor)buscarInfoPos(raiz->listaChavesValores, i + 1);
        if (pfc(pcv->chave, chave) == 0) {
            return 1; // Chave já existe
        }
    }
    return 0;
}

// Função para dividir um nó interno

pNohBTree dividirNohInterno(pNohBTree noh) {
    pNohBTree novoNoh = criaNoh();
    pChaveValor chaveMedia = (pChaveValor)excluirInfoPos(noh->listaChavesValores, CAPACIDADE_MAXIMA_NOH / 2);

    // Mover metade das chaves do nó atual para o novo nó
    while (noh->listaChavesValores->quantidade > CAPACIDADE_MAXIMA_NOH / 2) {
        pChaveValor chavePromovida = (pChaveValor)excluirInfoPos(noh->listaChavesValores, CAPACIDADE_MAXIMA_NOH / 2);
        incluirInfoOrdenada(novoNoh->listaChavesValores, chavePromovida, comparaChaveValor);
    }

    // Atualiza o encadeamento de folhas
    novoNoh->proximo = noh->proximo;
    noh->proximo = novoNoh;

    // Atualiza o nó pai ou cria uma nova raiz
    if (noh->pai == NULL) {
        pNohBTree novaRaiz = criaNoh();
        chaveMedia->filhoMaior = novoNoh; // Ajusta filho maior
        incluirInfoOrdenada(novaRaiz->listaChavesValores, chaveMedia, comparaChaveValor);
        novaRaiz->primeiroFilho = noh;
        return novaRaiz;
    }

    // Se o nó pai já existe, atualiza com a chave promovida
    ChaveValor* chavePai = criaChaveValor(chaveMedia->chave, NULL, novoNoh);
    incluirInfoOrdenada(noh->pai->listaChavesValores, chavePai, comparaChaveValor);

    if (noh->pai->listaChavesValores->quantidade > CAPACIDADE_MAXIMA_NOH) {
        return dividirNohInterno(noh->pai);
    }

    return noh->pai;
}

pNohBTree incluirInfoBTreeRecursivo(pNohBTree raiz, void* chave, void* valor, FuncaoComparacao pfc) {
    if (raiz == NULL) {
        pNohBTree novo = criaNoh();
        ChaveValor *pcv = criaChaveValor(chave, valor, NULL);
        incluirInfoOrdenada(novo->listaChavesValores, pcv, comparaChaveValor);
        return novo;
    }

    pNohBTree novaRaiz = raiz;
    if (ehFolha(raiz)) {
        if (verificarChaveExistente(raiz, chave, pfc)) {
            return NULL; // A chave já existe, não insere
        }

        ChaveValor *pcv = criaChaveValor(chave, valor, NULL);
        incluirInfoOrdenada(raiz->listaChavesValores, pcv, comparaChaveValor);

        if (raiz->listaChavesValores->quantidade > CAPACIDADE_MAXIMA_NOH) {
            pNohBTree novoIrmao = criaNoh();
            pChaveValor chaveMedia = (pChaveValor)excluirInfoPos(raiz->listaChavesValores, CAPACIDADE_MAXIMA_NOH / 2);

            incluirInfoOrdenada(novoIrmao->listaChavesValores, chaveMedia, comparaChaveValor);
            novoIrmao->proximo = raiz->proximo;  // Mantém o encadeamento de folhas
            raiz->proximo = novoIrmao;

            if (raiz->pai == NULL) {
                pNohBTree novaRaiz = criaNoh();
                raiz->pai = novaRaiz;
                novoIrmao->pai = novaRaiz;

                ChaveValor* chavePai = criaChaveValor(chaveMedia->chave, NULL, novoIrmao);
                incluirInfoOrdenada(novaRaiz->listaChavesValores, chavePai, comparaChaveValor);
                novaRaiz->primeiroFilho = raiz;
                return novaRaiz;
            } else {
                ChaveValor* chavePai = criaChaveValor(chaveMedia->chave, NULL, novoIrmao);
                incluirInfoOrdenada(raiz->pai->listaChavesValores, chavePai, comparaChaveValor);

                if (raiz->pai->listaChavesValores->quantidade > CAPACIDADE_MAXIMA_NOH) {
                    return dividirNohInterno(raiz->pai);
                }

                return raiz->pai;
            }
        }
    } else {
        pChaveValor anterior = chaveAnterior(raiz->listaChavesValores, chave, pfc);
        if (anterior == NULL)
            novaRaiz = incluirInfoBTreeRecursivo(raiz->primeiroFilho, chave, valor, pfc);
        else
            novaRaiz = incluirInfoBTreeRecursivo(anterior->filhoMaior, chave, valor, pfc);
    }

    if (novaRaiz == NULL)
        return NULL;

    return novaRaiz->pai == NULL ? novaRaiz : novaRaiz->pai;
}

int incluirInfoBTree(pDBTree arvore, void *chave, void *valor, FuncaoComparacao pfc) {
    printf("\n ---> Incluindo ....: %d [ ", *((int*)chave));

    pNohBTree novaRaiz = incluirInfoBTreeRecursivo(arvore->raiz, chave, valor, pfc);
    if (novaRaiz == NULL) {
        printf(" -->> Erro! Chave informada já existe na árvore!!! <<--");
    } else {
        arvore->raiz = novaRaiz;
    }

    printf(" ] \n\n");

    // Verifica se a árvore foi alterada
    desenhaArvore(arvore, imprimeInt);
    return 1;
}

#endif
