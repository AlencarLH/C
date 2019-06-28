#include <stdio.h>
#include <stdlib.h>

int vetor[30];
int qtd=0;

int main()
{
    int opcao,numero,retorno;

    do
    {
        printf("\n1  - Push");
        printf("\n2  - Pop ");
        printf("\n3  - Stackpop ");
        printf("\n4  - Size ");
        printf("\n5  - Empty ");
        printf("\n10 - Sair ");
        scanf("%d",&opcao);

        switch (opcao)
        {
        case 1:
            printf("\n Digite um numero que deseja inserir: ");
            scanf("%d",&numero);
            retorno=push(numero);
            if (retorno==1)
            {
                printf("\n inserido com sucesso");
            }
            else
            {
                printf("\n Pilha Cheia");
            }
            break;
        case 2:
            retorno = pop();
            if (retorno==0)
            {
                printf("\n Pilha vazia");
            }
            else
            {
                printf("\n Numero removido : %d",retorno);
            }
            break;
        case 3:
            retorno = stackpop();
            if ( retorno==0)
            {
                printf("\n Pilha vazia");
            }
            else
            {
                printf("\n NUmero no topo da pilha: %d",retorno);
            }

            break;
        case 4:
            printf("\n Tamanho da pilha :%d",size());
            break;
        case 5:
            if (empty())
            {
                printf("\n Pilha vazia");
            }
            else
            {
                printf("\n Pilha possui elementos.");
            }
            break;
        case 10:
            printf("\n Saindo do programa");
            break;
        default:
            printf("\n Opcao invalida");
            break;


        }
    }while(opcao!=10);

    return 0;
}

int push(int x)
{
   if (qtd==30)
   {
       return 0;
   }
   else
   {
       vetor[qtd] = x;
       qtd++;
       return 1;
   }
}

int pop()
{
    int aux;
    if (qtd<=0)
    {
        return 0;
    }
    else
    {
       aux = vetor[qtd-1];
       qtd--;

       return aux;
    }
}

int empty()
{
    if (qtd==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int size()
{
    return 30;
}

int stackpop()
{
    if (qtd==0)
    {
        return 0;
    }
    else
    {
        return vetor[qtd-1];
    }
}
