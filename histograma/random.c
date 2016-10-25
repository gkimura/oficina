
#include <stdio.h>
#include <stdlib.h>
#define A 40692
#define C 127
#define M 10000000

long seed = 0;

long random_cl(){
	seed =((A*seed) + C) % M; 
	return seed;
}

void random_cl_seed(long s){
	seed=s;
}

long random_cl_max(){
	return (M-1);	
}
