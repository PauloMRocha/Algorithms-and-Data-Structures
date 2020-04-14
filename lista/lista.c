#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct lista_{
  int list[100]; //lista de inteiros
  int tam; //tamanho da lista
};

/* funçao que cria uma lista vazia e retorna seu endereço */
LISTA *lista_criar(){
  LISTA *end=malloc(sizeof(LISTA));
  end->tam = 0;
  return end;
}

/* verifica se uma lista esta cheia */
int lista_cheia(LISTA *lista){
  if((lista->tam) > MAX) return 1;
  else return 0;
}

/* funçao lista_inserir: insere um elemento na lits e retorna o numeros de
comparaçoes necessarias para isso
*/
int lista_inserir(LISTA *lista, int num){
  int cont = 0;
  if((lista->tam) > MAX){
    printf("Lista cheia. Impossível realizar o processamento.\n");
    return 0;
  }
  for(int i=0; i < (lista->tam); i++){
    cont++;
    if( (lista->list)[i] == num) return cont;
  }
  lista->list[lista->tam] = num;
  lista->tam ++;
  return cont;
}

/* função lista_print: imprime a lista */
void lista_print(LISTA *lista){

  for(int i=0; i < lista->tam; i++){
    printf("%d\t", (lista->list)[i]);
  }
  printf("\n");
}

/* função len: retorna o tamanho da lista */
int lista_len(LISTA *lista){
  return lista->tam;
}

/* funçao lista_apaga: da free no bloco alocado para a lista */
void lista_apagar(LISTA *lista){
  free(lista);
}
