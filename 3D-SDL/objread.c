
#include <stdio.h>
#include "datatypes.h"

//corta em strings menores, leitura de um inteiro(numeracao do vertice)
void Leitura_Faces(Face *ap_f, char *line){
	char *aux;
	ap_f->nv = 0;

	aux = strtok(line, " "); 
	aux = strtok(NULL, " ");
	while((aux!=NULL) && (aux[0]!=' ') && (aux[0]!='/') && (aux[0]!='\n')){
		ap_f->vet[ap_f->nv] = atoi(aux);
		ap_f->nv++; //acrescenta indice do vertice da face 
		aux = strtok(NULL, " ");
	}
}

void Leitura_Arquivo(int argc, char *argv[],Vertice *ap_v, Face *ap_f, int *n_vertice, int *n_face){
	FILE *in;
	Vertice *auxv = ap_v;
	Face *auxf = ap_f;
	*n_vertice = 0;
	*n_face = 0;
	char line[180];
	char var;
	if (argc > 1){
		in = fopen(argv[1],"r");
	}else{
		in = stdin;
	}

	while(fgets(line,180,in)){
		if(line[0]=='#'); // comentario,ignora
		else if ((line[0]=='v')&&(line[1]==' ')){ //formato 'v '
			if(*n_vertice == 0){ //primeiro vertice lido, nao precisa criar novo nodo de lista Vértice
				sscanf(line,"%c %f %f %f",&var,&ap_v->x,&ap_v->y,&ap_v->z); //leitura x,y,z 
			}else{
				ap_v->prox = (Vertice*)malloc(sizeof(Vertice));
				ap_v = ap_v->prox;
				sscanf(line,"%c %f %f %f",&var,&ap_v->x,&ap_v->y,&ap_v->z);
				
			}
			(*n_vertice)++;
		}else if ((line[0]=='f')&&(line[1]==' ')){ //formato 'f '
			if(*n_face == 0) // primeira face lida, nao precisa criar novo nodo de lista Face
				Leitura_Faces(ap_f,line);
			else{
				ap_f->prox = (Face*)malloc(sizeof(Face));
				ap_f = ap_f->prox;
				Leitura_Faces(ap_f,line);
			}
			(*n_face)++;
		}
	}

	ap_v->prox = NULL; //fim de lista vertice
	ap_f->prox = NULL; //fim de lista face

	ap_v = auxv; //retorna ponteiro ao inicio da lista
	ap_f = auxf;	
}

void Free_Listas(Vertice *ap_v, Face *ap_f){
	Vertice *aux;
	aux = ap_v;
	while(aux!=NULL){
		ap_v = ap_v->prox;
		free(aux);
		aux = ap_v;
	}

	Face *aux2;
	aux2 = ap_f;
	while(aux2!=NULL){
		aux2 = aux2->prox;
		free(aux2);
	}

}
