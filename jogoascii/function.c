
#include "function.h"


void Vitoria(Space_Invaders *SI,Aliens *inimigo,Tiro *tiro_inimigo, Tiro *tiro_player,Shelter *shelter){
	clear();
	nodelay(stdscr,0);
	attron (COLOR_PAIR(5));
	mvprintw(LINES/2-3, (COLS / 2) - 25, "__     __          __          ___         _   _ ");
	mvprintw(LINES/2-2, (COLS / 2) - 25, "\\ \\   / /          \\ \\        / (_)       | | | |");
	mvprintw(LINES/2-1, (COLS / 2) - 25, " \\ \\_/ /__  _   _   \\ \\  /\\  / / _ _ __   | | | |");
	mvprintw(LINES/2, (COLS / 2) - 25, "  \\   / _ \\| | | |   \\ \\/  \\/ / | | '_ \\  | | | |");
	mvprintw(LINES/2+1, (COLS / 2) - 25, "   | | (_) | |_| |    \\  /\\  /  | | | | | |_| |_|");
	mvprintw(LINES/2+2, (COLS / 2) - 25, "   |_|\\___/ \\__,_|     \\/  \\/   |_|_| |_| (_) (_)");
	mvprintw(LINES/2+3, (COLS / 2) - 25, "      Final Score: %d ",SI->score);
	mvprintw(LINES/2+4, (COLS / 2) - 25, "      Time: %d ",SI->time/1000);
	attroff(COLOR_PAIR(5));
	refresh();
	getch();

	//desalocacao de memoria
	free(inimigo);                           
	free(tiro_inimigo);
	free(tiro_player);
	free(shelter);
	usleep(800000);
	endwin();
	exit(0);

}

void Game_Over(Space_Invaders *SI,Aliens *inimigo,Tiro *tiro_inimigo, Tiro *tiro_player,Shelter *shelter){
	clear();
	nodelay(stdscr,false);

	attron (COLOR_PAIR(5));
	mvprintw(LINES/2-3, (COLS / 2) - 25, "__     __           _                      _   _ ");
	mvprintw(LINES/2-2, (COLS / 2) - 25, "\\ \\   / /          | |                    | | | |");
	mvprintw(LINES/2-1, (COLS / 2) - 25, " \\ \\_/ /__  _   _  | |     ___  ___  ___  | | | |");
	mvprintw(LINES/2, (COLS / 2) - 25, "  \\   / _ \\| | | | | |    / _ \\/ __|/ _ \\ | | | |");
	mvprintw(LINES/2+1, (COLS / 2) - 25, "   | | (_) | |_| | | |___| (_) \\__ \\  __/ |_| |_|");
	mvprintw(LINES/2+2, (COLS / 2) - 25, "   |_|\\___/ \\__,_| |______\\___/|___/\\___| (_) (_)");
	mvprintw(LINES/2+3, (COLS / 2) - 25, "      Final Score: %d ",SI->score);
	mvprintw(LINES/2+4, (COLS / 2) - 25, "      Time: %d ",SI->time/1000);
	attroff(COLOR_PAIR(5));
	getch();	

	//desalocao de memoria
	free(inimigo);
	free(tiro_inimigo);
	free(tiro_player);
	free(shelter);
	usleep(800000);

	endwin();
	exit(0);
}

	
void Tempo(Space_Invaders *SI){

	usleep(70);
	SI->time ++;
}


void Check_Vitoria(Space_Invaders *SI,int *inimigo_ativo,int *time_alien,Aliens *inimigo,Tiro *tiro_inimigo,Tiro *tiro_player,Shelter *shelter){
	//ao longo da morte de inimigos, a movimentacao deles eh mais rapida
	if(*inimigo_ativo == NALIENS-10)
		*time_alien = 1200;
	else if(*inimigo_ativo == NALIENS-20)
		*time_alien = 800;
	else if (*inimigo_ativo == NALIENS-30)
		*time_alien = 700;
	else if (*inimigo_ativo == NALIENS-40)
		*time_alien = 500;
	else if (*inimigo_ativo == NALIENS-50)
		*time_alien = 200;	
	
	if(*inimigo_ativo == 0) Vitoria(SI,inimigo,tiro_inimigo,tiro_player,shelter);
	else if (SI->life == 0)Game_Over(SI,inimigo,tiro_inimigo,tiro_player,shelter);
}
