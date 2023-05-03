#include <stdio.h>

int main() {
  int v[3] = { 5,6,7 };
  int* p1;
  p1 = v; // observe que aqui não precisa usar &v
  for (int i = 0; i < 3; i++)
    printf("%d %d %d\n", *(p1 + i), p1[i], v[i]); // *(p+i) = p[i] = v[i]
  printf("sizeof(p) = %lu\n", sizeof(p1));
  printf("sizeof(v) = %lu\n", sizeof(v));
  printf("#v = %lu", sizeof(v) / sizeof(int));
  return 0;
}