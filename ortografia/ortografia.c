
#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main(){
	FILE *in, *out ,*dici;
	int cont;
	char **vet;

	dici = fopen("/usr/share/dict/brazilian","r");
	in = stdin;
	out = stdout;	

	if (!dici){
		printf("Erro na abertura de arquivo dicionario.\n");
	}
	if (!in){
		printf("Erro na abertura de arquivo de entrada.\n");
	}
	if (!out){
		printf("Erro na abertura de arquivo de saida.\n");
	}
	
	cont = Contagem_Palavras(dici); //contagem do numero de palavras do dicionario
	vet = Aloca_Vet(cont);//aloca vetor de ponteiros
	rewind(dici);
	Copia_String(dici,vet,cont);//copia palavras do dicionario ao vetor
	Corretor_Ortografico(in,out,vet,cont);//correcao e impressao na saida
		
	Free_Vet(vet,cont);
	
	return 0;
}
