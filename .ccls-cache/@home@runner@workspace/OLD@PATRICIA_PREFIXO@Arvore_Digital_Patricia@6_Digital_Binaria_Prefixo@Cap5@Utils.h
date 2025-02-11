#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>

/* ---------------------------------------- */
/* Tipo de dado INT */
/* ---------------------------------------- */
int compararInt(void *info1, void *info2)
{
   int *p1 = (int *)info1;
   int *p2 = (int *)info2;
   return *p2 - *p1;
}
/* ---------------------------------------- */
void imprimirInt(void *info)
{
   int *pi = (int *)info;
   printf("%d - ", *pi);
}
/* ---------------------------------------- */
void *alocarInfoInt(void *info)
{
   int *pi = (int *)malloc(sizeof(int));
   *pi = *((int *)info);
   return pi;
}
/* ---------------------------------------- */
int *alocarInt(int n)
{
   int *pi = (int *)malloc(sizeof(int));
   *pi = n;
   return pi;
}

/* ---------------------------------------- */
/* Tipo de dado STRUCT Data */
/* ---------------------------------------- */
struct Data
{
   int dia, mes, ano;
};
/* ---------------------------------------- */
int compararData(void *info1, void *info2)
{
   struct Data *p1 = (struct Data *)info1;
   struct Data *p2 = (struct Data *)info2;
   return ((p2->ano - p1->ano) * 365) +
          ((p2->mes - p1->mes) * 30) +
          (p2->dia - p1->dia);
}
/* ---------------------------------------- */
void imprimirData(void *info)
{
   struct Data *pd = (struct Data *)info;
   printf("%d/%d/%d - ", pd->dia, pd->mes, pd->ano);
}
/* ---------------------------------------- */
void *alocarInfoData(void *info)
{
   struct Data *pd = (struct Data *)malloc(sizeof(struct Data));
   pd->dia = ((struct Data *)info)->dia;
   pd->mes = ((struct Data *)info)->mes;
   pd->ano = ((struct Data *)info)->ano;
   return pd;
}
/* ---------------------------------------- */
struct Data *alocarData(int dia, int mes, int ano)
{
   struct Data *pd = (struct Data *)malloc(sizeof(struct Data));
   pd->dia = dia;
   pd->mes = mes;
   pd->ano = ano;
   return pd;
}

/* ---------------------------------------- */
/* Tipo de dado CHAR */
/* ---------------------------------------- */
int compararChar(void *info1, void *info2)
{
   char *c1 = (char *)info1;
   char *c2 = (char *)info2;
   return *c1 - *c2;
}
/* ---------------------------------------- */
void *subString(void *info, int pos)
{
   char *chave = (char *)info;
   char *simbolo = (char *)malloc(sizeof(char));
   *simbolo = chave[pos];
   return simbolo;
}
/* ---------------------------------------- */
void imprimirChar(void *info)
{
   char *pc = (char *)info;
   printf("%s", pc); // Imprime a string completa
}

/* ---------------------------------------- */
/* Funções auxiliares */
/* ---------------------------------------- */
// Função para obter o bit na posição i de uma chave
int obterBit(char *chave, int i)
{
   int byteIndex = i / 8;
   int bitIndex = 7 - (i % 8);
   return (chave[byteIndex] & (1 << bitIndex)) != 0;
}

static inline int obterBit(const char *chave, int indice) {
    if (indice < 0 || chave == NULL) {
        return 0;  // Retorna 0 para bits inválidos (evita acessos incorretos)
    }
    
    int byte = indice / 8;  // Qual byte acessar?
    int bit = indice % 8;   // Qual bit dentro do byte?

    if (byte >= strlen(chave)) {
        return 0; // Se o índice ultrapassa o tamanho da string, assume-se 0
    }

    return (chave[byte] >> (7 - bit)) & 1; // Retorna o bit correspondente
}


#endif /* UTILS_H */
