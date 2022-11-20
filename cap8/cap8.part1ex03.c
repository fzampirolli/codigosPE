#include "myLista.h"
int main() {
  Lista0* lista = lista0_cria();
  for (int i = 0; i < MAX_LISTA; i++)
    lista0_insere_inicio(lista, i + 1);
  lista0_imprime(lista);
  printf("%d\n", lista0_busca(lista, 1));
  lista0_remove(lista);
  lista0_imprime(lista);
  lista0_remove_inicio(lista);
  lista0_imprime(lista);
  lista0_troca(lista, 0, 2);
  lista0_imprime(lista);
  lista0_remove_conteudo(lista, 3);
  lista0_imprime(lista);
  lista0_Bubble(lista);
  lista0_Selection(lista);
  lista0_Insertion(lista);
  lista0_imprime(lista);
  lista0_free(lista);
  return 1;
}