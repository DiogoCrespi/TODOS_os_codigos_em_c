#ifndef INCLUIR_INFO_RUBRO_NEGRA_H
#define INCLUIR_INFO_RUBRO_NEGRA_H
#include "../ArvoreRubroNegra.h"

//----------------------------------
pNohArvore rotacaoDireita(pNohArvore raiz){

    return NULL;
}

//----------------------------------
pNohArvore rotacaoEsquerda(pNohArvore raiz){

    return NULL;
}


//----------------------------------
pNohArvore rotacaoDireitaEsquerda(pNohArvore raiz){

    return NULL;
}

//----------------------------------
pNohArvore rotacaoEsquerdaDireita(pNohArvore raiz){

    return NULL;
}

//----------------------------------
pNohArvore tio(pNohArvore raiz){
    if (raiz == NULL)
        return NULL;

    // e a raiz principal da arvore
    if (raiz->pai == NULL)
        return NULL;

    if (raiz->pai->pai == NULL)
        return NULL;

    if (raiz->pai->pai->direita == raiz->pai)
        return raiz->pai->pai->esquerda;

    return raiz->pai->pai->direita;
}

/* ---------------------------------------------------------------------*/
pNohArvore incluirInfoRecursivo(pNohArvore raiz, pNohArvore sentinela, void *info, FuncaoComparacao pfc){

    // caso base
    if (raiz == NULL || raiz == sentinela){
       raiz = malloc(sizeof(NohArvore));
       raiz->info     = info;
       raiz->esquerda = sentinela;
       raiz->direita  = sentinela;
       raiz->cor      = RED;
       raiz->pai      = NULL; // sera tratado no caso recursivo
       return raiz;
    }
    else{

       pNohArvore filho;

       /* caso recursivo */
       if (pfc(info, raiz->info) >= 0){
           filho = incluirInfoRecursivo(raiz->esquerda, sentinela, info, pfc);

           filho->pai     = raiz;
           raiz->esquerda = filho;
           // verifica se houve rotacao, a� mudou a raiz
           // .....
        }
        else {
           filho = incluirInfoRecursivo(raiz->direita, sentinela, info, pfc);

           filho->pai = raiz;
           raiz->direita = filho;
           // verifica se houve rota�o, a� mudou a raiz
           // .....
        }

        if (raiz->pai == NULL){
            // � a raiz da �rvore, tem que ser BLACK
            raiz->cor = BLACK;
            return raiz;
        }

        // verifica a cor do pai
        if (raiz->cor == BLACK ||
            (raiz->cor == RED && filho->cor == BLACK)){
            // n�o precisa fazer nada, n�o tem como violar alguma das regras
             return raiz;
        }

         // problema!!!!

         // ----------------------------------------------
        // caso 1: verifica se ambos o pai e o tio s�o RED,
        //         muda a cor de ambos para BLACK e a cor do
        //         av� para RED
        // ----------------------------------------------
        pNohArvore titio = tio(filho);
        if (titio != NULL && titio->cor == RED){
            raiz->cor      = BLACK;
            titio->cor     = BLACK;
            raiz->pai->cor = RED;
        }

        // ----------------------------------------------
        // Caso 2: pai RED e tio BLACK
        if (titio != NULL && titio->cor == BLACK){

            // S�o 4 casos que requerem rota�es.


        }

    }
    return raiz;
}

/* ----------------------------------------------------------*/
void incluirInfo(pDArvore arvore, void *info, FuncaoComparacao pfc){

    printf("\n ---- Incluindo info: %d ----\n", *((int*)info));
    arvore->raiz      = incluirInfoRecursivo(arvore->raiz, arvore->sentinela, info, pfc);
    arvore->raiz->cor = BLACK;
    arvore->quantidadeNohs++;

   // printf("\n -----------------------------------------");
    desenhaArvore(arvore, imprimeInt);
  //  printf("\n ----------------------------------------- \n");
}

#endif

