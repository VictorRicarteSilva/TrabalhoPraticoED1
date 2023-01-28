#ifndef fila_h // Verifica se a fila_h existe no escopo
#define fila_h // Caso não exista no escopo defini fila_h

#include "lista.h"

typedef struct node Node;

typedef struct pessoa { // define o tipo de dado Pessoa
  char nome[50];
  lista *comanda;
} Pessoa;

typedef struct fila { // define o tipo de dado fila
  Node *inicio;
  Node *fim;
} Fila;


Fila *criaFila();                     // aloca uma Fila no mémoria
int filaCheia(Fila *F);               // verifica se a fila esta cheia
int filaVazia(Fila *F);               // verifica se a fila esta vazia
int insereNaFila(Fila *F, Pessoa p);  // insere uma nova Pessoa na fila
int retiraDaFila(Fila *F); // retira uma pessoa da fila
int PrimeiroDaFila(Fila *F, Pessoa *p); // mostra o primeiro cliente na fila do caixa
int deletaFila(Fila *F);       // libera uma fila da mémoria

#endif
