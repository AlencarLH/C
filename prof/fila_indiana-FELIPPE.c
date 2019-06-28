#include <stdio.h>
#include <stdlib.h>

void push(int x);
int pop();
int stackpop();


int vet[10];

int qtd=0;

int main()
{
    int opcao;
    int numero;

    do
    {
        printf("\n 1- push");
        printf("\n 2- pop");
        printf("\n 3- stackpop");
        scanf("%d",&opcao);

        switch (opcao)
        {
        case 1:
            printf("\n qual numero deseja inserir");
            scanf("%d",&numero);
            push(numero);
            break;
        case 2:
            numero = pop();
            if (numero>=0)
            {
                 printf("\n numero que saiu: %d",numero);
            }

            break;
        case 3:
            numero = stackpop();
            if (numero>=0)
            {
                 printf("\n numero que esta no topo %d",numero);
            }


            break;
        case 4:
            printf("\n saindo do programa");
            break;
        default:
            printf("\n opcao invalida");
            break;
        }


    }while(opcao!=4);
    return 0;


}


void push(int x)
{
    if (qtd==10)
    {
        printf("fila cheia");
    }
    else
    {
        vet[qtd] = x;
        qtd++;
    }
}

int pop()
{
    int aux;
    int i;
    if (qtd==0)
    {
        printf("\n Fila vazia");
        return -1;
    }
    else
    {
        aux = vet[0];


        for(i=0;i<qtd;i++)
        {
            vet[i] = vet[i+1];
        }

        qtd--;
        return aux;

    }
}

int stackpop()
{
    if (qtd==0)
    {
        printf("\n ninguem na fila");
        return -1;
    }
    else
    {
        return vet[0];
    }

}



