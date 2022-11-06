#include "myLista.h"
int main() {
  Celula* cabeca = lista_cria();

  for (int i = 0; i < MAX_LISTA; i++)
    lista_insere(cabeca, i + 1);
  lista_imprime(cabeca);
  lista_remove(cabeca);
  lista_imprime(cabeca);
  lista_busca_remove(cabeca, 3);
  lista_imprime(cabeca);
  lista_busca_insere(cabeca, 0, 8);
  lista_imprime(cabeca);
  lista_free(cabeca);
  return 0;
}