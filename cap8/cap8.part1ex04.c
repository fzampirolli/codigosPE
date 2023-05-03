#include "myLista.h"
int main() {
  Lista1* lista = lista1_cria();
  for (int i = 0; i < MAX_LISTA; i++)
    lista1_insere_final(lista, i + 1);
  lista1_imprime(lista);
  printf("%d\n", lista1_tamanho(lista));
  lista1_remove(lista);
  lista1_imprime(lista);
  lista1_remove_final(lista);
  lista1_imprime(lista);
  lista1_remove_conteudo(lista, 3);
  lista1_imprime(lista);
  lista1_free(lista);
  return 0;
}