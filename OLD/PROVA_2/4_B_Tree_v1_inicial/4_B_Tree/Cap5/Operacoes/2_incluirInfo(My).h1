#ifndef INCLUIR_INFO_BTREE_H
#define INCLUIR_INFO_BTREE_H
#include "../BTree.h"
#include "../Utils.h"
#include "../../Cap3/Operacoes/2_incluirInfo.h"

int comparaChaveValor(void* info1, void* info2) {
    pChaveValor p1 = (pChaveValor) info1;
    pChaveValor p2 = (pChaveValor) info2;
    return *((int*)(p2->chave)) - *((int*)(p1->chave));
}

pNohBTree criaNoh() {
    pNohBTree pNovo = (pNohBTree) malloc(sizeof(NohBTree));
    pNovo->listaChavesValores = criarLista();
    pNovo->primeiroFilho = NULL;
    pNovo->pai = NULL;
    printf("Nó criado: %p\n", (void*)pNovo);
    return pNovo;
}

ChaveValor* criaChaveValor(void* chave, void* valor, pNohBTree filhoMaior) {
    ChaveValor* pcv = (ChaveValor*) malloc(sizeof(struct chaveValor));
    pcv->chave = chave;
    pcv->valor = valor;
    pcv->filhoMaior = filhoMaior;
    return pcv;
}

int ehFolha(pNohBTree noh) {
    return noh->primeiroFilho == NULL;
}

// Função auxiliar para promover a chave do meio e mover as chaves corretamente
ChaveValor* promoverChave(pNohBTree noh, int ordem, pNohBTree novoNoh) {
    int meio = ordem;
    ChaveValor* chavePromovida = (ChaveValor*) buscarInfoPos(noh->listaChavesValores, meio);
    printf("Promovendo chave %d do nó %p\n", *((int*)chavePromovida->chave), (void*)noh);

    // Move somente as chaves à direita do meio para o novo nó
    for (int i = meio + 1; i <= noh->listaChavesValores->quantidade; i++) {
        ChaveValor* chave = (ChaveValor*) buscarInfoPos(noh->listaChavesValores, i);
        incluirInfo(novoNoh->listaChavesValores, chave);
        printf("Movendo chave %d para novo nó %p\n", *((int*)chave->chave), (void*)novoNoh);
    }

    // Ajuste a quantidade de chaves no nó original para incluir apenas as chaves à esquerda do meio
    noh->listaChavesValores->quantidade = meio;

    // Remove a chave promovida do nó original para evitar duplicação
    excluirInfoPos(noh->listaChavesValores, meio);

    return chavePromovida;
}

// Função para dividir o nó, criando um novo nó e promovendo a chave do meio
void dividirNoh(pNohBTree noh, int ordem) {
    pNohBTree novoNoh = criaNoh();
    novoNoh->pai = noh->pai;

    // Promove a chave do meio para o nó pai e move as chaves para o novo nó
    ChaveValor* chavePromovida = promoverChave(noh, ordem, novoNoh);

    // Caso o nó original seja a raiz, cria uma nova raiz
    if (noh->pai == NULL) {
        pNohBTree novaRaiz = criaNoh();
        incluirInfo(novaRaiz->listaChavesValores, chavePromovida);
        novaRaiz->primeiroFilho = noh;
        noh->pai = novaRaiz;
        novoNoh->pai = novaRaiz;
        printf("Nova raiz criada %p com chave promovida %d\n", (void*)novaRaiz, *((int*)chavePromovida->chave));
    } else {
        // Caso contrário, promove a chave para o pai existente
        incluirInfo(noh->pai->listaChavesValores, chavePromovida);
        chavePromovida->filhoMaior = novoNoh;
        if (noh->pai->listaChavesValores->quantidade > 2 * ordem) {
            dividirNoh(noh->pai, ordem);
        }
    }
}

pNohBTree incluirInfoBTreeRecursivo(pNohBTree noh, int ordem, void* chave, void* valor, FuncaoComparacao pfc) {
    printf("Inserindo chave %d em nó %p\n", *((int*)chave), (void*)noh);

    if (ehFolha(noh)) {
        ChaveValor* novaChaveValor = criaChaveValor(chave, valor, NULL);
        incluirInfo(noh->listaChavesValores, novaChaveValor);
        printf("Chave %d inserida em folha %p\n", *((int*)chave), (void*)noh);

        if (noh->listaChavesValores->quantidade > 2 * ordem) {
            printf("Folha cheia após inserir chave %d, dividindo...\n", *((int*)chave));
            dividirNoh(noh, ordem);
            if (noh->pai == NULL) return noh;
        }
    } else {
        int i;
        for (i = 1; i <= noh->listaChavesValores->quantidade; i++) {
            pChaveValor pcv = (pChaveValor) buscarInfoPos(noh->listaChavesValores, i);
            if (pfc(pcv->chave, chave) > 0) break;
        }
        pNohBTree proximoFilho = (i == 1) ? noh->primeiroFilho : ((pChaveValor)buscarInfoPos(noh->listaChavesValores, i - 1))->filhoMaior;
        printf("Descendo para filho %p para inserir chave %d\n", (void*)proximoFilho, *((int*)chave));
        return incluirInfoBTreeRecursivo(proximoFilho, ordem, chave, valor, pfc);
    }
    return noh;
}

int incluirInfoBTree(pDBTree arvore, void* chave, void* valor, FuncaoComparacao pfc) {
    printf("\n ---> Incluindo ....: %d [ ", *((int*)chave));

    if (arvore->raiz == NULL) {
        arvore->raiz = criaNoh();
        printf("Criada raiz para chave %d\n", *((int*)chave));
    }

    arvore->raiz = incluirInfoBTreeRecursivo(arvore->raiz, arvore->ordem, chave, valor, pfc);
    if (arvore->raiz->pai != NULL) {
        arvore->raiz = arvore->raiz->pai;  // Atualiza a raiz se a altura da árvore aumentar
        printf("Atualizada raiz para %p\n", (void*)arvore->raiz);
    }
    printf(" ] \n\n");

    desenhaArvore(arvore, imprimeInt);
    return 1;
}

#endif
