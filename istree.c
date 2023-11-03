#include <stdio.h>
#include <stdlib.h>
int cc=0;

typedef struct vertice{

    int visitado;
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

void mostrar_lista(lista *l);
int incluir(lista *l, int x);
lista *aloca_lista();
registro *aloca_registro();
void append_vertice(vertice *v, int x);
void dfs(vertice *v, int raiz);


int main(int argc, char const *argv[])
{

    lista *l = aloca_lista();
    int qtd_vertices, qtd_arestas = 0;
    int a,b = 0;

   // printf("Qtd de vertices e arestas\n");
    scanf("%d %d", &qtd_vertices, &qtd_arestas);

    vertice *v = (vertice*)calloc(qtd_vertices+1, sizeof(vertice));

    for(int i =0; i<qtd_arestas; i++){
        scanf("%d %d", &a, &b);
        append_vertice(&v[a], b);
        append_vertice(&v[b], a);
    }

   // printf("\nChamando DFS:.    ");
    
    dfs(v,1);
    cc++;

    if(qtd_arestas == qtd_vertices-1 && cc == 1){
        printf("\nYES");
    }

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

void append_vertice(vertice *v, int x){
    v->lista_adj == NULL ? v->lista_adj = aloca_lista() : NULL;
    incluir(v->lista_adj, x);
}

int incluir(lista *l, int x){

    registro *novo = aloca_registro();
    novo->valor = x;

    if(l->qtd <= 0){
        l->inicio = novo;
        l->fim = novo;
    }else{

        l->fim->prox = novo;
        l->fim = novo;
    }
    l->qtd++;
}

void mostrar_lista(lista *l){
    registro *aux = l->inicio;

    while (aux!= NULL)
    {
        printf("-> %d", aux->valor);
        aux= aux->prox;
    }
}

void dfs(vertice *v, int raiz){
    // 1 marca visitado
    v[raiz].visitado = 1;
    registro *aux;

    // 2 percorre lista de adj da raiz
    aux = v[raiz].lista_adj->inicio;
    while (aux!=NULL)
    {
        if(v[aux->valor].visitado == 0){
           // printf("\n-> elemento: %d\n", raiz);
           // mostrar_lista(v[raiz].lista_adj);
            dfs(v, aux->valor);
        }
        aux = aux->prox;
    }

}










/*
int qtd= 0;

typedef struct vertice{
    int visitado;
    struct lista *lista_adj;
}vertice;

typedef struct lista{
    int qtd;
    struct registro *inicio; 
}lista;

typedef struct registro{
    int valor;
    struct registro *prox;
}registro;

vertice *aloca_vertice();
lista *aloca_lista();
registro *aloca_registro();
void incluir(lista *l, int x);
void mostrar_lista(lista *l);
void append_vertice(vertice *v, int x);
void dfs(vertice * vertices , int x);

int main(){

    vertice *vertices;
    int qtd_vertices =0, qtd_arestas =0;
    int input;
    int x =0,y =0;

    int cc=0;

    printf("\ninsira a quantidade de vertices seguida da quantidade de arestas\n");
	printf("----------------------------------------------------------------\n");
    scanf("%d %d",&qtd_vertices, &qtd_arestas);
    
    vertices = (vertice*)calloc(qtd_vertices+1,sizeof(vertice));
    
    int i = 0;
    
    while(i < qtd_arestas)
    {
        printf("insira os vertices\n");
        scanf("%d %d",&x, &y);
        
        append_vertice(&vertices[x], y);
        append_vertice(&vertices[y], x);
      
        i++;
    }

    // incrementa a qtd de cc
    printf("\ncalling DFS\n");
   
    for(i=1;i<=qtd_vertices;i++)
    {
        if (vertices[i].visitado==0)
        {
            dfs(vertices,i);
            cc++;
        }
    }
    printf("\n Componentes conectados: %d", cc);

    //verifica se eh arvore
    if (cc == 1 && qtd_vertices - 1 == qtd_arestas)
        printf("\nYES\n");
    else
        printf("\nNO\n");

    return 0;
}



lista *aloca_lista(){
    lista *novo = (lista*)calloc(1,sizeof(lista));
    return novo;
}

registro *aloca_registro(){
    registro *novo = (registro*)calloc(1, sizeof(registro));
    return novo;
}

void incluir(lista *l, int x){
    registro *novo, *aux;

    novo = aloca_registro();
    novo->valor = x;

    if(l-> inicio == NULL){
        l->inicio = novo;
    }else{
        aux = l->inicio;
        
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novo;
    }
    l->qtd++;
}

void mostrar_lista(lista *l){
    registro *aux;
    aux = l->inicio;

    printf("\n mostrando lista:\n");
    while (aux!= NULL)
    {   
        
        printf(" -> %d ", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
}


void append_vertice(vertice *v, int x){
    v->lista_adj == NULL ? v->lista_adj = aloca_lista() : NULL;
    incluir(v->lista_adj, x);
}


void dfs(vertice * vertices , int x){
    registro * aux;
    //1 marca o elemento como visitado 
    vertices[x].visitado=1;
   // qtd++; //testar se precisa

    if (vertices[x].lista_adj==NULL){
        return;
    }

    //2 percorre a lista de adj do elemento        
    aux = vertices[x].lista_adj->inicio;

    while(aux!=NULL){
        //3 se nao tiver sido visitado mostra o conteudo dele e chama o dfs denovo    
        if (vertices[aux->valor].visitado==0){
           // printf("%d -> %d\n",x , aux->valor);
            printf("\n >> elemento %d:. ",x);
            mostrar_lista(vertices[x].lista_adj);
            dfs(vertices,aux->valor); 
          
        }
        aux = aux->prox;
    }

}


*/