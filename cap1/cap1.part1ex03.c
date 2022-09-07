#include <stdio.h>
int main(void) {
  char ch;
  int i;
  long int li;
  short s;
  unsigned int ui;
  float f;
  double d;
  long double ld;

  printf("Numero de bytes por tipo de dados:\n");
  printf("char:         %ld\n", sizeof(ch));
  printf("int:          %ld\n", sizeof(i));
  printf("long int:     %ld\n", sizeof(li));
  printf("short:        %ld\n", sizeof(s));
  printf("unsigned int: %ld\n", sizeof(ui));
  printf("float:        %ld\n", sizeof(f));
  printf("double:       %ld\n", sizeof(d));
  printf("long double:  %ld\n", sizeof(ld));
  return 0;
}