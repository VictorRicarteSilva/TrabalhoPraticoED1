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

//criar uma pilha de chocolate
int main(void) { 
  pilha *chocolate = criaPilha_Chocolate();
  printf("Quantos chocolates estão na pilha: ");
  int n;
  scanf("%d", &n);

  //empilhar as difrentes opções de chocolate
  for (int i = 0; i < n; i++) {
    char Chocolate[20];
    scanf(" %s", Chocolate);
    empilha_Chocolate(chocolate, Chocolate);
  }

  //criar a lista do cardapio
  lista *cardapio = criaLista();
  printf("Quantos itens no cardapio:");
  scanf("%d", &n);

  //colocar descrição/nome do prato e preço
  for (int i = 0; i < n; i++) {
    produto P;
    P.id = i;
    scanf(" %s", P.descricao);
    scanf(" %lf", &P.valor);
    salvarItem_Lista(cardapio, P);
  }

  //cria a fila de cliente
  Fila *cliente = criaFila();

  //controle de menus 
  while (1) {
    int i;
    menu();
    scanf("%d", &i);
    if (i == 0) {
      if (!filaVazia(cliente)) { //verificar se existe pessoas na fila do caixa
        printf("Ainda ha pessoas na fila do Caixa\n");
      } else
        break;
    } else if (i == 1) { //adicionar pessoas ao restaurnate com o seu nome e sua comanda
      Pessoa cl;
      printf("Nome: ");
      scanf(" %s", cl.nome);
      cl.comanda = criaLista(); //insere comanda para o cliente
      while (1) {
        menuCliente(); //redireciona para os pedidos do menu
        int j;
        scanf("%d", &j);
        if (j == 0) {
          insereNaFila(cliente, cl); //redireciona para o caixa
          break;
        } else {
          imprimeLista(cardapio); //mostra as opções do cardapio
          printf("\nNmr do Prato: ");
          int p;
          scanf("%d", &p); //pede uma das opções existentes
          produto pd;
          int t = buscaLista(cardapio, p, &pd); //busca no menu
          if (!t) {
            printf("ERRO no pedido\n");
          } else {
            salvarItem_Lista(cl.comanda, pd); //salva na comanda do cliente
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
        printf("%s\n", p.nome); //mostra nome do git
        imprimeLista(p.comanda); //mostra os pedidos feitos 
        printf("\nTotal: %.2lf\n", somaLista(p.comanda)); //soma os pedidos feitos
        if (!pilhaVazia(chocolate)) { //retira um cholate da lista apos a soma da comanda
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
