#ifndef UTILS_H
#define UTILS_H
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* ---------------------------------------- */
/* tipo de dado INT */
/* ---------------------------------------- */
int comparaInt(void *info1, void *info2) {
    int *p1 = (int *) info1;
    int *p2 = (int *) info2;
    return *p2 - *p1;
}
int compararInt(const void *a, const void *b) {
    int int_a = *((int *)a);
    int int_b = *((int *)b);
    if (int_a < int_b) return -1;
    if (int_a > int_b) return 1;
    return 0;
}


/* ---------------------------------------- */
void imprimeInt(void *info) {
    int *pi = (int *) info;
    printf("%d", *pi);
}
/* ---------------------------------------- */
void* alocaInfoInt(void *info){
   int * pi = (int *) malloc(sizeof(int));
   *pi = *((int*)info);
   return pi;
}
/* ---------------------------------------- */
int* alocaInt(int n) {
    int *pi = (int *) malloc(sizeof(int));
    if (pi != NULL) {
        *pi = n;
    }
    return pi;
}

/* ---------------------------------------- */
/* tipo de dado STRUCT Data */
/* ---------------------------------------- */
struct Data{
   int dia, mes, ano;
};
/* ---------------------------------------- */
int          comparaData  (void *info1, void *info2){
    struct Data *p1 = (struct Data *) info1;
    struct Data *p2 = (struct Data *) info2;
    return ((p2->ano - p1->ano)*365) +
           ((p2->mes - p1->mes)*30)  +
            (p2->dia - p1->dia)  ;
}
/* ---------------------------------------- */
void         imprimeData  (void *info){
   struct Data *pd = (struct Data *) info;
   printf("%d/%d/%d - ", pd->dia, pd->mes, pd->ano);
}
/* ---------------------------------------- */
void*        alocaInfoData(void *info){
   struct Data * pd = (struct Data *) malloc(sizeof(struct Data));
   pd->dia = ((struct Data*)info)->dia;
   pd->mes = ((struct Data*)info)->mes;
   pd->ano = ((struct Data*)info)->ano;
   return pd;
}
/* ---------------------------------------- */
struct Data* alocaData    (int dia, int mes, int ano){
   struct Data *pd = (struct Data *) malloc(sizeof(struct Data));
   pd->dia = dia;
   pd->mes = mes;
   pd->ano = ano;
   return pd;
}

#endif /* UTILS_H */
