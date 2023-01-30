#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

struct node { //definição do tipo do no, contendo um cliente e um ponteiro pro proximo no
  Pessoa cliente;
  struct node *next;
};

Fila *criaFila() { //cria uma fila 
  Fila *f;
  f = malloc(sizeof(Fila));
  return f;
}

int filaCheia(Fila *F) { //para este codigo assumimos que nossa fila nunca estará cheia
  return 1; 
}

int filaVazia(Fila *F) { //verifica se fila esta vazia 
  if (F->inicio == NULL) { 
    return 1; 
  }
  return 0; 
}

int insereNaFila(Fila *F, Pessoa p) { //insere na fila usando a regra FIFO
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

int retiraDaFila(Fila *F) { //retira da fila pela regra FIFO
  Node *aux = F->inicio;
  F->inicio = F->inicio->next;
  free(aux);
  return 1;
}

int PrimeiroDaFila(Fila *F, Pessoa *p) { //Mostra o primeiro da fila 
  if (F == NULL)
    return 0;
  *p = F->inicio->cliente;
  return 1;
}

int deletaFila(Fila *F) { //Deleta a fila e libra o espaço dela da memoria 
  if(F==NULL)return 0;
  while(!filaVazia(F)){
    retiraDaFila(F);
  }
  free(F);
  F = NULL;
  return 1;
}
