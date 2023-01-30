#ifndef pilha_h // Verifica se a pilha_h existe no escopo
#define pilha_h // Caso não exista no escopo defini pilha_h

typedef struct node Node;
typedef struct pilha pilha;

struct pilha { 
  int tam;
  Node *no;
};

pilha *criaPilha_Chocolate(); // aloca a Pilha na mémoria
int empilha_Chocolate(pilha *P, char *chocolate); // insere chocolate na pilha
int retiraPilha_Chocolate(pilha *P); // retira da pilha
void imprimeTopo(pilha *P); // imprime o topo da pilha
int pilhaVazia(pilha *P); // verifica se a pilha esta vazia
int pilhaCheia(pilha *P); // verifica se a pilha esta cheia
void destroiPilha(pilha *P); // libera a pilha da mémoria

#endif
