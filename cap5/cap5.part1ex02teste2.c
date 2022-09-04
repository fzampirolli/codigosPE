#include <stdio.h>
#include <stdlib.h>

int* leiaVetor(int n) {
  int* v = malloc(sizeof(n));  // ALOCAÇÃO DINÂMICA
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  return v;
}

int main(void) {

  // ENTRADA DE DADOS
  int n, * ras, * notas;   // variaveis de referência ras e notas

  printf("Digite o numero de alunos: ");
  scanf("%d", &n);

  printf("RAs: ");
  ras = leiaVetor(n);

  printf("Notas: ");
  notas = leiaVetor(n);

  // PROCESSAMENTO ?
  // SAÍDA
  printf("LISTA DE ALUNOS\nNúmero\t RA\t Nota\n");
  for (int i = 0; i < n; i++) {
    printf("%d\t %d\t %d\n", i + 1, ras[i], notas[i]);
  }
  free(ras);   // liberar memória alocado com malloc
  free(notas);
  return 0;
}