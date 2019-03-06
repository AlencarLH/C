#include <stdio.h>
#include <stdlib.h>
//ERRO BIZONHO DE FALHA DE SEGMENTAÇAO MAS TA TUDO IDENTICO
//COLAR ESSE CODIGO NUM COMPILADOR ONLINE
typedef struct fila{
  int *vet;
  int tamanho,qtd;
}fila;

fila *alocaFila();

int main() {
  fila *p1;
  int opcao,numero,retorno;

  p1 = alocaFila();

  do {
  puts("~~~~~~~~~~~~~~~~~");
  puts("1:Push          |");
  puts("2:Pop           |");
  puts("3:Stackpop      |");
  puts("4:ResetaFila    |");
  puts("5:Sair          |");
  puts("~~~~~~~~~~~~~~~~~");
  scanf("\n%d",&opcao);

    switch (opcao) {
      case 1:
        puts("Numero a ser inserido na fila: ");
        scanf("%d",&numero);
        retorno = push(p1,numero);

          if (retorno == 0) {
            printf("\nFila cheia!\n");
          }
          else{
            printf("\nNumero inserido com sucesso!\n");
          }
      break;
      case 2:
        retorno = pop(p1);
          if (retorno != 0) {
            printf("\nNumero retirado: %d\n",retorno);
          }
          else{
            puts("\nFila vazia!\n");
          }
      break;
      case 3:
        retorno = stackPop(p1);
          if (retorno !=0) {
            printf("\nNumero a ser retirado: %d\n",retorno);
          }
          else{
            printf("\nFila vazia!\n");
          }
      break;
      case 4:
        free(p1->vet);
        free(p1);
        p1=alocaFila();
      break;
      case 5:
        puts("Saindo do programa...");
      break;
      default:
        puts("Opcao invalida!\n");
      break;
    }
  } while(opcao!=5);
  return 0;
}

int push (fila *p,int x){
  if (p->qtd == p->tamanho) {
    return 0;
  }
  else{
    p->vet[p->qtd] = x;
    p->qtd++;
    return 1;
  }
}
int pop(fila *p){
  int aux,i;
  if (p->qtd==0) {
    return 0;
  }
  else{
    aux = p->vet[0];
    while (i < p->qtd) {
      p->vet[i]=p->vet[i+1];
    }
    p->qtd--;
    return aux;
  }
}
int stackPop(fila *p){
  if (p->qtd==0) {
    return 0;
  }
  else{
    return p->vet[0];
  }
}
fila *alocaFila(fila *p){
  p = (fila*)malloc(sizeof(fila));
  printf("Qual o tamanho da fila ? \n");
  scanf("%d",&p->tamanho );

  p->vet = (int*)malloc(sizeof(int)*p->tamanho);
  p->qtd = 0;
  return p;
}
