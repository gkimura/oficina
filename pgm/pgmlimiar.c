#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcarq.h"

void Filtro_Limiar(int **mat, int **mat_final, int linhas, int colunas,int max,int limiar){
	int i,j;
	for(i=0;i<linhas;i++){
		for(j=0;j<colunas;j++){
			if (mat[i][j]>= limiar)
				mat_final[i][j] = max;
			else
				mat_final[i][j] = 0; 
		}
	}
}

int main (int argc, char *argv[]){  
	FILE *in = malloc(sizeof(char));
	FILE *out = malloc(sizeof(char)); 
	int i,linhas,colunas,max_cinza,**mat,**mat_final,limiar;
	char*infile=NULL;
	char*outfile=NULL;
	char *aux,c1,c2;

	//leitura nome do outfile 
	for( i=0; i<argc; i++ ){
		 if (strcmp(argv[i], "-o") == 0){ 
			i++;
			outfile = argv[i];
			strcat(outfile,".pgm");
			out = fopen(outfile,"w");
		}

	}
	if(!outfile)
		out = stdout;		

	for( i=0; i<argc; i++ ){
		if (strcmp(argv[i], "-i") == 0){
			i++;
			infile = argv[i];
			strcat(infile,".pgm");
			in = fopen(infile,"r");
		}
	}
	if(!infile)
		in = stdin;
	
	for( i=0; i<argc; i++ ){
		if (strcmp(argv[i], "-l") == 0){
			i++;
			aux = argv[i];
		}
	}
	if(!aux){
		limiar = max_cinza/2;
	}else{
		sscanf(aux,"%d",&limiar);
	}

	c1 = 'P';
	//recebe formato de imagem P2 ou P5
	c2 = Confere_Formato(in,c1);

	//pula comentarios
	Skip_Comments(in);

	//le valores de colunas,linhas e maximo de cinza
	Le_Valores(in,&colunas,&linhas,&max_cinza);

	//alocacao das matrizes inicial e resultante
	mat = Aloca_Matriz(linhas,colunas); 
	if(!mat){ fprintf(stderr,"ERRO: Falha na alocacao de matriz"); exit(1); }
	mat_final = Aloca_Matriz(linhas,colunas);
	if(!mat_final){ fprintf(stderr,"ERRO: Falha na alocacao de matriz"); exit(1); }
	//le elementos da matriz
	Leitura_Arquivo(in,mat,c2,linhas,colunas,max_cinza);

	//realiza o filtro
	Filtro_Limiar(mat,mat_final,linhas,colunas,max_cinza,limiar);

	//escreve no arquivo final
	Escrita_Arquivo(out,mat_final,linhas,colunas,max_cinza,c1,c2);	

	//desalocacao de memoria
	Free_Matriz(mat,mat_final,linhas);

	//fecha arquivos
	fclose(in);
	fclose(out);
	return 0;
}
