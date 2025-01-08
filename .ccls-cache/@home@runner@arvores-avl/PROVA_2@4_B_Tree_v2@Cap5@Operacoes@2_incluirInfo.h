#ifndef INCLUIR_INFO_BTREE_H
#define INCLUIR_INFO_BTREE_H
#include "../BTree.h"
#include "../Utils.h"
#include "../../Cap3/Operacoes/2_incluirInfo.h"
#include "../../Cap3/Operacoes/2_3_incluirInfoOrdenada.h"
#include "12_desenhaArvore.h" 
//pNohBTree buscarInfoBTreeRecursivo(pNohBTree , void *, FuncaoComparacao);

//---------------------------------
int comparaChaveValor(void *info1, void *info2){
    pChaveValor  p1 = (pChaveValor) info1;
    pChaveValor  p2 = (pChaveValor) info2;
    return *((int*)(p2->chave)) - *((int*)(p1->chave));
}

//---------------------------------
pNohBTree criaNoh(){

    pNohBTree pNovo           = malloc(sizeof(NohBTree));
    pNovo->listaChavesValores = criarLista();
    pNovo->primeiroFilho      = NULL;
    pNovo->pai                = NULL;
    return pNovo;
}

//---------------------------------
ChaveValor* criaChaveValor(void* chave, void* valor, pNohBTree filhoMaior){

    ChaveValor* pcv = malloc(sizeof(struct chaveValor));
    pcv->chave      = chave;
    pcv->valor      = valor;
    pcv->filhoMaior = filhoMaior;
    return pcv;
}

/* --------------------------*/
int ehFolha(pNohBTree raiz){

   if(raiz == NULL)
      return 0;

   if(raiz->primeiroFilho != NULL)
      return 0;

   int i=1;
   while (i <= raiz->listaChavesValores->quantidade){

        pChaveValor pcv = buscarInfoPos(raiz->listaChavesValores, i);

        if(pcv->filhoMaior != NULL){
           return 0;
        }

        i++;
    }
    // eh folha, retorna 1 [true]
    return 1;
}

/* --------------------------*/
pChaveValor chaveAnterior(pDLista lista, void* chave, FuncaoComparacao pfc){
    pNoh atual = lista->primeiro;
    pNoh ant   = NULL;
    while (atual != NULL){
       pChaveValor pcv = (pChaveValor) atual->info;
       printf("Atual: %d - chave: %d \n", *((int*)pcv->chave), *((int*)chave));
       if(pfc(pcv->chave, chave) < 0){
           if (ant != NULL)
             return ant->info;

           return NULL;
       }

        ant   = atual;
        atual = atual->prox;
    }
    return ant->info;
}

/* --------------------------*/
pNohBTree incluirInfoBTreeRecursivo(pNohBTree raiz, int ordem, void* chave, void* valor, FuncaoComparacao pfc){

   // caso base 1 - �rvore n�o tem raiz
   if (raiz == NULL){
       pNohBTree novo  = criaNoh();
       ChaveValor *pcv = criaChaveValor(chave, valor, NULL);
       incluirInfoOrdenada(novo->listaChavesValores, pcv, comparaChaveValor);
       return novo;
   }

   pNohBTree novaRaiz = raiz;

   // caso baso 2 - a raiz � uma folha
   if(ehFolha(raiz) == 1){

      // verifica se a folha tem a chave
      int resultado = contemInfo(raiz->listaChavesValores, chave, pfc);
      if (resultado != 0)
          return NULL;  // retorna pois a chave j� est� na �rvore

      // faz a inclus�o da chave na �rvore
      ChaveValor *pcv = criaChaveValor(chave, valor, NULL);
      incluirInfoOrdenada(raiz->listaChavesValores, pcv, comparaChaveValor);
   }
   else {
     // caso recursivo
     pChaveValor anterior = chaveAnterior(raiz->listaChavesValores, chave, pfc);
     if (anterior == NULL)
         novaRaiz = incluirInfoBTreeRecursivo(raiz->primeiroFilho, ordem, chave, valor, pfc);
      else
         novaRaiz = incluirInfoBTreeRecursivo(anterior->filhoMaior, ordem, chave, valor, pfc);
   }

   // verifica se a chave foi encontrada na �rvore - novaRaiz == NULL
   if(novaRaiz == NULL)
      return NULL;

   // ap�s a inclus�o da chave na �rvore, verifica se a folha que recebeu a chave
   // n�o violou a regra de conter no m�ximo 2d+1 chaves
   if(raiz->listaChavesValores->quantidade > 2*ordem){

      // precisa particionar a raiz
      pNohBTree pai = raiz->pai;
      if(raiz->pai == NULL)
          pai   = criaNoh();

      pNohBTree irmao = criaNoh();

      raiz->pai  = pai;
      irmao->pai = pai;

      pChaveValor mediana = excluirInfoPos(raiz->listaChavesValores, ordem+1);
      incluirInfoOrdenada(pai->listaChavesValores, mediana, comparaChaveValor);
      pDLista listaIrmao = dividirLista(raiz->listaChavesValores, ordem);

    //  pChaveValor d2 = buscarInfoPos(listaIrmao, 1); // listaIrmao->primeiro->info
      irmao->primeiroFilho = mediana->filhoMaior;
      mediana->filhoMaior = irmao;
      irmao->listaChavesValores = listaIrmao;

      if (pai->listaChavesValores->quantidade == 1){
         pai->primeiroFilho = raiz;
      }

     return pai;

   }

   if (novaRaiz->pai == NULL)
       return novaRaiz;

   return novaRaiz->pai;
}

/* ----------------------------------------------------------*/
int incluirInfoBTree(pDBTree arvore, void *chave, void *valor, FuncaoComparacao pfc){

     desenhaArvore(arvore, imprimeInt);
     printf("\n ---> Incluindo ....: %d [ ", *((int*)chave));

     pNohBTree novaRaiz = incluirInfoBTreeRecursivo(arvore->raiz, arvore->ordem, chave, valor, pfc);
     if (novaRaiz == NULL){
        printf(" -->> Erro! Chave informada j� existe na �rvore!!! <<--");
     }
     else{
        arvore->raiz = novaRaiz;
     }

     printf(" ] \n\n");
     return 1;
}

#endif

