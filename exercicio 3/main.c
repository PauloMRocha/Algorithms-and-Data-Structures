#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(void){
  char* nome = malloc(sizeof(char)*40);
  char* url = malloc(sizeof(char)*512);
  int lugar, op = 0;
  Lista* lista = cria_lista();

  while(op != 4){
    scanf("%d", &op);
    switch(op){
      case (1):
        scanf(" %s", nome);
        scanf(" %s", url);
        insere_aba(lista, nome, url);
      break;
      case (2):
        scanf(" %s", nome);
        scanf(" %d", &lugar);
        troca_aba(lista, nome, lugar);
      break;
      case (3):
        print_lista(lista);
      break;
      case (4):
        apaga_lista(&lista);
      break;
    }
  }
  free(nome);
  free(url);
  return 0;
}
