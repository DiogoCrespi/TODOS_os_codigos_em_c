#ifndef STRUCT_ARVORE_H
#define STRUCT_ARVORE_H
#include "../ArvoreAVL.h"
struct nohArvore{
   void*              info;
   struct nohArvore  *esquerda;
   struct nohArvore  *direita;
   int    fb;
};

#endif
