#ifndef EXCLUIR_INFO_H
#define EXCLUIR_INFO_H

int excluirInfo(pDLista pd, void *info, FuncaoComparacao pfc) {
    pNoh atual, ant;

    atual = pd->primeiro;
    ant = NULL;

    // Localizar a informação na lista
    while (atual != NULL) {
        if (pfc(atual->info, info) == 0)
            break;
        ant = atual;
        atual = atual->prox;
    }

    // Verificar se a informação foi encontrada
    if (atual != NULL) {
        if (atual == pd->primeiro) {
            // Caso o elemento seja o primeiro
            pd->primeiro = atual->prox;
        } else if (atual == pd->ultimo) {
            // Caso o elemento seja o último
            pd->ultimo = ant;
            if (ant != NULL) ant->prox = NULL;
        } else {
            // Caso o elemento esteja no meio
            ant->prox = atual->prox;
        }

        // Atualizar quantidade e liberar memória
        pd->quantidade--;
        free(atual->info);
        free(atual);

        return 1; // Exclusão bem-sucedida
    }

    return 0; // Informação não encontrada
}
#endif
