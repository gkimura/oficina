
#ifndef _drawerase_h_
#define _drawerase_h_

#include "structs4.h"

void Colors();
void Draw(DESENHO *desenho,int lin,int col,int cor);
void Erase(DESENHO *desenho,int lin,int col);
void Imprime_Header(Space_Invaders *SI);
void Imprime_Jogo(Player *player, Aliens *inimigo,Tiro *tiro_inimigo,Tiro *tiro_player,Shelter *shelter);
void Imprime_Intro(Space_Invaders *SI);

#endif
