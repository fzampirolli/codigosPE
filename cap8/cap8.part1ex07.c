#include "myFila.h"
int main() {
  Fila* fila = fila_cria();

  for (int i = 0; i < MAX; i++)
    fila_insere(fila, i + 1);
  fila_imprime(fila);
  fila_remove(fila);
  fila_imprime(fila);
  fila_remove(fila);
  fila_imprime(fila);
  fila_free(fila);
  return 0;
}