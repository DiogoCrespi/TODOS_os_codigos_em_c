#include <stdio.h>
#include "Utils.h"
#include "ArvoreAVL.h"

pDArvore constroiArvore(int dados[], int tam) {
    pDArvore arvore = criarArvore(2);
    int i;
    for (i = 0; i < tam; i++) {
        incluirInfo(arvore, alocaInt(dados[i]), comparaInt);
    }
    return arvore;
}

int main() {
    int ex1[] = {5, 10, 3, 7, 6};             // rotacao simples - direita
    int ex2[] = {5, 10, 3, 12, 14};           // rotacao simples - esquerda
    int ex3[] = {5, 10, 3, 7, 8};             // rotacao dupla - esquerda/direita
    int ex4[] = {5, 10, 3, 4, 12, 9, 14, 13}; // rotacao dupla - direita/esquerda
    int ex5[] = {5, 10, 3, 4, 12, 9, 14};     // Nao precisa rotacionar

    int escolha;

    while (1) {
        printf("\n\n");
        printf("****************************************\n");
        printf("* 1. Rotacao simples - direita         *\n");
        printf("* 2. Rotacao simples - esquerda        *\n");
        printf("* 3. Rotacao dupla - esquerda/direita  *\n");
        printf("* 4. Rotacao dupla - direita/esquerda  *\n");
        printf("* 5. Nao precisa rotacionar            *\n");
        printf("* 6. Excluir valor na arvore           *\n");
        printf("* 7. Buscar valor na arvore            *\n");
        printf("* 8. Exibir em ordem                   *\n");
        printf("* 9. Exibir em pre-ordem               *\n");
        printf("* 10. Exibir em pos-ordem              *\n");
        printf("* 11. Quantidade de folhas na arvore   *\n");
        printf("* 12. Altura da arvore                 *\n");
        printf("* 13. Quantidade de nos na arvore      *\n");
        printf("* 14. Balancear a arvore               *\n");
        printf("* 15. Recalcular fator de balanceamento*\n");
        printf("* 0. Sair                              *\n");
        printf("****************************************\n");

        printf("Opcao: ");
        scanf("%d", &escolha);

        if (escolha == 0) {
            printf("Saindo...\n");
            break;
        }

        pDArvore arvore;
        int valor;

        switch (escolha) {
            case 1:
                system("cls");
                printf("\nExemplo 1: Rotacao simples - direita\n");
                arvore = constroiArvore(ex1, 5);
                break;
            case 2:
                system("cls");
                printf("\nExemplo 2: Rotacao simples - esquerda\n");
                arvore = constroiArvore(ex2, 5);
                break;
            case 3:
                system("cls");
                printf("\nExemplo 3: Rotacao dupla - esquerda/direita\n");
                arvore = constroiArvore(ex3, 5);
                break;
            case 4:
                system("cls");
                printf("\nExemplo 4: Rotacao dupla - direita/esquerda\n");
                arvore = constroiArvore(ex4, 8);
                break;
            case 5:
                system("cls");
                printf("\nExemplo 5: Nao precisa rotacionar\n");
                arvore = constroiArvore(ex5, 7);
                break;
            case 6:
                system("cls");
                arvore = constroiArvore(ex5, 7);
                desenhaArvore(arvore, imprimeInt);
                printf("\nex5[] = {5, 10, 3, 4, 12, 9, 14}");
                printf("\nDigite o valor a ser excluido: ");
                scanf("%d", &valor);
               
                if (excluirInfo(arvore, &valor, comparaInt)) {
                    printf("Valor %d excluido da arvore.\n", valor);
                } else {
                    printf("Valor %d nao encontrado para exclusao.\n", valor);
                }
                    break;
            case 7:
                system("cls");
                printf("\nex5[] = {5, 10, 3, 4, 12, 9, 14}");
                printf("\nDigite o valor a ser buscado: ");
                scanf("%d", &valor);
                arvore = constroiArvore(ex5, 7);
                pNohArvore resultadoBusca = buscarInfo(arvore, &valor, comparaInt);
                if (resultadoBusca != NULL) {
                    printf("Valor %d encontrado na arvore.\n", valor);
                } else {
                    printf("Valor %d nao encontrado na arvore.\n", valor);
                }
                    break;
            case 8:
                system("cls");
                printf("\nExibindo em ordem:\n");
                arvore = constroiArvore(ex5, 7);
                emOrdem(arvore->raiz, imprimeInt);
                printf("\n");
                break;

            case 9:
                system("cls");
                printf("\nExibindo em pre-ordem:\n");
                arvore = constroiArvore(ex5, 7);
                preOrdem(arvore->raiz, imprimeInt);
                printf("\n");
                break;

            case 10:
                system("cls");
                printf("\nExibindo em pos-ordem:\n");
                arvore = constroiArvore(ex5, 7);
                posOrdem(arvore->raiz, imprimeInt);
                printf("\n");
                break;
            case 11:
                system("cls");
                printf("\nQuantidade de folhas na arvore:\n");
                arvore = constroiArvore(ex5, 7);
                printf("%d folhas\n", quantidadeFolhas(arvore));
                break;

            case 12:
                system("cls");
                printf("\nAltura da arvore:\n");
                arvore = constroiArvore(ex5, 7);
                printf("%d\n", altura(arvore));
                break;

            case 13:
                system("cls");
                printf("\nQuantidade de nos na arvore:\n");
                arvore = constroiArvore(ex5, 7);
                printf("%d nos\n", quantidadeNohs(arvore));
                break;

            case 14:
                system("cls");
                arvore = constroiArvore(ex5, 7);
                desenhaArvore(arvore, imprimeInt);
                printf("\nBalanceando a arvore:\n");
                balancear(arvore);
      
                break;

            case 15:
                system("cls");
                printf("\nRecalculando fator de balanceamento da arvore:\n");
                arvore = constroiArvore(ex5, 7);
                recalcularFB(arvore);
                break;

            default:
                printf("Escolha invalida!\n");
                continue;
        }

        desenhaArvore(arvore, imprimeInt);
    }

    return 0;
}
