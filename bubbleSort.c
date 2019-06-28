#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int vet[10],int n);

int main() {
  clock_t begin,end;

  int vet[10],i,n;
  n=10;

  double tempo;
    begin = clock();

  for ( i = 0; i < 10; i++) {
      vet[i] = rand() %10;
      printf("%d ",vet[i]);
  }
  puts("\n");

  bubbleSort(vet,n);

  for (i = 0;i < n;i++) {
    printf("%d ",vet[i]);
  }
puts("\n");

  tempo = clock() - 1;
  tempo = (tempo) /CLOCKS_PER_SEC;
  printf("%fs\n",tempo);

  return 0;
}

void bubbleSort(int vet[10],int n) {
  int i,j,aux,troca = 1;

  for ( i = 0; i < n-1 && troca ==1; i++) {
    troca = 0;
    for (j = 0; j < n-1; j++) {
      if (vet[j] > vet[j+1]) {
        troca =1;
        aux = vet[j];
        vet[j] = vet[j+1];
        vet[j+1] = aux;
      }
    }
  }

}
