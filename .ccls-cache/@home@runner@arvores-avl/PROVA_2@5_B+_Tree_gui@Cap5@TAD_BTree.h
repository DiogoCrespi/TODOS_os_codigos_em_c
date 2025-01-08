#ifndef BTREE_TAD_H
#define BTREE_TAD_H

/*------------------------------------------*/
/* tipos de dados                           */
/*------------------------------------------*/

/* estrutura do noh da arvore B */
typedef struct chaveValor ChaveValor;
typedef ChaveValor*       pChaveValor;

/* estrutura do noh da arvore B */
typedef struct nohBTree NohBTree;
typedef NohBTree*        pNohBTree;

/* descritor da arvore B */
typedef struct dBTree  DBTree;
typedef DBTree*        pDBTree;

/* tipos referentes aos ponteiros para funcao */
typedef int  (*FuncaoComparacao)(void*, void*);
typedef void (*FuncaoImpressao)(void*);

/*------------------------------------------*/
/* operacoes                                */
/*------------------------------------------*/

pDBTree  criarBTree(int ordem);

int    incluirInfoBTree (pDBTree arvore, void* chave, void* valor, FuncaoComparacao pfc);
int    excluirInfoBTree (pDBTree arvore, void* chave, FuncaoComparacao pfc);
void*  buscarInfoBTree  (pDBTree arvore, void* chave, FuncaoComparacao pfc);

//void desenhaArvoreBTree(pDBTree arvore, FuncaoImpressao fi);

#endif
