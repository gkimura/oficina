
#include "game.h"
#include "function.h"
#include "drawerase.h"
#include "structs4.h"

int main(){
	FILE *score;
	Space_Invaders SI;
	Player player;
	Aliens *inimigo;
	Tiro *tiro_inimigo;
	Tiro *tiro_player;
	Shelter *shelter;

	int tiro_ativo=0;       //numero de tiros de inimigo ativos em jogo
	int tiro_player_ativo = 0;     //numero de tiros do player ativos em jogo
	int inimigo_ativo = NALIENS;      //numero de aliens vivos em jogo
	int especial_ativo = NALIENS-50;
	int time_alien=3000;      //controle tempo de impressao dos inimigos
	int cont_especial= 20;   //controle de impressao de inimigos especiais

	inimigo = malloc(NALIENS*(sizeof(Aliens)));
	tiro_inimigo =malloc(NTIROS*(sizeof(Tiro)));
	tiro_player=malloc(NTIROSPLAYER*(sizeof(Tiro)));
	shelter = malloc(NSHELTER*(sizeof(Shelter)));
	score = fopen("score.txt","w");

	fprintf(score,"-== SPACE INVADERS ==-\n");
	fprintf(score,"        SCORE\n  ");

	initscr();

	Imprime_Intro(&SI);
	Imprime_Header(&SI);
	//Confere_Tela();
	Inic_Jogo(&SI,&player,inimigo,tiro_inimigo,tiro_player,shelter);
	Imprime_Jogo(&player,inimigo,tiro_inimigo,tiro_player,shelter);

	while(1){
			Imprime_Header(&SI);
			Movimento_Player(&SI,&player,tiro_player,&tiro_player_ativo,inimigo,tiro_inimigo,shelter);	
			Movimento_Tiros(&SI,&player,inimigo,tiro_inimigo,tiro_player,&tiro_ativo,&tiro_player_ativo,&inimigo_ativo,shelter);
			Movimento_Aliens(&SI,&player,inimigo,tiro_inimigo,&tiro_ativo,&inimigo_ativo,&time_alien,shelter,tiro_player,score,&cont_especial,&especial_ativo);		
			Check_Vitoria(&SI,&inimigo_ativo,&time_alien,inimigo,tiro_inimigo,tiro_player,shelter);			
			Tempo(&SI);
	}


	return 0;
}
