
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM_PALAVRA 20

//contagem do numero de palavras do dicionario
int Contagem_Palavras(FILE *stream){
	int i=0;
	char ch=fgetc(stream);
	while(ch!=EOF){
		if (ch=='\n'){
			i++;
		}
	ch = fgetc(stream);
	}
	return (i); // numero de palavras do dicionario
}

//alocacao de vetor de strings
char **Aloca_Vet(int cont){
	char **aux;
	int i;
	aux = (char **)malloc(cont*sizeof(char*));
	for(i=0;i<cont;i++){
		aux[i] = (char*)malloc(TAM_PALAVRA*sizeof(char));
	}
	return(aux);
}

//copia as palavras do dicionario para o vetor
void Copia_String(FILE *stream,char **vet,int cont){
	int i,j;
	char ch;
	for(i=0;i<cont;i++){
		j=0;
		ch = fgetc(stream);
		while((ch!='\n') && (ch!=EOF)){
			vet[i][j]=ch;
			ch=fgetc(stream);
			j++;
		}
		vet[i][j] = '\0';
	}
}

//compara a palavra do texto com cada palavra do dicionario
int Compara(char **vet,char palavra[],int cont){
	int i;
	for(i=0;i<cont;i++){
		if(strcmp(palavra,vet[i])==0)
			return 1;
	}
	return (0);
}

int Eh_Numero(char c){
	if(c>='0' && c<='9')
		return 1;
	else 
		return 0;
}

// converte caracteres maiusculos para minusculos
void Minuscula (char *palavra){
	int i;
	for(i=0; palavra[i]!='\0'; i++){
		if((palavra[i]>='A')&&(palavra[i]<='Z'))
    			palavra[i] = palavra[i]+32;
  	}
}

void Corretor_Ortografico(FILE *in,FILE *out,char **vet,int cont){
	int eh_igual, i;
	char palavra[TAM_PALAVRA], copia[TAM_PALAVRA], c;

	while(!feof(in)){
		c = getc(in);
		if(ispunct(c)||Eh_Numero(c)||c==' '||c=='\n'){ //nao eh palavra, só imprimir
			fprintf(out,"%c",c);
		}else{	
			//leitura da palavra
			i=0;
			while ((!ispunct(c)) && (!Eh_Numero(c)) && c!='\n' && c!=' ' && i<TAM_PALAVRA && c!=EOF){
 				palavra[i]=c;
 				i++;  
				c = getc(in);  
 			}
			//impressao da palavra e o caractere de parada
			if(c != EOF){
				palavra[i]='\0';
				if(palavra[1]=='\0'){ // unica letra, nao considerada uma palavra -> so imprimir
					fprintf(out,"%s",palavra);
				}else{
					strcpy(copia,palavra);//faz copia da palavra original
					Minuscula(copia);
 					eh_igual = Compara(vet,copia,cont);
					if (eh_igual==1){
		 				fprintf(out,"%s", palavra);
					}else{
						fprintf(out,"[%s]", palavra);
					}
				}	
			fprintf(out,"%c",c);	
			}
		}
	}

}
//desalocacao de memoria
void Free_Vet(char **vet,int numb){
	int i;
	for(i=0;i<numb;i++){
		free(vet[i]);
	}
	free(vet);
}

