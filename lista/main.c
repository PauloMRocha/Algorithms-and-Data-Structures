#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(void){
//declaração de variaveis
  int n, num, comp = 0;
  LISTA *lista;

//criando a lista
  lista = lista_criar();

//loop para inserir os n elementos na lista
  scanf("%d", &n);
  while(n--){
    scanf("%d", &num);
    comp += lista_inserir(lista, num);
  }

  if(lista_cheia(lista) == 0){
//impressao das informaçoes pedidas no problrma
  lista_print(lista);
  printf("Tamanho da lista: %d\n", lista_len(lista));
  printf("Total de comparações: %d\n", comp);
  }

//apagando a lista
  lista_apagar(lista);

  return 0;
}
