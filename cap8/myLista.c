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
Lista1* lista1_cria(void) {
  Lista1* lista = (Lista1*)malloc(sizeof(Lista1));
  if (lista == NULL) {
    printf("ERRO: sem memoria\n");
    exit(1);
  }
  return lista;
}
void lista1_free(Lista1* lista) {
  if (lista == NULL) exit(1);
  while ((*lista) != NULL) {
    Celula* no = *lista;
    *lista = (*lista)->prox;
    free(no);
  }
  free(lista);
}
int lista1_insere(Lista1* lista, int conteudo) {
  if (lista == NULL) return -1;
  Celula* no = (Celula*)malloc(sizeof(Celula));
  no->conteudo = conteudo;
  no->prox = *lista;
  *lista = no;
  return 1;
}
int lista1_insere_final(Lista1* lista, int conteudo) {
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
void lista1_imprime(Lista1* lista) {
  Celula* no = *lista;
  while (no != NULL) {
    printf("%d ", no->conteudo);
    no = no->prox;
  }
  printf("\n");
}
int lista1_tamanho(Lista1* lista) {
  if (lista == NULL) return -1;
  Celula* no = *lista;
  int cont = 0;
  while (no != NULL) {
    no = no->prox;
    cont++;
  }
  return cont;
}
int lista1_remove(Lista1* lista) {
  if (lista == NULL || *lista == NULL) return -1;
  Celula* no = *lista;
  *lista = no->prox;
  free(no);
  return 1;
}
int lista1_remove_final(Lista1* lista) {
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
int lista1_remove_conteudo(Lista1* lista, int conteudo) {
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

//////////////////// Versão 2 - ***SEM*** PONTEIRO DE PONTEIRO
// ref. https://www.ime.usp.br/~pf/algoritmos/aulas/lista.html
Celula* lista_cria(void) {
  Celula* inicio = (Celula*)malloc(sizeof(Celula));
  if (inicio == NULL) {
    printf("ERRO: sem memoria\n");
    exit(1);
  }
  return inicio;
}
void lista_insere(Celula* p, int conteudo) {
  // insere numa posicao p qualquer da lista
  if (p == NULL) exit(1);
  Celula* novo = (Celula*)malloc(sizeof(Celula));
  novo->conteudo = conteudo;
  novo->prox = p->prox;
  p->prox = novo;
}
void lista_free(Celula* lista) {
  if (lista == NULL) exit(1);
  Celula* aux = lista->prox;
  while (aux != NULL) {
    Celula* no = aux;
    aux = aux->prox;
    free(no);
  }
  free(lista);
}
void lista_imprime(Celula* lista) {
  Celula* p;
  for (p = lista->prox; p != NULL; p = p->prox)
    printf("%d ", p->conteudo);
  printf("\n");
}
void lista_remove(Celula* p) {
  if (p == NULL) exit(1);
  Celula* no;
  no = p->prox;
  p->prox = no->prox;
  free(no);
}
void lista_busca_remove(Celula* cabeca, int conteudo) {
  if (cabeca == NULL) exit(1);
  Celula* no, * antes;
  antes = cabeca;
  no = antes->prox;
  while (no != NULL && no->conteudo != conteudo) {
    antes = no;
    no = no->prox;
  }
  lista_remove(antes);
}
void lista_busca_insere(Celula* cabeca, int busca, int novo) {
  // insere antes da primeiro ocorrencia de conteudo ou no final
  if (cabeca == NULL) exit(1);
  Celula* no, * antes;
  antes = cabeca;
  no = antes->prox;
  while (no != NULL && no->conteudo != busca) {
    antes = no;
    no = no->prox;
  }
  lista_insere(antes, novo);
}