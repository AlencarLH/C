#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencher_vetor(long int * vetor, long int n);
void mostrar_vetor(long int * vetor, long int n);
void mostrar_tempo(clock_t inicio, clock_t fim);


int main()
{
    long int n;
    long int * vetor;
    clock_t inicio, fim;


    printf("\n Digite N: ");
    scanf("%d",&n);

    vetor = (long int*)malloc(sizeof(long int)*n);

    inicio = clock();
    preencher_vetor(vetor,n);
    fim    = clock();
    printf("\n Mostrando tempo de Alocacao: ");
    mostrar_tempo(inicio,fim);

    inicio=clock();
    quicksort(vetor,0,n-1);
    fim   = clock();
    printf("\n Mostrando tempo de Ordenacao");
    mostrar_tempo(inicio,fim);



        inicio = clock();
        mostrar_vetor(vetor,n);
        fim    = clock();
        printf("\n Mostrando Tempo do Mostrar");
        mostrar_tempo(inicio,fim);




    return 0;
}

void preencher_vetor(long int * vetor, long int n)
{
    long int i;
    long int aux;

    /*
    srand(time(NULL));

    for(i=0; i<n; i++)
    {
        vetor[i] = rand() % n + 1;
    }
    */

    for(i=0;i<n;i++)
    {
        vetor[i] = 1;
    }






}

void mostrar_vetor(long int * vetor, long int n)
{
    long int i;
    printf("\n Mostrando Vetor: ");

    for(i=0; i<n; i++)
    {
        printf(" %d",vetor[i]);
    }

}

void mostrar_tempo(clock_t inicio, clock_t fim)
{
    printf("\n clock inicio = %lf",(double)inicio);
    printf("\n clock fim    = %lf",(double)fim);
    printf("\n clocks per second: = %lf",(double)CLOCKS_PER_SEC);
    printf ( "\n Tempo gasto %lf segundos\n", ((double)( fim - inicio ) / ((double)CLOCKS_PER_SEC )));
}


void bubblesort(long int * vetor, int n)
{
    int pass, i,trocou=1;
    long int aux;

    for(pass=0; pass<n-1 && trocou==1; pass++)
    {
        trocou=0;
        for(i=0; i<n-pass-1; i++)
        {
            if (vetor[i] > vetor[i+1])
            {
                trocou=1;
                aux = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = aux;
            }
        }
    }
}


void quicksort(long int * vetor, int ini, int fim)
{
    int pivo, aux;
    int troca1;
    long int troca2;
    pivo = ini;
    aux  = fim;

    while(pivo!=aux)
    {
        if (pivo<aux)
        {
            if (vetor[pivo]>vetor[aux])
            {

                troca1= pivo;
                pivo = aux;
                aux = troca1;

                troca2 = vetor[pivo];
                vetor[pivo] = vetor[aux];
                vetor[aux] =troca2;

            }
        }
        else
        {
            if (vetor[pivo]<vetor[aux])
            {

                troca1= pivo;
                pivo = aux;
                aux = troca1;

                troca2 = vetor[pivo];
                vetor[pivo] = vetor[aux];
                vetor[aux] =troca2;

            }

        }

        if ( pivo<aux)
        {
            aux--;
        }
        else
        {
            aux++;
        }

    }

    if (ini<pivo-1)
    {
        quicksort(vetor,ini,pivo-1);
    }

    if (fim>pivo+1)
    {
        quicksort(vetor,pivo+1,fim);
    }

}



