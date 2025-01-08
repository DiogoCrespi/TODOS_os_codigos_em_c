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

// Função de comparação da chave para o Produto (baseada no código)
int comparaChaveProduto(void *info1, void *info2){
    int    *p1 = (int *) info1;
    int    *p2 = (int *) info2;
    return *p2 - *p1;
}

// Função para alocar um produto
struct Produto* alocaProduto(int cod, char nome[], float preco){
    struct Produto *pp = malloc(sizeof(struct Produto));
    pp->codigo = cod;
    strcpy(pp->nome, nome);
    pp->preco = preco;

    return pp;
}


// int main(){
//     // Define a ordem da árvore B
//     pDBTree bTreeProduto = criarBTree(2);

//     // Teste de inclusão
//     incluirInfoBTree(bTreeProduto, alocaInt(6),  alocaProduto( 6, "Pao de Queijo", 2.50), comparaChaveProduto);
//     incluirInfoBTree(bTreeProduto, alocaInt(3),  alocaProduto( 3, "Cappucino com canela", 4.00), comparaChaveProduto);
//     incluirInfoBTree(bTreeProduto, alocaInt(10), alocaProduto(10, "Hamburgao", 6.00), comparaChaveProduto);
//     incluirInfoBTree(bTreeProduto, alocaInt(7),  alocaProduto( 7, "Tubaina", 5.00), comparaChaveProduto);
//     incluirInfoBTree(bTreeProduto, alocaInt(1),  alocaProduto( 1, "Farofa", 7.00), comparaChaveProduto);
//     incluirInfoBTree(bTreeProduto, alocaInt(2),  alocaProduto( 2, "Suco de Laranja", 6.00), comparaChaveProduto);
//     incluirInfoBTree(bTreeProduto, alocaInt(12), alocaProduto(12, "Pastel de carne com ovo", 6.00), comparaChaveProduto);
//     incluirInfoBTree(bTreeProduto, alocaInt(4),  alocaProduto( 4, "Picanha", 65.00), comparaChaveProduto);
//     incluirInfoBTree(bTreeProduto, alocaInt(8),  alocaProduto( 8, "Coca-Cola", 8.00), comparaChaveProduto);
//     incluirInfoBTree(bTreeProduto, alocaInt(11), alocaProduto(11, "Coracaozinho", 20.00), comparaChaveProduto);
//     incluirInfoBTree(bTreeProduto, alocaInt(5),  alocaProduto( 5, "Sprite", 7.00), comparaChaveProduto);

//     incluirInfoBTree(bTreeProduto, alocaInt(15), alocaProduto(15, "Produto X", 7.00), comparaChaveProduto);
//     incluirInfoBTree(bTreeProduto, alocaInt(9),  alocaProduto( 9, "Produto Y", 7.00), comparaChaveProduto);
//     incluirInfoBTree(bTreeProduto, alocaInt(20), alocaProduto(20, "Produto Z", 7.00), comparaChaveProduto);
//     incluirInfoBTree(bTreeProduto, alocaInt(18), alocaProduto(18, "Produto N", 7.00), comparaChaveProduto);
//     incluirInfoBTree(bTreeProduto, alocaInt(30), alocaProduto(30, "Produto M", 7.00), comparaChaveProduto);
//     incluirInfoBTree(bTreeProduto, alocaInt(17), alocaProduto(17, "Produto K", 7.00), comparaChaveProduto);
//     incluirInfoBTree(bTreeProduto, alocaInt(16), alocaProduto(16, "Produto L", 7.00), comparaChaveProduto);
//     printf("\n---------------------------------\n");
//     int chaveExcluir1 = 6;  // Produto "Pao de Queijo"
//     int chaveExcluir2 = 10; // Produto "Hamburgao"
//     int chaveExcluir3 = 4;  // Produto "Picanha"


       
        // printf("\n\n ---------------------------------------------- \n");

        //         printf("\n\n --- Arvore antes da exclusão --- \n\n");
        //         desenhaArvore(bTreeProduto, imprimeInt);
               
        //         printf("\n\n --- Excluindo os produtos de codigo %d, %d e %d --- \n\n", chaveExcluir1, chaveExcluir2, chaveExcluir3);

        //         excluirInfoBTree(bTreeProduto, alocaInt(chaveExcluir1), comparaChaveProduto);
        //         excluirInfoBTree(bTreeProduto, alocaInt(chaveExcluir2), comparaChaveProduto);
        //         excluirInfoBTree(bTreeProduto, alocaInt(chaveExcluir3), comparaChaveProduto);

        //         printf("\n\n --- Arvore apos a exclusão --- \n\n");
        //         desenhaArvore(bTreeProduto, imprimeInt);
        //       return 0;
        //       }

