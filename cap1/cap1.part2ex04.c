#include <stdio.h>
int main(void) {
  double d = 3.14;
  int i = (int)d; // AQUI ESTA O CAST
  printf("double = %f\n", d);
  printf("int = %d\n", i);
  return 0;
}