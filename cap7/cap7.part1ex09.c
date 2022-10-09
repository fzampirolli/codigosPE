#include "myBiblioteca.h"

int main() {
  Cliente clientes[20];
  char* filename = "dados.csv";

  // ENTRADA DE DADOS
  FILE* file; // Cria arquivo para leitura
  if ((file = fopen(filename, "r")) == NULL) {
    printf("Erro ao abrir o arquivo: %s\n", filename);
    return -1;
  }

  int contador = 0;
  char linha[512]; // espaço para cada linha lida
  while (fgets(linha, sizeof(linha), file))  // para cada linha
    criaCliente(&clientes[contador++], linha);

  // SAÍDA DE DADOS
  for (int i = 0; i < contador; i++) {
    printf("\nImprimir dados do cliente %d\n", i + 1);
    escrevaCliente(clientes[i]);
  }

  fclose(file); // fecha arquivo
  return 0;
}