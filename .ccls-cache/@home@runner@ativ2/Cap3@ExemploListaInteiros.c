#include <stdio.h>
#include <stdlib.h>
#include "Utils.h"
#include "Lista.h"

int main(){
    pDLista pListaInt = criarLista();

    int* pi = alocaInt_lista(5);

    /* teste de inclusao */
    incluirInfo_lista(pListaInt, pi);
    incluirInfo_lista(pListaInt, alocaInt_lista(3));
    incluirInfo_lista(pListaInt, alocaInt_lista(9));
    incluirInfo_lista(pListaInt, alocaInt_lista(1));
    incluirInfo_lista(pListaInt, alocaInt_lista(2));

    printf("\nResultado da inclusao \n");
    imprimirLista(pListaInt, imprimeInt_lista);

    /* teste de exclusao */
    excluirInfo_lista(pListaInt, alocaInt_lista(9), comparaInt_lista);
    printf("\nResultado da exclusao \n");
    imprimirLista(pListaInt, imprimeInt_lista);

    /* teste de busca */
    int result = contemInfo_lista(pListaInt, alocaInt_lista(5), comparaInt_lista);
    printf("\nResultado da busca do numero 5: 0-[Nao encontrou], 1-[ok] -> %d\n", result);

    /* teste de duplicacao de lista */
    pDLista copia = duplicarLista(pListaInt, alocaInfoInt_lista);
    printf("\nResultado da duplicacao \n");
    imprimirLista(copia, imprimeInt_lista);

    /* teste de divisao de lista */
    pDLista novaLista = dividirLista(pListaInt, 3);
    printf("\nResultado da divisao \n");
    printf("    Lista Original: ");
    imprimirLista(pListaInt, imprimeInt_lista);
    printf("\n    Nova Lista: ");
    imprimirLista(novaLista, imprimeInt_lista);

    /* teste de destruicao da lista */
    //destruirListaInfo(pListaInt, liberaInt_lista);
    //printf("\nResultado da destruicao da lista \n");
    //imprimirLista(pListaInt, imprimeInt_lista);

  //  unirListas(pListaInt, pListaInt, comparaInt_lista);


}
