#ifndef EXCLUIR_INFO_B_MAIS_TREE_H
#define EXCLUIR_INFO_B_MAIS_TREE_H 
#include "../BTree.h"

// Função recursiva para exclusão de informações na árvore B+
pNohBTree excluirInfoBTreeRecursivo(pNohBTree nohAtual, void *chave, FuncaoComparacao pfc) {
  // Caso base 1: Nó atual é nulo
  if (nohAtual == NULL) {
    return NULL;
  }

  // Itera sobre os pares chave-valor do nó atual
  pNoh atual = nohAtual->listaChavesValores->primeiro;
  pChaveValor anterior = NULL;

  while (atual != NULL) {
    pChaveValor pcv = (pChaveValor)atual->info;

    // Caso 2: Encontrou a chave
    if (pfc(chave, pcv->chave) == 0) {
      if (nohAtual->ehFolha) {
        // Caso 2.1: Exclusão em nó folha
        excluirInfo(nohAtual->listaChavesValores, pcv, comparaChaveValor);
      } else {
        // Caso 2.2: Exclusão em nó interno
        pChaveValor sucessor =
            (pChaveValor)buscarInfoPos(nohAtual->listaChavesValores, 2); // Busca o sucessor
        if (sucessor != NULL) {
          pcv->chave = sucessor->chave; // Substitui chave pelo sucessor
          pcv->valor = sucessor->valor; // Substitui valor pelo sucessor
          excluirInfo(nohAtual->listaChavesValores, sucessor, comparaChaveValor); // Remove sucessor
        }
      }
      break;
    }

    // Caso 3: Chave não encontrada ainda, verifica o próximo
    if (pfc(chave, pcv->chave) < 0) {
      break;
    }
    anterior = pcv;
    atual = atual->prox;
  }

  // Caso 4: Nó atual não é folha, continua a busca recursivamente
  if (!nohAtual->ehFolha) {
    pNohBTree filho =
        (anterior == NULL) ? nohAtual->primeiroFilho : anterior->filhoMaior;
    excluirInfoBTreeRecursivo(filho, chave, pfc);

    // Caso 5: Verifica se o nó precisa de redistribuição ou fusão
    if (nohAtual->listaChavesValores->quantidade < 1) {
      if (nohAtual->pai != NULL) {
        pNohBTree pai = nohAtual->pai;
        // Redistribuição ou fusão a ser implementada
      }
    }
  }

  return nohAtual;
}

// Função principal para excluir uma chave na árvore
int excluirInfoBTree(pDBTree arvore, void *chave, FuncaoComparacao pfc) {
  // Caso base: Árvore ou raiz nula
  if (arvore == NULL || arvore->raiz == NULL) {
    return 0;
  }

  // Chama a função recursiva de exclusão
  arvore->raiz = excluirInfoBTreeRecursivo(arvore->raiz, chave, pfc);
  return 1;
}

#endif // EXCLUIR_INFO_B_MAIS_TREE_H
