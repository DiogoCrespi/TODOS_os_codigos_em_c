
#include "FuncoesGenericas.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024 // Ajuste de acordo com o tamanho máximo da linha

int main() {
    FILE *fp_in, *fp_out;
    char linha[MAX_LINE_LENGTH];
    char *turma, *horario;

    // Abrir os arquivos
    fp_in = fopen("dados_turmas.txt", "r");
    if (fp_in == NULL) {
        perror("Erro ao abrir o arquivo de entrada");
        return 1;
    }
    fp_out = fopen("turmas_manha.txt", "w");
    if (fp_out == NULL) {
        perror("Erro ao abrir o arquivo de saída");
        fclose(fp_in);
        return 1;
    }

    // Ler cada linha do arquivo de entrada
    while (fgets(linha, MAX_LINE_LENGTH, fp_in) != NULL) {
        // Procurar por "m" no campo de horário
        horario = strstr(linha, "m");
        if (horario != NULL) {
            // Extrair o nome da turma (ajuste conforme o formato do arquivo)
            turma = strtok(linha, "\t");
            fprintf(fp_out, "%s, %s\n", turma, horario);
        }
    }

    // Fechar os arquivos
    fclose(fp_in);
    fclose(fp_out);

    return 0;
}





