#ifndef STRUCT_ARVORE_RUBRO_H
#define STRUCT_ARVORE_RUBRO_H
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
