#ifndef LISTA_H
#define LISTA_H
#define MAX 99

/*Lista sem repetiçoes*/
typedef struct lista_ LISTA;

//cria uma lista de inteiros vazia que suporta até 100 elementos
LISTA *lista_criar();

//insere um elemnto na lista e retorna o numero de
//comparaçoes necessarias para a incerção
int lista_inserir(LISTA *lista, int num);

//imprime todos os elementos da lista na ordem em que foram colocados
void lista_print(LISTA *lista);

//retorna o numero de elemntos da lista
int lista_len(LISTA* lista);

//apaga uma lista
void lista_apagar(LISTA *lista);

//retorna 1 se a lista estiver cheia 
int lista_cheia(LISTA *lista);

#endif
