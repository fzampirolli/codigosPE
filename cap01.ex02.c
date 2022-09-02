#include <stdio.h>
int main(void) {
  int C;
  scanf("%d", &C);
  float F = C * 9 / 5 + 32;
  printf("%d graus Celsius corresponde a %.1f graus Fahrenheit", C, F);
  return 0;
}