#include "myPilha.h"
int main() {
  Pilha0* pilha = pilha0_cria();
  for (int i = 0; i < MAX; i++)
    pilha0_insere(pilha, i + 1);
  pilha0_imprime(pilha);
  pilha0_remove(pilha);
  pilha0_imprime(pilha);
  pilha0_remove(pilha);
  pilha0_imprime(pilha);
  pilha0_free(pilha);
  return 1;
}