#ifndef LISTA_H
#define LISTA_H

// Tipo opaco: o usuário não vê os detalhes internos
typedef struct No No;
typedef struct Lista Lista;

// Criação e destruição
Lista* lista_criar(void);
void lista_destruir(Lista* lista);

// Operações básicas
int lista_inserir_inicio(Lista* lista, int valor);
int lista_inserir_fim(Lista* lista, int valor);
int lista_remover(Lista* lista, int valor);
int lista_buscar(Lista* lista, int valor); // retorna 1 se achou, 0 se não
int lista_tamanho(Lista* lista);
int lista_vazia(Lista* lista);

// Utilitário
void lista_imprimir(Lista* lista);

#endif