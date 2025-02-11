#ifndef INCLUIR_INFO_BTREE_H
#define INCLUIR_INFO_BTREE_H
#include "../BTree.h"
#include "../Utils.h"
#include "12_desenhaArvore.h"

// Retorna o par chave-valor anterior à chave fornecida
pChaveValor chaveAnterior(pDLista listaChavesValores, void *chave, FuncaoComparacao pfc) {
  pNoh atual = listaChavesValores->primeiro;
  pChaveValor chaveAnterior = NULL;

  while (atual && pfc(((pChaveValor)atual->info)->chave, chave) < 0) {
    chaveAnterior = (pChaveValor)atual->info;
    atual = atual->prox;
  }
  return chaveAnterior;
}

// Função para comparar dois pares chave-valor
int comparaChaveValor(void *info1, void *info2) {
  pChaveValor p1 = (pChaveValor)info1;
  pChaveValor p2 = (pChaveValor)info2;
  return *((int *)(p2->chave)) - *((int *)(p1->chave));
}

// Cria um novo nó da árvore B+
pNohBTree criaNoh(int ehFolha) {
  pNohBTree pNovo = (pNohBTree)malloc(sizeof(NohBTree));
  pNovo->listaChavesValores = criarLista();
  pNovo->primeiroFilho = NULL;
  pNovo->pai = NULL;
  pNovo->proxFolha = NULL;
  pNovo->ehFolha = ehFolha;
  return pNovo;
}

// Cria um novo par chave-valor
ChaveValor *criaChaveValor(void *chave, void *valor, pNohBTree filhoMaior) {
  ChaveValor *pcv = (ChaveValor *)malloc(sizeof(ChaveValor));
  pcv->chave = chave;
  pcv->valor = valor;
  pcv->filhoMaior = filhoMaior;
  return pcv;
}

// Verifica se o nó é folha
int ehFolha(pNohBTree raiz) { 
  return raiz != NULL && raiz->ehFolha; 
}

// Função recursiva para inserir informação na árvore B+
pNohBTree incluirInfoBTreeRecursivo(pNohBTree raiz, int ordem, void *chave, void *valor, FuncaoComparacao pfc) {
  // Caso base 1: Se a raiz é nula, cria um novo nó folha
  if (raiz == NULL) {
    // Cria um novo nó como folha
    pNohBTree novo = criaNoh(1);
    // Cria um par chave-valor
    ChaveValor *pcv = criaChaveValor(chave, valor, NULL);
    // Insere o par ordenadamente no nó
    incluirInfoOrdenada(novo->listaChavesValores, pcv, comparaChaveValor);
    // Retorna o novo nó criado como a raiz ou subárvore
    return novo;
  }

  // Caso base 2: Se o nó atual é uma folha
  if (ehFolha(raiz)) {
    // Verifica se a chave já existe no nó
    int resultado = contemInfo(raiz->listaChavesValores, chave, pfc);
    if (resultado != 0) // Chave já existe, nenhuma ação é necessária
      return NULL;

    // Cria um novo par chave-valor
    ChaveValor *pcv = criaChaveValor(chave, valor, NULL);
    // Insere o par ordenadamente no nó folha
    incluirInfoOrdenada(raiz->listaChavesValores, pcv, comparaChaveValor);
  } else {
    // Caso recursivo: Se o nó atual é interno
    // Localiza o filho apropriado para continuar a inserção
    pChaveValor anterior = chaveAnterior(raiz->listaChavesValores, chave, pfc);
    if (anterior == NULL) {
      // A chave é menor que todas as chaves do nó atual, vai para o primeiro filho
      raiz = incluirInfoBTreeRecursivo(raiz->primeiroFilho, ordem, chave, valor, pfc);
    } else {
      // A chave está entre duas chaves ou maior que todas, vai para o filho apropriado
      raiz = incluirInfoBTreeRecursivo(anterior->filhoMaior, ordem, chave, valor, pfc);
    }
  }

  // Verifica se o nó excedeu a capacidade permitida (2 * ordem)
  if (raiz->listaChavesValores->quantidade > 2 * ordem) {
    // Se o nó precisa ser dividido, cria o pai (se não existir) e o irmão
    pNohBTree pai = raiz->pai ? raiz->pai : criaNoh(0);
    pNohBTree irmao = criaNoh(raiz->ehFolha);

    // Atualiza os ponteiros de pai para os dois nós (atual e irmão)
    raiz->pai = pai;
    irmao->pai = pai;

    // Encontra a chave mediana e a remove do nó atual
    pChaveValor mediana = (pChaveValor)excluirInfoPos(raiz->listaChavesValores, ordem + 1);
    // Insere a chave mediana no pai
    incluirInfoOrdenada(pai->listaChavesValores, mediana, comparaChaveValor);

    // Divide a lista de chaves e valores entre o nó atual e o irmão
    pDLista listaIrmao = dividirLista(raiz->listaChavesValores, ordem);
    irmao->listaChavesValores = listaIrmao;

    if (raiz->ehFolha) {
      // Se o nó é folha, ajusta o encadeamento entre folhas
      irmao->proxFolha = raiz->proxFolha;
      raiz->proxFolha = irmao;
    } else {
      // Se o nó é interno, ajusta os ponteiros para os filhos
      irmao->primeiroFilho = mediana->filhoMaior;
      mediana->filhoMaior = irmao;
    }

    if (pai->listaChavesValores->quantidade == 1) {
      // Se o pai é um novo nó, atualiza seu primeiro filho
      pai->primeiroFilho = raiz;
    }
    // Retorna o nó pai atualizado após a divisão
    return pai;
  }

  // Retorna a raiz atualizada ou o pai, se existente
  return raiz->pai ? raiz->pai : raiz;
}

// Função principal para incluir informação na árvore
int incluirInfoBTree(pDBTree arvore, void *chave, void *valor, FuncaoComparacao pfc) {
  desenhaArvore(arvore, imprimeInt);
  printf("\n ---> Incluindo ....: %d [ ", *((int *)chave));

  pNohBTree novaRaiz = incluirInfoBTreeRecursivo(arvore->raiz, arvore->ordem, chave, valor, pfc);
  arvore->raiz = novaRaiz;
  printf(" ] \n");
  return 1;
}

#endif //INCLUIR_INFO_BTREE_H
