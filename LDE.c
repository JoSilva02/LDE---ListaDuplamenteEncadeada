#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura para o nó
typedef struct No {
    int valor;
    struct No *prox;
    struct No *ant;
} No;

typedef struct {
    No* inicio;
    No* fim;
} LDE;

// Função para criar uma lista duplamente encadeada
void add_no_fim(LDE* lista, int valor) {
    No* novo_no = (No*)malloc(sizeof(No));
    if (novo_no == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    novo_no->valor = valor;
    novo_no->prox = NULL;
    novo_no->ant = lista->fim;

    if (lista->fim != NULL) {
        lista->fim->prox = novo_no;
    } else {
        lista->inicio = novo_no;
    }
    lista->fim = novo_no;
}

// Função para encontrar a posição de um valor na lista
void find_position(LDE lista, int valor, int* pos_inicio, int* pos_fim) {
    No* no_atual = lista.inicio;
    No* no_final = lista.fim;
    *pos_inicio = 0;
    *pos_fim = 0;

    // Percorrendo a lista a partir do início
    while (no_atual != NULL) {
        (*pos_inicio)++;
        if (no_atual->valor == valor) {
            break;
        }
        no_atual = no_atual->prox;
    }

    // Percorrendo a lista a partir do fim
    while (no_final != NULL) {
        (*pos_fim)++;
        if (no_final->valor == valor) {
            break;
        }
        no_final = no_final->ant;
    }
}

// Função para liberar a memória alocada para a lista
void liberar_lista(LDE* lista) {
    No* atual = lista->inicio;
    No* prox;
    while (atual != NULL) {
        prox = atual->prox;
        free(atual);
        atual = prox;
    }
    lista->inicio = NULL;
    lista->fim = NULL;
}

int main() {
    LDE lista;
    lista.inicio = NULL;
    lista.fim = NULL;

    int elements[] = {1, 6, 2, 10, 4, 7, 3, 9, 5, 8};
    int tam = sizeof(elements) / sizeof(elements[0]);

    // Adicionando elementos à lista
    for (int i = 0; i < tam; i++) {
        add_no_fim(&lista, elements[i]);
    }

    int pos_inicio, pos_fim;
    find_position(lista, 7, &pos_inicio, &pos_fim);

    printf("O elemento 7 ocupa a %da posicao em relacao ao inicio e a %da posicao em relacao ao fim.\n", pos_inicio, pos_fim);

    // Liberando a memória alocada
    liberar_lista(&lista);

    return 0;
}
