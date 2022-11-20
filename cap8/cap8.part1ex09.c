#include "myPilha.h"
int main() {
  Celula* pilha = pilha_cria();

  for (int i = 0; i < MAX; i++)
    pilha_insere(pilha, i + 1);
  pilha_imprime(pilha);
  pilha_remove(pilha);
  pilha_imprime(pilha);
  pilha_remove(pilha);
  pilha_imprime(pilha);
  pilha_free(pilha);
  return 0;
}