CC = gcc
CFLAGS = -DDEBUG -Wall -ggdb -O2

hanoi : hanoiprog.o hanoi.o pilha.o
	$(CC) $(CFLAGS) hanoiprog.o hanoi.o pilha.o -o hanoi -lncurses

hanoiprog.o : hanoiprog.c	
	$(CC) $(CFLAGS) -c hanoiprog.c

hanoi.o : hanoi.c
	$(CC) $(CFLAGS) -c hanoi.c

pilha.o : pilha.c
	$(CC) $(CFLAGS) -c pilha.c

clean :
	rm *.o hanoi

