#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

struct node { // definição do tipo do no, contendo um cliente e um ponteiro pro
              // proximo no
  Pessoa cliente;
  struct node *next;
};

Fila *criaFila() {
  Fila *f;
  f = malloc(sizeof(Fila));
  return f;
}

int filaCheia(Fila *F) {
  return 1; // para este codigo assumimos que nossa fila nunca estará cheia
}

int filaVazia(Fila *F) {
  if (F->inicio ==
      NULL) { // verifica se o incio da fila e nulo (nenhum elemento na fila)
    return 1; // fila vazia
  }
  return 0; // há ao menos um elemento na lista
}

int insereNaFila(Fila *F, Pessoa p) {
  Node *n = malloc(sizeof(Node));
  if (n == NULL)
    return 0;
  n->cliente = p;
  if (F->inicio == NULL)
    F->inicio = n;
  n->next = NULL;
  if (F->fim != NULL)
    F->fim->next = n;
  F->fim = n;
  return 1;
}
int retiraDaFila(Fila *F) {
  Node *aux = F->inicio;
  F->inicio = F->inicio->next;
  free(aux);
  return 1;
}

int PrimeiroDaFila(Fila *F, Pessoa *p) {
  if (F == NULL)
    return 0;
  *p = F->inicio->cliente;
  return 1;
}

int deletaFila(Fila *F) {
  if(F==NULL)return 0;
  while(!filaVazia(F)){
    retiraDaFila(F);
  }
  free(F);
  F = NULL;
  return 1;
}
