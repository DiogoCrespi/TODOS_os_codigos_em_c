#ifndef EXCLUIRINFO_ARVORE_RUBRONRGRA_H
#define EXCLUIRINFO_ARVORE_RUBRONRGRA_H
#include "../ArvoreRubroNegra.h"
#include "../TAD_Arvore.h"
#include "../Utils.h"
pNohArvore excluirInfoRecursivo(pNohArvore raiz, pNohArvore sentinela, void *info, FuncaoComparacao pfc) {
    if (raiz == sentinela) {
        printf("Nó não encontrado.\n");
        return sentinela;
    }

    int comparacao = pfc(info, raiz->info);
    

    if (comparacao < 0) {
        raiz->esquerda = excluirInfoRecursivo(raiz->esquerda, sentinela, info, pfc);
    } else if (comparacao > 0) {
        raiz->direita = excluirInfoRecursivo(raiz->direita, sentinela, info, pfc);
    } else {
        
        if (raiz->esquerda == sentinela) {
            pNohArvore temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == sentinela) {
            pNohArvore temp = raiz->esquerda;
            free(raiz);
            return temp;
        }

        pNohArvore sucessor = raiz->direita;
        while (sucessor->esquerda != sentinela) {
            sucessor = sucessor->esquerda;
        }

        raiz->info = sucessor->info;
        raiz->direita = excluirInfoRecursivo(raiz->direita, sentinela, sucessor->info, pfc);
    }

    return raiz;
}

int excluirInfo(pDArvore arvore, void *info, FuncaoComparacao pfc) {
    printf("\n ----------- Excluindo info: %d ----------- \n", *((int *)info));
    arvore->raiz = excluirInfoRecursivo(arvore->raiz, arvore->sentinela, info, pfc);

    printf("\n -----------------------------------------");
    
    
    return 1;
}



#endif
