#include <stdio.h>
#include <string.h>

struct TAluno {
  char nome[50];
  int idade;
  char rua[50];
  int numero;
};

int main() {
  struct TAluno ana; // instancia um variável c do tipo TAluno
  // ENTRADA DE DADOS
  strcpy(ana.nome, "Ana Silva");
  ana.idade = 18;
  strcpy(ana.rua, "Avenida Paulista");
  ana.numero = 1000;

  // SAÍDA DE DADOS
  printf("nome: %s\nidade: %d\n", ana.nome, ana.idade);
  printf("rua: %s\nnúmero: %d\n", ana.rua, ana.numero);
  return 0;
}