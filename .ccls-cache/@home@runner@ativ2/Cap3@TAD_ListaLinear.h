#ifndef LISTA_TAD_H
#define LISTA__TAD_H
/*------------------------------------------*/
/* tipos de dados                           */
/*------------------------------------------*/
typedef struct noh  Noh;
typedef Noh*        pNoh;

/* descritor da lista */
typedef struct dLista  DLista;
typedef DLista*        pDLista;

/* 3 tipos que representam ponteiros para funcao */
typedef int   (*FuncaoComparacao_lista)(void *, void *);
typedef void  (*FuncaoImpressao_lista) (void *);
typedef void* (*FuncaoAlocacao_lista)  (void *);
typedef void  (*FuncaoLiberacao_lista)  (void *);

/*------------------------------------------*/
/* operacoes                                */
/*------------------------------------------*/
pDLista  criarLista       ();

void     incluirInfo_lista      (pDLista, void *);
void     incluirInfoInicio_lista(pDLista, void *);
void     incluirInfoNoMeio_lista(pDLista, void *, int);

int      excluirInfo_lista      (pDLista, void *, FuncaoComparacao_lista);
//int      excluirInfoEx3   (pDLista, void *, FuncaoComparacao_lista, FuncaoLiberacao_lista);

int      contemInfo_lista       (pDLista, void *, FuncaoComparacao_lista);
void     imprimirLista    (pDLista, FuncaoImpressao_lista);

void     destruirLista        (pDLista);
void     destruirListaNormal  (pDLista);
void     destruirListaInfo    (pDLista, FuncaoLiberacao_lista);

pDLista  duplicarLista    (pDLista, FuncaoAlocacao_lista);

/* o parametro int estabelece a posicao da lista onde a divisao deve acontecer */
pDLista  dividirLista     (pDLista, int);

pDLista  unirListas     (pDLista, pDLista, FuncaoComparacao_lista);

void*    buscarNohInfo_lista    (pDLista, void*, FuncaoComparacao_lista);
void*    buscarInfoPos_lista    (pDLista, int);

#endif

