#include <stdio.h>

int main() {
  char* filename = "teste.txt";

  FILE* fp;
  fp = fopen(filename, "w"); // Cria arquivo para escrita
  if (fp == NULL) {
    printf("Erro ao abrir o arquivo: %s\n", filename);
    return -1;
  }

  for (int i = 0; i < 10; i++)
    fprintf(fp, "Linha %02d\n", i + 1); // Escrever algo no arquivo

  fclose(fp); // fecha arquivo

  return 0;
}