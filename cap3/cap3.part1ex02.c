#include <stdio.h>

// MÉTODO
float leia() {
  float valor;
  printf("Entre com um valor: ");
  scanf("%f", &valor);
  return valor;
}

// PROGRAMA PRINCIPAL
int main(void) {

  // ENTRADAS
  float nota1 = leia();
  float nota2 = leia();

  // PROCESSAMENTO E SAÍDA
  float media = (nota1 + nota2) / 2;
  if (media >= 9.0)
    printf("Conceito A\n");
  else if (media >= 7.5)
    printf("Conceito B\n");
  else if (media >= 6.0)
    printf("Conceito C\n");
  else if (media >= 5.0)
    printf("Conceito D\n");
  else
    printf("Reprovado! Conceito F\n");
  return 0;
}