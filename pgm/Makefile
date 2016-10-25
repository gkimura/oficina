CC = gcc
CFLAGS = -Wall -g 

all: pgmlimiar pgmmedia pgmmediana pgmnega

pgmlimiar: pgmlimiar.c funcarq.c
	$(CC) $(CFLAGS) pgmlimiar.c funcarq.c -o pgmlimiar

pgmmedia: pgmmedia.c funcarq.c
	$(CC) $(CFLAGS) pgmmedia.c funcarq.c -o pgmmedia

pgmmediana: pgmmediana.c funcarq.c
	$(CC) $(CFLAGS) pgmmediana.c funcarq.c -o pgmmediana

pgmnega: pgmnega.c funcarq.c
	$(CC) $(CFLAGS) pgmnega.c funcarq.c -o pgmnega

funcarq.o: funcarq.c  funcarq.h
	$(CC) $(CFLAGS) -c funcarq.c

clean: 
	$(RM) count *.o *~

