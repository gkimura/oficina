CC = gcc
CFLAGS = -Wall -g 
OFLAGS = -lSDL2 -lSDL2_gfx -lm


wireframe: wireframe.o objread.o graphics.o 
	$(CC) $(CFLAGS) wireframe.o objread.o graphics.o $(OFLAGS) -o wireframe

graphics.o: graphics.c
	$(CC) $(OFLAGS) -c graphics.c

objread.o: objread.c
	$(CC) $(OFLAGS) -c objread.c

clean :
	rm *.o wireframe


