#ifndef DESENHA_ARVORE_BTREE_H
#define DESENHA_ARVORE_BTREE_H
#include "../BTree.h"
#include "../Utils.h"
#include "../../Cap3/Operacoes/2_incluirInfo.h"

#define ESPACO 5

void desenhaArvoreBTreeRecursivo(pNohBTree raiz, FuncaoImpressao fi) {

   if (raiz == NULL){
       printf("?");
       return;
   }

   if (raiz->listaChavesValores == NULL ||
       raiz->listaChavesValores->quantidade == 0){
     printf("[ ?-? ]");
     return;
   }

   int i;
   printf("[ ");

   desenhaArvoreBTreeRecursivo(raiz->primeiroFilho, fi);

   for (i=0; i < raiz->listaChavesValores->quantidade; i++){
      pChaveValor pcv = buscarInfoPos(raiz->listaChavesValores, i+1);
      fi(pcv->chave);
      desenhaArvoreBTreeRecursivo(pcv->filhoMaior, fi);
   }

   printf(" ]");
}

void desenhaArvore(pDBTree arvore, FuncaoImpressao fi) {

    desenhaArvoreBTreeRecursivo(arvore->raiz, fi);

}

#endif
