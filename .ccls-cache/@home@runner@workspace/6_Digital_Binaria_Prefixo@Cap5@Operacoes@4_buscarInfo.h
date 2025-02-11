#ifndef BUSCAR_INFO_PREFIXO_H
#define BUSCAR_INFO_PREFIXO_H

int buscarInfoPrefixoRecursivo (pNohPrefixo raiz, char chave[], int k, int* L)
{
    (*L)++; // incrementa pois iniciou em ZERO

     // caso base 1 - a chave é prefixo de outra chave
    if(raiz != NULL && *L == k){
        return 1;
    }

    // caso base 2 - outra chave é prefixo da chave sendo buscada
    if(raiz != NULL && raiz->terminal == 1 && *L < k){
       return 1;
    }


    // caso base 1 - a chave não foi encontrada na árvore
    if(raiz == NULL && *L <= k){
       return 0;
    }

    if (chave[*L] == '0'){
        return buscarInfoPrefixoRecursivo(raiz->esquerda, chave, k , L);
    }
    else {
        return buscarInfoPrefixoRecursivo(raiz->direita, chave, k , L);
    }
}


/* ----------------------------------------------------------*/
int buscarInfoPrefixo (pDPrefixo arvore, char chave[], int k)
{
    int L=-1;

    return buscarInfoPrefixoRecursivo(arvore->raiz, chave, k, &L);

}

#endif

