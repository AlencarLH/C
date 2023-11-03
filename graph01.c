
#include <stdlib.h>
#include <stdio.h>

int qtd=0;

typedef struct vertice{
    int visitado;
    int vetor_adj[1000];
    int vetor_adj_size;
}vertice;

void mostrar_grafo(vertice *v, int qtd_vertices);
void dfs(vertice * vertices , int x);

int main(){

    vertice *vertices;
    int qtd_vertices=0, qtd_arestas = 0;
    int x=0,y =0;

    printf("\ninsira a quantidade de vertices seguida da quantidade de arestas\n");
	printf("----------------------------------------------------------------\n");
    scanf("%d %d",&qtd_vertices, &qtd_arestas);

    vertices = (vertice*)calloc(qtd_vertices+1, sizeof(vertice));
    
    int i = 0;

    while(i < qtd_arestas)
    {
        printf("\nInsira os vertices\n");
        scanf("%d %d", &x, &y);

        vertices[x].vetor_adj[vertices[x].visitado] = y;
        vertices[x].visitado++;
        printf("%d conectado a %d\n", x,y);

        vertices[y].vetor_adj[vertices[y].visitado] = x;
        vertices[y].visitado++;
        
       // vertices[x].vetor_adj[vertices[x].vetor_adj_size] = y;
       // vertices[x].vetor_adj_size++;
//
       // vertices[y].vetor_adj[vertices[y].vetor_adj_size] = x;
       // vertices[y].vetor_adj_size++;

        printf("%d",i);
        i++;
    }

    printf("\n==== Displaying graph ====\n");
    mostrar_grafo(vertices, qtd_vertices);

    printf("\ncalling DFS\n");
    dfs(vertices, 1);

    return 0;
}

void mostrar_grafo(vertice *v, int qtd_vertices){

   // loop responsável por percorrer o vetor de vértices
    for(int j = 1; j < qtd_vertices; j++)
    {
        printf(" vertice %d -> ", j);

        // loop principal: verifica cada elemento do vetor de adjacencias 
        // do vertice na posição J do vetor de vertices
        for(int k = 0; k < v[j].vetor_adj[k]; k++)
        {
            printf("%d ", v[j].vetor_adj[k]);
        }
        printf("\n");
    }

}

void dfs(vertice *vertices, int x) {
    vertices[x].visitado = 1;
    int aux = 0;
    qtd++;

    if (vertices[x].vetor_adj[aux] == 0) {
        return;
    }

    aux = vertices[x].vetor_adj[aux];

    while (aux != 0) {
        if (vertices[aux].vetor_adj[vertices[aux].visitado] == 0) {
            printf("\n >> elemento %d:. ", x);         
            printf("\n%d", aux);

            dfs(vertices, aux);
        }
        aux = vertices[x].vetor_adj[aux];
    }
}
