#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"


struct aba_{
  char nome[40];
  char url[512];
  struct aba_ *prox;
};

struct lista_{
  int tam;
  Aba* head;
  Aba* fim;
};

Lista* cria_lista(){
  Lista* l = (Lista*)malloc(sizeof(Lista));
  Aba* cabeca = (Aba*)malloc(sizeof(Aba));
  if(cabeca != NULL){
    cabeca->prox = NULL;
  }else return NULL;

  if(l != NULL){
    l->tam = 0;
    l->head = cabeca;
    l->fim = cabeca;
  }
  return l;
}

bool insere_aba(Lista* lista, char* nome, char* url){
  Aba* a = (Aba*)malloc(sizeof(Aba));
  if((a != NULL) && (lista != NULL)){
    strcpy(a->nome, nome);
    strcpy(a->url, url);
    a->prox = NULL;

    lista->fim->prox = a;
    lista->fim = a;
    lista->tam ++;
    return TRUE;
  }
  return FALSE;
}

void print_lista(Lista* lista){
  Aba* atual = lista->head->prox;
  while(atual != NULL){
    printf("%s %s\n", atual->nome, atual->url);
    atual = atual->prox;
  }
  return;
}

void troca_aba(Lista* lista, char* nome, int lugar){
  int cont = 1, flag = 0;
  Aba* atual = lista-> head;
  Aba* local = NULL;
  Aba* aux = NULL;
  while(atual != NULL){
    if(atual->prox != NULL && strcmp(atual->prox->nome, nome) == 0){
      aux = atual->prox;
      atual->prox = aux->prox;
      flag++;
    }
    if(cont == lugar){
      local = atual;
      flag++;
    }
    atual = atual->prox;
    cont ++;
    if(flag == 2) break;
  }
  if(aux == NULL) return;
  if(local == NULL) local = lista->fim;
  aux->prox = local->prox;
  local->prox = aux;
  return;
}

void apaga_lista(Lista** lista){
  Aba* atual = (*lista)->head;
  Aba* aux = NULL;
  if(*lista == NULL)return;

  while(atual != NULL){
    aux = atual;
    atual = atual->prox;
    aux->prox = NULL;
    free(aux);
  }
  free((*lista));
  *lista = NULL;
  return;
}
