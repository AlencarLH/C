#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
  int qtd;
  struct no* inicio;
  struct no* fim;
}lista;

typedef struct no{
  int valor;
  struct no *ant;
  struct no *prox;
}no;

no *alocaNo();
lista *alocaLista();
void push(int x, lista *l);
int pop(lista *l);

int main(lista *l, no *n) {
  l = alocaLista();
  n = alocaNo();
  int cartas,i,aux;

  printf("digite o numero de cartas: \n");
  scanf("%d\n",&cartas);

  while (i<cartas) {
    push(aux,l);
    i++;
  }

  printf("Cartas retiradas\n");
  while (l->qtd>=2) {
    aux = pop(l);
    printf("%d\n",aux);
    aux = pop(l);
    push(aux,l);
  }
  aux = pop(l);
  printf("cartas que sobraram: \n",aux);


  return 0;
}


lista *alocaLista(){
  lista *l;
  l = (lista*)malloc(sizeof(lista));
  l->qtd = 0;
  l->inicio = NULL;
  l->fim = NULL;
  return l;
}

no *alocaNo(){
  no *n;
  n = (no*)malloc(sizeof(lista));
  n->valor = 0;
  n->ant = NULL;
  n->prox = NULL;
  return n;
}


void push(int x, lista *l){
  no *novo, *aux;
  novo = alocaNo();
  novo->valor = x;

  if (l->inicio == NULL) {
    l->inicio = novo;
    l->fim = novo;
  }
  else{
    aux = l->fim;
    aux->prox = novo;
    novo->ant = aux;
    l->fim = novo;
  }
  l->qtd++;
}

int pop(lista *l){
  no *aux,*aux1;

  if (l->inicio == NULL) {
    return 0;
  }
  else{
    aux = l->inicio;
    aux1 = aux->prox;
    l->inicio = aux1;
  }
  l->qtd--;
  return aux->valor;
  free(aux);
}
