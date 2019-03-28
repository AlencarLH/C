#include<stdlib.h>
#include<stdio.h>
#include<string.h>

char pilha[1001];
int qtd=0,topo;

int push(char x);
int pop();

int main() {
  char str[1000];
  int tenta,i,j,strSize,elementos,x;
  int *p;
  p = pilha;

  printf("numero de tentativas: \n");
  scanf("%d\n",&tenta);
  strSize = strlen(str);

  for ( i = 0; i < tenta; i++) {
    gets(str);
    elementos=0;
      for ( j = 0; j < strSize; j++) {
        if (str[j]=='<') {
          push(p);
        }
        else if(str[i]=='.'){
          x=pop(p);
        }
        else if(str[j]=='>'){
          x=pop(p);
          elementos++;
        }
      }
      printf("%d\n",elementos);
  }


  return 0;
}

int push(char x){
  if (qtd==topo) {
    return 0;
  }
  else{
    pilha[qtd] = x;
    qtd++;
    return 1;
  }
}

int pop(){
  char aux;
  if (qtd==0) {
    return 0;
  }
  else{
    aux = pilha[qtd];
    qtd--;
  }
}
