#include <stdio.h>
#include <string.h>

typedef struct TAluno {
  char nome[50];
  int idade;
  char rua[50];
  int numero;
} Aluno;

int main() {
  // ENTRADA DE DADOS
  Aluno ana = { "Ana Silva" , 18, "Avenida Paulista" , 1000 };

  // SAÍDA DE DADOS
  printf("%s %d %s %d", ana.nome, ana.idade, ana.rua, ana.numero);
  return 0;
}