#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

struct deque_{
  char itens[TAM];
  int tam;
  int ini;
  int fim;
};

DEQUE* deque_cria(){
  DEQUE* d = malloc(sizeof(DEQUE));
  d->tam = 0;
  d->ini = 0;
  d->fim = 0;

  return d;
}

int deque_tam(DEQUE* d){
  return (d!= NULL ? d->tam : ERRO);
}

bool deque_vazio(DEQUE* d){
  return (d!=NULL ? d->tam == 0 : TRUE);
}

bool deque_cheio(DEQUE* d){
  return (d != NULL ? d->tam == TAM : ERRO);
}

bool deque_insere_fim(DEQUE* d, char c){
  if(d != NULL && !deque_cheio(d)){
    d->itens[d->fim] = c;
    d->fim = (d->fim + 1)%TAM;
    d->tam ++;
    return TRUE;
  }
  return FALSE;
}

bool deque_insere_inicio(DEQUE* d, char c){
  if(d != NULL && !deque_cheio(d)){
    d->fim = (d->ini - 1 + TAM)%TAM;
    d->itens[d->ini] = c;
    d->tam ++;
    return TRUE;
  }
  return FALSE;
}

char deque_remove_fim(DEQUE* d){
  if(d != NULL && !deque_vazio(d)){
    char i;
    d->fim = (d->fim - 1 + TAM)%TAM;
    i = d->itens[d->fim];
    d->tam --;
    return i;
  }
  return '#';
}

char deque_remove_inicio(DEQUE* d){
  if(d != NULL && !deque_vazio(d)){
    char i= d->itens[d->ini];
    d->ini = (d->ini + 1)%TAM;
    d->tam --;
    return i;
  }
  return '#';
}
