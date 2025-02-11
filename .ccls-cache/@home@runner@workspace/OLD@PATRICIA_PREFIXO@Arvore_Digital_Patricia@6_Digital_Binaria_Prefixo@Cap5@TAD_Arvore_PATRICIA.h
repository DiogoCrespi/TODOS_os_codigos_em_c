#ifndef PATRICIA_TAD_H
#define PATRICIA_TAD_H
/*------------------------------------------*/
/* tipos de dados                           */
/*------------------------------------------*/
/* estrutura do noh da arvore */
typedef struct nohPatricia NohPatricia;
typedef NohPatricia *pNohPatricia;
/* descritor da arvore */
typedef struct dPatricia DPatricia;
typedef DPatricia *pDPatricia;
typedef void (*FuncaoImpressao)(void *);
/*------------------------------------------*/
/* operacoes                                */
/*------------------------------------------*/
pDPatricia criarArvorePatricia();

int adicionarChavePatricia(pDPatricia arvore, char *chave);

int removerChavePatricia(pDPatricia arvore, char *chave);

int buscarChavePatricia(pDPatricia arvore, char *chave);

//void desenharArvorePatricia(pDPatricia arvore);


#endif

