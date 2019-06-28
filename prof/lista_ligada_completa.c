#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int qtd;
    struct registro * inicio;
} lista;

typedef struct registro
{
    int valor;
    struct registro * prox;
} registro;

lista * aloca_lista();
registro * aloca_registro();
void incluir_no_fim(lista * l, int x);
void mostrar(lista * l);
void menu(lista * l);
registro * buscar(lista * l, int x);
int remover(lista * l, int x);
void incluir_no_inicio(lista * l,int x);

int main()
{
    lista * l1;
    l1 = aloca_lista();
    menu(l1);
    return 0;
}

lista * aloca_lista()
{
    lista * novo;
    novo =(lista*)malloc(sizeof(lista));
    novo->qtd=0;
    novo->inicio=NULL;
    return novo;
}

registro * aloca_registro()
{
    registro * novo;
    novo=(registro*)malloc(sizeof(registro));
    novo->valor=0;
    novo->prox=NULL;
    return novo;
}

void incluir_no_fim(lista * l, int x)
{
    registro * novo, * aux;
    novo = aloca_registro();
    novo->valor=x;

    if (l->inicio==NULL)
    {
        l->inicio=novo;
    }
    else
    {
        aux = l->inicio;
        while(aux->prox!=NULL)
        {
            aux=aux->prox;
        }
        aux->prox=novo;
    }
    l->qtd++;
}

void mostrar(lista * l)
{
    registro * aux;

    if (l->inicio==NULL)
    {
        printf("\n Nao existem elementos");
    }
    else
    {
        aux = l->inicio;
        while(aux!=NULL)
        {
            printf(" %d",aux->valor);
            aux = aux->prox;
        }
    }
}

registro * buscar(lista * l, int x)
{
    registro * aux;
    if (l->inicio==NULL)
    {
        return NULL;
    }
    else
    {
        aux=l->inicio;

        while(aux->valor!=x && aux->prox!=NULL)
        {
            aux = aux->prox;
        }

        if ( aux->valor == x)
        {
            return aux;
        }
        else
        {
            return NULL;
        }

    }
}

int remover(lista * l, int x)
{
    registro * ant=NULL, * aux=l->inicio;

    if (l->inicio==NULL)
    {
        return 0;
    }
    else
    {
        while(aux->valor!=x && aux->prox!=NULL)
        {
            ant=aux;
            aux=aux->prox;
        }
        if (aux->valor == x)
        {
            if (ant==NULL)
            {
                l->inicio = aux->prox;
            }
            else
            {
                ant->prox=aux->prox;
            }
            l->qtd--;
            free(aux);
            return 1;
        }
        else
        {
            return 0;
        }
    }
}


void menu(lista * l)
{
    int opcao;
    int numero;

    registro * aux;

    do
    {
        printf("\n 1  - Incluir_no_inicio");
        printf("\n 2  - Incluir_no_final");
        printf("\n 3  - Mostrar");
        printf("\n 4  - Buscar");
        printf("\n 5  - Remover");
        printf("\n 10 - Sair");
        scanf("%d",&opcao);

        switch (opcao)
        {
        case 1:
            printf("\n Digite o numero que deseja inserir");
            scanf("%d",&numero);            incluir_no_inicio(l,numero);

            break;
        case 2:
            printf("\n Digite o numero que deseja inserir: ");
            scanf("%d",&numero);
            incluir_no_fim(l,numero);

            break;
        case 3:
            mostrar(l);
            break;
        case 4:
            printf("\n Digite o numero que deseja buscar: ");
            scanf("%d",&numero);
            aux = buscar(l,numero);
            if ( aux==NULL)
            {
                printf("\n Numero nao esta na lista");
            }
            else
            {
                printf("\n Numero %d encontrado",aux->valor);
            }
            break;
        case 5:
            printf("\n Qual numero deseja remover: ");
            scanf("%d",&numero);

            if(remover(l,numero))
            {
                printf("numero removido com sucesso");
            }
            else
            {
                printf("\n Numero nao esta na lista");
            }
            break;
        case 10:
            printf("\n Saindo do programa");
            break;
        default:
            printf("\n opcao invalida");
            break;
        }
    }
    while(opcao!=10);
}

void incluir_no_inicio(lista * l,int x)
{
    registro * novo;
    novo = aloca_registro();
    novo->valor = x;
    novo->prox = l->inicio;
    l->inicio=novo;
    l->qtd++;
}
