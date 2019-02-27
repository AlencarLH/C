#include <stdio.h>
#include <stdlib.h>
//front = primeiro
//rear = ultimo
#define MAX 10


 struct fila{

  int qtd[MAX];
  int inicio,fim; //primeiro e ultimo elementos da fila

};
void push ();
int pop ();
int stackpop ();

int main() {
  int opcao;
//  int numero;
  struct fila numero;
  numero.inicio = 0;
  numero.fim = 0;


  do {

    printf("\n 1- PUSH\n");
    printf("\n 2- POP\n");
    printf("\n 3- STACKPOP\n");
    scanf("%d",&opcao);

    switch (opcao) {
      case 1:
      printf("\nNumero a ser inserido");
      scanf("%d",&numero);
      push(&numero);
      break;

      case 2:
      pop(&numero);
      if (numero.qtd>=0) {
        printf("Numero retirado: %d",numero);
      }
      break;

      case 3:
      stackpop(&numero);
      if (numero.qtd>=0) {
        printf("Numero a ser retirado: %d",numero);
      }
      break;

      case 4:
        printf("Saindo do programa");
      break;

      default:
        printf("Opcao invalida!");
      break;
    }

  } while(opcao<4);
return 0;
}

void push (struct fila *p,int x){

  if (p->fim >= MAX+1) {     //se o fim for >= maximo
    printf("Overflow!\n");
    exit(1);
  }
  p->qtd[p->fim++] = x; //x recebe o valor de qtd na posiçao final
  return;
}

int pop (struct fila *p){

  int aux,i;

  if (p->inicio == p->fim) {
    printf("Fila vazia\n");
    exit(1);
  }
    else{
  //agora,salva o primeiro e refaz o arranjo trazendo cada elemento para frente
  aux = p->qtd[0]; //armazena para retornar qual elemento saiu
  for (i = 0; i < p->fim-1; i++) {
    p->qtd[i] = p->qtd[i+1];
  }
  p->fim--; //o fim decresce
  return aux; //retorna o elemento retirado
  }
}

int stackpop (struct fila *p){
  //retorna o elemento que está na frente, prestes a sair
  return p->qtd[0];
}
