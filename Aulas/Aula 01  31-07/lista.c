#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct No {
    int valor;
    struct No* prox;
};

struct Lista {
    No* inicio;
    int tamanho;
};

Lista* lista_criar(void) {
    Lista* l = malloc(sizeof(Lista));
    if (!l) return NULL;
    l->inicio = NULL;
    l->tamanho = 0;
    return l;
}

void lista_destruir(Lista* lista) {
    No* atual = lista->inicio;
    while (atual != NULL) {
        No* prox = atual->prox;
        free(atual);
        atual = prox;
    }
    free(lista);
}

int lista_inserir_inicio(Lista* lista, int valor) {
    No* novo = malloc(sizeof(No));
    if (!novo) return 0;
    novo->valor = valor;
    novo->prox = lista->inicio;
    lista->inicio = novo;
    lista->tamanho++;
    return 1;
}

int lista_inserir_fim(Lista* lista, int valor) {
    No* novo = malloc(sizeof(No));
    if (!novo) return 0;
    novo->valor = valor;
    novo->prox = NULL;

    if (lista->inicio == NULL) {
        lista->inicio = novo;
    } else {
        No* atual = lista->inicio;
        while (atual->prox != NULL)
            atual = atual->prox;
        atual->prox = novo;
    }
    lista->tamanho++;
    return 1;
}

int lista_remover(Lista* lista, int valor) {
    No* atual = lista->inicio;
    No* anterior = NULL;

    while (atual != NULL && atual->valor != valor) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) return 0; // não encontrado

    if (anterior == NULL)
        lista->inicio = atual->prox;
    else
        anterior->prox = atual->prox;

    free(atual);
    lista->tamanho--;
    return 1;
}

int lista_buscar(Lista* lista, int valor) {
    No* atual = lista->inicio;
    while (atual != NULL) {
        if (atual->valor == valor) return 1;
        atual = atual->prox;
    }
    return 0;
}

int lista_tamanho(Lista* lista) {
    return lista->tamanho;
}

int lista_vazia(Lista* lista) {
    return lista->tamanho == 0;
}

void lista_imprimir(Lista* lista) {
    No* atual = lista->inicio;
    printf("[");
    while (atual != NULL) {
        printf("%d", atual->valor);
        if (atual->prox != NULL) printf(", ");
        atual = atual->prox;
    }
    printf("]\n");
}