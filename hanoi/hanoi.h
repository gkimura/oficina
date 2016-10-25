#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

typedef struct _hanoi{
    Pilha *pinos[3];
}Hanoi;

Hanoi *InicHanoi(int ndiscos);

int FimHanoi(Hanoi *hanoi);

int VazioPino(Pilha *pino);

void MovimentaHanoi(Hanoi *hanoi,int origem,int destino);

void ImprimeHanoi(Hanoi *hanoi);

void ApagaHanoi(Hanoi *hanoi);


