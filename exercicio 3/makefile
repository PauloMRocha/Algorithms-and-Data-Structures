all: lista.o main.o
	gcc -g lista.o main.o -o prog
	@./prog
lista.o:
	gcc -c lista.c -Wall -g -o lista.o
main.o: lista.o
	gcc -c main.c -Wall -g -o main.o
run:
	./prog
