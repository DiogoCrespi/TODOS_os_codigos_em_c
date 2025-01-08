#include <stdio.h>
#include <stdlib.h>
#include "Utils.h"
#include "ArvoreRubroNegra.h"

pDArvore constroiArvore(int dados[], int tam){

    pDArvore arvore = criarArvore(2);
    int i;
    for(i=0; i<tam; i++){
        incluirInfo(arvore, alocaInt(dados[i]),comparaInt);
    }

    return arvore;
}



int main() {
       int ex1[]   = {5, 10, 3, 2};   // caso 1
       int ex1_1[] = {5, 3, 2};       // caso 2.1
       int ex1_2[] = {5, 10, 12};     // caso 2.2
       int ex1_3[] = {5, 3, 4};       // caso 2.3
       int ex2[]   = {5, 10, 3, 2, 12, 11};  // caso 1 e caso 2.3
       int ex3[]   = {5, 10, 3, 2, 7, 8};    // caso 2.2
       int ex4[]   = {5, 10, 3, 2, 14, 12};  // caso 2.4
       int ex5[]   = {8, 3, 21, 16, 27, 9, 18, 29, 10}; // varios
    int escolha;
    pDArvore arvore;
    int valor;
while (1) {
        printf("\n\n");
        printf("*****************************************\n");
        printf("* 1. Ex1 = {5, 10, 3, 2}                *\n");
        printf("* 2. Ex1_1 = {5, 3, 2}                  *\n");
        printf("* 3. Ex1_2 = {5, 10, 12};               *\n");
        printf("* 4. Ex1_3 = {5, 3, 4}                  *\n");
        printf("* 5. Ex2 = {5, 10, 3, 2, 12, 11}        *\n");
        printf("* 6. Ex3 = {5, 10, 3, 2, 7, 8};         *\n");
        printf("* 7. Ex4 = {5, 10, 3, 2, 14, 12};       *\n");
        printf("* 8. Ex5 = {8,3,21,16,27,9,18,29,10}    *\n");
        printf("* 9. Excluir valor da arvore            *\n");
        printf("* 10. Buscar valor na arvore            *\n");
        printf("* 0. Sair                               *\n");
        printf("*****************************************\n");

        printf("Opcao: ");
        scanf("%d", &escolha);

        if (escolha == 0) {
            printf("Saindo...\n");
            break;
        }

        int valor;

        switch (escolha) {
            case 1:
                system("cls");
                arvore = constroiArvore(ex1, 4);
                break;
            case 2:
                system("cls");
                arvore = constroiArvore(ex1_1, 3);
                break;
            case 3:
                system("cls");
                arvore = constroiArvore(ex1_2, 3);
                break;
            case 4:
                system("cls");
                arvore = constroiArvore(ex1_3, 3);
                break;
            case 5:
                system("cls");
                arvore = constroiArvore(ex2, 6);
                break;
            case 6:
                system("cls");
                arvore = constroiArvore(ex3, 6);
                break;
            case 7:
                system("cls");
                arvore = constroiArvore(ex4, 6);
                break;
            case 8:
                system("cls");
                arvore = constroiArvore(ex5, 9);
                break;
            case 9:
                arvore = constroiArvore(ex5, 9);
                printf("Digite o valor a ser excluido: ");
                scanf("%d", &valor);
                excluirInfo(arvore, alocaInt(valor), comparaInt);
                break;
            case 10:
                arvore = constroiArvore(ex5, 9);
                printf("Digite o valor a ser buscado: ");
                scanf("%d", &valor);
                pNohArvore resultado = buscarInfo(arvore, alocaInt(valor), comparaInt);
                if (resultado != NULL) {
                    printf("Valor %d encontrado na arvore.\n", valor);
                } else {
                    printf("Valor %d nao encontrado na arvore.\n", valor);
                }
                break;
            default:
                printf("Escolha invalida!\n");
                continue;
        }

        if (arvore != NULL) {
            printf("\n*****************************************\n");
            desenhaArvore(arvore, imprimeInt);
            printf("\n*****************************************\n");
        }
    }

    return 0;
}