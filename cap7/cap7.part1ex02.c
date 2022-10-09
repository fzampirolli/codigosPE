#include <stdio.h>
#include <string.h>

struct TAluno {
  char nome[50];
  int idade;
  char rua[50];
  int numero;
};

int main() {
  struct TAluno Alunos[2]; // instancia um vetor do tipo TAluno
  // ENTRADA DE DADOS
  for (int i = 0; i < 2; i++) {
    printf("Entre com os dados: nome, idade, rua, número:\n");
    fflush(stdin);
    fgets(Alunos[i].nome, 50, stdin);
    scanf("%d", &Alunos[i].idade);
    fflush(stdin);
    fgets(Alunos[i].rua, 50, stdin);
    scanf("%d", &Alunos[i].numero);
  }
  // SAÍDA DE DADOS
  for (int i = 0; i < 2; i++) {
    printf("nome: %s\nidade: %d\n", Alunos[i].nome, Alunos[i].idade);
    printf("rua: %s\nnúmero: %d\n", Alunos[i].rua, Alunos[i].numero);
  }
  return 0;
}