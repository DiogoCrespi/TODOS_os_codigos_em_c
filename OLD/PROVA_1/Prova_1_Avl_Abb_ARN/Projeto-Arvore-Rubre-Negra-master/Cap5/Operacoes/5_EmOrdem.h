#ifndef EMORDEM_ARVORE_BINARIA_H
#define EMORDEM_ARVORE_BINARIA_H
#include "../ArvoreRubroNegra.h"
/* --------------------------*/
void EmOrdem(pNohArvore raiz, FuncaoImpressao fi)
{

    if (raiz != NULL)
    {

        EmOrdem(raiz->esquerda, fi);
        fi(raiz->info);
        EmOrdem(raiz->direita, fi);
    }
}

#endif
