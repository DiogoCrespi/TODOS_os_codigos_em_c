#ifndef STRUCT_ARVORE_H
#define STRUCT_ARVORE_H

typedef struct nohPatricia
{
   int ehFolha;
   int indice;
   struct nohPatricia *esquerda;
   struct nohPatricia *direita;
   char *chave;
} NohPatricia;

#endif
