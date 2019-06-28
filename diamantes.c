#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int qtd;
    int * valor;
}pilha;

pilha *alocaPilha();

int main(){
    char expressao[1001];
    int qtd2,tam,i,rey,j,N;
    pilha *p;

    scanf("%d",&N);

    for(i=0;i<N;i++){
        //free(p);
        p=alocaPilha();
        qtd2=0;
        fflush(stdin);
        gets(expressao);
        tam=strlen(expressao);
        for(j=0;j<tam;j++){
            if(expressao[j]=='<'){
                push(p,1);
            }else{
                if(expressao[j]=='>'){
                    rey=pop(p);
                    if(rey!=0){
                        qtd2++;
                    }
                }
            }
        }
        printf("%d\n",qtd2);
    }
    return 0;
}
pilha *alocaPilha(){
    pilha *novo;
    novo=(pilha*)malloc(sizeof(pilha));
    novo->qtd=0;
    novo->valor=NULL;
    return novo;
}
void push(pilha *p, int x){
    int *aux;
    if(p->qtd==0){
        p->valor=(int*)malloc(sizeof(int));
    }else{
        aux=(int*)realloc(p->valor,(p->qtd+1)*sizeof(int));
        p->valor=aux;
    }
    p->valor[p->qtd]=x;
    p->qtd++;
}
int pop(pilha *p){
    int *aux,levi;
    if(p->qtd==0){
        return 0;
    }else{
        if(p->qtd==1){
            free(p->valor);
        }else{
            levi=(int*)realloc(p->valor,(p->qtd-1)*sizeof(int));
        }
    }
    p->qtd--;
    return 1;
}
