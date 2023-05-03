#include <stdio.h>
#include <string.h>

typedef struct {
  char nome[50];
  int idade;
  char rua[50];
  int numero;
} Aluno;

int main() {
  Aluno Alunos[2]; // instancia uma vetor do tipo Aluno
  Aluno* p; // cria um ponteiro para Aluno
  p = Alunos; // associa p a lista de alunos
  // ENTRADA DE DADOS
  for (int i = 0; i < 2; i++) {
    printf("Entre com os dados: nome, idade, rua, número:\n");
    fflush(stdin);
    fgets(p[i].nome, 50, stdin);
    scanf("%d", &p[i].idade);
    fflush(stdin);
    fgets(p[i].rua, 50, stdin);
    scanf("%d", &p[i].numero);
  }
  // SAÍDA DE DADOS
  for (int i = 0; i < 2; i++) {
    printf("nome: %s\nidade: %d\n", p[i].nome, p[i].idade);
    printf("rua: %s\nnúmero: %d\n", p[i].rua, p[i].numero);
  }
  return 0;
}