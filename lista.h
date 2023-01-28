#ifndef lista_h // Verifica se a lista_h existe no escopo
#define lista_h // Caso não exista no escopo defini lista_h

typedef struct produto produto;
typedef struct node node;
typedef struct lista lista;

struct produto {
  int id;
  double valor;
  char descricao[100];
};

struct lista {
  int tam;
  node *no;
  node *cauda;
};

lista *criaLista();                          // aloca a Lista na mémoria
int salvarItem_Lista(lista *L, produto P);   // insere um novo item na lista
int buscaLista(lista *L, int n, produto *P); // busca na Lista
int listaCheia(lista *L);                    // verifica se a lista esta cheia
int listaVazia(lista *L);                    // verifica se a lista esta vazia
int retiraLista(lista *L, int n);            // retira um elemento da lista
int destroiLista(lista *L);                  // libera a lista da mémoria
void imprimeLista(lista *L);
double somaLista(lista *L);

#endif
