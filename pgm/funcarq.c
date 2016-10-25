
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int **Aloca_Matriz(int linhas,int colunas){
	int i,**aux;
	if((aux =(int **) malloc (linhas * sizeof(int*)))==NULL) return NULL;

	for(i=0; i<linhas; i++){
		if((aux[i] = (int*)malloc (colunas * sizeof (int)))==NULL)
			return NULL;
	}
	return (aux);
}
 
void Skip_Comments(FILE *in){
	char ch;
	//se a proxima posicao for # (comentario) entao avança, senao retorna uma posicao do ponteiro
	while((ch=getc(in))!='\n') getc(in);
	if((ch=getc(in)) =='#'){
		while(ch != '\n'){ 
			ch=getc(in);
		}
	}else{
		fseek(in,-1,1);
	}
}

void Le_Valores(FILE *in,int *colunas,int *linhas,int *max_cinza){
	fscanf(in,"%d", colunas);
	fscanf(in,"%d", linhas);
	getc(in);
	fscanf(in,"%d", max_cinza);
}

//confere se formato de imagem eh valido
//retorna 2 ou 5 (PGM PLAIN ou PGM RAW)
char Confere_Formato(FILE *in, char c1){
	char c0,c2;
	if( in==NULL ){
		fprintf(stderr,"Erro: Falha na abertura do arquivo 1.\n");
		exit(1); 
	}else{
		c0 = getc(in);
		c2 = getc(in); 
		if(c0 != c1){
			fprintf(stderr,"ERRO: Formato desconhecido.\n");
			exit(1);
		}else{
			if((c2 != '2') && (c2 != '5')){
				fprintf(stderr,"ERRO: Formato de imagem invalido.\n");
				exit(1);
			}
		} 
	}
	return c2;
}

void Leitura_Arquivo(FILE *in,int **mat,char tipo_mat,int linhas,int colunas,int max){
	int i,j;
	unsigned char ch;
   	 if(tipo_mat == '2'){ //pgm P2
       		for (i=0; i<linhas; i++){
         		for (j=0; j<colunas; j++){			
		           		 if(!fscanf(in,"%d", &mat[i][j])) fprintf(stderr,"ERRO: falha ao ler a linha");else;
			}
         	}
  	  }else{//pgm P5
		for(i=0;i<linhas;i++){
			j=0;
			while(j<colunas){
				ch=getc(in);
				if(ch=='\n') ch=getc(in);
				else{
					mat[i][j]=(int)ch;
					j++;
				} 
			} 
		}
	 }
}

void Escrita_Arquivo(FILE *out,int **mat_final,int linhas,int colunas,int max_cinza,int c1,int c2){
	int i,j;	
	if( out == NULL ){
		fprintf(stderr,"Erro: Falha na abertura de arquivo 2.\n");
		exit(1);
	}else{	
		fprintf(out, "%c%c\n",c1,c2);
		fprintf(out, "%d %d\n", colunas, linhas);
		fprintf(out, "%d\n", max_cinza);
		for(i=0;i<linhas;i++){
			for(j=0;j<colunas;j++){
				fprintf(out,"%d ",mat_final[i][j]);
			}
			fprintf(out,"\n");
		}	
	}	
}

//Desalocacao de matrizes
void Free_Matriz(int **mat,int **mat_final,int linhas){
	int i;
	for(i=0;i<linhas;i++){
		free (mat[i]);
		free (mat_final[i]);
	}
	free(mat);
	free(mat_final);
}
