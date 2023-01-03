#include "myFila.h"

/////////////////// TAD Fila Estatica ///////////////////
Fila0* fila0_cria(void) {
  Fila0* Fila = (Fila0*)calloc(1, sizeof(Fila0));
  if (Fila == NULL) {
    printf("ERRO: sem memoria\n");
    exit(1);
  }
  return Fila;
}
void fila0_free(Fila0* fila) {
  free(fila);
}
int fila0_tamanho(Fila0* fila) {
  if (fila == NULL) return -1;
  return fila->tamanho;
}
int fila0_cheia(Fila0* fila) {
  if (fila == NULL) return -1;
  if (fila->tamanho == MAX)
    return 1; // CHEIA
  return 0;
}
void fila0_imprime(Fila0* fila) {
  if (fila == NULL) exit(1);
  for (int i = fila->inicio; i < fila->final; i++)
    printf("%d ", fila->conteudos[i]);
  printf("\n");
}
int fila0_insere(Fila0* fila, int conteudo) { // insere no final
  if (fila == NULL) return -1;
  if (!fila0_cheia(fila)) {
    fila->conteudos[fila->final++] = conteudo;
    fila->tamanho++;
    return 1;
  }
  return 0;
}
int fila0_remove(Fila0* fila) { // remove no inicio
  if (fila == NULL) return -1;
  if (fila->tamanho) {
    fila->inicio++;
    fila->tamanho--;
    return 1;
  }
  return 0;
}

//////////////////// Versão 2 - ***SEM*** PONTEIRO DE PONTEIRO
// ref. https://www.ime.usp.br/~pf/algoritmos/aulas/lista.html
Fila* fila_cria(void) {
  Fila* f = (Fila*)malloc(sizeof(Fila));
  f->inicio = f->final = NULL;
  return f;
}
void fila_insere(Fila* fila, int conteudo) {
  Celula* novo = (Celula*)malloc(sizeof(Celula));
  novo->conteudo = conteudo;
  novo->prox = fila->final;
  if (fila->inicio == NULL)
    fila->inicio = novo;
  fila->final = novo;
}
void fila_imprime(Fila* fila) {
  for (Celula* p = fila->final; p != NULL; p = p->prox)
    printf("%d ", p->conteudo);
  printf("\n");
}
void fila_free(Fila* fila) {
  if (fila == NULL) exit(1);
  Celula* aux = fila->final;
  while (aux != fila->inicio) {
    Celula* no = aux;
    aux = aux->prox;
    free(no);
  }
  free(fila);
}
void fila_remove(Fila* fila) { // remove p->prox
  Celula* ant = fila->final;
  while (ant->prox != fila->inicio)
    ant = ant->prox;
  ant->prox = NULL;
  free(fila->inicio);
  fila->inicio = ant;
}