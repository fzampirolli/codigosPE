#include<stdio.h>
void funcao(int* v) {
  printf("sizeof(v)=%ld\n", sizeof(v));
  printf("sizeof(int)=%ld\n", sizeof(int));
  printf("tamanho=%li\n", (int)sizeof(v) / sizeof(int));
}
int main() {
  int v[5] = { 3,4,5,6,7 };
  funcao(v);
  return 0;
}