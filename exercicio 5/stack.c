#include<stdio.h>
#include<stdlib.h>
#include "stack.h"
#include "arvore.h"

typedef struct node_{
	ITM * content;
	struct node_ * next;
}Node;

struct stack_{
	Node * top;
	int size;
};

//cria uma pilha
Stack * stack_create(){
	Stack *p = (Stack *)malloc(sizeof(Stack));
	if(p!=NULL){
		p->top=NULL;
		p->size=0;
	}
	return p;
}

//verifica se a pilha esta vazia
boolean stack_empty(Stack *p){
	return p!=NULL?p->size==0:TRUE;
}

//verifica se a pilha esta cheia
boolean stack_full(Stack * p){
	return(p != NULL ? p->size == MAX_S : ERRO);
}

//retorna o numero de elementos existentes na pilha
int stack_size(Stack * stack){
	return stack!=NULL?stack->size:ERRO;
}

//retorna o elemreto do topo da pilha
void * stack_top(Stack *p){
	if(p!=NULL && p->size!=0){
		return p->top->content;
	}
	return NULL;
}

//empilha um elemrnto
boolean stack_push(Stack* p, ITM* x){
	if(p!=NULL){
		Node * new=(Node*)malloc(sizeof(Node));
		if(new!=NULL){
			//ITM* aux = x;
			new->content= x;
			new->next=p->top;
			p->top=new;
			p->size++;
			return TRUE;
		}
	}
	return FALSE;
}

//desempilha um elemento e retorna ele
void* stack_pop(Stack * p){
	if(p!=NULL && !stack_empty(p)){
		ITM* x = stack_top(p);
		Node *aux = p->top;
		p->top = p->top->next;
		aux->next=NULL;
		free(aux);
		p->size--;
		return x;
	}
	return NULL;
}

//apaga uma pilha existente
void stack_erase(Stack ** p){
	free(*p);
	p=NULL;
}
