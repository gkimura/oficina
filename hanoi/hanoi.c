
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

typedef struct _hanoi{
    Pilha *pinos[3];
}Hanoi;

Hanoi *InicHanoi(int ndiscos){
    Hanoi *aux;
    int i;
    aux=(Hanoi *)malloc(sizeof(Hanoi));
    aux->pinos[0]=InicPilha(sizeof(int),ndiscos);
    aux->pinos[1]=InicPilha(sizeof(int),ndiscos);
    aux->pinos[2]=InicPilha(sizeof(int),ndiscos);

    for(i=ndiscos;i!=0;i--){
        Push(aux->pinos[0],&i);
    }

    return aux;
}

int FimHanoi(Hanoi *hanoi){
    if((hanoi->pinos[1]->topo_pilha==hanoi->pinos[1]->tam_pilha)||(hanoi->pinos[2]->topo_pilha==hanoi->pinos[2]->tam_pilha))
    return 1;
    else
    return 0;
}

int VazioPino(Pilha *pino){
    return(pino->topo_pilha==0);
}

void MovimentaHanoi(Hanoi *hanoi,int origem,int destino){
    if (destino==origem||origem<=-1||origem>3||destino<=-1||destino>3)
        printf("Opcao Invalida");
    else if (VazioPino(hanoi->pinos[origem]))
        printf("Sem disco para deslocar\n");
else if((!VazioPino(hanoi->pinos[destino]))&&(*(int*)Top(hanoi->pinos[origem])) >(*(int*)Top(hanoi->pinos[destino])))
        printf("Disco de origem maior  que o de destino\n");
    else
        Push(hanoi->pinos[destino],Pop(hanoi->pinos[origem]));
}

void ImprimeHanoi(Hanoi *hanoi){
    int i;
    for (i=0;i<3;i++){
        if(VazioPino(hanoi->pinos[i]))
             printf("Pino %d: \n\n",i);
         else{
             printf("Pino %d: \n",i);
             ImprimePilha(hanoi->pinos[i]);
        }
    }

}

void ApagaHanoi(Hanoi *hanoi){
    int i;
    for (i=0;i<2;i++)
        FimPilha(hanoi->pinos[i]);
    free(hanoi);
}

