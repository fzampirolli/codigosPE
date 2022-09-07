#include <stdio.h>

float lerNota(float acumulador, int n) {
  float nota;
  if (n > 0) { // CRITÉRIO DE PARADA
    do {
      scanf("%f", &nota);
    } while (nota < 0.0 || nota > 10.0);
    acumulador = lerNota(acumulador, n - 1); // CHAMADA RECURSIVA,
    // ALTERAÇÃO DO VALOR DO ARGUMENTO !!!
  }
  return acumulador + nota;
}

int main(void) {

  // ENTRADA DE DADOS e PROCESSAMENTO
  float acumulador = 0, nota, media;
  int contador = 10;

  printf("Entre com %d notas válidas\n", contador);
  acumulador = lerNota(acumulador, contador);
  media = acumulador / contador;

  // SAÍDA
  printf("A média das %d notas é %.1f\n", contador, media);

  return 0;
}