#include<stdio.h>
#include<stdlib.h>

int main() {
  int* p = (int*)malloc(5 * sizeof(int));

  printf("sizeof(p)=%li\n", sizeof(p));
  printf("sizeof(int)=%li\n", sizeof(int));
  printf("tamanho=%li\n", (int) sizeof(p) / sizeof(int));
  return 0;
}