#include "myBiblioteca.h"

int main() {
  Cliente clientes[2];
  // ENTRADA DE DADOS
  for (int i = 0; i < 2; i++) {
    printf("Cadastrar dados do cliente %d\n", i + 1);
    leiaCliente(&clientes[i]);
  }

  // SAÍDA DE DADOS
  for (int i = 0; i < 2; i++) {
    printf("Imprimir dados do cliente %d\n", i + 1);
    escrevaCliente(clientes[i]);
  }
  return 0;
}