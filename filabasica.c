#include <stdio.h>
#include <stdlib.h>
void push(int x);
int pop();
int stackpop();

int vet[10];
int qtd = 0;

int main() {
int opcao,numero;
  do {
    printf("\n 1:PUSH ");
    printf("\n 2:POP ");
    printf("\n 3:STACKPOP \n");
    scanf("%d",&opcao);

    switch (opcao) {
      case 1:
      printf("\nNumero a ser inserido: ");
      scanf("%d",&numero);
      push(numero);
      break;

      case 2:
      numero=pop();
      if (numero>=0) {
        printf("\nNumero retirado: %d",numero );
      }
      break;
      case 3:
      numero=push();
      if (numero>=0) {
        printf("\nNumero a ser retirado: %d",numero);
      }
      break;
      case 4:
      printf("\nSaindo do programa...");
      break;
    default:
      printf("\nOpcao invalida");
      break;
    }

  } while(opcao!=4);
  return 0;
}

void push (int x){

  if (qtd==10) {
    printf("Fila cheia\n");
  }
  else{
    vet[qtd]=x;
    qtd++;
  }
}

int pop(){
int aux,i;

  if (qtd==0) {
    printf("fila vazia\n");
    return -1;
  }
  else{
      aux = vet[0];
      for ( i = 0; i < qtd; i++) {
        vet[i] = vet[i+1];
      }
      qtd--;
      return aux;
  }
}

int stackpop(){

if (qtd==0) {
  printf("fila vazia\n");
}
  else{
    return vet[0];
  }
}
