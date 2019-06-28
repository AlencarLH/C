#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int *vet,int n){
  int i,j,key;

  for ( i = 0; i < n; i++) {
    key = vet[i];
    j = i-1;

    while (j>=0 && vet[j] > key) {
      vet[j+1] = vet[j];
      j = j-1;
    }
    vet[j+1] = key;
  }

}


int main() {

  int *vet;
  int i,n;

  printf("Qual o tamanho do vetor ?\n");
  scanf("%d",&n);

  vet = (int*)calloc(1,sizeof(int)*n);

  for ( i = 0; i < n; i++) {
    vet[i] = rand()%10;
    printf("%d ",vet[i]);
  }

  insertionSort(vet,n);
  puts("\n");
  for ( i = 0; i < n; i++) {
  //  vet[i] = rand()%10;
    printf("%d ",vet[i]);
  }




  return 0;
}


/*
  loop de 1 pra n
  mover os elementos que são maiores
  que a chave para uma posição a frente

*/
