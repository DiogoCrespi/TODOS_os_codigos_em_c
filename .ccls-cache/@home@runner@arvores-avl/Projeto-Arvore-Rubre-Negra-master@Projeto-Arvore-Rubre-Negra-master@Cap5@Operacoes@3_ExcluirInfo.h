#ifndef EXCLUIR_INFO_H
#define EXCLUIR_INFO_H
#include "../ArvoreRubroNegra.h"

pNohArvore RotacaoEsquerdaExclusao(pNohArvore *raiz, pNohArvore noAtual) {
    pNohArvore noDireita = noAtual->direita;
    noAtual->direita = noDireita->esquerda;
    if (noDireita->esquerda != NULL)
        noDireita->esquerda->pai = noAtual;
    noDireita->pai = noAtual->pai;
    if (noAtual->pai == NULL)
        *raiz = noDireita;
    else if (noAtual == noAtual->pai->esquerda)
        noAtual->pai->esquerda = noDireita;
    else
        noAtual->pai->direita = noDireita;
    noDireita->esquerda = noAtual;
    noAtual->pai = noDireita;
    return noDireita;
}

pNohArvore RotacaoDireitaExclusao(pNohArvore *raiz, pNohArvore noAtual) {
    pNohArvore noEsquerda = noAtual->esquerda;
    noAtual->esquerda = noEsquerda->direita;
    if (noEsquerda->direita != NULL)
        noEsquerda->direita->pai = noAtual;
    noEsquerda->pai = noAtual->pai;
    if (noAtual->pai == NULL)
        *raiz = noEsquerda;
    else if (noAtual == noAtual->pai->esquerda)
        noAtual->pai->esquerda = noEsquerda;
    else
        noAtual->pai->direita = noEsquerda;
    noEsquerda->direita = noAtual;
    noAtual->pai = noEsquerda;
    return noEsquerda;
}

pNohArvore EncontrarMenorExclusao(pNohArvore no, pNohArvore sentinela) {
    while (no->esquerda != sentinela)
        no = no->esquerda;
    return no;
}

void TransplantarArvore(pNohArvore *raiz, pNohArvore noOrigem, pNohArvore noDestino, pNohArvore sentinela) {
    if (noOrigem->pai == NULL)
        *raiz = noDestino;
    else if (noOrigem == noOrigem->pai->esquerda)
        noOrigem->pai->esquerda = noDestino;
    else
        noOrigem->pai->direita = noDestino;
    if (noDestino != sentinela)
        noDestino->pai = noOrigem->pai;
}

void CorrigirExclusao(pNohArvore *raiz, pNohArvore noAtual, pNohArvore sentinela) {
    while (noAtual != *raiz && (noAtual == sentinela || noAtual->cor == BLACK)) {
        if (noAtual == noAtual->pai->esquerda) {
            pNohArvore irmao = noAtual->pai->direita;
            if (irmao->cor == RED) {
                irmao->cor = BLACK;
                noAtual->pai->cor = RED;
                RotacaoEsquerdaExclusao(raiz, noAtual->pai);
                irmao = noAtual->pai->direita;
            }
            if ((irmao->esquerda == sentinela || irmao->esquerda->cor == BLACK) &&
                (irmao->direita == sentinela || irmao->direita->cor == BLACK)) {
                irmao->cor = RED;
                noAtual = noAtual->pai;
            } else {
                if (irmao->direita == sentinela || irmao->direita->cor == BLACK) {
                    if (irmao->esquerda != sentinela)
                        irmao->esquerda->cor = BLACK;
                    irmao->cor = RED;
                    RotacaoDireitaExclusao(raiz, irmao);
                    irmao = noAtual->pai->direita;
                }
                irmao->cor = noAtual->pai->cor;
                noAtual->pai->cor = BLACK;
                if (irmao->direita != sentinela)
                    irmao->direita->cor = BLACK;
                RotacaoEsquerdaExclusao(raiz, noAtual->pai);
                noAtual = *raiz;
            }
        } else {
            pNohArvore irmao = noAtual->pai->esquerda;
            if (irmao->cor == RED) {
                irmao->cor = BLACK;
                noAtual->pai->cor = RED;
                RotacaoDireitaExclusao(raiz, noAtual->pai);
                irmao = noAtual->pai->esquerda;
            }
            if ((irmao->direita == sentinela || irmao->direita->cor == BLACK) &&
                (irmao->esquerda == sentinela || irmao->esquerda->cor == BLACK)) {
                irmao->cor = RED;
                noAtual = noAtual->pai;
            } else {
                if (irmao->esquerda == sentinela || irmao->esquerda->cor == BLACK) {
                    if (irmao->direita != sentinela)
                        irmao->direita->cor = BLACK;
                    irmao->cor = RED;
                    RotacaoEsquerdaExclusao(raiz, irmao);
                    irmao = noAtual->pai->esquerda;
                }
                irmao->cor = noAtual->pai->cor;
                noAtual->pai->cor = BLACK;
                if (irmao->esquerda != sentinela)
                    irmao->esquerda->cor = BLACK;
                RotacaoDireitaExclusao(raiz, noAtual->pai);
                noAtual = *raiz;
            }
        }
    }
    if (noAtual != sentinela)
        noAtual->cor = BLACK;
}

pNohArvore ExcluirNoRecursivo(pNohArvore *raiz, void *info, FuncaoComparacao pfc, pNohArvore sentinela) {
    DArvore arvoreTemp = {*raiz, 0, 0, sentinela};
    pNohArvore noExclusao = BuscarInfoExclusao(&arvoreTemp, info, pfc);
    if (noExclusao == NULL)
        return *raiz;

    pNohArvore substituto = noExclusao;
    pNohArvore filhoSubstituto;
    char corOriginal = substituto->cor;

    if (noExclusao->esquerda == sentinela) {
        filhoSubstituto = noExclusao->direita;
        TransplantarArvore(raiz, noExclusao, noExclusao->direita, sentinela);
    } else if (noExclusao->direita == sentinela) {
        filhoSubstituto = noExclusao->esquerda;
        TransplantarArvore(raiz, noExclusao, noExclusao->esquerda, sentinela);
    } else {
        substituto = EncontrarMenorExclusao(noExclusao->direita, sentinela);
        corOriginal = substituto->cor;
        filhoSubstituto = substituto->direita;
        if (substituto->pai == noExclusao) {
            if (filhoSubstituto != sentinela)
                filhoSubstituto->pai = substituto;
        } else {
            TransplantarArvore(raiz, substituto, substituto->direita, sentinela);
            substituto->direita = noExclusao->direita;
            substituto->direita->pai = substituto;
        }
        TransplantarArvore(raiz, noExclusao, substituto, sentinela);
        substituto->esquerda = noExclusao->esquerda;
        substituto->esquerda->pai = substituto;
        substituto->cor = noExclusao->cor;
    }

    if (corOriginal == BLACK) {
        CorrigirExclusao(raiz, filhoSubstituto == sentinela ? substituto : filhoSubstituto, sentinela);
    }

    free(noExclusao);
    return *raiz;
}

void ExcluirInfo(pDArvore arvore, void *info, FuncaoComparacao pfc) {
    if (arvore == NULL || arvore->raiz == arvore->sentinela)
        return;

    arvore->raiz = ExcluirNoRecursivo(&(arvore->raiz), info, pfc, arvore->sentinela);
    if (arvore->raiz != arvore->sentinela)
        arvore->raiz->cor = BLACK;
    arvore->quantidadeNohs--;
}

#endif
