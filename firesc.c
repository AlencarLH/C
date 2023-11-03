#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct amigos{
    int tamanho;
    int* pai;
    int* tamanho_grupo;
} amigos;

typedef struct Grafo{
    int tamanho;
    bool* visitado;
    int* num_amigos;
}Grafo;

amigos* aloca_conjunto(int n);
Grafo* aloca_grafo(int n);
int encontrar(amigos* grupo, int x);
void append_grupos(amigos* grupo, int a, int b);
void dfs(Grafo* grafo, amigos* grupo, int v);

int main(){
    int t;
    scanf("%d", &t);

    int *resultados = (int*)malloc(t * 2 * sizeof(int));

    for (int i = 0; i < t; i++){
        int n, m; 
        int numRotas = 0;
        int numFormas = 1;

        scanf("%d %d", &n, &m);

        amigos* conjunto = aloca_conjunto(n);
        Grafo* grafo = aloca_grafo(n);

        for (int j = 0; j < m; j++){
            int a, b;
            scanf("%d %d", &a, &b);
            
            grafo->num_amigos[a]++;
            grafo->num_amigos[b]++;
            
            dfs(grafo, conjunto, a);
        }

       
        for (int j = 1; j <= n; j++){
           
            if (conjunto->pai[j] == j){
                numRotas++;
                numFormas = (numFormas * conjunto->tamanho_grupo[j]) % 1000000007;
            }
        }

        resultados[i * 2] = numRotas;
        resultados[i * 2 + 1] = numFormas;

    }

        printf("\n-----\n");
    for (int i = 0; i < t; i++){
        printf("%d %lld\n", resultados[i * 2], resultados[i * 2 + 1]);
    }

    free(resultados);

    return 0;
}



//conjuntos de amigos
amigos* aloca_conjunto(int n) 
{

    amigos* conjunto = (amigos*)malloc(sizeof(amigos));
    conjunto->tamanho = n;

    conjunto->pai = (int*)malloc((n + 1) * sizeof(int));
    conjunto->tamanho_grupo = (int*)calloc(n + 1, sizeof(int));

    for (int i = 1; i <= n; i++){
        conjunto->pai[i] = i;
        conjunto->tamanho_grupo[i] = 1;
    }

    return conjunto;
}

Grafo* aloca_grafo(int n){
    Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));
    grafo->tamanho = n;

    grafo->visitado = (bool*)calloc(n + 1, sizeof(bool));
    grafo->num_amigos = (int*)calloc(n + 1, sizeof(int));

    return grafo;
}

int encontrar(amigos* grupo, int x) 
{
    if (grupo->pai[x] == x)
        return x;
    return grupo->pai[x] = encontrar(grupo, grupo->pai[x]);
}

void append_grupos(amigos* grupo, int a, int b) 
{
    int raizA = encontrar(grupo, a);
    int raizB = encontrar(grupo, b);

    if (raizA != raizB) {
        grupo->pai[raizA] = raizB;
        grupo->tamanho_grupo[raizB] += grupo->tamanho_grupo[raizA];
    }
}

void dfs(Grafo* grafo, amigos* grupo, int v)
{
    grafo->visitado[v] = true;

    for (int i = 1; i <= grafo->tamanho; i++){
        if (!grafo->visitado[i] && grafo->num_amigos[i] > 0 && grupo->pai[i] != grupo->pai[v]) {
            append_grupos(grupo, i, v);
            dfs(grafo, grupo, i);
        }
    }
}