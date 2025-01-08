#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Utils.h"
#include "BTree.h"

struct Produto{
   int   codigo;
   char  nome[50];
   float preco;
};
int comparaChaveProduto(void *info1, void *info2) {
    int *p1 = (int *)info1;
    int *p2 = (int *)info2;
    return *p1 - *p2; 
}
struct Produto* alocaProduto(int cod, char nome[], float preco){
    struct Produto *pp = malloc(sizeof(struct Produto));
    pp->codigo = cod;
    strcpy(pp->nome, nome);
    pp->preco = preco;

    return pp;
}

int main(){
    pDBTree bTreeProduto = criarBTree(2);

    /* Teste de inclusao de produtos */
     incluirInfoBTree(bTreeProduto, alocaInt(6),  alocaProduto( 6, "Pao de Queijo", 2.50), comparaChaveProduto);
    incluirInfoBTree(bTreeProduto, alocaInt(3),  alocaProduto( 3, "Cappucino com canela", 4.00), comparaChaveProduto);
    incluirInfoBTree(bTreeProduto, alocaInt(10), alocaProduto(10, "Hamburgao", 6.00), comparaChaveProduto);
    incluirInfoBTree(bTreeProduto, alocaInt(7),  alocaProduto( 7, "Tubaina", 5.00), comparaChaveProduto);
    incluirInfoBTree(bTreeProduto, alocaInt(1),  alocaProduto( 1, "Farofa", 7.00), comparaChaveProduto);
    incluirInfoBTree(bTreeProduto, alocaInt(2),  alocaProduto( 2, "Suco de Laranja", 6.00), comparaChaveProduto);
    incluirInfoBTree(bTreeProduto, alocaInt(12), alocaProduto(12, "Pastel de carne com ovo", 6.00), comparaChaveProduto);
    incluirInfoBTree(bTreeProduto, alocaInt(4),  alocaProduto( 4, "Picanha", 65.00), comparaChaveProduto);
    incluirInfoBTree(bTreeProduto, alocaInt(8),  alocaProduto( 8, "Coca-Cola", 8.00), comparaChaveProduto);
    incluirInfoBTree(bTreeProduto, alocaInt(11), alocaProduto(11, "Coracaozinho", 20.00), comparaChaveProduto);
    incluirInfoBTree(bTreeProduto, alocaInt(5),  alocaProduto( 5, "Sprite", 7.00), comparaChaveProduto);

    incluirInfoBTree(bTreeProduto, alocaInt(15), alocaProduto(15, "Produto X", 7.00), comparaChaveProduto);
    incluirInfoBTree(bTreeProduto, alocaInt(9),  alocaProduto( 9, "Produto Y", 7.00), comparaChaveProduto);
    incluirInfoBTree(bTreeProduto, alocaInt(20), alocaProduto(20, "Produto Z", 7.00), comparaChaveProduto);
    incluirInfoBTree(bTreeProduto, alocaInt(18), alocaProduto(18, "Produto N", 7.00), comparaChaveProduto);
    incluirInfoBTree(bTreeProduto, alocaInt(30), alocaProduto(30, "Produto M", 7.00), comparaChaveProduto);
    incluirInfoBTree(bTreeProduto, alocaInt(17), alocaProduto(17, "Produto K", 7.00), comparaChaveProduto);
    incluirInfoBTree(bTreeProduto, alocaInt(16), alocaProduto(16, "Produto L", 7.00), comparaChaveProduto);


    printf("\n --- Arvore final apos inclusao --- \n");
    desenhaArvore(bTreeProduto, imprimeInt);

    // Teste de busca
    printf("\n --- Busca pelo produto com codigo 15 --- \n\n");
    struct Produto* produtoBuscado = buscarInfoBTree(bTreeProduto, alocaInt(15), comparaChaveProduto);
    if (produtoBuscado != NULL) {
        struct Produto* p = (struct Produto*)produtoBuscado;
        printf("Produto: %s, Codigo: %d, Preco: %.2f\n", p->nome, p->codigo, p->preco);
    } else {
        printf("Produto com codigo 15 nao encontrado.\n");
    }

    // Teste de exclusao
    printf("\n --- Exclusao do produto com codigo 9 --- ");
    excluirInfoBTree(bTreeProduto, alocaInt(9), comparaChaveProduto); 

    printf("\n --- Arvore apos exclusao do codigo 9 --- \n");
    desenhaArvore(bTreeProduto, imprimeInt);

    return 0;

}
