#include <stdlib.h>
#include <stdio.h>


int intercala(int *vet, int l, int pj, int r){
  int i,j,k;

  int p1 = pj-l +1;
  int p2 = r-pj;

  int aux[p1],aux2[p2];

  for(i=0;i<p1;i++)
    aux[i] = vet[l+i];

  for(j = 0; j < p2; j++)
    aux2[j] = vet[pj + 1 + j];


}




int main(int argc, char const *argv[]) {


  return 0;
}
