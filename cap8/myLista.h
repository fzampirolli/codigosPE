#include <stdio.h>
#include <stdlib.h>

#define MAX_LISTA 6

/////////////////// TAD Lista Estatica ///////////////////
typedef struct {
  int tamanho;
  int conteudos[MAX_LISTA];
} Lista0; // AQUI Lista estática é Lista0 e lista0

Lista0* lista0_cria(void);
void lista0_free(Lista0* lista);
int lista0_tamanho(Lista0* lista);
int lista0_cheia(Lista0* lista);
int lista0_insere(Lista0* lista, int conteudo); // insere no final
void lista0_imprime(Lista0* lista);
int lista0_insere_inicio(Lista0* lista, int conteudo);
int lista0_busca(Lista0* lista, int conteudo); // indice 1a ocorrencia
int lista0_remove(Lista0* lista); // remove no final
int lista0_remove_inicio(Lista0* lista);
int lista0_troca(Lista0* lista, int i, int j);
int lista0_remove_conteudo(Lista0* lista, int conteudo); // remove 1o conteudo

/////////////////// TAD Lista Dinamica ///////////////////
struct TCelula {
  int conteudo;
  struct TCelula* prox;
};
typedef struct TCelula Celula;
typedef struct TCelula* Lista;

Lista* lista_cria(void);
void lista_free(Lista* lista);
int lista_insere(Lista* lista, int conteudo);
int lista_insere_final(Lista* lista, int conteudo);
void lista_imprime(Lista* lista);
int lista_tamanho(Lista* lista);
int lista_remove(Lista* lista);
int lista_remove_final(Lista* lista);
int lista_remove_conteudo(Lista* lista, int conteudo); // remove 1o conteudo
/*
int lista_busca(Lista* lista, int conteudo); // indice 1a ocorrencia
int lista_remove(Lista* lista); // remove no final
int lista_troca(Lista* lista, int i, int j);
*/