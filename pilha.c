#include <stdio.h>
#include <stdlib.h>

typedef struct pilha{
  int *vet;
  int topo,qtd;
}pilha;

pilha *alocaPilha();
int push();
int pop();
int stackPop();

int main() {
  pilha *p1;
  int opcao,numero,retorno;

  p1 = alocaPilha();

  do {
    puts("~~~~~~~~~~~~~~~~~");
    puts("1:Push          |");
    puts("2:Pop           |");
    puts("3:Stackpop      |");
    puts("4:ResetaPilha   |");
    puts("5:Sair          |");
    puts("~~~~~~~~~~~~~~~~~");
    scanf("\n%d",&opcao);

    switch (opcao) {
      case 1:
        puts("Numero a ser inserido: \n");
        scanf("%d",&numero );

        retorno = push(p1,numero);

        if (retorno == 0) {
          puts("Pilha Cheia!\n");
        }
        else{
          puts("Numero inserido com sucesso\n");
        }
      break;
      case 2:
        retorno = pop(p1);
        if (retorno != 0) {
          printf("Numero removido: %d\n",retorno);
        }
        else{
          puts("Pilha vazia\n");
        }
      break;
      case 3:
        retorno = stackPop(p1);
        if (retorno !=0) {
          printf("Numero a ser removido %d\n",retorno);
        }
        else{
          puts("Pilha \n");
        }
      break;
      case 4:
      free(p1->vet);
      free(p1);
      p1 = alocaPilha();
      break;
      case 5:
      puts("Saindo do programa...\n");
      break;
      default: puts("Opçcao invalida\n");
      break;
    }
  } while(opcao!=5);
  return 0;
}

pilha *alocaPilha(pilha *p){
  p = (pilha*)malloc(sizeof(pilha));

  printf("Qual o tamanho da pilha? ");
  scanf("%d",&p->topo);

  p->vet = (int*)malloc(sizeof(int)*p->topo);
  p->qtd = 0;
}


int push(pilha *p){
  int x;
  if (p->qtd == p->topo) {
    return 0;
  }
  else{
    p->vet[p->qtd] = x;
    p->qtd++;
    return 1;
  }
}

int pop(pilha *p){
  if (p->qtd == 0) {
    return 0;
  }
  else{
  return p->qtd--;
  }
}

int stackPop(pilha *p){
  if (p->qtd == 0) {
    return 0;
  }
  else{
    return p->qtd;
  }
}
