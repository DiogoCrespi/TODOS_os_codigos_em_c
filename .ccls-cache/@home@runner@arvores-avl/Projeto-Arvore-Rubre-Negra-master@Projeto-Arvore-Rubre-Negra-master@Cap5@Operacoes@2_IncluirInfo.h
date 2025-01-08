#ifndef CRIAR_ARVORE_BINARIA_H
#define CRIAR_ARVORE_BINARIA_H
#define BLACK 'B'
#define RED 'R'
#include "../ArvoreRubroNegra.h"

pNohArvore Avo(pNohArvore raiz) {
    if (raiz == NULL || raiz->pai == NULL)
        return NULL;
    return raiz->pai->pai;
}

pNohArvore Tio(pNohArvore raiz) {
    if (raiz == NULL || raiz->pai == NULL)
        return NULL;
    if (Avo(raiz) != NULL && Avo(raiz)->esquerda == raiz->pai)
        return Avo(raiz)->direita;
    return Avo(raiz)->esquerda;
}

char CorTio(pNohArvore raiz) {
    pNohArvore tioRaiz = Tio(raiz);
    if (tioRaiz == NULL)
        return 'X';
    return tioRaiz->cor;
}

void InverteCor(pNohArvore raiz) {
    if (raiz == NULL)
        return;
    raiz->cor = (raiz->cor == RED) ? BLACK : RED;
}

pNohArvore RotacaoDireita(pNohArvore raiz) {
    if (raiz == NULL || raiz->pai == NULL || Avo(raiz) == NULL)
        return NULL;
    pNohArvore avoRaiz = Avo(raiz);
    avoRaiz->pai = raiz->pai;
    raiz->pai->pai = avoRaiz->pai;
    avoRaiz->esquerda = raiz->pai->direita;
    raiz->pai->direita = avoRaiz;
    raiz->pai->cor = BLACK;
    avoRaiz->cor = RED;
    return raiz->pai;
}

pNohArvore RotacaoEsquerda(pNohArvore raiz) {
    if (raiz == NULL || raiz->pai == NULL || Avo(raiz) == NULL)
        return NULL;
    pNohArvore avoRaiz = Avo(raiz);
    raiz->pai->pai = avoRaiz->pai;
    avoRaiz->pai = raiz->pai;
    avoRaiz->direita = raiz->pai->esquerda;
    raiz->pai->esquerda = avoRaiz;
    raiz->pai->cor = BLACK;
    avoRaiz->cor = RED;
    return raiz->pai;
}

pNohArvore RotacaoEsquerdaDireita(pNohArvore raiz) {
    if (raiz == NULL || raiz->pai == NULL || Avo(raiz) == NULL)
        return NULL;
    pNohArvore avoRaiz = Avo(raiz);
    pNohArvore paiRaiz = raiz->pai;
    paiRaiz->pai = raiz;
    raiz->pai = avoRaiz;
    paiRaiz->direita = raiz->esquerda;
    raiz->esquerda = paiRaiz;
    return RotacaoDireita(paiRaiz);
}

pNohArvore RotacaoDireitaEsquerda(pNohArvore raiz) {
    if (raiz == NULL || raiz->pai == NULL || Avo(raiz) == NULL)
        return NULL;
    pNohArvore avoRaiz = Avo(raiz);
    pNohArvore paiRaiz = raiz->pai;
    paiRaiz->pai = raiz;
    raiz->pai = avoRaiz;
    paiRaiz->esquerda = raiz->direita;
    raiz->direita = paiRaiz;
    return RotacaoEsquerda(paiRaiz);
}

pNohArvore IncluirInfoRecursivo(pNohArvore raiz, void *info, FuncaoComparacao pfc, pNohArvore sentinela) {
    if (raiz == sentinela) {
        raiz = malloc(sizeof(NohArvore));
        raiz->info = info;
        raiz->esquerda = sentinela;
        raiz->direita = sentinela;
        raiz->cor = RED;
        return raiz;
    } else {
        pNohArvore filho;
        if (pfc(info, raiz->info) >= 0) {
            filho = IncluirInfoRecursivo(raiz->esquerda, info, pfc, sentinela);
            if (filho->direita == raiz) {
                raiz = filho;
            } else {
                filho->pai = raiz;
                raiz->esquerda = filho;
            }
        } else {
            filho = IncluirInfoRecursivo(raiz->direita, info, pfc, sentinela);
            if (filho->esquerda == raiz) {
                raiz = filho;
            } else {
                filho->pai = raiz;
                raiz->direita = filho;
            }
        }

        if (raiz->pai == NULL) {
            raiz->cor = BLACK;
            return raiz;
        }

        if (raiz->cor == BLACK || (raiz->cor == RED && filho->cor == BLACK)) {
            return raiz;
        }

        if (raiz->cor == RED && CorTio(filho) == RED) {
            raiz->cor = BLACK;
            Tio(filho)->cor = BLACK;
            if (Avo(filho) != NULL) {
                Avo(filho)->cor = RED;
            }
            return raiz;
        }

        if (raiz->cor == RED && CorTio(filho) != RED) {
            pNohArvore novaRaiz;
            if (raiz->esquerda == filho && raiz->pai->esquerda == raiz) {
                novaRaiz = RotacaoDireita(filho);
            } else if (raiz->direita == filho && raiz->pai->esquerda == raiz) {
                novaRaiz = RotacaoEsquerdaDireita(filho);
            } else if (raiz->direita == filho && raiz->pai->direita == raiz) {
                novaRaiz = RotacaoEsquerda(filho);
            } else if (raiz->esquerda == filho && raiz->pai->direita == raiz) {
                novaRaiz = RotacaoDireitaEsquerda(filho);
            }
            return novaRaiz;
        }
    }
    return raiz;
}

void IncluirInfo(pDArvore arvore, void *info, FuncaoComparacao pfc) {
    arvore->raiz = IncluirInfoRecursivo(arvore->raiz, info, pfc, arvore->sentinela);
    arvore->raiz->cor = BLACK;
    arvore->quantidadeNohs++;
}

#endif
