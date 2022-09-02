#include <stdio.h>
int main(void) {
  int a = 2, b = 3, c = -5;
  float delta = b * b - 4 * a * c;
  printf("%.2f\n", delta);
  return 0;
}