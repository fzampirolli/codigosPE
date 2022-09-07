#include <stdio.h>
#include <stdlib.h>  // malloc e free

int* leiaVetor(int n) {
  int* v = malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  return v;
}

void escrevaVetor(int* v, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d\n", v[i]);
  }
}

int main(void) {
  // ENTRADA DE DADOS
  int n, * v1;   // variaveis de referência v1
  printf("Digite o tamanho do vetor: ");
  scanf("%d", &n);
  int* v2 = malloc(100 * sizeof(int));
  printf("Digite os elementos: ");
  v1 = leiaVetor(n);
  // PROCESSAMENTO
  for (int i = 0; i < n; i++) {
    int max = v1[i];
    if (i - 1 >= 0 && max < v1[i - 1])
      max = v1[i - 1];
    if (i + 1 < n && max < v1[i + 1])
      max = v1[i + 1];
    v2[i] = max;
  }
  // SAÍDA:
  printf("\nv2:\n");
  escrevaVetor(v2, n);
  free(v1); // liberar memória alocado com malloc
  free(v2);
  return 0;
}