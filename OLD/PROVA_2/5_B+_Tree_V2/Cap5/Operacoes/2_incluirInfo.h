#ifndef INCLUIR_INFO_B_MAIS_TREE_H
#define INCLUIR_INFO_B_MAIS_TREE_H
#include "../BTree.h"
#include "../Utils.h"
#include "../../Cap3/Operacoes/2_incluirInfo.h"
#include "../../Cap3/Operacoes/2_3_incluirInfoOrdenada.h"
#include "../../Cap3/Operacoes/10_buscarInfoPos.h"
#include "../../Cap3/Operacoes/3_1_excluirInfoPos.h"
#include "12_desenhaArvore.h"

#define CAPACIDADE_MAXIMA_NOH 4

pChaveValor chaveAnterior(pDLista lista, void* chave, FuncaoComparacao pfc) {
    pNoh atual = lista->primeiro;
    pNoh ant = NULL;
    while (atual != NULL) {
        pChaveValor pcv = (pChaveValor)atual->info;
        if (pfc(pcv->chave, chave) >= 0) {
            return ant != NULL ? (pChaveValor)ant->info : NULL;
        }
        ant = atual;
        atual = atual->prox;
    }
    return NULL;
}

int comparaChaveValor(void *info1, void *info2) {
    pChaveValor p1 = (pChaveValor)info1;
    pChaveValor p2 = (pChaveValor)info2;
    return *((int *)(p1->chave)) - *((int *)(p2->chave));
}


int verificarChaveExistente(pNohBTree noh, void* chave, FuncaoComparacao pfc) {
    if (noh == NULL) return 0;

    for (int i = 0; i < noh->listaChavesValores->quantidade; i++) {
        pChaveValor pcv = (pChaveValor)buscarInfoPos(noh->listaChavesValores, i + 1);
        if (pfc(pcv->chave, chave) == 0) {
            return 1;
        }
    }
    return 0;
}


// pNohBTree criarNohBMais(int ehFolha) {
//     pNohBTree noh = (pNohBTree)malloc(sizeof(struct nohBTree));
//     noh->listaChavesValores = criarLista();
//     noh->primeiroFilho = NULL;
//     noh->pai = NULL;
//     noh->proxFolha = NULL;
//     noh->ehFolha = ehFolha;
//     return noh;
// }

pChaveValor criarChaveValor(void* chave, void* valor, pNohBTree filhoMaior) {
    pChaveValor pcv = (pChaveValor)malloc(sizeof(struct chaveValor));
    pcv->chave = chave;
    pcv->valor = (filhoMaior == NULL ? valor : NULL);
    pcv->filhoMaior = filhoMaior;
    return pcv;
}

pNohBTree dividirNohBMais(pNohBTree noh, int ordem) {
    int medianaIndex = ordem;
    pChaveValor chavePromovida = (pChaveValor)buscarInfoPos(noh->listaChavesValores, medianaIndex);

    pNohBTree novoNoh = criarNohBMais(noh->ehFolha);

    while (noh->listaChavesValores->quantidade > medianaIndex) {
        pChaveValor chaveMovida = (pChaveValor)excluirInfoPos(noh->listaChavesValores, medianaIndex + 1);
        incluirInfoOrdenada(novoNoh->listaChavesValores, chaveMovida, comparaChaveValor);
    }

    if (noh->ehFolha) {
        novoNoh->proxFolha = noh->proxFolha;
        noh->proxFolha = novoNoh;
    }

    if (noh->pai == NULL) {
        pNohBTree novaRaiz = criarNohBMais(0);
        incluirInfoOrdenada(novaRaiz->listaChavesValores, criarChaveValor(chavePromovida->chave, NULL, novoNoh), comparaChaveValor);
        novaRaiz->primeiroFilho = noh;
        noh->pai = novaRaiz;
        novoNoh->pai = novaRaiz;
    } else {
        incluirInfoOrdenada(noh->pai->listaChavesValores, criarChaveValor(chavePromovida->chave, NULL, novoNoh), comparaChaveValor);
        novoNoh->pai = noh->pai;
    }

    excluirInfoPos(noh->listaChavesValores, medianaIndex);

    if (noh->pai->listaChavesValores->quantidade > 2 * ordem) {
        return dividirNohBMais(noh->pai, ordem);
    }

    return noh->pai;
}

pNohBTree incluirInfoBMaisRecursivo(pNohBTree noh, int ordem, void* chave, void* valor, FuncaoComparacao pfc) {
    if (noh == NULL) {
        pNohBTree novo = criarNohBMais(1);
        pChaveValor pcv = criarChaveValor(chave, valor, NULL);
        incluirInfoOrdenada(novo->listaChavesValores, pcv, comparaChaveValor);
        return novo;
    }

    if (noh->ehFolha) {
        if (contemInfo(noh->listaChavesValores, chave, pfc)) return NULL;

        pChaveValor pcv = criarChaveValor(chave, valor, NULL);
        incluirInfoOrdenada(noh->listaChavesValores, pcv, comparaChaveValor);

        if (noh->listaChavesValores->quantidade > 2 * ordem) {
            return dividirNohBMais(noh, ordem);
        }
        return noh;
    }

    pChaveValor anterior = chaveAnterior(noh->listaChavesValores, chave, pfc);
    if (anterior == NULL) {
        return incluirInfoBMaisRecursivo(noh->primeiroFilho, ordem, chave, valor, pfc);
    } else {
        return incluirInfoBMaisRecursivo(anterior->filhoMaior, ordem, chave, valor, pfc);
    }
}

int incluirInfoBMais(pDBTree arvore, void* chave, void* valor, FuncaoComparacao pfc) {
    printf("\n ---> Incluindo ....: %d [ ", *((int*)chave));

    pNohBTree novaRaiz = incluirInfoBMaisRecursivo(arvore->raiz, arvore->ordem, chave, valor, pfc);
    if (novaRaiz == NULL) {
        printf(" -->> Erro! Chave informada já existe na árvore!!! <<--\n");
    } else {
        arvore->raiz = novaRaiz;
    }

    printf(" ] \n\n");
    desenhaArvore(arvore, imprimeInt);
    return 1;
}

#endif


