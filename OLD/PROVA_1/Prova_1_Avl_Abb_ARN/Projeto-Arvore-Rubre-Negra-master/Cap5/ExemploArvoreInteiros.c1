

#include <stdio.h>
#include <stdlib.h>
#include "Utils.h"
#include "ArvoreRubroNegra.h"

pDArvore constroiArvore(int dados[], int tam)
{
    pDArvore arvore = CriarArvore(NULL); 
    int i;
    for (i = 0; i < tam; i++)
    {
        IncluirInfo(arvore, AlocaInt(dados[i]), ComparaInt);
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
                    arvore = constroiArvore(ex1, sizeof(ex1) / sizeof(ex1[0]));
                    break;
                case 2:
                    arvore = constroiArvore(ex1_1, sizeof(ex1_1) / sizeof(ex1_1[0]));
                    break;
                case 3:
                    arvore = constroiArvore(ex1_2, sizeof(ex1_2) / sizeof(ex1_2[0]));
                    break;
                case 4:
                    arvore = constroiArvore(ex1_3, sizeof(ex1_3) / sizeof(ex1_3[0]));
                        DesenhaArvore(arvore, ImprimeInt);
                    break;
                case 5:
                    arvore = constroiArvore(ex2, sizeof(ex2) / sizeof(ex2[0]));
                    break;
                case 6:
                    arvore = constroiArvore(ex3, sizeof(ex3) / sizeof(ex3[0]));
                    break;
                case 7:
                    arvore = constroiArvore(ex4, sizeof(ex4) / sizeof(ex4[0]));
                    break;
                case 8:
                    arvore = constroiArvore(ex5, sizeof(ex5) / sizeof(ex5[0]));
                    break;
                case 9: {

                    arvore = constroiArvore(ex5, sizeof(ex5) / sizeof(ex5[0]));

                    for (int i = 0; i < sizeof(ex5) / sizeof(ex5[0]); i++) {


                    }
                    break;
                }




            case 10:

                break;
            default:
                printf("Escolha invalida!\n");
                continue;
        }

        if (arvore != NULL) {
            printf("\n*****************************************\n");
                DesenhaArvore(arvore, ImprimeInt);
            printf("\n*****************************************\n");
        }
    }

    return 0;
}