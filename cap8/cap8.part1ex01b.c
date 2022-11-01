#include<stdio.h>

int main() {
  int v[5] = { 3,4,5,6,7 };

  printf("sizeof(v)=%ld\n", sizeof(v));
  printf("sizeof(int)=%ld\n", sizeof(int));
  printf("tamanho=%li\n", (int)sizeof(v) / sizeof(int));
  return 0;
}