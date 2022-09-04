#include <stdio.h>
#include <stdlib.h>

int* leiaVetor(int n) {
  int* v = malloc(sizeof(n));
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  return v;
}

int main(void) {

  // ENTRADA DE DADOS
  int n, * ras, * notas;   // variaveis de referência ras e notas
  float media, somador = 0.0;
  int contador = 0;

  printf("Digite o numero de alunos: ");
  scanf("%d", &n);

  printf("RAs: ");
  ras = leiaVetor(n);

  printf("Notas: ");
  notas = leiaVetor(n);

  // PROCESSAMENTO: soma, média e contador
  for (int i = 0; i < n; i++) {
    somador = somador + notas[i];   // soma
  }
  media = (float)somador / n;            // média

  for (int i = 0; i < n; i++) {
    if (notas[i] >= media) {        // conta alunos>=media
      contador = contador + 1;
    }
  }
  // SAÍDA DE DADOS
  printf("Média da turma = %.1f\n", media);
  printf("Número de alunos acima da média = %d\n", contador);
  printf("LISTA DE ALUNOS ACIMA DA MÉDIA\nRA\t Nota\n");
  for (int i = 0; i < n; i++) {
    if (notas[i] >= media) {        // conta alunos>=media
      printf("%d\t %d\n", ras[i], notas[i]);
    }
  }
  free(ras);  // liberar memória alocado com malloc
  free(notas);
  return 0;
}