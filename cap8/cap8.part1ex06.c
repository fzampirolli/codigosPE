#include "myFila.h"
int main() {
  Fila0* fila = fila0_cria();
  for (int i = 0; i < MAX; i++)
    fila0_insere(fila, i + 1);
  fila0_imprime(fila);
  fila0_remove(fila);
  fila0_imprime(fila);
  fila0_free(fila);
  return 1;
}