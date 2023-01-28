#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
// declarar funçoes de lista.h

struct node {
  produto P;
  node *next;
};

lista *criaLista() {
  lista *P = malloc(sizeof(lista)); // insere na memoria uma lista

  if (P == NULL) { // se o ponteiro P for igual a NULL
    return NULL;   // retorno NULL
  }
  P->no = NULL; // se não crio a lista com o no cabeca apontando pra NULL
  P->tam = 0;   // com tamanho 0
  return P;     // retorno a lista
}

int salvarItem_Lista(lista *L, produto P) { // insere
  node *Paux = malloc(sizeof(node));
  if (Paux == NULL)
    return 0;
  Paux->next = NULL;
  Paux->P = P;
  if (L->tam == 0) {
    L->no = Paux;
    L->cauda = Paux;
  } else {
    L->cauda->next = Paux;
    L->cauda = Paux;
  }
  L->tam++;
  return 1;
}

int buscaLista(lista *L, int n, produto *p) {
  node *P;
  P = L->no;
  while (P != NULL) {
    if (P->P.id == n) {
      *p = P->P;
      return 1;
    }
    P = P->next;
  }
  return 0;
}

int listaCheia(lista *L) {
  return 1;
  // Neste codigo assumimos que a lista nunca estara cheia
}

int listaVazia(lista *L) {
  if (L->no == NULL) { // se o primeiro elemento da lista for NULL
    return 0;          // retorno True a lista esta vazia
  } else
    return 1; // se não retorno false
}

int retiraLista(lista *L, int n) {
  node *P;
  node *Paux;
  P = L->no;
  // Pesquisa se o elemento n esta na lista
  while (P != NULL && P->P.id < n) {
    Paux = P;
    P = P->next;
  }

  /*
  Encontro o elemento n, então remove
  Confere se o elemento esta na cabeça ou no final da lista
  */
  if (P != NULL && P->P.id == n) {
    if (P != L->no) {
      Paux->next = P->next;
      free(P);
    } else { // P eh a cabeça
      L->no = L->no->next;
      free(P);
    }
    return 0;
  } else
    return 1;
}

int destroiLista(lista *L) {
  int n=0;
  while (listaVazia(L) == 1) {
    retiraLista(L, n);
    n++;
  }
  free(L);
}

void imprimeLista(lista *L) {
  if (L == NULL)
    return;
  node *aux = L->no;
  while (aux != NULL) {
    printf("%d %s - %lf\n", aux->P.id, aux->P.descricao, aux->P.valor);
    aux = aux->next;
  }
}

double somaLista(lista *L) {
  if (L == NULL)
    return 0;
  node *aux = L->no;
  double sum=0;
  while (aux != NULL) {
    sum+= aux->P.valor;
    aux = aux->next;
  }
  return sum;
}
