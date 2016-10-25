#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _pilha{
        void *dados_pilha;
        int tam_pilha;
        int tam_elem;
        int topo_pilha;
}Pilha;

Pilha *InicPilha (int tamelem,int nelem){
    Pilha *aux;
    if ((aux=(Pilha *)malloc(sizeof(Pilha)))==NULL)
        return NULL;
    aux->tam_elem=tamelem;
    aux->tam_pilha=aux->tam_elem*(nelem);
    if((aux->dados_pilha=malloc(aux->tam_pilha))==NULL)
        return NULL;
    aux->topo_pilha=0;
    return aux;
}

void FimPilha(Pilha *pilha){
    free(pilha->dados_pilha);
    free(pilha);
}

int Push(Pilha *pilha,void *elem){
    void *pos;
    if(pilha->topo_pilha==pilha->tam_pilha)
        return 0;
    else{
        pos=pilha->dados_pilha+pilha->topo_pilha;
        pilha->topo_pilha=pilha->topo_pilha+pilha->tam_elem;
        memcpy(pos,elem,pilha->tam_elem);
        return 1;
    }
}

void *Pop(Pilha *pilha){
    void *aux;
    if (pilha->topo_pilha==0)
        return 0;
    else{
        pilha->topo_pilha=pilha->topo_pilha-pilha->tam_elem;
        aux=pilha->dados_pilha+pilha->topo_pilha;
        return aux;
    }
}

void *Top(Pilha *pilha){
	if (pilha->topo_pilha==0)
		return 0;
	else{
		void *aux;
		aux=pilha->dados_pilha+(pilha->topo_pilha-pilha->tam_elem);
		return(aux);
	}
}

int N_Itens(Pilha *pilha){
	return(pilha->topo_pilha/pilha->tam_elem);
}



void ImprimePilha(Pilha *pilha){
    int *impressor;
    int i;
    if (pilha->topo_pilha==0)
        printf("Pilha vazia.\n");
    else{
        for (i=0;i<pilha->topo_pilha-pilha->tam_elem+1;i=i+pilha->tam_elem){
            impressor=pilha->dados_pilha+i;
            printf("%d ",*impressor);
        }
        printf("\n");
  }

}

