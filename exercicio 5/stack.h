#ifndef STACK_H
#define STACK_H
#define MAX_S 5 //tamanho maximo da pilha
#define ERRO -32000
#define TRUE 1
#define FALSE 0
#include "item.h"
#include "arvore.h"


typedef int boolean;
typedef struct stack_ Stack;
typedef NO ITM;

//cria uma pilha
Stack* stack_create();
//verifica se a pilha esta cheia
boolean stack_empty(Stack * p);
//imprime todos os elementos da pilha
boolean stack_full(Stack * p);
//retorna o numero de elementos existentes na pilha
int stack_size(Stack * stack);
//empilha um elemento
void * stack_top(Stack * p);
//verifica se a pilha esta vazia
boolean stack_push(Stack * p, ITM * x);
//desempilha um elemento e retorna ele
void * stack_pop(Stack * p);
//apaga uma pilha existente
void stack_erase(Stack **p);
//retorna o elemrnto do topo da pilha
void stack_print(Stack * p);
//procura um elemento na pilha com base em uma chave (retorna TRUE caso encontre, caso contrario retorna FALSE)
//boolean stack_search(Stack* q, int placa);
#endif
