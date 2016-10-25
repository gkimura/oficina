CC = gcc
CFLAGS = -Wall -g 
OFLAGS = -lm -lncurses

all: main.o game.o drawerase.o function.o 
	$(CC) $(CFLAGS) main.o game.o drawerase.o function.o $(OFLAGS) -o game

main.o: main.c
	$(CC) $(OFLAGS) -c main.c

game.o: game.c
	$(CC) $(OFLAGS) -c game.c

drawerase.o: drawerase.c
	$(CC) $(OFLAGS) -c drawerase.c

function.o: function.c
	$(CC) $(OFLAGS) -c function.c


clean :
	rm *.o game


