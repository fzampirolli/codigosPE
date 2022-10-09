#include "myBiblioteca.h"
// cria um cliente a partir de uma linha de texto. Exemplo:
// "Maria Souza, 20, Avenida Paulista, 1200"
void criaCliente(Cliente* cliente, char linha[512]) {
  // Ler nome
  char* token = strtok(linha, ","); // ler até a primeira ","
  strcpy((*cliente).nome, token); // nome

  // Ler idade
  token = strtok(NULL, ","); // continar lendo até a próxima ","
  (*cliente).idade = atoi(token); // converter str to int

  // Ler rua
  token = strtok(NULL, ",");
  strcpy((*cliente).end.rua, token + 1); // +1 retira 1o espaço em branco

  // Ler numero
  token = strtok(NULL, ",");
  (*cliente).end.numero = atoi(token); // converter str to int
}

void escrevaCliente(Cliente cliente) {
  printf("nome: %s\nidade: %d\n", cliente.nome, cliente.idade);
  printf("rua: %s\nnúmero: %d\n", cliente.end.rua, cliente.end.numero);
}

// leia um cliente a partir do teclado
// nome, idade, rua, numero
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
