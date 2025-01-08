
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
// ----------------------------------------------------------
// ---- Definição dos tipos de dado -------------------------
// ----------------------------------------------------------
struct Pessoa {
   char *nome;
   int idade;
};

// ----------------------------------------------------------
// ---- Definição dos tipos de ponteiros para função---------
// ----------------------------------------------------------
typedef  int  (*FuncaoComparacao)   (void *, void *);
typedef  int  (*FuncaoPredicado)    (void *);
typedef  void (*FuncaoOperacao)     (void *);
typedef  void (*FuncaoPessoa)       (struct Pessoa);

// ----------------------------------------------------------
// --------- Assinaturas das funções ------------------------
// ----------------------------------------------------------

void bubbleSort(void* [], int, FuncaoComparacao);

void* encontrarMaior(void* [], int, FuncaoComparacao);

int contar(void* [], int, FuncaoPredicado);

void aplicarOperacao(void* [], int, FuncaoOperacao);

void identificarMenoresIdade(struct Pessoa [], int, FuncaoPessoa);


// ----------------------------------------------------------
// --------- implementação das funções descritas acima-------
// ----------------------------------------------------------



//-----------------------bubbleSort------------------
void bubbleSort(void* dados[], int tam, FuncaoComparacao pfc) {

    int   res, i, j, r;
    void  *temp;

    for (i=0; i<tam-1; i++){
       for (j=0; j<tam-(i+1); j++){
         r = pfc(dados[j],dados[j+1]);
         if (r<0){
            temp       = dados[j];
            dados[j]   = dados[j+1];
            dados[j+1] = temp;
         }
       }
    }
}

//----------------------encontrarMaior----------------------
void* encontrarMaior(void* dados[], int tam, FuncaoComparacao pfc){

  void *maior;
  maior = dados[0];
  int i;

  for(i=1; i<tam; i++){

    if (pfc(maior, dados[i]) > 0)
      maior = dados[i];

  }

   return maior;
}

//-------------------------contar------------------------------
int contar(void* dados[], int tam, FuncaoPredicado pfp){

   int i, cont=0;
   for (i=0; i<tam; i++){
     if (pfp(dados[i]) != 0)
        cont++;
   }
   return cont;
}

//--------------------aplicarOperacao--------------------
void aplicarOperacao(void* dados[], int tam, FuncaoOperacao pfo){
   for (int i = 0; i < tam; i++) {
        pfo(dados[i]);
    }
}

//-----------------identificaMenoresIdade----------------
void identificaMenoresIdade(struct Pessoa pessoas[], int tam, FuncaoPessoa pfp){
    for (int i = 0; i < tam; i++) {
        if (pessoas[i].idade < 18) {
            pfp(pessoas[i]);
        }
    }
}




//---------------------------------------------------------------
// --------- Função de comparação de inteiros ------------------
// --------------------------------------------------------------



int compararInteiros(void* a, void* b) {
    int* valorA = (int*)a;
    int* valorB = (int*)b;
    return (*valorA - *valorB);
}

void imprimirNomePessoaMenorIdade(struct Pessoa pessoa) {
    printf("Nome: %s Idade: %d\n", pessoa.nome, pessoa.idade);
}

int compararIdade(void* a, void* b) {
        struct Pessoa* pessoaA = (struct Pessoa*) a;
        struct Pessoa* pessoaB = (struct Pessoa*) b;
        return (pessoaB->idade - pessoaA->idade);
}


int serPar(void *info) {
  int *p = (int *)info;
  return (*p % 2 == 0);
}


void soma(void *info) {
  int *p = (int *)info;
  *p += 10;
}
