
#ifndef _function_h_
#define _function_h_

#include "structs4.h"

void Vitoria(Space_Invaders *SI,Aliens *inimigo,Tiro *tiro_inimigo, Tiro *tiro_player,Shelter *shelter);
void Game_Over(Space_Invaders *SI,Aliens *inimigo,Tiro *tiro_inimigo, Tiro *tiro_player,Shelter *shelter);
void Tempo(Space_Invaders *SI);
void Check_Vitoria(Space_Invaders *SI,int *inimigo_ativo,int *time_alien,Aliens *inimigo,Tiro *tiro_inimigo,Tiro *tiro_player,Shelter *shelter);

#endif
