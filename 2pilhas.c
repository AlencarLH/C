#include <stdio.h>
#include <stdlib.h>

/*
2.2.7. Elabore um método para manter duas pilhas dentro de um único vetor
linear v[spacesize] de modo que nenhuma das pilhas incorra em estouro
até que toda a memória seja usada, e uma pilha inteira nunca seja
deslocada para outro local dentro do vetor. Escreva rotinas em C,
push1, push2, pop1 e pop2, para manipular as duas pilhas. (Dica: as
duas pilhas crescem na direção da outra.)
*/

int push1();
int push2();
int pop1();
int pop2();
int stackpop1();
int stackpop2();
int size();
int empty1();
int empty2();

int vet[10];
int qtd1 =0;
int qtd2 =0;



int main() {
  int retorno,opcao,numero;

  do {
    printf("\n1  - Push1");
    printf("\n2  - Push2 ");
    printf("\n3  - Pop1 ");
    printf("\n4  - Pop2 ");
    printf("\n5  - Stackpop1 ");
    printf("\n6  - Stackpop2 ");
    printf("\n7  - StackSize");
    printf("\n8  - Empty1");
    printf("\n9  - Empty2");
    printf("\n10 - Sair");
    scanf("%d",&opcao);

    switch (opcao) {
      case 1:
        printf("\n Inserir - pilha 1: ");
        scanf("%d",&opcao);
        retorno = push1(numero);
        if (retorno==1) {
          printf("Numero inserido com sucesso\n");
        }
        else{
          printf("Pilha 1 cheia, tente na pilha 2\n");
        }
      break;
      case 2:
      printf("\n Inserir - pilha 2: ");
      scanf("%d",&opcao);
      retorno = push2(numero);
      if (retorno==1) {
        printf("Numero inserido com sucesso\n");
      }
      else{
        printf("Pilha 2 cheia! tente na pilha 1\n");
      }
      break;
      case 3:
        retorno = pop1();
        if (retorno == 0) {
          printf("pilha vazia!\n");
        }
        else{
          printf("Numero retirado %d",retorno);
        }
      break;
      case 4:
        retorno = pop2();
        if (retorno == 0) {
          printf("pilha vazia!\n");
        }
        else{
          printf("Numero retirado %d",retorno);
        }
      break;
      case 5:
        retorno = stackpop1();
        if (retorno == 0) {
          printf("pilha vazia!\n");
        }
        else{
          printf("Numero a se retirado %d",retorno);
        }
      break;
      case 6:
      retorno = stackpop2();
      if (retorno == 0) {
        printf("pilha vazia!\n");
      }
      else{
        printf("Numero a se retirado %d",retorno);
      }
      break;
      case 7:
        printf("Tamanho das pilhas: %d\n",size());
      break;
      case 8:
        if (empty1()) {
          printf("Pilha vazia!\n");
        }
        else{
          printf("Pilha nao vazia!\n");
        }
      break;
      case 9:
      if (empty2()) {
        printf("Pilha vazia!\n");
      }
      else{
        printf("Pilha nao vazia!\n");
      }
      break;
      case 10:
        printf("Saindo do programa...\n");
      break;
      default:
      printf("Opcao invalida\n");
      break;
    }

  } while(opcao!=10);

  return 0;
}

int push1(int x){
  if (qtd1>=5) {
    return 0;
  }
  else{
    vet[qtd1] = x;
    qtd1++;
    return 1;
  }
}
int push2(int x){
  if (qtd2==10) {
    return 0;
  }
  else{
    vet[qtd2] = x;
    qtd2++;
    return 1;
  }
}

int pop1(){
  int aux;
  if (qtd1==0) {
    return 0;
  }
  else{
    aux = vet[qtd1-1];
    qtd1--;
    return aux;
  }
}

int pop2(){
  int aux;
  if (qtd2<=5) {
    return 0;
  }
  else{
    aux = vet[qtd2-1];
    qtd2--;
    return aux;
  }
}

int stackpop1(){
  if (qtd1==0) {
    return 0;
  }
  else{
    return vet[0];
  }
}

int stackpop2(){
  if (qtd2<=5) {
    return 0;
  }
  else{
    return vet[5];
  }
}

int size(){
  return 5;
}

int empty1(){
  if (qtd1==0) {
    return 1;
  }
  else{
    return 0;
  }
}

int empty2(){
  if (qtd1<=5) {
    return 1;
  }
  else{
    return 0;
  }
}
//falta fazer as ultimas funcoes e o menu!!!!!
