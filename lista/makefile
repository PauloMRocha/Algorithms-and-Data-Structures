prog : lista.o main.o
	gcc lista.o main.o -o prog

lista.o : lista.c
	gcc -g -c lista.c -o lista.o

main.o : main.c lista.o
	gcc -g -c main.c -o main.o
