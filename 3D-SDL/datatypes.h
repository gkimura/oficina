

#ifndef _datatypes_h
#define _datatypes_h

#include <SDL2/SDL.h>
#include <SDL/SDL.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct _vertice{
	float x,y,z; //vertices dimensão
	struct _vertice *prox;
}Vertice;

typedef struct _face{
	int nv; // numero de vertices
	int vet[10];  //vetor de vertices de cada face
	struct _face *prox;
}Face;

#endif
