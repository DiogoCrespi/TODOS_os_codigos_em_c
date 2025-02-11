#include <stdio.h>
#include <strings.h>
#include "Utils.h"
#include "ArvorePrefixo.h"

DPatricia *constroiArvorePatricia(char* chaves[], int tam) {
    DPatricia *arvore = criarArvorePatricia();
    int r;
    for (int i = 0; i < tam; i++) {
        r = incluirChave(arvore, chaves[i]);
        desenhaArvorePatricia(arvore);  // Chama a funcao para desenhar a arvore apos a inclusao
        if (r == 0)
            printf("\nErro na inclusao da chave [%s] - chave ja existe ou erro de estrutura!", chaves[i]);
    }

    return arvore;
}

// Testando a busca e inclusao
void testarBusca(DPatricia *arvore, const char *chave) {
    int resultado = buscarInfoPatricia(arvore, chave);

    // Mensagem de resultado da busca
    if (resultado)
        printf("Chave [%s] encontrada na arvore.\n", chave);
    else
        printf("Chave [%s] nao encontrada na arvore.\n", chave);
}

// Testando a exclusao
void testarExclusao(DPatricia *arvore, const char *chave) {
    int resultado = excluirChave(arvore, chave);

    // Mensagem de resultado da exclusao
    if (resultado) {
        printf("Chave [%s] excluida com sucesso.\n", chave);
        desenhaArvorePatricia(arvore); // Exibe a arvore apos a exclusao
    } else {
        printf("Chave [%s] nao encontrada para exclusao.\n", chave);
    }
}

int main() {
    // Conjunto de chaves para testar
    char* ex1[] = {"001100", "01", "00110100", "1100", "11"};
    char* ex2[] = {"00110001 00001100 ", "101", "001101", "00110010", "11"};

    // Construir a arvore com o conjunto de chaves ex1
    printf("\nConstruindo arvore com conjunto ex1:\n");
    DPatricia *arvoreEx1 = constroiArvorePatricia(ex1, 5);

    // Testando a busca das chaves
    printf("\nTestando busca na arvore ex1:\n");
    testarBusca(arvoreEx1, "001100");  // Esperado: Chave encontrada
    testarBusca(arvoreEx1, "01");      // Esperado: Chave encontrada
    testarBusca(arvoreEx1, "00110100");  // Esperado: Chave encontrada
    testarBusca(arvoreEx1, "1100");   // Esperado: Chave nao encontrada
    testarBusca(arvoreEx1, "0000000");

    // Testando exclusao de chaves na arvore ex1
    printf("\nTestando exclusao na arvore ex1:\n");
    testarExclusao(arvoreEx1, "001100");
    testarExclusao(arvoreEx1, "01");
    testarExclusao(arvoreEx1, "00110100");
    testarExclusao(arvoreEx1, "1100");
    testarExclusao(arvoreEx1, "0000"); // Chave que nao existe

    // Testando o segundo conjunto de chaves (ex2)
    printf("\nConstruindo arvore com conjunto ex2:\n");
    DPatricia *arvoreEx2 = constroiArvorePatricia(ex2, 5);

    printf("\nTestando busca na arvore ex2:\n");
    testarBusca(arvoreEx2, "00110001 00001100 ");  // Esperado: Chave encontrada
    testarBusca(arvoreEx2, "101");     // Esperado: Chave encontrada
    testarBusca(arvoreEx2, "001101");  // Esperado: Chave encontrada
    testarBusca(arvoreEx2, "00110010");  // Esperado: Chave encontrada
    testarBusca(arvoreEx2, "11");

    printf("\nTestando exclusao na arvore ex2:\n");
    testarExclusao(arvoreEx2, "00110001 00001100 ");
    testarExclusao(arvoreEx2, "101");
    testarExclusao(arvoreEx2, "001101");
    testarExclusao(arvoreEx2, "11");
    testarExclusao(arvoreEx2, "0000"); // Chave que nao existe

    return 0;
}
