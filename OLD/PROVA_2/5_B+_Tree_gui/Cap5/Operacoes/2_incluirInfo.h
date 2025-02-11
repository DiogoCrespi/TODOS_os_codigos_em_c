#ifndef INCLUIR_INFO_BTREE_H
#define INCLUIR_INFO_BTREE_H
#include "../BTree.h"
#include "../Utils.h"
#include "12_desenhaArvore.h"

// Função para obter um elemento de uma lista ou árvore
pChaveValor obterElemento(pDLista lista, void* chave, FuncaoComparacao pfc) {
    pNoh atual = lista->primeiro; // Usando o campo correto da estrutura DLista

    while (atual != NULL) {
        pChaveValor chaveValorAtual = (pChaveValor) atual->info;
        if (pfc(chaveValorAtual->chave, chave) == 0) {
            return chaveValorAtual;  // Retorna o elemento que corresponde à chave
        }
        atual = atual->prox;
    }

    return NULL;  // Retorna NULL se o elemento não for encontrado
}



pChaveValor chaveAnterior(pDLista listaChavesValores, void* chave, FuncaoComparacao pfc) {
    pChaveValor chaveAnterior = NULL;
    pNoh atual = listaChavesValores->primeiro;  // Começa do primeiro nó da lista

    while (atual != NULL) {
        pChaveValor chaveValorAtual = (pChaveValor) atual->info;
        if (pfc(chaveValorAtual->chave, chave) >= 0) {
            break;  // Encontrou a chave ou um valor maior, então a anterior é a última
        }
        chaveAnterior = chaveValorAtual;
        atual = atual->prox;
    }

    return chaveAnterior;  // Retorna a chave anterior encontrada
}



// Função para comparar chaves
int comparaChaveValor(void *info1, void *info2) {
    pChaveValor p1 = (pChaveValor) info1;
    pChaveValor p2 = (pChaveValor) info2;
    return *((int*)(p2->chave)) - *((int*)(p1->chave));
}

// Função para criar um novo nó BTree
pNohBTree criaNoh(int ehFolha) {
    pNohBTree pNovo = malloc(sizeof(NohBTree));
    pNovo->listaChavesValores = criarLista(); // Lista que guarda as chaves, sem valores
    pNovo->primeiroFilho = NULL;  // Ponteiro para o primeiro filho (usado em nós internos)
    pNovo->pai = NULL;            // Ponteiro para o nó pai
    pNovo->proxFolha = NULL;      // Ponteiro para o próximo nó folha
    pNovo->ehFolha = ehFolha;    // Define se o nó é folha
    return pNovo;
}

// Função para criar uma nova chave e valor
ChaveValor* criaChaveValor(void* chave, void* valor, pNohBTree filhoMaior) {
    ChaveValor* pcv = malloc(sizeof(ChaveValor));
    pcv->chave = chave;
    pcv->valor = valor;
    pcv->filhoMaior = filhoMaior;  // Para nós internos, filhoMaior aponta para o nó filho
    return pcv;
}

// Função para verificar se um nó é uma folha
int ehFolha(pNohBTree raiz) {
    return raiz != NULL && raiz->ehFolha;
}

// Função recursiva para incluir uma chave e valor na árvore 
pNohBTree incluirInfoBTreeRecursivo(pNohBTree raiz, int ordem, void* chave, void* valor, FuncaoComparacao pfc) {
    // Caso base 1: A árvore não tem raiz
    if (raiz == NULL) {
        pNohBTree novo = criaNoh(1);  // Cria um nó folha
        ChaveValor *pcv = criaChaveValor(chave, valor, NULL);
        incluirInfoOrdenada(novo->listaChavesValores, pcv, comparaChaveValor);
        return novo;
    }

    // Caso base 2: A raiz é uma folha
    if (ehFolha(raiz)) {
        int resultado = contemInfo(raiz->listaChavesValores, chave, pfc);
        if (resultado != 0)
            return NULL;  // A chave já existe na árvore

        // Inclui a chave na folha
        ChaveValor *pcv = criaChaveValor(chave, valor, NULL);
        incluirInfoOrdenada(raiz->listaChavesValores, pcv, comparaChaveValor);
    } else {
        // Caso recursivo: A raiz não é uma folha
        pChaveValor anterior = chaveAnterior(raiz->listaChavesValores, chave, pfc);
        if (anterior == NULL)
            raiz = incluirInfoBTreeRecursivo(raiz->primeiroFilho, ordem, chave, valor, pfc);
        else
            raiz = incluirInfoBTreeRecursivo(anterior->filhoMaior, ordem, chave, valor, pfc);
    }

    // Verifica se o nó precisa ser dividido
    if (raiz->listaChavesValores->quantidade > 2 * ordem) {
        pNohBTree pai = raiz->pai ? raiz->pai : criaNoh(0); // Cria um nó interno
        pNohBTree irmao = criaNoh(raiz->ehFolha); // Cria um nó irmão

        raiz->pai = pai;
        irmao->pai = pai;

        // Divide a lista de chaves
        pChaveValor mediana = excluirInfoPos(raiz->listaChavesValores, ordem + 1);
        incluirInfoOrdenada(pai->listaChavesValores, mediana, comparaChaveValor);

        pDLista listaIrmao = dividirLista(raiz->listaChavesValores, ordem);
        irmao->primeiroFilho = mediana->filhoMaior;
        mediana->filhoMaior = irmao;
        irmao->listaChavesValores = listaIrmao;

        if (pai->listaChavesValores->quantidade == 1) {
            pai->primeiroFilho = raiz;
        }

        return pai;  // Retorna o novo pai
    }

    return raiz->pai ? raiz->pai : raiz;
}

// Função de inclusão principal para a Árvore 
int incluirInfoBTree(pDBTree arvore, void *chave, void *valor, FuncaoComparacao pfc) {
    desenhaArvore(arvore, imprimeInt);
    printf("\n ---> Incluindo ....: %d [ ", *((int*)chave));

    pNohBTree novaRaiz = incluirInfoBTreeRecursivo(arvore->raiz, arvore->ordem, chave, valor, pfc);
    if (novaRaiz == NULL) {
        printf(" -->> Erro! Chave informada já existe na árvore!!! <<--");
    } else {
        arvore->raiz = novaRaiz;
    }

    printf(" ] \n\n");
    return 1;
}

// Função para encadear as folhas (essa parte é específica para a árvore )
void encadearFolhas(pDBTree arvore) {
    pNohBTree folha = arvore->raiz;
    while (folha != NULL && !ehFolha(folha)) {
        folha = folha->primeiroFilho;
    }
    if (folha == NULL) return;

    pNohBTree atual = folha;
    while (atual != NULL) {
        if (atual->proxFolha != NULL) {
            atual->proxFolha = atual->proxFolha;
        }
        atual = atual->proxFolha;
    }
}


#endif
