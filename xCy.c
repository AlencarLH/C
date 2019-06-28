#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char pilha[100],pilha2[100];
int qtd=0,qtd2=0;

void push1(char x);
void push2(char x);
char pop1();
char pop2();
int empty1();
int empty2();

int main() {
  char texto[100];
  char texto2[100];
  char aux;
  int i,j;
  int tipo=0;

  gets(texto);

  for ( i = 0; i < strlen(texto); i++) {
    push1(texto[i]);
}

  while (texto[i]!='C') {
    aux = pop1();
    push2(aux);
  }

  printf("%s\n",texto2);


/*
  if (texto == texto2) {
    printf("CERTO\n");
  }
  else{
    printf("ERRO\n");
  }
*/


/*
  for ( j = 0; j < strlen(texto); j++) {
      printf("%s\n",texto);
  }
*/

  return 0;
}

void push1(char x){
  if (qtd==100) {
    printf("pilha cheia\n");
  }
  else{
    pilha[qtd]=x;
    qtd++;

  }
}
void push2(char x){
  if (qtd2==100) {
    printf("pilha cheia\n");
  }
  else{
    pilha2[qtd2]=x;
    qtd2++;

  }
}

char pop1(){
  if (qtd==0) {
    return ' ';
  }
  else{
    char aux;
    aux = pilha[qtd-1];
    qtd--;
    return aux;
  }
}

char pop2(){
  if (qtd2==0) {

    return ' ';
  }
  else{
    char aux;
    aux = pilha2[qtd2-1];
    qtd2--;
    return aux;
  }
}

int empty1(){
  if (qtd==0) {
    return 1;
  }
  else{
    return 0;
  }
}

int empty2(){
  if (qtd2==0) {
    return 1;
  }
  else{
    return 0;
  }
}
