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

/////////////////// TAD Lista Dinamica V.1 ///////////////////
typedef struct TCelula Celula;
struct TCelula {
  int conteudo;
  Celula* prox;
};

//////////////////// Versão 1 - PONTEIRO DE PONTEIRO
typedef struct TCelula* Lista1; // AQUI LISTA1 É PONTEIRO DE PONTEIRO

Lista1* lista1_cria(void);
void lista1_free(Lista1* lista);
int lista1_insere(Lista1* lista, int conteudo);
int lista1_insere_final(Lista1* lista, int conteudo);
void lista1_imprime(Lista1* lista);
int lista1_tamanho(Lista1* lista);
int lista1_remove(Lista1* lista);
int lista1_remove_final(Lista1* lista);
int lista1_remove_conteudo(Lista1* lista, int conteudo); // remove 1o conteudo
/*
int lista_busca(Lista* lista, int conteudo); // indice 1a ocorrencia
int lista_remove(Lista* lista); // remove no final
int lista_troca(Lista* lista, int i, int j);
*/


//////////////////// Versão 2 - ***SEM*** PONTEIRO DE PONTEIRO
// ref.: https://www.ime.usp.br/~pf/algoritmos/aulas/lista.html
// "o endereço de uma lista é o endereço da primeira célula"
//
Celula* lista_cria(void);
void lista_insere(Celula* p, int conteudo);
void lista_imprime(Celula* cabeca);
void lista_free(Celula* cabeca);
void lista_remove(Celula* p);
void lista_busca_remove(Celula* cabeca, int conteudo);
void lista_busca_insere(Celula* cabeca, int busca, int novo);
void lista0_Bubble(Lista0* lista);
void lista0_Bubble2(Lista0* lista); // versão simplificada
void lista0_Selection(Lista0* lista);
void lista0_Insertion(Lista0* lista);
