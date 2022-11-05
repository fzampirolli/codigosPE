#include "myLista.h"

/////////////////// TAD Lista Estatica ///////////////////
Lista0* lista0_cria(void) {
  Lista0* lista = (Lista0*)calloc(1, sizeof(Lista0));
  if (lista == NULL) {
    printf("ERRO: sem memoria\n");
    exit(1);
  }
  return lista;
}
void lista0_free(Lista0* lista) {
  free(lista);
}
int lista0_tamanho(Lista0* lista) {
  if (lista == NULL) return -1;
  return lista->tamanho;
}
int lista0_cheia(Lista0* lista) {
  if (lista == NULL) return -1;
  if (lista->tamanho == MAX_LISTA)
    return 1; // CHEIA
  return 0;
}
int lista0_insere(Lista0* lista, int conteudo) { // insere no final
  if (lista == NULL) return -1;
  if (!lista0_cheia(lista)) {
    lista->conteudos[lista->tamanho] = conteudo;
    lista->tamanho++;
    return 1;
  }
  return 0;
}
void lista0_imprime(Lista0* lista) {
  if (lista == NULL) exit(1);
  for (int i = 0; i < lista->tamanho; i++)
    printf("%d ", lista->conteudos[i]);
  printf("\n");
}

int lista0_insere_inicio(Lista0* lista, int conteudo) {
  if (lista == NULL) return -1;
  if (!lista0_cheia(lista)) {
    for (int i = lista->tamanho; i > 0; i--)
      lista->conteudos[i] = lista->conteudos[i - 1];
    lista->conteudos[0] = conteudo;
    lista->tamanho++;
    return 1;
  }
  return 0;
}
int lista0_busca(Lista0* lista, int conteudo) { // indice 1a ocorrencia
  if (lista == NULL) return -1;
  for (int i = 0; i < lista->tamanho; i++)
    if (lista->conteudos[i] == conteudo)
      return i;
  return -1;
}
int lista0_remove(Lista0* lista) { // remove no final
  if (lista == NULL) return -1;
  if (lista->tamanho) {
    lista->tamanho--;
    return 1;
  }
  return 0;
}
int lista0_remove_inicio(Lista0* lista) {
  if (lista == NULL) return -1;
  if (lista->tamanho) {
    for (int i = 0; i < lista->tamanho; i++)
      lista->conteudos[i] = lista->conteudos[i + 1];
    lista->tamanho--;
    return 1;
  }
  return 0;
}
int lista0_troca(Lista0* lista, int i, int j) {
  if (lista == NULL) return -1;
  if (i >= 0 && j >= 0 && i < lista->tamanho && j < lista->tamanho) {
    int aux = lista->conteudos[i];
    lista->conteudos[i] = lista->conteudos[j];
    lista->conteudos[j] = aux;
    return 1;
  }
  return 0;
}
int lista0_remove_conteudo(Lista0* lista, int conteudo) {
  if (lista == NULL) return -1;
  int indice = lista0_busca(lista, conteudo);
  if (indice >= 0) {
    for (int i = indice; i < lista->tamanho; i++)
      lista->conteudos[i] = lista->conteudos[i + 1];
    lista->tamanho--;
  }
  return 0;
}

/////////////////// TAD Lista Dinamica ///////////////////
Lista* lista_cria(void) {
  Lista* lista = (Lista*)malloc(sizeof(Lista));
  if (lista == NULL) {
    printf("ERRO: sem memoria\n");
    exit(1);
  }
  return lista;
}
void lista_free(Lista* lista) {
  if (lista == NULL) exit(1);
  while ((*lista) != NULL) {
    Celula* no = *lista;
    *lista = (*lista)->prox;
    free(no);
  }
  free(lista);
}
int lista_insere(Lista* lista, int conteudo) {
  if (lista == NULL) return -1;
  Celula* no = (Celula*)malloc(sizeof(Celula));
  no->conteudo = conteudo;
  no->prox = *lista;
  *lista = no;
  return 1;
}
int lista_insere_final(Lista* lista, int conteudo) {
  if (lista == NULL) return -1;
  Celula* no = (Celula*)malloc(sizeof(Celula));
  no->conteudo = conteudo;
  no->prox = NULL;
  if (*lista == NULL) // lista vazia
    *lista = no;
  else {
    Celula* p = *lista;
    while (p->prox != NULL)
      p = p->prox;
    p->prox = no;
  }
  return 1;
}
void lista_imprime(Lista* lista) {
  Celula* no = *lista;
  while (no != NULL) {
    printf("%d ", no->conteudo);
    no = no->prox;
  }
  printf("\n");
}
int lista_tamanho(Lista* lista) {
  if (lista == NULL) return -1;
  Celula* no = *lista;
  int cont = 0;
  while (no != NULL) {
    no = no->prox;
    cont++;
  }
  return cont;
}
int lista_remove(Lista* lista) {
  if (lista == NULL || *lista == NULL) return -1;
  Celula* no = *lista;
  *lista = no->prox;
  free(no);
  return 1;
}
int lista_remove_final(Lista* lista) {
  if (lista == NULL || *lista == NULL) return -1;
  Celula* no = *lista, * ant;
  while (no->prox != NULL) {
    ant = no;
    no = no->prox;
  }
  if (no == *lista) // 1 elemento
    *lista = NULL;
  else
    ant->prox = no->prox;
  free(no);
  return 1;
}
int lista_remove_conteudo(Lista* lista, int conteudo) {
  if (lista == NULL || *lista == NULL) return -1;
  Celula* no = *lista, * ant;
  while (no != NULL && no->conteudo != conteudo) {
    ant = no;
    no = no->prox;
  }
  if (no == NULL) // nao achou
    return 0;
  else if (no == *lista) // 1 elementos
    *lista = no->prox;
  else
    ant->prox = no->prox;
  free(no);
  return 1;
}