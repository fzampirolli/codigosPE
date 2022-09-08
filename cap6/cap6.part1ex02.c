#include <stdio.h>

int main() {
  char* filename = "teste.txt";

  // Criar arquivo para escrita
  FILE* fp = fopen(filename, "w");
  if (fp == NULL) {
    printf("Erro ao abrir o arquivo: %s\n", filename);
    return -1;
  }
  // Escrever algo no arquivo
  for (int i = 0; i < 10; i++)
    fprintf(fp, "Linha #%d\n", i + 1);

  // close the file
  fclose(fp);

  return 0;
}