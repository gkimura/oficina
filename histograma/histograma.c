
#include <stdio.h>
#include <stdlib.h>
#include "random.h"
#define MAX 1000000

//sorteia vetor de 1000000 numeros
void sorteia_conta( int vetor[] ){
	int i,n;
	for( i=0;i<100;i++ )
		vetor[i]=0;
	for( i=0;i<MAX;i++ ){
		n = random_cl()%100;
		vetor[n]++;
	} 	
}
//encontra o maior numero de repeticoes
long maior_numero( int vetor[]){
	int i,maior;
	maior = vetor[0];

	for( i=0;i<100;i++ ){
		if ( vetor[i]> maior ){
			maior = vetor[i];
		}
	}	

	return maior;
}
//transforma vetor de numeros no intervalo [0..99]
void normaliza_vetor( int vetor[], int valor_maximo){
	int i;
	for( i=0;i<100;i++ ){
		vetor[i]= (100*vetor[i])/valor_maximo;
	}
}

//impressao do histograma
void impressao_histograma (int vetor[]){
	int i,j;
	printf("   0   10   20   30   40   50   60   70   80   90   100\n");
	printf("   +----+----+----+----+----+----+----+----+----+----+\n");
	for( i=0;i<10;i++ ){
		printf("%d  |",i);
		for( j=1;j<=(vetor[i]/2);j++ ){
			printf("*");
		}
		printf("\n");
	}
	for( i=10;i<100;i++ ){
		printf("%d |",i);
		for( j=1;j<=(vetor[i]/2);j++ ){
			printf("*");
		}
		printf("\n");
	}
}
int main(){
	int vetor[100],repeticao_maxima;

	//sorteia 10^6 numeros e conta quantas vezes se repetem
	sorteia_conta(vetor);
	//encontra o maior numero
	repeticao_maxima = maior_numero(vetor);			
	//normaliza o vetor
	normaliza_vetor (vetor, repeticao_maxima);
	//impressao do histograma
	impressao_histograma(vetor);

	return 0;			
}
