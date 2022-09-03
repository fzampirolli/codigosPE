#include <stdio.h>
int main() {
  float area;
  int escolha, num;
  printf("1. Circulo\n");
  printf("2. Quadrado\n");
  printf("Escolha:\n");

  scanf("%d", &escolha);

  switch (escolha) {
  case 1: {
    printf("Raio:\n");
    scanf("%d", &num);
    area = 3.14 * num * num;
    printf("Area do circulo: ");
    printf("%.2f\n", area);
    break;
  }
  case 2: {
    printf("Lado:\n");
    scanf("%d", &num);
    area = num * num;
    printf("Area do quadrado: ");
    printf("%.2f\n", area);
    break;
  }
  default:
    printf("Escolha Incorreta!\n");
  }
  return 0;
}