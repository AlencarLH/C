#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void bubbleSort(int *vet,int n){

  int i,j;
int flag=1;
  for ( i = 0; i < n-1 && flag == 1; i++) {
     flag = 0;
    for ( j = 0; j<n-i-1; j++) {

      if(vet[j]>vet[j+1]){
        flag =1;
      int aux = vet[j];
      vet[j] = vet[j+1];
      vet[j+1] = aux;
      }
    }

  }

}




int main(int argc, char const *argv[]) {
  int *vet;
  int num,i;
  srand(time(NULL));
  printf("digite o tamanho do vetor  ");
  scanf("%d",&num);

  //memset(vet,0,sizeof(num));

  for ( i = 0; i < num-1; i++) {
    vet[i] = rand()%10;
    printf("|%d ",vet[i]);
  }
  puts("\n");

  bubbleSort(vet,num);

    for ( i = 0; i < num-1; i++) {
      printf("|%d ",vet[i]);
    }

  return 0;
}
