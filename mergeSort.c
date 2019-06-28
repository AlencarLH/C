#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mergeSort(int vet[],int inicio, int fim){
  int i,j,k=0,*aux;

    if (inicio == fim)
      return;


  int meio = (inicio + fim)/2;
  i = inicio;
  j = meio+1;

  mergeSort(vet,inicio,meio);
  mergeSort(vet,meio+1,fim);

  aux = (int*)malloc(sizeof(int) * (meio+inicio+1));

  while (i<meio+1||j<fim+1) {
    if (i==meio+1) {
      aux[k] = vet[j];
      j++;
      k++;
    }else
      if(j==fim+1){
        aux[k] = vet[i];
        i++;
        k++;
    }else
      if(vet[i] < vet[j]){
        aux[k] = vet[i];
        i++;
        k++;
      }
  }

  for ( i = 0; i <= fim; i++) {
    vet[i] = aux[i-inicio];
  }
  free(aux);
  return ;

}

int main() {

  int i,j,vet[10],n;





  for ( i = 0; i < 10; i++) {
    vet[i] = rand() %10;
    printf("%d ",vet[i]);
  }

  mergeSort(vet,0,10);

  for ( i = 0; i < 10; i++) {

    printf("%d ",vet[i]);
  }


  return 0;
}