int main() {
    pDBTree bTreeProduto = criarBTree(2);

    // Teste de inclusão de produtos
    incluirInfoBMais(bTreeProduto, alocaInt(6),  alocaProduto(6, "Pao de Queijo", 2.50), comparaChaveProduto);
    incluirInfoBMais(bTreeProduto, alocaInt(3),  alocaProduto(3, "Cappucino com canela", 4.00), comparaChaveProduto);
    incluirInfoBMais(bTreeProduto, alocaInt(10), alocaProduto(10, "Hamburgao", 6.00), comparaChaveProduto);
    incluirInfoBMais(bTreeProduto, alocaInt(7),  alocaProduto(7, "Tubaina", 5.00), comparaChaveProduto);
    incluirInfoBMais(bTreeProduto, alocaInt(1),  alocaProduto(1, "Farofa", 7.00), comparaChaveProduto);
    incluirInfoBMais(bTreeProduto, alocaInt(2),  alocaProduto(2, "Suco de Laranja", 6.00), comparaChaveProduto);
    incluirInfoBMais(bTreeProduto, alocaInt(12), alocaProduto(12, "Pastel de carne com ovo", 6.00), comparaChaveProduto);
    incluirInfoBMais(bTreeProduto, alocaInt(4),  alocaProduto(4, "Picanha", 65.00), comparaChaveProduto);
    incluirInfoBMais(bTreeProduto, alocaInt(8),  alocaProduto(8, "Coca-Cola", 8.00), comparaChaveProduto);
    incluirInfoBMais(bTreeProduto, alocaInt(11), alocaProduto(11, "Coracaozinho", 20.00), comparaChaveProduto);
    incluirInfoBMais(bTreeProduto, alocaInt(5),  alocaProduto(5, "Sprite", 7.00), comparaChaveProduto);
    incluirInfoBMais(bTreeProduto, alocaInt(15), alocaProduto(15, "Produto X", 7.00), comparaChaveProduto);
    incluirInfoBMais(bTreeProduto, alocaInt(9),  alocaProduto(9, "Produto Y", 7.00), comparaChaveProduto);
    incluirInfoBMais(bTreeProduto, alocaInt(20), alocaProduto(20, "Produto Z", 7.00), comparaChaveProduto);

    // Teste de busca
    int chaveBusca = 10;
    printf("\nBuscando produto com código %d\n", chaveBusca);

    void* produto = buscarChaveBTree(bTreeProduto->raiz, alocaInt(chaveBusca), comparaChaveProduto);

    if (produto != NULL) {
        struct Produto* p = (struct Produto*)produto;
        printf("Produto encontrado: %s, %.2f\n", p->nome, p->preco);
    } else {
        printf("Produto não encontrado!\n");
    }

    // Excluir produtos
    int chavesExcluir[] = {6, 10, 4};

    printf("\n\n --- Arvore antes da exclusão --- \n\n");
    desenhaArvore(bTreeProduto, imprimeInt);

    printf("\n --- Excluindo os produtos de codigo 6, 10 e 4 --- \n");
    for (int i = 0; i < 3; i++) {
        printf("Excluindo chave %d...\n", chavesExcluir[i]);
            excluirInfoBTree(bTreeProduto, alocaInt(chavesExcluir[i]), comparaChaveProduto);
    }

    printf("\n\n --- Arvore apos a exclusão --- \n\n");
    desenhaArvore(bTreeProduto, imprimeInt);

    return 0;
}





    