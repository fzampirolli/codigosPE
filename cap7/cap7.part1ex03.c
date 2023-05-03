#include <stdio.h>
#include <string.h>

struct TAluno {
  char nome[50];
  int idade;
  char rua[50];
  int numero;
};

typedef struct TAluno Aluno;

int main() {
  // ENTRADA DE DADOS
  Aluno Ana = { "Ana Silva" , 18, "Avenida Paulista" , 1000 };

  // SAÍDA DE DADOS
  printf("%s %d %s %d", Ana.nome, Ana.idade, Ana.rua, Ana.numero);
  return 0;
}