#include <stdio.h>

int main() {
  char* filename = "teste.txt", ch;

  FILE* fp;
  fp = fopen(filename, "r"); // Cria arquivo para escrita
  if (fp == NULL) {
    printf("Erro ao abrir o arquivo: %s\n", filename);
    return -1;
  }

  while ((ch = fgetc(fp)) != EOF) { // Lê arquivo
    printf("%c", ch); // caracter por caracter
  }

  fclose(fp); // fecha arquivo

  return 0;
}