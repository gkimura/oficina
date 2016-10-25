
#include "drawerase.h"

void Colors(){
	start_color();
	init_pair (1,COLOR_MAGENTA,COLOR_BLACK);
	init_pair (2,COLOR_BLUE,COLOR_BLACK);
	init_pair (3,COLOR_GREEN,COLOR_BLACK);
	init_pair (4,COLOR_RED,COLOR_BLACK);
	init_pair (5,COLOR_CYAN,COLOR_BLACK);
	init_pair (6,COLOR_YELLOW,COLOR_BLACK);
	init_pair (7,COLOR_WHITE,COLOR_BLACK);
	init_pair (8,COLOR_BLUE,COLOR_BLUE);
}

void Draw(DESENHO *desenho,int lin,int col,int cor){
	int i,j;
	attron(A_BOLD);   // coloração mais clara
	attron (COLOR_PAIR(cor));
	for (i = 0;i < desenho->lin;i++){                     //para impressao do desenho
		for(j = 0;j < desenho->col;j++){	      //calculo da respectiva posicao da matriz		
			if (desenho->matriz[j+(desenho->col*i)] != ' '){
				mvprintw (lin + i,col + j,"%c",desenho->matriz[j+(desenho->col*i)]);
			}
		}
	}
	attroff (COLOR_PAIR(cor));
	attroff(A_BOLD);
}


void Erase(DESENHO *desenho,int lin,int col){
	int i,j;
	for (i = 0;i < desenho->lin;i++){
		for(j = 0;j < desenho->col;j++){
			if (desenho->matriz[j+(desenho->col*i)] != ' '){
					mvprintw (lin + i,(col + j)-2,"  ");
					mvprintw (lin + i,(col + j)+1,"  ");
					mvprintw (lin + i,col + j,"  ");
			}
		}			
	}
}

void Imprime_Header(Space_Invaders *SI){
	attron (COLOR_PAIR(7));
	mvprintw(0,(COLS/2)-7,"SPACE INVADERS");//Nome do jogo
	mvprintw(1,1," SCORE <1>    TIME");
	mvprintw(2,4,"%d          %d",SI->score,SI->time/1000);
	mvprintw(0,COLS-6,"/\\/\\ ");
	mvprintw(1,COLS-6,"\\  /");
	mvprintw(2,COLS-6," \\/");	
	mvprintw(1,COLS-5,"%d",SI->life);
	mvprintw(1,COLS-18,"PAUSE");
	mvprintw(2,COLS-16,"P");
	attroff (COLOR_PAIR(7));

}

//Impressao do jogo inicial, shelter, player e todos os inimigos vivos
void Imprime_Jogo(Player *player, Aliens *inimigo,Tiro *tiro_inimigo,Tiro *tiro_player,Shelter *shelter){
	int i;
	Draw(player->desenho,player->lin,player->col,player->cor);

	for(i=0;i<NALIENS;i++){
		if(inimigo[i].estado == VIVO)
			Draw(inimigo[i].desenho,inimigo[i].lin,inimigo[i].col,inimigo[i].cor);
	}
	for(i=0;i<NSHELTER;i++){
		Draw(shelter[i].desenho,shelter[i].lin,shelter[i].col,shelter[i].cor);

	}
	attron (COLOR_PAIR(7));

	//impressao dos tiros inimigo
	for(i=0;i<NTIROS;i++){
		if(tiro_inimigo[i].estado==ON)
			mvprintw(tiro_inimigo[i].lin,tiro_inimigo[i].col,"%c",tiro_inimigo[i].desenho);
	}
	for(i=0;i<NTIROSPLAYER;i++){
		if(tiro_player[i].estado == ON)
			mvprintw(tiro_player[i].lin,tiro_player[i].col,"%c",tiro_player[i].desenho);
	}
	attroff (COLOR_PAIR(7));	
}

void Imprime_Intro(Space_Invaders *SI){
	int action;
	curs_set(0);
	nodelay(stdscr,0);
	Colors();
	attron(A_BOLD); //brighter color 
	attron (COLOR_PAIR(6));
	mvprintw(LINES/2-8, (COLS / 2) - 30, "                            _                     _  ");
	mvprintw(LINES/2-7, (COLS / 2) - 30, "                           |_|                   | |  ");
	mvprintw(LINES/2-6, (COLS / 2) - 30, " ___ _ __   __ _  ___ ___   _ _ ____   ____ _  __| | ___ _ __ ___ ");
	mvprintw(LINES/2-5, (COLS / 2) - 30, "/ __| '_ \\ / _` |/ __/ _ \\ | | '_ \\ \\ / / _` |/ _` |/ _ \\ '__/ __|");
	mvprintw(LINES/2-4, (COLS / 2) - 30, "\\__ \\ |_) | (_| | (_|  __/ | | | | \\ V / (_| | (_| |  __/ |  \\__ \\");
	mvprintw(LINES/2-3, (COLS / 2) - 30, "|___/ .__/ \\__,_|\\___\\___| |_|_| |_|\\_/ \\__,_|\\__,_|\\___|_|  |___/");
	mvprintw(LINES/2-2, (COLS / 2) - 30, "    | | ");
	mvprintw(LINES/2-1, (COLS / 2) - 30, "    |_| ");
	
	attroff(COLOR_PAIR(6));
	attroff(A_BOLD);

	mvprintw(LINES/2+2,(COLS/2)-30,"CLICK  H  FOR INSTRUCTIONS OR ANY OTHER BUTTON TO START THE GAME");
	action = getch();
	if((action == 'H')||(action=='h')){
		clear();
		mvprintw((LINES/2)-3,COLS/2-10,"-==SPACE INVADERS==-");
		mvprintw((LINES/2)-2,COLS/2-5,"HOW TO PLAY:");
		mvprintw((LINES/2),COLS/2-45,"Use the arrow keys from your keyboard to move the player and click the space bar to shoot");
		mvprintw((LINES/2)+3,(COLS/2)-17,"Click any button to start the game");
		action = getch();
	}

	usleep(500);
	nodelay(stdscr,1);
	

}
