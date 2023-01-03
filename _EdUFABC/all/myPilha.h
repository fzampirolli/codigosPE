#include <stdio.h>
#include <stdlib.h>

#define MAX 6
typedef struct {
  int tamanho;  // topo da pilha
  int conteudos[MAX];
} Pilha0; // AQUI pilha Estática é Pilha0 e pilha0

Pilha0* pilha0_cria(void);
void pilha0_free(Pilha0* pilha);
int pilha0_tamanho(Pilha0* pilha);
int pilha0_cheia(Pilha0* pilha);
void pilha0_imprime(Pilha0* pilha);
int pilha0_insere(Pilha0* pilha, int conteudo); // insere no topo
int pilha0_remove(Pilha0* pilha); // remove no topo

/////////////////// TAD pilha Dinamica V.1 ///////////////////
typedef struct TCelula Celula;
struct TCelula {
  int conteudo;
  Celula* prox;
};
Celula* Pilha;

//////////////////// Versão ***SEM*** PONTEIRO DE PONTEIRO
Celula* pilha_cria(void);
void pilha_free(Celula* pilha);
void pilha_imprime(Celula* pilha);
void pilha_insere(Celula* pilha, int conteudo);
void pilha_remove(Celula* pilha);
