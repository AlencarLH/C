#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quickSort(int *vet,int left, int right){
  int i,j,pj,aux;

  i = left;
  j = right;

  pj = vet[(right + left)/2];

  do {
    while(vet[i] < pj && i < right)
      i++;

    while (vet[j] > pj && j > left)
      j--;

    if (i<=j) {
    aux = vet[i];
    vet[i] = vet[j];
    vet[j] = aux;
    i++;
    j--;
  }

  } while(i<=j);

  if (left < j)
    quickSort(vet,left,j);

  if(right> i)
    quickSort(vet,i,right);

}

int main() {

  int vet[10],i,j,n;


  for ( i = 0; i < 10; i++) {
    vet[i] = rand()%10;
    printf("%d",vet[i]);
  }

  puts("\n");

    quickSort(vet,0,10);

  for ( i = 0; i < 10; i++) {
    printf("%d",vet[i]);
  }

  return 0;
}
