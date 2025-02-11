#ifndef INCLUIR_INFO_PREFIXO_H
#define INCLUIR_INFO_PREFIXO_H

int buscarInfoPrefixo (pDPrefixo, char [], int);

/* --------------------------*/
pNohPrefixo incluirInfoPrefixoRecursivo(pNohPrefixo raiz, char chave[], int k, int* L){

  pNohPrefixo novo;

  (*L)++;

  // caso base - todos os dígitos foram colocados na árvore
  if (*L == k){

     novo = criarNohPrefixo(1);   // cria um terminal
     return novo;
  }

   if (raiz == NULL){
     // cria um novo nóh interno para acomodar o próximo dígito da chave
     novo = criarNohPrefixo(0);
     if (chave[*L] == '0'){
         // próximo símbolo da chave, pois L começou com ZERO
         novo->esquerda = incluirInfoPrefixoRecursivo(novo->esquerda, chave, k, L);
     }
     else {
        novo->direita = incluirInfoPrefixoRecursivo(novo->direita, chave, k, L);
     }

     return novo;
  }

  // caso recursivo
  if (chave[*L] == '0'){
     raiz->esquerda = incluirInfoPrefixoRecursivo(raiz->esquerda, chave, k, L);
  }
  else{
    raiz->direita = incluirInfoPrefixoRecursivo(raiz->direita, chave, k, L);
  }

  return raiz;

}

/* ----------------------------------------------------------*/
int incluirInfoPrefixo (pDPrefixo arvore, char chave[], int k){

   int L=-1;

   printf("\n Buscando a chave: %s", chave);
   int r = buscarInfoPrefixo(arvore, chave, k);  // verifica também se é prefixo

   printf("\n Achou chave ou prefixo= %d \n", r);
   if (r == 0){
      // a raiz da árvore não deve ser alterada devido a uma inclusão
      incluirInfoPrefixoRecursivo(arvore->raiz, chave, k, &L);
      return 1;
   }

   return 0;
}

#endif

