#include "fila.h"
#include "lista.h"
#include "pilha.h"
#include <stdio.h>

struct mesa {
  char cliente[50];
  lista comanda;
};

void menu() {
  printf("1 - Receber Cliente \n");
  printf("2 - Gerenciar fila do caixa \n");
  printf("0 - Sair\n");
  printf("\nOpcao: ");
}

void menuCliente() {
  printf("1 - Pedir Prato\n");
  printf("0 - Ir para o caixa\n");
  printf("\nOpcao: ");
}

int main(void) {
  pilha *chocolate = criaPilha_Chocolate();
  printf("Quantos chocolates estão na pilha: ");
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    char Chocolate[20];
    scanf(" %s", Chocolate);
    empilha_Chocolate(chocolate, Chocolate);
  }

  lista *cardapio = criaLista();
  printf("Quantos itens no cardapio:");
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    produto P;
    P.id = i;
    scanf(" %s", P.descricao);
    scanf(" %lf", &P.valor);
    salvarItem_Lista(cardapio, P);
  }

  Fila *cliente = criaFila();

  while (1) {
    int i;
    menu();
    scanf("%d", &i);
    if (i == 0) {
      if (!filaVazia(cliente)) {
        printf("Ainda ha pessoas na fila do Caixa\n");
      } else
        break;
    } else if (i == 1) {
      Pessoa cl;
      printf("Nome: ");
      scanf(" %s", cl.nome);
      cl.comanda = criaLista();
      while (1) {
        menuCliente();
        int j;
        scanf("%d", &j);
        if (j == 0) {
          insereNaFila(cliente, cl);
          break;
        } else {
          imprimeLista(cardapio);
          printf("\nNmr do Prato: ");
          int p;
          scanf("%d", &p);
          produto pd;
          int t = buscaLista(cardapio, p, &pd);
          if (!t) {
            printf("ERRO no pedido\n");
          } else {
            salvarItem_Lista(cl.comanda, pd);
          }
        }
      }
    } else if (i == 2) {
      if (filaVazia(cliente)) {
        printf("Não tem pessoas na fila\n");
      } else {
        Pessoa p;
        PrimeiroDaFila(cliente, &p);
        retiraDaFila(cliente);
        printf("%s\n", p.nome);
        imprimeLista(p.comanda);
        printf("\nTotal: %.2lf\n", somaLista(p.comanda));
        if (!pilhaVazia(chocolate)) {
          printf("Ganhou o chocolate: ");
          imprimeTopo(chocolate);
          printf("\n");
          retiraPilha_Chocolate(chocolate);
        }
        destroiLista(p.comanda);
      }
    }
  }
  destroiLista(cardapio);
  destroiPilha(chocolate);
  deletaFila(cliente);

  return 0;
}
