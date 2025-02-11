#ifndef STRUCT_ARVORE_PATRICIA_H
#define STRUCT_ARVORE_PATRICIA_H

struct nohPatricia {
   int terminal;        // Indica se o nó é terminal (armazena chave)
   int indice;          // Índice do dígito que diferencia as chaves
   struct nohPatricia* esquerda; // Filho à esquerda
   struct nohPatricia* direita;  // Filho à direita
};

#endif