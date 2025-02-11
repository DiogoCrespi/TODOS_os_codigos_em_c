#ifndef PREFIXO_TAD_H
#define PREFIXO_TAD_H
/*------------------------------------------*/
/* tipos de dados                           */
/*------------------------------------------*/
/* estrutura do noh da arvore */
typedef struct nohPrefixo  NohPrefixo;
typedef NohPrefixo*        pNohPrefixo;

/* descritor da arvore */
typedef struct dPrefixo  DPrefixo;
typedef DPrefixo*        pDPrefixo;

/*------------------------------------------*/
/* operacoes                                */
/*------------------------------------------*/
pDPrefixo  criarArvorePrefixo();

int  incluirInfoPrefixo (pDPrefixo, char[], int);
int  excluirInfoPrefixo (pDPrefixo, char[], int);
int  buscarInfoPrefixo  (pDPrefixo, char[], int);

void desenhaArvorePrefixo(pDPrefixo);

#endif

