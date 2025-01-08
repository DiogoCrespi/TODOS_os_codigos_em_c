#include <stdio.h>
#include "Utils.h"

#include "ArvoreRubroNegra.h"
pNoRubroNegra criarNo(int valor) {
    pNoRubroNegra novoNo = (pNoRubroNegra)malloc(sizeof(NoRubroNegra));
    novoNo->valor = valor;
    novoNo->cor = VERMELHO;
    novoNo->esquerda = novoNo->direita = novoNo->pai = NULL;
    return novoNo;
}

pArvoreRubroNegra criarArvoreRubroNegra() {
    pArvoreRubroNegra novaArvore = (pArvoreRubroNegra)malloc(sizeof(ArvoreRubroNegra));
    novaArvore->raiz = NULL;
    return novaArvore;
}

void rotacaoEsquerda(pArvoreRubroNegra arvore, pNoRubroNegra no) {
    pNoRubroNegra direita = no->direita;
    no->direita = direita->esquerda;
    if (direita->esquerda != NULL) {
        direita->esquerda->pai = no;
    }
    direita->pai = no->pai;
    if (no->pai == NULL) {
        arvore->raiz = direita;
    } else if (no == no->pai->esquerda) {
        no->pai->esquerda = direita;
    } else {
        no->pai->direita = direita;
    }
    direita->esquerda = no;
    no->pai = direita;
}

void rotacaoDireita(pArvoreRubroNegra arvore, pNoRubroNegra no) {
    pNoRubroNegra esquerda = no->esquerda;
    no->esquerda = esquerda->direita;
    if (esquerda->direita != NULL) {
        esquerda->direita->pai = no;
    }
    esquerda->pai = no->pai;
    if (no->pai == NULL) {
        arvore->raiz = esquerda;
    } else if (no == no->pai->direita) {
        no->pai->direita = esquerda;
    } else {
        no->pai->esquerda = esquerda;
    }
    esquerda->direita = no;
    no->pai = esquerda;
}

void corrigirInsercao(pArvoreRubroNegra arvore, pNoRubroNegra no) {
    pNoRubroNegra pai, avo;

    while ((no != arvore->raiz) && (no->cor != PRETO) && (no->pai->cor == VERMELHO)) {
        pai = no->pai;
        avo = pai->pai;

        if (pai == avo->esquerda) {
            pNoRubroNegra tio = avo->direita;

            if (tio != NULL && tio->cor == VERMELHO) {
                avo->cor = VERMELHO;
                pai->cor = PRETO;
                tio->cor = PRETO;
                no = avo;
            } else {
                if (no == pai->direita) {
                    rotacaoEsquerda(arvore, pai);
                    no = pai;
                    pai = no->pai;
                }
                rotacaoDireita(arvore, avo);
                pai->cor = PRETO;
                avo->cor = VERMELHO;
                no = arvore->raiz;
            }
        } else {
            pNoRubroNegra tio = avo->esquerda;

            if (tio != NULL && tio->cor == VERMELHO) {
                avo->cor = VERMELHO;
                pai->cor = PRETO;
                tio->cor = PRETO;
                no = avo;
            } else {
                if (no == pai->esquerda) {
                    rotacaoDireita(arvore, pai);
                    no = pai;
                    pai = no->pai;
                }
                rotacaoEsquerda(arvore, avo);
                pai->cor = PRETO;
                avo->cor = VERMELHO;
                no = arvore->raiz;
            }
        }
    }
    arvore->raiz->cor = PRETO;
}

void inserirArvoreRubroNegra(pArvoreRubroNegra arvore, int valor) {
    pNoRubroNegra novoNo = criarNo(valor);
    pNoRubroNegra y = NULL;
    pNoRubroNegra x = arvore->raiz;

    while (x != NULL) {
        y = x;
        if (novoNo->valor < x->valor) {
            x = x->esquerda;
        } else {
            x = x->direita;
        }
    }

    novoNo->pai = y;

    if (y == NULL) {
        arvore->raiz = novoNo;
    } else if (novoNo->valor < y->valor) {
        y->esquerda = novoNo;
    } else {
        y->direita = novoNo;
    }

    if (novoNo->pai == NULL) {
        novoNo->cor = PRETO;
        return;
    }

    if (novoNo->pai->pai == NULL) {
        return;
    }

    corrigirInsercao(arvore, novoNo);
}

void desenhaArvoreRubroNegra(pNoRubroNegra raiz) {
    if (raiz != NULL) {
        desenhaArvoreRubroNegra(raiz->esquerda);
        printf("%d (%s) ", raiz->valor, raiz->cor == VERMELHO ? "V" : "P");
        desenhaArvoreRubroNegra(raiz->direita);
    }
}

pArvoreRubroNegra constroiArvoreRubroNegra(int dados[], int tam) {
    pArvoreRubroNegra arvore = criarArvoreRubroNegra();
    int i;
    for(i = 0; i < tam; i++) {
        inserirArvoreRubroNegra(arvore, dados[i]);
    }
    return arvore;
}

int main() {
    int ex1[] = {5, 10, 3, 7, 6};             
    int ex2[] = {5, 10, 3, 12, 14};        
    int ex3[] = {5, 10, 3, 7, 8};            
    int ex4[] = {5, 10, 3, 4, 12, 9, 14, 13}; 
    int ex5[] = {5, 10, 3, 4, 12, 9, 14};   

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
