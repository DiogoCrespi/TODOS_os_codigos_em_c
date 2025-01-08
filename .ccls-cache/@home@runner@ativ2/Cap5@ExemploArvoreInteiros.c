#include "Utils.h"
#include "ArvoreBinaria.h"

void menuNormal(pDArvore arvore1, pDArvore arvore2, pDArvore arvore3) {
    int opcao;
    void *info;

    do {
        printf("\n********* Sub Menu Normal: **********\n");
        printf("* 1. arvores sao iguais             *\n");
        printf("* 2. arvore e estritamente binaria  *\n");
        printf("* 3. espelhamndo arvore             *\n");
        printf("* 4. comprimento interno da arvore  *\n");
        printf("* 5. arvore e balanceada            *\n");
        printf("* 6. arvore e BST                   *\n");
        printf("* 7. Caminhamento em Amplitude      *\n");
        printf("* 7. exclusao Folha                 *\n");
        printf("* 0. Sair                           *\n");
        printf("* Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                system("cls");
                 desenhaArvore(arvore1, imprimeInt);
                 desenhaArvore(arvore2, imprimeInt);
                if (iguais(arvore1, arvore2, comparaInt)) {
                    printf("As arvores SAO iguais.\n");
                } else {
                    printf("As arvores NAO sao iguais.\n");
                }
                break;

            case 2:
                system("cls");
                printf("\nArvore_3.\n");
                 desenhaArvore(arvore3, imprimeInt);
                if (estritamenteBinaria(arvore3)) {
                    printf("A arvore E estritamente binaria.\n");
                } else {
                    printf("A arvore NAO e estritamente binaria.\n");
                }
                //-------------------------
                printf("\nArvore_1.\n");
                 desenhaArvore(arvore1, imprimeInt);
                if (estritamenteBinaria(arvore1)) {
                    printf("A arvore E estritamente binaria.\n");
                } else {
                    printf("A arvore NAO e estritamente binaria.\n");
                }
                break;

            case 3:
                system("cls");
                printf("\nArvore_1 antes:\n");
                desenhaArvore(arvore1, imprimeInt);
                espelho(arvore1);
                printf("\nArvore_1 depois:\n");
                desenhaArvore(arvore1, imprimeInt);
                break;

            case 4:
                system("cls");
                printf("\nArvore_1:");
                desenhaArvore(arvore1, imprimeInt);
                printf("\nArvore_3:");
                desenhaArvore(arvore3, imprimeInt);
                printf("Comprimento interno Arvore_1: %d\n", comprimentoInterno(arvore1));
                 printf("Comprimento interno Arvore_3: %d\n", comprimentoInterno(arvore3));
                break;

            case 5:
                system("cls");
                printf("\nArvore_1:");
                desenhaArvore(arvore1, imprimeInt);

                if (balanceada(arvore1)) {
                    printf("A arvore E balanceada.\n");
                } else {
                    printf("A arvore NAO e balanceada.\n");
                }
                //------------------------------
                printf("\nArvore_3:");
                desenhaArvore(arvore3, imprimeInt);

                if (balanceada(arvore3)) {
                    printf("A arvore E balanceada.\n");
                } else {
                    printf("A arvore NAO e balanceada.\n");
                }
                break;

            case 6:
                system("cls");
                printf("Arvore1 e binaria de busca?\n");
                if (isBST(arvore1, NULL, NULL, comparaInt)) {
                    printf("A arvore E uma arvore binaria de busca (BST).\n");
                } else {
                    printf("A arvore NAO e uma arvore binaria de busca (BST).\n");
                }
                break;
            case 7:
                system("cls");
                printf("\nArvore_1:");
                desenhaArvore(arvore1, imprimeInt);
                printf("\nCaminhamento em Amplitude : ");
                amplitude(arvore1, imprimeInt);
                printf("\n");
                break;
            case 8:
                system("cls");
                printf("\nArvore_1 antes da exclusao:");
                desenhaArvore(arvore1, imprimeInt);

                int infoExcluir;
                printf("\nDigite o valor a ser excluido: ");
                scanf("%d", &infoExcluir);

                if (excluirInfo(arvore1, &infoExcluir, comparaInt)) {
                    printf("\nNo %d excluido com sucesso.\n", infoExcluir);
                } else {
                    printf("\nNo %d nao encontrado.\n", infoExcluir);
                }

                printf("\nArvore_1 apos a exclusao:");
                desenhaArvore(arvore1, imprimeInt);

                break;
            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    } while (opcao != 0);
}

void menuRecursivo(pDArvore arvore1, pDArvore arvore2, pDArvore arvore3) {
    int opcao;

    do {
        printf("\n******** Sub Menu Recursivo: ********\n");
        printf("* 1. arvores sao iguais             *\n");
        printf("* 2. arvore e estritamente binaria  *\n");
        printf("* 3. espelhamndo arvore             *\n");
        printf("* 4. comprimento interno da arvore  *\n");
        printf("* 5. arvore e balanceada            *\n");
        printf("* 6. arvore e BST                   *\n");
        printf("* 7. Caminhamento em amplitude      *\n");
        printf("* 0. Sair                           *\n");
        printf("* Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                system("cls");
                desenhaArvore(arvore1, imprimeInt);
                desenhaArvore(arvore2, imprimeInt);
                if (iguais(arvore1, arvore2, comparaInt)) {
                    printf("As arvores sao iguais.\n");
                } else {
                    printf("As arvores nao sao iguais.\n");
                }
                break;

            case 2:
                system("cls");
                printf("\nArvore_3.\n");
                 desenhaArvore(arvore3, imprimeInt);
                if (estritamenteBinaria(arvore3)) {
                    printf("A arvore e estritamente binaria.\n");
                } else {
                    printf("A arvore nao e estritamente binaria.\n");
                }
                break;

            case 3:
                system("cls");
                printf("espelhamento da arvore_1...\n");
                espelho(arvore1);
                desenhaArvore(arvore1, imprimeInt);
                break;

            case 4:
                system("cls");
                printf("Comprimento interno Arvore_1: %d\n", comprimentoInterno(arvore1));
                break;
            printf("Comprimento interno Arvore_3: %d\n", comprimentoInterno(arvore3));
            break;

            case 5:
                system("cls");
                desenhaArvore(arvore1, imprimeInt);
                if (balanceada(arvore1)) {
                    printf("A arvore e balanceada.\n");
                } else {
                    printf("A arvore nao e balanceada.\n");
                }
                break;

            case 6:
                system("cls");
                printf("Verificando se a arvore e uma arvore binaria de busca...\n");
                if (isBST(arvore1, NULL, NULL, comparaInt)) {
                    printf("A arvore e uma arvore binaria de busca (BST).\n");
                } else {
                    printf("A arvore nao e uma arvore binaria de busca (BST).\n");
                }
                break;
            case 7:
                system("cls");
                printf("Caminhamento em amplitude (recursivo):\n");
                amplitudeRecursiva(arvore1, imprimeInt);
                printf("\n");
                break;

            case 0:
                printf("Voltando ao menu principal...\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    } while (opcao != 0);
}
        void menuPrincipal(pDArvore arvore1, pDArvore arvore2, pDArvore arvore3) {
            int opcao;

            do {
                printf("\n---- Menu Principal ----\n");

                printf("| 1. Normal            | \n");
                printf("| 2. Recursivo         | \n");
                printf("| 0. Sair              | \n");
                printf("| Escolha uma opcao: ");
                scanf("%d", &opcao);
                printf("\n\n");
                switch (opcao) {
                    case 1:
                        system("cls");
                         menuNormal(arvore1, arvore2, arvore3);
                        break;

                    case 2:
                        system("cls");
                        menuRecursivo(arvore1, arvore2, arvore3);
                        break;

                    case 0:
                        printf("Saindo...\n");
                        break;

                    default:
                        printf("Opcao invalida. Tente novamente.\n");
                        break;
                }
            } while (opcao != 0);
        }

        int main() {
            pDArvore pArvoreInt1 = criarArvore(2);
            pDArvore pArvoreInt2 = criarArvore(2);
            pDArvore pArvoreInt3 = criarArvore(2);

            incluirInfo(pArvoreInt1, alocaInt(5), comparaInt);
            incluirInfo(pArvoreInt1, alocaInt(8), comparaInt);
            incluirInfo(pArvoreInt1, alocaInt(6), comparaInt);
            incluirInfo(pArvoreInt1, alocaInt(3), comparaInt);
            incluirInfo(pArvoreInt1, alocaInt(7), comparaInt);

            incluirInfo(pArvoreInt2, alocaInt(5), comparaInt);
            incluirInfo(pArvoreInt2, alocaInt(8), comparaInt);
            incluirInfo(pArvoreInt2, alocaInt(6), comparaInt);
            incluirInfo(pArvoreInt2, alocaInt(3), comparaInt);
            incluirInfo(pArvoreInt2, alocaInt(7), comparaInt);

            incluirInfo(pArvoreInt3, alocaInt(5), comparaInt);
            incluirInfo(pArvoreInt3, alocaInt(3), comparaInt);
            incluirInfo(pArvoreInt3, alocaInt(8), comparaInt);
            incluirInfo(pArvoreInt3, alocaInt(7), comparaInt);
            incluirInfo(pArvoreInt3, alocaInt(9), comparaInt);
            incluirInfo(pArvoreInt3, alocaInt(2), comparaInt);
            incluirInfo(pArvoreInt3, alocaInt(4), comparaInt);
            menuPrincipal(pArvoreInt1, pArvoreInt2, pArvoreInt3);

            return 0;
        }
