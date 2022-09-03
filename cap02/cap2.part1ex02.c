#include <stdio.h>

float delta(float a, float b, float c) {
  float d = b * b - 4 * a * c;
  return d;
}

float leia() {
  float valor;
  printf("Entre com um valor: ");
  scanf("%f", &valor);
  return valor;
}

int main(void) {
  // ENTRADAS
  float a, b, c, d;
  a = leia();
  b = leia();
  c = leia();

  // PROCESSAMENTO
  d = delta(a, b, c);

  //SAÍDA
  printf("Delta = %.1f\n", d);
  return 0;
}