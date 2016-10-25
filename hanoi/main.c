#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hanoi.h"

int main(void){
    Hanoi *hanoi;
    int ndiscos,origem,destino;
    printf("Insira numero de discos do hanoi: \n");
    scanf("%d",&ndiscos);
    hanoi=InicHanoi(ndiscos);
    ImprimeHanoi(hanoi);
    do{
        printf("\nEscolha as duas colunas:\n");
        scanf("%d %d",&origem,&destino);
        MovimentaHanoi(hanoi,origem,destino);
        ImprimeHanoi(hanoi);
    }while (!FimHanoi(hanoi));

    ApagaHanoi(hanoi);
    printf("Parabens,voce ganhou.\n");
}

