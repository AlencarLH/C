#include <stdio.h>
#include <stdlib.h>

typedef struct vertice{
    int distancia;
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

lista *aloca_lista();
registro *aloca_registro();
void incluir(lista *l, int x);
int pop(lista *l);
void append_vertice(vertice *v, int x);
int bfs(vertice *v, int raiz, int qtd_vertices);

int main(int argc, char const *argv[])
{
    int qtd_vertices, qtd_arestas = 0;
    int a,b = 0;
    int T; //casos de teste
    int k=0;
    int resposta[1000];
    int i= 0;

    scanf("%d", &T);
   
    do{
        scanf("%d %d", &qtd_vertices, &qtd_arestas);
        vertice *v = (vertice *)calloc(qtd_vertices + 1, sizeof(vertice));
        i = 0;
        for(i; i < qtd_arestas; i++)
        {
            scanf("%d %d", &a, &b);

            append_vertice(&v[a], b);
            append_vertice(&v[b], a);            
        } 
        
       // printf("%d\n",bfs(v,1,qtd_vertices));
        
        resposta[k] = bfs(v,1,qtd_vertices);
        k++;
        
       

        T--;   
    }while(T>0);

    printf("\n");
    
    i = 0;
    for (i; i < k; i++)
        {   
            printf("%d\n", resposta[i]);
        }
       
    return 0;
}


int bfs(vertice *v, int raiz, int qtd_vertices){

    // 1 - incluir a raiz
    // 2 - enquanto a fila tiver gente, executa o loop
    // 3 - pop, e se o elemento nao tiver sido visitado 
    // 4 - mostra o elemento removido e marca como visitado
    // 5 - percorre a lista de adj do elemento removido, incluindo os valores

    int current, filho;
    //int resposta[1000];

    lista *l = aloca_lista();
    v[raiz].distancia = 0;
    // 1
    incluir(l, raiz);
    //2
    while (l->qtd > 0)
    {
        //3
        current = pop(l);
        if(v[current].visitado == 0){
            //4
          //  printf("->[%d]", current);
            v[current].visitado = 1;
            //5
            registro *aux = v[current].lista_adj->inicio;
            while (aux!=NULL)
            {
                filho = aux->valor;

                if(v[filho].visitado == 0){
                   // v[filho].visitado = 1;

                    incluir(l, filho);
                    v[filho].distancia = v[current].distancia + 1;
                    
                    
                    if(filho == qtd_vertices){
                       // printf(" Distancia do %d para a raiz: %d\n",filho, v[filho].distancia);
                        return v[filho].distancia;

                    }                  
                }
                aux = aux->prox;
            }
        }
    }
    
}

lista *aloca_lista(){
    lista *novo = (lista *)calloc(1, sizeof(lista));
    return novo;
}

registro *aloca_registro(){
    registro *novo = (registro *)calloc(1,sizeof(registro));
    return novo;
}

void append_vertice(vertice *v, int x){
    v->lista_adj == NULL ? v->lista_adj = aloca_lista() : NULL;
    incluir(v->lista_adj, x);
}

void incluir(lista *l, int x){
    registro *novo = aloca_registro();

    novo->valor = x;

    if(l->inicio == NULL){
        l-> inicio = novo;
        l-> fim = novo;
    }else{
        l->fim->prox = novo;
        l->fim = novo;
    }
    l->qtd++;
}

int pop(lista *l){
    int retorno;

    if(l->qtd <= 0){
        return -1;
    }else{
       retorno = l->inicio->valor;
       l->inicio = l->inicio->prox;
       l->qtd--;
       return retorno;
    }

}