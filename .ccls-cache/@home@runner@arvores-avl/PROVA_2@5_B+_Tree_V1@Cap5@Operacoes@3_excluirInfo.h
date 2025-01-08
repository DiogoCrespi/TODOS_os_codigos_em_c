#ifndef EXCLUIRINFO_B_MAIS_TREE_H
#define EXCLUIRINFO_B_MAIS_TREE_H
#include "../BTree.h"
#include "../Utils.h"
#include "../../Cap3/Operacoes/2_incluirInfo.h"

int buscaPosChave(pDLista listaChavesValores, void *chave, FuncaoComparacao fc) {
    int i = 1;
    pNoh nohAtual = listaChavesValores->primeiro;
    while (nohAtual != NULL) {
        pChaveValor pcv = (pChaveValor) nohAtual->info;
        if (fc(pcv->chave, chave) == 0) {
            return i;
        }
        nohAtual = nohAtual->prox;
        i++;
    }
    return -1;
}

pNohBTree corrigirRaizBTree(pNohBTree raiz, int ordem) {
    if (raiz == NULL) {
        return NULL;
    }

    if (raiz->listaChavesValores->quantidade == 0) {
        pNohBTree novaRaiz = raiz->primeiroFilho;
        if (novaRaiz != NULL) {
            novaRaiz->pai = NULL;
        }
        free(raiz);
        return novaRaiz;
    }

    return raiz;
}

pNohBTree excluirFilho(pNohBTree noh, int pos) {
    if (noh == NULL || pos < 1 || pos > noh->listaChavesValores->quantidade) {
        return NULL;
    }

    pChaveValor chave = (pChaveValor) excluirInfoPos(noh->listaChavesValores, pos);
    return chave->filhoMaior;
}

void incluirFilho(pNohBTree noh, pNohBTree filho) {
    if (noh == NULL || filho == NULL) {
        return;
    }

    // Encontra a posição onde o filho deve ser inserido
    pChaveValor chaveFilho = criaChaveValor(NULL, NULL, filho);
    incluirInfoOrdenada(noh->listaChavesValores, chaveFilho, comparaChaveValor);
}

void redistribuirChaves(pNohBTree noEsquerdo, pNohBTree noDireito, pNohBTree pai, int indicePai, int ordem) {
    pChaveValor chavePai = (pChaveValor) excluirInfoPos(pai->listaChavesValores, indicePai + 1);

  
    incluirInfoOrdenada(noEsquerdo->listaChavesValores, chavePai, comparaChaveValor);

    pChaveValor chaveDireita = (pChaveValor) excluirInfoPos(noDireito->listaChavesValores, 1);
    incluirInfoOrdenada(noEsquerdo->listaChavesValores, chaveDireita, comparaChaveValor);

    if (!ehFolha(noEsquerdo) && !ehFolha(noDireito)) {
        pNohBTree filhoDireito = excluirFilho(noDireito, 1);
        incluirFilho(noEsquerdo, filhoDireito);
    }


    chavePai->filhoMaior = noEsquerdo;
    incluirInfoOrdenada(pai->listaChavesValores, chavePai, comparaChaveValor);
}


pNohBTree fundirNos(pNohBTree pai, int indice, int ordem) {
    pNohBTree noEsquerdo = pai->primeiroFilho;
    pNohBTree noDireito = noEsquerdo->proximo;

    pChaveValor chavePai = (pChaveValor) pai->listaChavesValores->primeiro->info;
    inserirInfoPos(noEsquerdo->listaChavesValores, noEsquerdo->listaChavesValores->quantidade, chavePai);

    pNoh nohDireitoAtual = noDireito->listaChavesValores->primeiro;
    while (nohDireitoAtual != NULL) {
        pChaveValor chaveDireita = (pChaveValor) nohDireitoAtual->info;
        inserirInfoPos(noEsquerdo->listaChavesValores, noEsquerdo->listaChavesValores->quantidade, chaveDireita);
        nohDireitoAtual = nohDireitoAtual->prox;
    }

    if (!ehFolha(noDireito)) {
        noEsquerdo->proximo = noDireito->proximo;
    }

    free(noDireito);
    return pai;
}

pNohBTree excluirInfoBTreeRecursivo(pNohBTree raiz, int ordem, void *chave, FuncaoComparacao fc) {
    if (raiz == NULL) {
        printf("Raiz nula durante exclusão\n");
        return NULL;
    }

    if (ehFolha(raiz)) {
        printf("Excluindo chave %d\n", *(int *) chave);
        int pos = buscaPosChave(raiz->listaChavesValores, chave, fc);
        if (pos == -1) {
            printf("Chave não encontrada!\n");
            return NULL;
        }

        excluirInfoPos(raiz->listaChavesValores, pos);
        printf("Chave excluída!\n");
    }else {
        // Localize a posição da chave no nó
        int pos = buscaPosChave(raiz->listaChavesValores, chave, fc);
        if (pos == -1) {
            printf("Chave não encontrada!\n");
            return NULL;
        }

        // Recursão no filho à esquerda ou à direita, conforme necessário
        pNohBTree filhoEsquerdo = raiz->primeiroFilho;
        pNohBTree filhoDireito = raiz->primeiroFilho->proximo; // Exemplo, ajusta conforme sua árvore

        // Exclua da árvore recursivamente
        if (ehFolha(filhoEsquerdo)) {
            // Chave está em um nó folha
            excluirInfoBTreeRecursivo(filhoEsquerdo, ordem, chave, fc);
        } else {
            // Chave está em um nó interno, recursão para o filho correspondente
            excluirInfoBTreeRecursivo(filhoDireito, ordem, chave, fc);
        }
    }


    raiz = corrigirRaizBTree(raiz, ordem);
    return raiz;
}


int excluirInfoBTree(pDBTree arvore, void *chave, FuncaoComparacao pfc) {
    if (arvore == NULL || arvore->raiz == NULL) {
        return 0;
    }

    pNohBTree novaRaiz = excluirInfoBTreeRecursivo(arvore->raiz, arvore->ordem, chave, pfc);
    if (novaRaiz == NULL) {
        printf(" -->> Erro! Chave informada não existe na árvore!!! <<--");
        return 0;
    } else {
        arvore->raiz = novaRaiz;
    }

    return 1;
}

#endif
