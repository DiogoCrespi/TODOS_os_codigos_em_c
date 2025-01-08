#include <stdio.h>
#include "Utils.h"

#include "ArvoreRubroNegra.h"
#include "ArvoreRubroNegrafuncao.h"
pArvoreRubroNegra constroiArvoreRubroNegra(int dados[], int tam) {
    pArvoreRubroNegra arvore = criarArvoreRubroNegra();
    int i;
    for(i = 0; i < tam; i++) {
        inserirArvoreRubroNegra(arvore, dados[i]);
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
        printf("1. Rotacao simples - direita\n");
        printf("2. Rotacao simples - esquerda\n");
        printf("3. Rotacao dupla - esquerda/direita\n");
        printf("4. Rotacao dupla - direita/esquerda\n");
        printf("5. Nao precisa rotacionar\n");
        printf("0. Sair\n");

        printf("Opcao: ");
        scanf("%d", &escolha);

        pArvoreRubroNegra arvore;

        switch (escolha) {
            case 1:
                system("cls");
                printf("\nExemplo 1: Rotacao simples - direita\n");
                arvore = constroiArvoreRubroNegra(ex1, 5);
                break;
            case 2:
                system("cls");
                printf("\nExemplo 2: Rotacao simples - esquerda\n");
                arvore = constroiArvoreRubroNegra(ex2, 5);
                break;
            case 3:
                system("cls");
                printf("\nExemplo 3: Rotacao dupla - esquerda/direita\n");
                arvore = constroiArvoreRubroNegra(ex3, 5);
                break;
            case 4:
                system("cls");
                printf("\nExemplo 4: Rotacao dupla - direita/esquerda\n");
                arvore = constroiArvoreRubroNegra(ex4, 8);
                break;
            case 5:
                system("cls");
                printf("\nExemplo 5: Nao precisa rotacionar\n");
                arvore = constroiArvoreRubroNegra(ex5, 7);
                break;
            default:
                printf("Escolha invalida!\n");
                continue;
        }

        desenhaArvoreRubroNegra(arvore->raiz);
    }

    return 0;
}
