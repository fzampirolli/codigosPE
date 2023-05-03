#include "myPilha.h"

/////////////////// TAD Pilha Estatica ///////////////////
Pilha0* pilha0_cria(void) {
  Pilha0* pilha = (Pilha0*)calloc(1, sizeof(Pilha0));
  if (pilha == NULL) {
    printf("ERRO: sem memoria\n");
    exit(1);
  }
  return pilha;
}
void pilha0_free(Pilha0* pilha) {
  free(pilha);
}
int pilha0_tamanho(Pilha0* pilha) {
  if (pilha == NULL) return -1;
  return pilha->tamanho;
}
int pilha0_cheia(Pilha0* pilha) {
  if (pilha->tamanho == MAX)
    return 1; // CHEIA
  return 0;
}
void pilha0_imprime(Pilha0* pilha) {
  if (pilha == NULL) exit(1);
  for (int i = 0; i < pilha->tamanho; i++)
    printf("%d ", pilha->conteudos[i]);
  printf("\n");
}
int pilha0_insere(Pilha0* pilha, int conteudo) { // insere no final
  if (!pilha0_cheia(pilha)) {
    printf("%d %d\n", conteudo, pilha->tamanho);
    pilha->conteudos[pilha->tamanho++] = conteudo;
    return 1;
  }
  return 0;
}
int pilha0_remove(Pilha0* pilha) { // remove no inicio
  if (pilha == NULL) return -1;
  if (pilha->tamanho) {
    pilha->tamanho--;
    return 1;
  }
  return 0;
}

//////////////////// Versão 2 - ***SEM*** PONTEIRO DE PONTEIRO
// ref. https://www.ime.usp.br/~pf/algoritmos/aulas/lista.html
Celula* pilha_cria(void) {
  Celula* cabeca = (Celula*)malloc(sizeof(Celula));
  if (cabeca == NULL) {
    printf("ERRO: sem memoria\n");
    exit(1);
  }
  cabeca->prox = NULL;
  return cabeca;
}
void pilha_insere(Celula* pilha, int conteudo) {
  if (pilha == NULL) exit(1);
  Celula* novo = (Celula*)malloc(sizeof(Celula));
  novo->conteudo = conteudo;
  novo->prox = pilha->prox;
  pilha->prox = novo;
}
void pilha_imprime(Celula* pilha) {
  for (Celula* p = pilha->prox; p != NULL; p = p->prox)
    printf("%d ", p->conteudo);
  printf("\n");
}
void pilha_free(Celula* pilha) {
  if (pilha == NULL) exit(1);
  Celula* aux = pilha->prox;
  while (aux != NULL) {
    Celula* no = aux;
    aux = aux->prox;
    free(no);
  }
  free(pilha);
}
void pilha_remove(Celula* pilha) { // remove p->prox
  if (pilha == NULL) exit(1);
  Celula* no;
  no = pilha->prox;
  pilha->prox = no->prox;
  free(no);
}