#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//com problema depois refazer
void printVetor(long int *vet);
void bubbleSort(long int *vet);
void selectionSort(long int *vet);
void insertionSort(long int *vet);
void quickSort(long int *vet, int left, int right);
void mergeSort(long int *vet,int l,int r);
void intercala(long int *vet,int l,int m, int r);

int main() {
  //neste caso o vetor tem apenas 10 posicoes
  int opcao,i,n;
  long int *vet;

  srand(time(NULL));
  /*for ( i = 0; i < 9; i++) {
    vet[i] = rand() %10;
  }*/
    //  printf("\nVetor atual: ");

    printf("Diga o tamanho do vetor\n");
    scanf("%d",&n);

    vet = (long int*)malloc(sizeof(long int)*n);

      printVetor(vet);

  do {
    printf("Escolha um tipo de ordenacao");
    puts("\n1- Bubble sort");
    puts("2- Selection sort");
    puts("3- Insertion sort");
    puts("4- Quick sort");
    puts("5- Merge sort");
    puts("6- Sair");
      scanf("%d",&opcao);

    switch (opcao) {
      case 1:
        bubbleSort(vet);
        printf("\nVetor ordenado:\n");
        printVetor(vet);
      break;

      case 2:
        selectionSort(vet);
        printf("\nVetor ordenado:\n");
        printVetor(vet);
      break;

      case 3:
        insertionSort(vet);
        printf("\nVetor ordenado:\n");
        printVetor(vet);
      break;

      case 4:
        quickSort(vet,0,9);
        printf("\nVetor ordenado:\n");
        printVetor(vet);
      break;

      case 5:
        mergeSort(vet,0,9);
        printf("\nVetor ordenado:\n");
        printVetor(vet);
      break;

      case 6:
      printf("Saindo do programa...\n");
      break;

    }

  } while(opcao!=6);



  return 0;
}

void printVetor(long int *vet){
  int i;
   int n;

  for ( i = 0; i < n-1; i++) {
    printf("%d ",vet[i]);
  }
  puts("\n");
  return;
}

void bubbleSort(long int *vet) {
  int i,j,aux,troca = 1;
   int n;

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
  return;
}


void selectionSort(long int *vet){
  int i,j,aux;
  int menor;
   int n;

  for ( i = 0; i < n-1; i++) {
    menor = i;
    for ( j = i+1; j < n-1; j++) {
      if (vet[j] < vet[menor]) {
        menor = j;
      }
    }
    aux = vet[i];
    vet[i] = vet[menor];
    vet[menor] = aux;
  }
  return;
}


void insertionSort(long int *vet){
  int i,j,iaux;
   int n;
    for ( i = 0; i < n-1; i++) {
        iaux = vet[i]; //importante declarar essa desgraça aqui e nao la em cima

      for ( j = i-1; j>=0 && iaux < vet[j]; j--) {
        vet[j+1] = vet[j];
      }
    vet[j+1] = iaux;
    }
    return;
}

void quickSort(long int *vet, int left, int right){
  int i,j,aux,pivo;
  i = left;
  j = right;

  pivo = vet[(left+right)/2]; //pivo no meio

  do {
    while (vet[i] < pivo &&  i < right) {
      i++;  //incrementa i enquanto i for menor que o pivo && max do vetor
    }

    while (vet[j] > pivo && j>left) {
      j--; //mesma coisa no lado direito do pivo
    }

    if (i <= j) {
      //troca
      aux = vet[i];
      vet[i] = vet[j];
      vet[j] = aux;

      i++;
      j--;
    }
  } while(i<=j);

  if (left < j) {
    quickSort(vet,left,j);
  }

  if (right > i) {
    quickSort(vet,i,right);
  }
  return;
}




void mergeSort(long int *vet,int l,int r){
  int m =(l+r)/2;

  if (l < r) {
    mergeSort(vet,l,m);
    mergeSort(vet,m+1,r);
    intercala(vet,l,m,r);
  }
  return;
}

void intercala(long int *vet,int l,int m, int r){

  int i,j,k,*aux;
  aux = (int*)calloc(sizeof(int), r - l+1);

  i = l;
  j = m+1;
  k = 0;

  while (i <= m && j<=r) { //i menor que meio, j menor que o ultimo

    if (vet[i] <= vet[j]) {
      aux[k] = vet[i];
      i++;  //se vet[i] <= vet[j] joga os elementos desse lado no vetor auxiliar
    }
    else{
      aux[k] = vet[j];
      j++; //senao joga os elementos desse outro lado no vetor auxiliar
    }
    k++;  //incrementa o contador do auxiliar
  }

  while (i <= m) {
    aux[k] = vet[i];
    i++;
    k++;
  }
  while (j <= r) {
    aux[k] = vet[j];
    j++;
    k++;
  }

  for (i = 0; i < (r-l)+1; i++) {
    vet[l+i] = aux[i];      //copia os elementos do vet aux pro vet normal
  }
  free(aux);
  return;
}
