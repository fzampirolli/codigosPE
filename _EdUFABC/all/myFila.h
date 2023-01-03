#include <stdio.h>
#include <stdlib.h>

#define MAX 6
typedef struct {
  int tamanho;
  int inicio;
  int final;
  int conteudos[MAX];
} Fila0; // AQUI Fila Estática é Fila0 e fila0

Fila0* fila0_cria(void);
void fila0_free(Fila0* fila);
int fila0_tamanho(Fila0* fila);
int fila0_cheia(Fila0* fila);
void fila0_imprime(Fila0* fila);
int fila0_insere(Fila0* fila, int conteudo); // insere no final
int fila0_remove(Fila0* fila); // remove no inicio

/////////////////// TAD Fila Dinamica V.1 ///////////////////
typedef struct TCelula Celula;
struct TCelula {
  int conteudo;
  Celula* prox;
};
typedef struct TFila Fila;
struct TFila {
  Celula* inicio;
  Celula* final;
};
//////////////////// Versão ***SEM*** PONTEIRO DE PONTEIRO
Fila* fila_cria(void);
void fila_free(Fila* fila);
void fila_imprime(Fila* fila);
void fila_insere(Fila* fila, int conteudo);
void fila_remove(Fila* fila);
