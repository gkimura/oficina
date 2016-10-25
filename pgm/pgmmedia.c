#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcarq.h"

void Filtro_Media(int **mat,int **mat_final,int linhas,int colunas){
	int i,j;int soma;
	//media middle
	for(i=1;i<linhas-1;i++){
		for(j=1;j<colunas-1;j++){
			soma= mat[i-1][j-1]+ mat[i-1][j] + mat[i-1][j+1] + mat[i][j-1] + mat[i][j] + mat [i][j+1] + mat[i+1][j-1] + mat[i+1][j] + mat[i+1][j+1];
			mat_final[i][j] = soma/9;
		}
	}
	//media up-down
	i=0;
	for(j=1;j<colunas-1;j++){
		soma = mat[i][j-1] + mat[i][j] + mat[i][j+1] + mat[i+1][j-1] + mat[i+1][j] + mat[i+1][j+1];
		mat_final[i][j] = soma/6;
	}
	i=linhas-1;
	for(j=1;j<colunas-1;j++){
		soma = mat[i][j-1] + mat[i][j] + mat[i][j+1] + mat[i-1][j-1] + mat[i-1][j] + mat[i-1][j+1] ;
		mat_final[i][j]= soma/6; 
	}
	//media left-right
	j=0;
	for(i=1;i<linhas-1;i++){
		soma = mat[i-1][j] + mat[i][j] + mat[i+1][j] + mat[i-1][j+1] + mat[i][j+1] + mat[i+1][j+1];
		mat_final[i][j] = soma/6;
	}
	j=colunas-1;
	for(i=1;i<linhas-1;i++){
		soma = mat[i-1][j] + mat[i][j] + mat[i+1][j] + mat[i-1][j-1] + mat[i][j-1] + mat[i+1][j-1];
		mat_final[i][j] = soma/6;
	}	
	//media corners
	//media up
	i=0;j=0;
	mat_final[i][j]=(mat[i][j] + mat[i+1][j+1] + mat[i][j+1] + mat[i+1][j])/4;
	j=colunas-1;
	mat_final[i][j]=(mat[i][j] + mat[i+1][j] + mat[i][j-1] + mat [i+1][j-1])/4;
	//media down
	i=linhas-1;j=0;
	mat_final[i][j]=(mat[i][j] + mat[i][j+1] + mat[i-1][j] + mat [i-1][j+1])/4;
	j=colunas-1;
	mat_final[i][j]=(mat[i][j] + mat[i][j-1] + mat[i-1][j] + mat [i-1][j-1])/4;
	
}



int main (int argc, char *argv[]){  
	FILE *in ;
	FILE *out; 
	int i,linhas,colunas,max_cinza,**mat,**mat_final;
	char*infile=NULL;
	char*outfile=NULL;
	char c1,c2;

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
	Filtro_Media(mat,mat_final,linhas,colunas);

	//escreve no arquivo final
	Escrita_Arquivo(out,mat_final,linhas,colunas,max_cinza,c1,c2);

	//desalocacao de memoria
	Free_Matriz(mat,mat_final,linhas);

	//fecha arquivos
	fclose(in);
	fclose(out);
	return 0;	
}
