#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct registro

{

int codigo;

char nome[50];

}registro;

void insertionSort(registro *arr,int n){
  int i, key, j;
   for (i = 1; i < n; i++) {
       key = arr[i].codigo;
       j = i - 1;

       /* Move elements of arr[0..i-1], that are
         greater than key, to one position ahead
         of their current position */
       while (j >= 0 && arr[j].codigo > key) {
           arr[j + 1].codigo = arr[j].codigo;
           j = j - 1;
       }
       arr[j + 1].codigo = key;
   }

}


int main() {

  srand(time(NULL));
  registro *r;
  int num,i;

  printf("Quantas structs devem existir ?\n");
  scanf("%d",&num);


  r = (registro*)calloc(1,sizeof(registro)*num);

  r[i].nome[0] = 'a';

    for ( i = 0; i < num; i++) {
    r[i].codigo = rand()%10;
  printf("%d%s ",r[i].codigo,r[0].nome);
  }

  insertionSort(r,num);
  puts("\n");
  for ( i = 0; i < num; i++) {

  printf("%d%s ",r[i].codigo,r[0].nome);
  }

  return 0;
}
