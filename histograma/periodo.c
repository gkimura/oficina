
#include <stdio.h>
#include <stdlib.h>
#include "random.h"

//Primeira vez sorteado adiciona 1 ao numero, senao para a busca
int busca(char vetor[],long sorteado){
	if( vetor[sorteado]==1 )
		return 1;
	else{
		vetor[sorteado]++;
		return 0;
	}
}


int main(void){
	long vet_tam,tam,sorteado;
	//vet_tam recebe o numero maximo que pode ser sorteado
	vet_tam = random_cl_max();

	char *vetor;
	vetor = malloc((vet_tam+1)*sizeof(char));

	tam=0;
	sorteado = random_cl();
	while( busca(vetor,sorteado)==0 ){
		tam++;
		sorteado = random_cl();
	}
	
	printf("Tamanho maximo da sequencia gerada sem repeticoes de numeros eh : %ld\n",tam);
	
	return 0;
}
