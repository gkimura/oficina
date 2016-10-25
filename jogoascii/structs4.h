
#ifndef _structs4_h
#define _structs4_h
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include <curses.h>
#include <time.h>
#include <string.h>

#define MORTO 0
#define QSE_MORTO -1
#define VIVO 1
#define AGUARDANDO 2 
#define ON 1 
#define OFF 0
#define DIREITA 1
#define ESQUERDA -1
#define NTIROS 5
#define NALIENS 55
#define NTIROSPLAYER 3
#define NSHELTER 5

typedef struct{
	int lin,col;
	char matriz[];
}DESENHO;

typedef struct{
	int time;
	int life;
	int score;
}Space_Invaders;

typedef struct{
	DESENHO *desenho; 
	int lin,col;
	int cor;
}Player;

typedef struct{
	char desenho; //player = '|' inimigo = '*'
	int lin,col;
	int estado; //1-on 0-off
}Tiro;

typedef struct{
	DESENHO *desenho;
	int lin,col;
	int cor;
}Shelter;

typedef struct{
	DESENHO *desenho;
	int lin,col; //linha,coluna atual
	int estado; // 0 morto 1 vivo 2 aguardando para aparecer
	int pontos; //quanto vale cada inimigo morto
	int t_entrada; //hora que o elemento aparece	
	int direcao; //e-esquerda d-direita
	int t_tiro[3];// t_tiro[0]: tempo inicial para o tiro automatico, t_tiro[1]: contador, t_tiro[1]: 1-pode atirar 0-nao pode atirar
	int dano;
	int cor;
}Aliens;









#endif
