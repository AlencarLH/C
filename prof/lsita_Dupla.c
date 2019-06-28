#include<stdio.h>
#include<stdlib.h>
typedef struct lista
{
    int qtd;
    struct no *inicio;
    struct no *fim;
}lista;
typedef struct no
{
    int valor;
    struct no * prox;
    struct no * ant;
}no;
lista* aloca_lista();
no * aloca_no();
void push_inicio(int x, lista * l);
void push_final(int x, lista *l);
void mostrar(lista l);
no * buscar(lista *l, int x);
int remocao(lista *l, int x);
void menu(lista * l);
int main()
{
    lista * l1;
    l1 = aloca_lista();

    menu(l1);
    return 0;
}

lista* aloca_lista()
{
 lista * novo;
    novo=(lista*)malloc(sizeof(lista));
    //novo=(lista*)calloc(1,sizeof(lista)); já inicializa os valores > PERIGO!
    novo->qtd=0;
    novo->inicio = NULL;
    novo->fim = NULL;
    return novo;
}

no * aloca_no(){
    no * novo;
    novo= (no*) malloc(sizeof(no));
    novo->valor=0;
    novo->prox=NULL;
    novo->ant=NULL;
    return novo;
}

void push_inicio(int x, lista * l){
    no * novo;
    no * aux;
    novo=aloca_no();
    novo->valor=x;
    if(l->inicio==NULL){
        l->inicio=novo;
        l->fim=novo;
    } else {
        aux = l->inicio;
        aux->ant = novo;
        novo->prox = aux;
        l->inicio = novo;
    }
    l->qtd++;
}

void push_final(int x, lista *l){
    no *novo, *aux;

    novo = aloca_no();
    novo->valor = x;

    if(l->inicio == NULL){
        l->inicio = novo;
        l->fim = novo;
    }
    else{
        aux = l->fim;
        aux->prox = novo;
        novo->ant = aux;
        l->fim = novo;

    }

    l->qtd++;



}



void mostrar(lista l)
{
    no * aux;

    if(l.inicio == NULL)
    {
        printf("Lista vazia!\n");
    }
    else
    {
        aux = l.inicio;

        while(aux != NULL )
        {
            printf("%d ", aux->valor);
            aux = aux->prox;
        }

    }
}


no * buscar(lista *l, int x)
{
    no * aux;

    if(l->inicio == NULL)
    {
        return NULL;
    }
    else
    {
        aux = l->inicio;

        while(aux != NULL)
        {
            if(aux->valor == x)
            {
                return aux;
            }
            else
            {
                aux = aux->prox;
            }
        }
        return NULL;
    }
}

int remocao(lista *l, int x){
    no *aux, *tras, *frente;

    aux = buscar(l, x);

    if(aux == NULL){
        return 0;
    }else{
       tras = aux->ant;
       frente = aux->prox;
            if(tras == NULL){
                l->inicio = frente;
            }else{
                tras->prox = frente;
            }
            if(frente == NULL){
                l->fim = tras;
            }else{
                frente->ant = tras;
            }
            l->qtd--;
            free(aux);
            return 1;
    }
}

void menu(lista * l)
{

    int opcao,numero,retorno;
    no * aux;
    do
    {
        printf("\n 1- incluir_inicio");
        printf("\n 2- incluir_fim");
        printf("\n 3- buscar ");
        printf("\n 4- mostrar");
        printf("\n 5- remover");
        printf("\n 6- sair");
        scanf("%d",&opcao);

        switch(opcao)
        {
        case 1:
           printf("\n Digite um numero: ");
           scanf("%d",&numero);
           push_inicio(numero,l);
           break;
        case 2:
           printf("\n Digite um numero: ");
           scanf("%d",&numero);
           push_final(numero,l);
           break;
        case 4:
            mostrar(*l);
            break;
        case 3:
            printf("\n Digite um numero: ");
            scanf("%d",&numero);
            aux = buscar(l,numero);

            if ( aux == NULL)
            {
                printf("\n Nao encontrado ");

            }
            else
            {
                printf("\n %d encontrado na lista",aux->valor);
            }
            break;
        case 5:
            printf("\n Digite o numero que deseja remover: ");
            scanf("%d",&numero);

            if (remocao(l,numero))
            {
                printf("\n Removido com sucesso");
            }
            else
            {
                printf("\n numero nao removido");
            }




        }

    }while(opcao!=6);
}

