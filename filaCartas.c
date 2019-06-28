#include <stdio.h>
#include <stdlib.h>
//cartas

int fila[50];
int qtd=0;
void push(int x);
int pop();

int main(){
int n,i,aux;

    do
    {
        printf("Digite um numero\n");
        scanf("%d",&n);

        for(i=0;i<n;i++){
            push(i+1);
          }
        printf("\nDescartadas : \n");
        while(qtd>=2){
            aux = pop();
            printf("%d ",aux);
            aux = pop();
            push(aux);

          }


        aux = pop();
      printf("\n carta que sobrou: %d\n ",aux);

    }while(n!=0);

    return 0;
}

void push(int x){
    if(qtd>=50){
        printf("Fila cheia men");
    }
    else{
        fila[qtd]=x;
        qtd++;
    }
}

int pop(){
    int aux,i;
    if(qtd<=0){
        printf("Fila vazia");
        return 0;
    }
    else{
        aux = fila[0];
        for( i=0;i<qtd-1;i++){
            fila[i]=fila[i+1];

        }
        qtd--;
        return aux;
    }
}
