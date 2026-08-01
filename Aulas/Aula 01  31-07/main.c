#include <stdio.h>
#include "lista.h"

int main(void) {
    Lista* l = lista_criar();

    lista_inserir_fim(l, 10);
    lista_inserir_fim(l, 20);
    lista_inserir_inicio(l, 5);

    lista_imprimir(l);              // [5, 10, 20]
    printf("Tamanho: %d\n", lista_tamanho(l));

    lista_remover(l, 10);
    lista_imprimir(l);              // [5, 20]

    printf("Contém 20? %d\n", lista_buscar(l, 20));

    lista_destruir(l);
    return 0;
}