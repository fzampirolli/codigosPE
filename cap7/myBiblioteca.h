#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  char rua[50];
  int numero;
} Endereco;

typedef struct {
  char nome[50];
  int idade;
  Endereco end;
} Cliente;

void leiaCliente(Cliente* cliente);
void escrevaCliente(Cliente cliente);
void criaCliente(Cliente* cliente, char linha[512]);