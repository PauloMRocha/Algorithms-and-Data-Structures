all: main.o deque.o
	gcc -Wall -g deque.o main.o -o t
main.o: deque.o main.c
	gcc -Wall -g -c main.c -o main.o
deque.o: deque.c
	gcc -Wall -g -c deque.c -o deque.o
run:
	./t
clean:
	rm *.o t
