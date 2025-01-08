#include <stdio.h>
#include <string.h>

#define MAX_DISCIPLINAS 100
#define MAX_LINE_LENGTH 1024

int main() {
    char disciplinas_manter[MAX_DISCIPLINAS][100] = {
    "Lógica Matemática",
    "Fundamentos de Programação",
    "Linguagem de Programação Estruturada",
    "Introdução à Ciência da Computação",
    "Comunicação de Dados",
    "Filosofia",
    "Cálculo Diferencial e Integral 1",
    "Estrutura de Dados",
    "Engenharia de Requisitos",
    "Fundamentos de Banco de Dados",
    "Circuitos Digitais",
    "Redes de Computadores 1",
    "Geometria Analítica e Álgebra Linear",
    "Probabilidade e Estatística",
    "Estrutura de Dados",
    "Programação Orientada a Objetos",
    "Redes de Computadores 2",
    "Engenharia de Software 1",
    "Sistemas Gerenciadores de Banco de Dados",
    "Geometria Analitica e Álg. Linear",
    "Paradigmas de Linguagens de Programação",
    "Pesquisa e Ordenação de Dados",
    "Desenvolvimento de Aplicações para Dispositivos Móveis",
    "Sistemas Operacionais",
    "Arquitetura e Organização de Computadores",
    "Engenharia de Software 2",
    "Linguagens Formais e Automatos + Aspectos Formais da Computação",
    "Cálculo Numérico",
    "Comunicação e Linguística",
    "Laboratório de Sistemas Operacionais",
    "Arquitetura Avançada de Hardware",
    "Interação Ser Humano-Computador",
    "Fundamentos de Sistemas Inteligentes",
    "Metodologia da Pesquisa",
    "Construção de Compiladores",
    "Sistemas Distribuídos",
    "Gerenciamento de Projetos",
    "Tecnologia em Desenvolvimento de Sistemas",
    "Empreendedorismo",
    "Sistemas Inteligentes Aplicados",
    "Trabalho de Conclusão de Curso 1",
    };
    int num_disciplinas = sizeof(disciplinas_manter) / sizeof(disciplinas_manter[0]);

    FILE *fp_in, *fp_out1, *fp_out2;
    char linha[MAX_LINE_LENGTH];
    char disciplina[100];

    fp_in = fopen("turmas_manha.txt", "r");
    fp_out1 = fopen("turmas_manha_filtrado.txt", "w");
    fp_out2 = fopen("covalidacao.txt", "w");

    while (fgets(linha, MAX_LINE_LENGTH, fp_in) != NULL) {
        sscanf(linha, "%s", disciplina); // Assumindo que o nome da disciplina está no início da linha

        int i;
        int encontrada = 0;
        for (i = 0; i < num_disciplinas; i++) {
            if (strcmp(disciplina, disciplinas_manter[i]) == 0) {
                encontrada = 1;
                break;
            }
        }

        if (encontrada) {
            fprintf(fp_out1, "%s\n", linha);
        } else {
            fprintf(fp_out2, "%s\n", linha);
        }
    }

    fclose(fp_in);
    fclose(fp_out1);
    fclose(fp_out2);

    return 0;
}