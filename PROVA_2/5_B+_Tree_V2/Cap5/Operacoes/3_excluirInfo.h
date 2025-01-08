#ifndef EXCLUIRINFO_B_MAIS_TREE_H
#define EXCLUIRINFO_B_MAIS_TREE_H
#include "../BTree.h"
#include "../Utils.h"
#include "../../Cap3/Operacoes/2_incluirInfo.h"
#include "../../Cap3/Operacoes/2_3_incluirInfoOrdenada.h"
#include "12_desenhaArvore.h"

// Função para buscar a posição de uma chave em um nó
int buscaPosChave(pDLista listaChavesValores, void *chave, FuncaoComparacao fc) {
    int i = 1;
    while (i <= listaChavesValores->quantidade) {
        pChaveValor pcv = (pChaveValor) buscarInfoPos(listaChavesValores, i);
        if (fc(pcv->chave, chave) == 0) {
            return i; // Retorna a posição onde a chave foi encontrada
        }
        i++;
    }
    return -1; // Retorna -1 se a chave não for encontrada
}

// Função para corrigir a árvore caso um nó fique abaixo do limite após a exclusão
// Corrige o nó quando está abaixo do limite
pNohBTree corrigirNohBMais(pNohBTree noh, int ordem) {
    if (noh == NULL) return NULL;

    if (noh->listaChavesValores->quantidade < ordem - 1) {
        pNohBTree pai = noh->pai;

        if (pai != NULL) {
            int posNoPai = buscaPosChave(pai->listaChavesValores, noh->listaChavesValores->primeiro->info, comparaChaveValor);

            // Identificar irmãos para redistribuição ou fusão
            pNohBTree irmaoEsquerdo = posNoPai > 1 ? (pNohBTree)buscarInfoPos(pai->listaChavesValores, posNoPai - 1) : NULL;
            pNohBTree irmaoDireito = posNoPai < pai->listaChavesValores->quantidade ? (pNohBTree)buscarInfoPos(pai->listaChavesValores, posNoPai + 1) : NULL;

            // Caso de redistribuição com o irmão esquerdo
            if (irmaoEsquerdo && irmaoEsquerdo->listaChavesValores->quantidade > ordem - 1) {
                pChaveValor chavePai = (pChaveValor)buscarInfoPos(pai->listaChavesValores, posNoPai - 1);
                pChaveValor chaveRedistribuida = (pChaveValor)excluirInfoPos(irmaoEsquerdo->listaChavesValores, irmaoEsquerdo->listaChavesValores->quantidade);

                incluirInfoOrdenada(noh->listaChavesValores, chavePai, comparaChaveValor);
                chavePai->chave = chaveRedistribuida->chave;
                return noh;
            }

            // Caso de redistribuição com o irmão direito
            if (irmaoDireito && irmaoDireito->listaChavesValores->quantidade > ordem - 1) {
                pChaveValor chavePai = (pChaveValor)buscarInfoPos(pai->listaChavesValores, posNoPai);
                pChaveValor chaveRedistribuida = (pChaveValor)excluirInfoPos(irmaoDireito->listaChavesValores, 1);

                incluirInfoOrdenada(noh->listaChavesValores, chavePai, comparaChaveValor);
                chavePai->chave = chaveRedistribuida->chave;
                return noh;
            }

            // Caso de fusão
            if (irmaoEsquerdo) {
                pChaveValor chavePai = (pChaveValor)buscarInfoPos(pai->listaChavesValores, posNoPai - 1);

                // Mesclar as chaves do nó atual e do irmão esquerdo
                while (noh->listaChavesValores->quantidade > 0) {
                    pChaveValor chaveMovida = (pChaveValor)excluirInfoPos(noh->listaChavesValores, 1);
                    incluirInfoOrdenada(irmaoEsquerdo->listaChavesValores, chaveMovida, comparaChaveValor);
                }
                incluirInfoOrdenada(irmaoEsquerdo->listaChavesValores, chavePai, comparaChaveValor);
                excluirInfoPos(pai->listaChavesValores, posNoPai - 1);

                // Ajustar ponteiro de folhas
                irmaoEsquerdo->proximo = noh->proximo;
                free(noh);
                return irmaoEsquerdo;
            }

            if (irmaoDireito) {
                pChaveValor chavePai = (pChaveValor)buscarInfoPos(pai->listaChavesValores, posNoPai);

                // Mesclar as chaves do nó atual e do irmão direito
                while (irmaoDireito->listaChavesValores->quantidade > 0) {
                    pChaveValor chaveMovida = (pChaveValor)excluirInfoPos(irmaoDireito->listaChavesValores, 1);
                    incluirInfoOrdenada(noh->listaChavesValores, chaveMovida, comparaChaveValor);
                }
                incluirInfoOrdenada(noh->listaChavesValores, chavePai, comparaChaveValor);
                excluirInfoPos(pai->listaChavesValores, posNoPai);

                // Ajustar ponteiro de folhas
                noh->proximo = irmaoDireito->proximo;
                free(irmaoDireito);
                return noh;
            }
        } else {
            // Caso de nó raiz com menos chaves
            if (noh->listaChavesValores->quantidade == 0) {
                pNohBTree novaRaiz = noh->primeiroFilho;
                free(noh);
                return novaRaiz;
            }
        }
    }

    return noh;
}


