#include <stdio.h>
#include <string.h>

typedef struct {
  char rua[50];
  int numero;
} Endereco;

typedef struct {
  char nome[50];
  int idade;
  Endereco end;
} Cliente;

void leiaCliente(Cliente* cliente) {
  fflush(stdin);
  printf("nome: ");
  fgets((*cliente).nome, 50, stdin);
  printf("idade: ");
  scanf("%d", &(*cliente).idade);
  fflush(stdin);
  printf("rua: ");
  fgets((*cliente).end.rua, 50, stdin);
  printf("numero: ");
  scanf("%d", &(*cliente).end.numero);
}

void escrevaCliente(Cliente cliente) {
  printf("nome: %s\nidade: %d\n", cliente.nome, cliente.idade);
  printf("rua: %s\nnumero: %d\n", cliente.end.rua, cliente.end.numero);
}

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