CC = gcc
CFLAGS = -Wall 

ortografia : ortografia.o funcoes.o 
	$(CC) $(CFLAGS) ortografia.o funcoes.o -o ortografia

ortografia.o : ortografia.c	
	$(CC) $(CFLAGS) -c ortografia.c

funcoes.o : funcoes.c
	$(CC) $(CFLAGS) -c funcoes.c

clean :
	rm *.o ortografia

