#include <stdio.h>
#include <string.h>

void main() {
  char s[40];
  printf("digite algo:\n");
  fgets(s, 40, stdin);
  printf("saida: \"%s\" tamanho: %ld\n", s, strlen(s));
  s[strlen(s) - 1] = '\0'; // substituir \n por \0
  printf("saida: \"%s\" tamanho: %ld\n", s, strlen(s));
}