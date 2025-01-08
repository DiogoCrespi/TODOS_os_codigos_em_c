#ifndef ARVORE_RUBRO_NEGRA_H
#define ARVORE_RUBRO_NEGRA_H

#include <stdio.h>
#include <stdlib.h>

typedef enum { VERMELHO, PRETO } Cor;

typedef struct NoRubroNegra {
    int valor;
    Cor cor;
    struct NoRubroNegra *esquerda, *direita, *pai;
} NoRubroNegra, *pNoRubroNegra;

typedef struct {
    pNoRubroNegra raiz;
} ArvoreRubroNegra, *pArvoreRubroNegra;



/* tipos referentes aos ponteiros para funcao */
typedef int  (*FuncaoComparacao)(void*, void*);
typedef void (*FuncaoImpressao)(int);


pNoRubroNegra criarNo(int valor);
pArvoreRubroNegra criarArvoreRubroNegra();
void rotacaoEsquerda(pArvoreRubroNegra arvore, pNoRubroNegra no);
void rotacaoDireita(pArvoreRubroNegra arvore, pNoRubroNegra no);
void corrigirInsercao(pArvoreRubroNegra arvore, pNoRubroNegra no);
void inserirArvoreRubroNegra(pArvoreRubroNegra arvore, int valor);
void desenhaArvoreRubroNegra(pNoRubroNegra raiz);

#endif // ARVORE_RUBRO_NEGRA_H
