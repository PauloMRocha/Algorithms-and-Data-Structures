all: main.o arvore.o item.o stack.o
	gcc -Wall -g main.o arvore.o stack.o item.o -o calc
main.o: main.c arvore.o item.o stack.o
	gcc -c -g -Wall main.c -o main.o
item.o: item.c
	gcc -c -g -Wall item.c -o item.o
arvore.o: arvore.c
	gcc -c -g -Wall arvore.c -o arvore.o
stack.o: stack.c
	gcc -c -g -Wall stack.c -o stack.o
clean:
	rm *.o calc
run:
	./calc
