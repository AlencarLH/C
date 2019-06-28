#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
  int qtd;
  struct no *inicio;
}lista;

typedef struct no{
  int valor;
  struct no* prox;
}no;

void incluirFim(int x,lista *l);
lista *aloca_lista();
no *aloca_no();
int removerFim(lista *l);

int main() {

  //precisa escolher entre incluir e remover, retornar os valores removidos
  lista *l;
  int retorno,opcao,numero;
  no *aux;

  l=aloca_lista();


  do {
    puts("\n1 - Incluir elementos na pilha\n");
    puts("2 - Remover elementos da pilha\n");
    puts("3 - Sair\n");

    scanf("%d",&opcao);

    switch (opcao) {
      case 1:
      printf("Digite o numero a ser inserido: \n");
        scanf("%d",&numero);
        incluirFim(numero,l);
      break;
      case 2:
      if (removerFim(l)) {
        printf("Removido com sucesso: %d\n",numero);
      }
      else{
        printf("Lista vazia\n");
      }
      break;
      case 3:
        printf("Saindo do programa...\n");
      break;
      default:
        printf("Opcao invalida.\n");
      break;
    }


  } while(opcao!=3);


  return 0;
}


lista *aloca_lista(){
  lista *novo;
  novo = (lista*)calloc(1,sizeof(lista));
  return novo;
}

no *aloca_no(){
  no *novo;
  novo = (no*)calloc(1,sizeof(no));
  return novo;
}

void incluirFim(int x,lista *l){

  no *novo;
  no *aux;

  novo =aloca_no(); //aloca um espaço pro novo
  novo->valor = x; //o valor do nó recebe um inteiro X

  if (l->inicio == NULL) {
    l->inicio = novo;
  }
  else{
    while (aux->prox != NULL) {
      aux = aux->prox;
    }
    aux->prox = novo;
  }
  l->qtd++;
}


int removerFim(lista *l){

  no *novo,*aux=l->inicio; //remover no fim nao precisa de ant, que é usado
                        //pra fazer o anterior apontar pro prox, e tirar o do meio
  if (l->inicio == NULL) {
    return 0;
  }
  else{
    while (aux->prox != NULL) {
    //  ant = aux;
      aux = aux->prox;
    }
    l->qtd--;
    free(aux);
    return 1;
  }
}
