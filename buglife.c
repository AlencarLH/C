#include <stdio.h>
#include <stdlib.h>

typedef struct vertice {
    int visitado;
    int cor;
    struct lista *lista_adj;
} vertice;

typedef struct lista {
    int qtd;
    struct registro *inicio;
} lista;

typedef struct registro {
    int valor;
    struct registro *prox;
} registro;

vertice *aloca_vertice();
lista *aloca_lista();
registro *aloca_registro();
void incluir(lista *l, int x);
void append_vertice(vertice *v, int x);
int dfs(vertice *vertices, int x, int cor);

int main() {
    int num_scenarios;
    scanf("%d", &num_scenarios);

    int resultado[10000];

    for (int casos = 0; casos < num_scenarios; casos++) {
        int num_bugs, num_interactions;
        scanf("%d %d", &num_bugs, &num_interactions);

        vertice *vertices = (vertice *)calloc(num_bugs + 1, sizeof(vertice));

        int x, y;
        for (int i = 0; i < num_interactions; i++) {
            scanf("%d %d", &x, &y);
            append_vertice(&vertices[x], y);
            append_vertice(&vertices[y], x);
        }

        int suspicious = 0;

        for (int i = 1; i <= num_bugs; i++) {
            if (vertices[i].visitado == 0) {
                if (dfs(vertices, i, 1) == 0) {
                    suspicious = 1;
                    break;
                }
            }
        }

        resultado[casos] = suspicious;

        for (int i = 1; i <= num_bugs; i++) {
            free(vertices[i].lista_adj);
        }
        free(vertices);
    }

    for (int casos = 0; casos < num_scenarios; casos++) {
        printf("Scenario #%d:\n", casos + 1);
        if (resultado[casos]) {
            printf("Suspicious bugs found!\n");
        } else {
            printf("No suspicious bugs found!\n");
        }
    }

    return 0;
}

lista *aloca_lista() {
    lista *novo = (lista *)calloc(1, sizeof(lista));
    return novo;
}

registro *aloca_registro() {
    registro *novo = (registro *)calloc(1, sizeof(registro));
    return novo;
}

void incluir(lista *l, int x) {
    registro *novo, *aux;

    novo = aloca_registro();
    novo->valor = x;

    if (l->inicio == NULL) {
        l->inicio = novo;
    } else {
        aux = l->inicio;

        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
    l->qtd++;
}

void append_vertice(vertice *v, int x) {
    v->lista_adj == NULL ? v->lista_adj = aloca_lista() : NULL;
    incluir(v->lista_adj, x);
}

int dfs(vertice *vertices, int x, int cor) {
    registro *aux;
    vertices[x].visitado = 1;
    vertices[x].cor = cor;

    if (vertices[x].lista_adj == NULL) {
        return 1;
    }

    aux = vertices[x].lista_adj->inicio;

    while (aux != NULL) {
        if (vertices[aux->valor].visitado == 0) {
            if (dfs(vertices, aux->valor, -cor) == 0) {
                return 0;
            }
        } else if (vertices[aux->valor].cor == vertices[x].cor) {
            return 0;
        }
        aux = aux->prox;
    }

    return 1;
}