// Função recursiva para excluir uma chave na árvore B+
pNohBTree excluirInfoBTreeRecursivo(pNohBTree raiz, int ordem, void *chave, FuncaoComparacao fc) {
    if (raiz == NULL) {
        return NULL;
    }

    // Caso a chave esteja na folha
    if (ehFolha(raiz)) {
        int pos = buscaPosChave(raiz->listaChavesValores, chave, fc);
        if (pos == -1) {
            return NULL; // A chave não foi encontrada
        }

        // Excluir a chave do nó folha
        excluirInfoPos(raiz->listaChavesValores, pos);
    } else {
        // Caso a chave esteja em um nó interno
        int pos = buscaPosChave(raiz->listaChavesValores, chave, fc);
        if (pos == -1) {
            // Se a chave não está no nó, descer para o filho correspondente
            pChaveValor anterior = chaveAnterior(raiz->listaChavesValores, chave, fc);
            if (anterior == NULL) {
                raiz->primeiroFilho = excluirInfoBTreeRecursivo(raiz->primeiroFilho, ordem, chave, fc);
            } else {
                anterior->filhoMaior = excluirInfoBTreeRecursivo(anterior->filhoMaior, ordem, chave, fc);
            }
        } else {
            // Se a chave está no nó interno, substituí-la pela maior chave do filho esquerdo
            pChaveValor substituta = (pChaveValor)buscarInfoPos(raiz->listaChavesValores, pos);
            substituta->chave = chave; // Atualizar com a chave substituta
            raiz->primeiroFilho = excluirInfoBTreeRecursivo(substituta->filhoMaior, ordem, chave, fc);
        }
    }

    // Verificar se o nó precisa de correção após a exclusão
    if (raiz->listaChavesValores->quantidade < ordem - 1) {
        raiz = corrigirNohBMais(raiz, ordem);
    }

    return raiz;
}

// Função principal para excluir uma chave na árvore B+
int excluirInfoBTree(pDBTree arvore, void *chave, FuncaoComparacao pfc) {
    pNohBTree novaRaiz = excluirInfoBTreeRecursivo(arvore->raiz, arvore->ordem, chave, pfc);
    if (novaRaiz == NULL) {
        printf(" -->> Erro! Chave informada não existe na árvore!!! <<--\n");
    } else {
        arvore->raiz = novaRaiz;
    }

    return 1;
}

#endif // EXCLUIRINFO_B_MAIS_TREE_H
