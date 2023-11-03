#include <stdio.h>
#include <stdlib.h>

typedef struct vertice{
    int visitado;
    int distancia;
    struct lista *lista_adj;
}vertice;

typedef struct lista{
    int qtd;
    struct registro *inicio;
    struct registro *fim;
}lista;

typedef struct registro{
    int valor;
    struct registro *prox;
}registro;

lista *aloca_lista(){
    lista *novo = (lista*)calloc(1,sizeof(lista));
    return novo;
}

registro *aloca_registro(){
    registro *novo = (registro*)calloc(1,sizeof(registro));
    return novo;
}

void incluir(lista *l, int x){
    registro *novo = aloca_registro();
    novo->valor = x;

    if(l->inicio == NULL){
        l->inicio = novo;
        l->fim = novo;
    }else{
        l->fim->prox = novo;
        l->fim = novo;
    }
    l->qtd++;
}

void mostrar_lista(lista *l){
    registro *aux;

    aux = l->inicio;
    while (aux!=NULL)
    {
        printf("-> %d ", aux->valor);
        aux = aux->prox;
    }
}

int pop(lista *l){

    if(l->qtd <= 0){
        return -1;
    }else{
        int retorno;
        retorno = l->inicio->valor;
        l->inicio = l->inicio->prox;
        l->qtd--;
        return retorno;
    }
}

void append_vertice(vertice *v, int x){

    v->lista_adj == NULL ? v->lista_adj = aloca_lista(): NULL;
    incluir(v->lista_adj, x); 
}

void bfs(vertice *v, int raiz){
    int filho, current =0;
    lista *l = aloca_lista();

    v[raiz].distancia = 0;
    incluir(l, raiz);

    while (l->qtd > 0)
    {

        current = pop(l);
        
        if(v[current].visitado == 0){
            printf("\n %d", current);
            v[current].visitado = 1;

            registro *aux = v[current].lista_adj->inicio;

            while(aux!=NULL){
                if(v[filho].visitado == 0){
                   filho = aux->valor;
                    incluir(l, filho);

                    v[filho].distancia = v[current].distancia + 1;
                                       
                }
                aux = aux->prox;
            }

        }


    }
    

}


int main(int argc, char const *argv[])
{

    lista *l = aloca_lista();

    printf("\nvertices e arestas\n");
    int qtd_vertices, qtd_arestas, a,b =0;

    scanf("%d %d", &qtd_vertices, &qtd_arestas);
    
    vertice *v = (vertice*)calloc(qtd_vertices+1,sizeof(vertice));

    for (int i = 0; i < qtd_arestas; i++)
    {
        scanf("%d %d", &a, &b);

        append_vertice(&v[a], b);
        append_vertice(&v[b], a);

    }
     
    bfs(v,1);

    return 0;
}
























/*
#include <stdio.h>
#include <stdlib.h>

typedef struct vertice{
    int visitado;
    int distancia;
    struct lista *lista_adj;
}vertice;

typedef struct lista{
    int qtd;
    struct registro *inicio; //será usado como primeiro elemento da fila
    struct registro *fim; //será usado como ultimo elemento da fila
}lista;

typedef struct registro{
    int valor;
    struct registro *prox;
}registro;

lista *aloca_lista();
registro *aloca_registro();
void incluir_queue(lista *l, int x);
int pop_queue( lista *l);
void mostrar_lista(lista *l);
void append_vertice(vertice *v, int x);
void bfs(vertice *v, int raiz);

int main(int argc, char const *argv[])
{   
    int x,quit = 0;
    int a,b = 0;
    int qtd_vertices, qtd_arestas = 0;    
    lista *l = aloca_lista();
    vertice *v = (vertice*)calloc(qtd_vertices+1,sizeof(vertice));
   
    printf("\n Qtd de vertices\n");
    scanf("%d",&qtd_vertices);

    printf("\n Qtd de arestas\n");
    scanf("%d", &qtd_arestas);


    for(int i =0; i<qtd_arestas; i++){
        scanf("%d %d", &a, &b);
        append_vertice(&v[a], b);
        append_vertice(&v[b], a);
    
    }

    printf("\nordem de chamadas BFS\n");
    bfs(v,1);

    return 0;
}

lista *aloca_lista(){
    lista *novo = (lista*)calloc(1,sizeof(lista));
    return novo;
}


registro *aloca_registro(){
    registro *novo = (registro*)calloc(1,sizeof(registro));
    return novo;
}


void incluir_queue(lista *l, int x){
    registro *novo,*aux;
    novo = aloca_registro();
    novo->valor = x;

    if(l->qtd == 0){
        l->inicio = novo;
        l->fim = novo;
    }else{
        l->fim->prox = novo;
        l->fim = novo;

    }
    l->qtd++;
}

int pop_queue( lista *l){
   
    int retorno;
    
    if(l->qtd == 0){
        return -1;
    }else{
        retorno = l->inicio->valor;
        l->inicio = l->inicio->prox;
        l->qtd--;
        return retorno;
    }
}

void append_vertice(vertice *v, int x){
    if(v->lista_adj == NULL){
        v->lista_adj = aloca_lista();
    }else{
        incluir_queue(v->lista_adj, x);
    }
}

void mostrar_lista(lista *l){
    registro *aux;

    aux = l->inicio;

    while (aux->prox != NULL)
    {
        printf("\n[%d]->", aux->valor);
        aux = aux->prox;
    }
    
}
void bfs(vertice *v, int raiz) {
    lista *l = aloca_lista();
    int current, filho;

    incluir_queue(l, raiz);

    while (l->qtd > 0) {
        current = pop_queue(l);
        if (v[current].visitado == 0) {
            printf(" -> [%d]", current);
        }
       
        v[current].visitado = 1;

        registro *aux = v[current].lista_adj->inicio;
        while (aux != NULL) {
            filho = aux->valor;

            if (v[filho].visitado == 0) {
        printf("oi");
                printf("distancia da raiz: %d\n", v[filho].distancia);
                v[filho].distancia = v[current].distancia + 1;
                incluir_queue(l, filho);
            }
            aux = aux->prox;
        }
    }
}

*/
