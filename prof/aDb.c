#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char p1[100], p2[100];
int qtd1=0, qtd2=0;

void push1(char x);
void push2(char x);
char pop1 ();
char pop2 ();
int empty1();
int empty2();

int main()
{
    char texto[100],aux;
    int i,tipo=0;
    printf("\n Digite um texto: ");
    gets(texto);

    for(i=0;i<strlen(texto);i++)
    {
        if (texto[i]=='D')
        {
            if (tipo ==0 || tipo ==2)
            {
                if (tipo==2 && !empty2())
                {
                    printf("\n errado ");
                    return 0;
                }
                tipo =1;
            }
            else
            {
                if (!empty1())
                {
                    printf("\n ERRADO");
                    return 0;
                }
                tipo = 2;
            }
        }
        else
        {
            switch(tipo)
            {
            case 0:
                push1(texto[i]);
                break;
            case 1:
                aux = pop1();
                if (aux!=texto[i])
                {
                    printf("\n ERRRADO");
                    return 0;
                }
                push2(texto[i]);
                break;
            case 2:

                aux = pop2();
                if (aux!=texto[i])
                {
                    printf("\n ERRRADO");
                    return 0;
                }
                push1(texto[i]);
                break;
            }
        }
    }

    if (tipo==1 && !empty1())
    {
        printf("\n errado");
        return 0;
    }
    if (tipo==2 && !empty2())
    {
        printf("\n errado");
        return 0;
    }

    printf("acertou mizeravel!");

    return 0;
}

void push1(char x)
{
    if (qtd1==100)
    {
        printf("\n fila cheia");
        return;
    }
    else
    {
        p1[qtd1] = x;
        qtd1++;
    }
}

void push2(char x)
{
    if (qtd2==100)
    {
        printf("\n pilha cheia");
        return;
    }
    else
    {
        p2[qtd2] = x;
        qtd2++;
    }
}


char pop1 ()
{
    char aux;
    if (qtd1==0)
    {
        printf("\n pilha vazia");
    }
    else
    {
        aux = p1[qtd1-1];
        qtd1--;
        return aux;
    }
}

char pop2 ()
{
    char aux;
    if (qtd2==0)
    {
        printf("\n pilha vazia");
    }
    else
    {
        aux = p2[qtd2-1];
        qtd2--;
        return aux;
    }
}

int empty1()
{
    if (qtd1==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int empty2()
{
    if (qtd2==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
