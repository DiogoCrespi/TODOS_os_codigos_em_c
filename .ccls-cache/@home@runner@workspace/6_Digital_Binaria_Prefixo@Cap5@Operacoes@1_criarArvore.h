#ifndef CRIAR_ARVORE_PREFIXO_H
#define CRIAR_ARVORE_PREFIXO_H

#include <stdlib.h>

//---------------------------------
pNohPrefixo criarNohPrefixo(int terminal){

    pNohPrefixo pNovo = malloc(sizeof(NohPrefixo));
    pNovo->terminal   = terminal;
    pNovo->esquerda   = NULL;
    pNovo->direita    = NULL;
    return pNovo;
}


/* --------------------------*/
pDPrefixo criarArvorePrefixo(){

    pDPrefixo dPref = malloc(sizeof(DPrefixo));
    dPref->raiz     = criarNohPrefixo(0);   // a raiz não armazena chave
    dPref->quantidadeNohs = 1;

    return dPref;
};

#endif
