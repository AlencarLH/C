#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct registro{
  int valor;
  char nome[20];
}registro;

void selectionSort(registro *vet,int n){
  int i,j,min;

  for ( i = 0; i < n-1; i++) {
    min = i;

      for ( j = i+1; j < n; j++)
        if (vet[j].valor < vet[min].valor)
          min = j;

          int aux = vet[min].valor;
          vet[min].valor = vet[i].valor;
          vet[i].valor = aux;


  }

}

int main(int argc, char const *argv[]) {
  srand(time(NULL));
  registro *vet;
  int n,i;


  printf("Quantas structs ?\n");
  scanf("%d",&n);


  vet = (registro*)calloc(1,sizeof(registro)*n);

  for ( i = 0; i < n; i++) {
    vet[i].valor = rand()%10;
    vet[i].nome[0] = 'a';
    printf("%d%s ",vet[i].valor,vet[0].nome);
  }

  selectionSort(vet,n);
  puts("\n");
  for ( i = 0; i < n; i++) {

    printf("%d%s ",vet[i].valor,vet[0].nome);
  }


  return 0;
}
