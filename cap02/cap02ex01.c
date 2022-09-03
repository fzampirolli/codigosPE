#include <stdio.h>
float delta(float a, float b, float c) {
  float d = b * b - 4 * a * c;
  return d;
}
int main(void) {
  float a = 5.0, b = -2.0, c = 4.0;
  printf("O delta de ax^2 + bx + c é %.1f", delta(a, b, c));
  return 0;
}