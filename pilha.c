#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// declarar funçes do pilha.h

struct node {
  char chocolate[20];
  Node *next;
};

pilha *criaPilha_Chocolate() {
  pilha *P = malloc(sizeof(pilha)); // insere na memoria uma pilha de chocolate

  if (P == NULL) { // se o ponteiro P for NULL
    return NULL;   // retorna NULL
  }
  P->no = NULL; // se não, o ponteiro P recebe NULL
  P->tam = 0;   // em seguida crio a pilha com tamanho 0
  return P;     // retorno a pilha P
}

int empilha_Chocolate(pilha *P, char *chocolate) { // insere o chocolate na
                                                   // pilha
  Node *Paux = malloc(sizeof(Node)); // insere um auxiliar na memoria

  if (Paux == NULL) // se Paux for NULL
    return 1;       // retorno false
  strcpy(
      Paux->chocolate,
      chocolate); // faz uma copia do elemento e empilha na pilha de chocolate
  Paux->next = P->no;

  P->no = Paux;
  P->tam++;
  return 0;
}

int retiraPilha_Chocolate(pilha *P) {
  Node *aux = P->no;
  free(aux);
  P->no = P->no->next;
  return 1;
}

void imprimeTopo(pilha *P) {
  printf("%s", P->no->chocolate); // imprime o elemento que esta no topo da
                                  // pilha de chocolate
}

int pilhaVazia(pilha *P) {
  if (P->tam == 0) // se o tamanho do ponteiro p for igual a 0
    return 1;      // então a pilha esta vazia
  else
    return 0; // se não a pilha pode ter um ou mais elementos
}

int pilhaCheia(pilha *P) {
  return 1;
} // Para o nosso codigo, assumimos que nossa pilha nunca estara cheia

void destroiPilha(pilha *P) {
  while (pilhaVazia(P) == 1) { // enquanto tiver elemento na pilha
    retiraPilha_Chocolate(P);  // retira da pilha
  }
  free(P);
}
