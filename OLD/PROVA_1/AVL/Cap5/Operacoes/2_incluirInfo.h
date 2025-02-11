#ifndef CRIAR_ARVORE_BINARIA_H
#define CRIAR_ARVORE_BINARIA_H
#include "../ArvoreAVL.h"

//---------------------------------------
pNohArvore rotacaoDireita(pNohArvore raiz) {
    pNohArvore u;
    u = raiz->esquerda;
    raiz->esquerda = u->direita;
    u->direita = raiz;
    return u;
}

//---------------------------------------
pNohArvore rotacaoEsquerda(pNohArvore raiz) {
    pNohArvore u;
    u = raiz->direita;
    raiz->direita = u->esquerda;
    u->esquerda = raiz;
    return u;
}

//---------------------------------------
pNohArvore rotacaoEsquerdaDireita(pNohArvore raiz) {
    raiz->esquerda = rotacaoEsquerda(raiz->esquerda);
    return rotacaoDireita(raiz);
}

//---------------------------------------
pNohArvore rotacaoDireitaEsquerda(pNohArvore raiz) {
    raiz->direita = rotacaoDireita(raiz->direita);
    return rotacaoEsquerda(raiz);
}

/* -------------------------- */
pNohArvore incluirInfoRecursivo(pNohArvore raiz, void *info, FuncaoComparacao pfc) {
       if (raiz == NULL) {       
           pNohArvore pnh = (pNohArvore) malloc(sizeof(NohArvore)); 
           pnh->info = info;
           pnh->esquerda = NULL;
           pnh->direita = NULL;
           pnh->fb = 0;
           return pnh;
       }
   if (pfc(raiz->info, info) <= 0) {
       raiz->esquerda = incluirInfoRecursivo(raiz->esquerda, info, pfc);
   } else {
       raiz->direita = incluirInfoRecursivo(raiz->direita, info, pfc);
   }
   raiz->fb = (alturaRecursiva(raiz->direita) - alturaRecursiva(raiz->esquerda));

   if (raiz->fb == 2 || raiz->fb == -2) {
       if (raiz->fb == 2) {
           if (raiz->direita->fb >= 0) {
               return rotacaoEsquerda(raiz);
           } else {
               return rotacaoDireitaEsquerda(raiz);  
           }
       } else if (raiz->fb == -2) {
           if (raiz->esquerda->fb <= 0) {
               return rotacaoDireita(raiz);  
           } else {
               return rotacaoEsquerdaDireita(raiz);  
           }
       }
   }

   return raiz;
}

/* ---------------------------------------------------------- */
void incluirInfo(pDArvore arvore, void *info, FuncaoComparacao pfc) {
    printf(" --- Incluindo info: %d ---\n", *((int*)info));
    arvore->raiz = incluirInfoRecursivo(arvore->raiz, info, pfc);
}

#endif
