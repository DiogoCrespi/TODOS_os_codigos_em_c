#ifndef STRUCT_ARVORE_H
#define STRUCT_ARVORE_H
#include "../ArvoreRubroNegra.h"

#define RED         'R'
#define BLACK       'B'
#define DOUBLEBLACK 'W'


struct nohArvore{
   void*              info;
   struct nohArvore  *esquerda;
   struct nohArvore  *direita;

   char               cor;
   struct nohArvore  *pai;
};

#endif
