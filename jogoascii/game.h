
#ifndef _game_h_
#define _game_h_

#include "structs4.h"

void Inic_Jogo(Space_Invaders *SI,Player *player, Aliens *inimigo,Tiro *tiro_inimigo,Tiro *tiro_player,Shelter *shelter);

void Movimento_Player(Space_Invaders *SI,Player *player,Tiro  *tiro_player,int *tiro_player_ativo,Aliens *inimigo,Tiro *tiro_inimigo,Shelter *shelter);

void Tiro_Inimigo(int *tiro_ativo,Tiro *tiro_inimigo,Aliens *inimigo,int k);

void Movimento_Aliens(Space_Invaders *SI,Player *player,Aliens *inimigo,Tiro *tiro_inimigo,int *tiro_ativo,int *inimigo_ativo,int *time_alien,Shelter *shelter,Tiro *tiro_player,FILE *score,int *cont_especial,int *especial_ativo);

void Movimento_Tiros(Space_Invaders *SI,Player *player,Aliens *inimigo,Tiro *tiro_inimigo,Tiro  *tiro_player,int *tiro_ativo,int *tiro_player_ativo,int *inimigo_ativo,Shelter *shelter);


#endif
