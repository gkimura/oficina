#include <ncurses.h>
#include <curses.h>
#include <string.h>
#include "hanoi.h"

#define P_LINES LINES-20
#define P_PINO1 (COLS/2)-32
#define P_PINO2 (COLS/2)-10   
#define P_PINO3 (COLS/2)+12



void Colors(){	
	start_color();
	init_pair (8,COLOR_BLACK,COLOR_WHITE);
	init_pair(0,COLOR_WHITE,COLOR_BLACK);
	init_pair(1,COLOR_WHITE,COLOR_GREEN);
        init_pair(2 , COLOR_WHITE, COLOR_MAGENTA);
        init_pair(3 , COLOR_WHITE, COLOR_YELLOW);
        init_pair(4 , COLOR_WHITE, COLOR_CYAN);
        init_pair(5 , COLOR_WHITE, COLOR_RED);
        init_pair(6, COLOR_WHITE, COLOR_GREEN);
        init_pair(7, COLOR_WHITE, COLOR_BLUE);
}

void ImprimirDiscos (Pilha *pilha,int pino_n){
	int n,haste,espaco,tam_disco,disco,disco_da_vez;
		n = pino_n; // salva numero do pino
	switch (pino_n){ // pega a coordenada do pino
		case 1:  pino_n = P_PINO1; break; 
		case 2:  pino_n = P_PINO2; break;
		case 3:  pino_n = P_PINO3; break;
	}
	mvprintw (P_LINES+1,pino_n,"          %d          ",n);
	for (disco = 0; disco < N_Itens(pilha);disco++){
		disco_da_vez = *(int*)(pilha->dados_pilha+(disco*sizeof(int)));
		espaco = 10 - (disco_da_vez + 1);  //espacamento para o disco permanecer no meio
		attrset(COLOR_PAIR(disco_da_vez));
		for (tam_disco = 0;tam_disco <= (disco_da_vez);tam_disco++){ 
			mvprintw(P_LINES-disco,pino_n+espaco+tam_disco," "); // imprimi primeiro lado do disco
		}	 
		mvprintw(P_LINES-disco,pino_n+espaco+tam_disco,"%d",disco_da_vez); // imprimi o numero do disco
		for (tam_disco = disco_da_vez+1;tam_disco <= (disco_da_vez*2)+1;tam_disco++){
			mvprintw(P_LINES-disco,pino_n+espaco+tam_disco+1," "); // imprimi o segundo lado do disco
		}
	}
	for (haste = (N_Itens(pilha)); haste <= 7; haste++){
		attrset(COLOR_PAIR(8));
		mvprintw(P_LINES - haste,pino_n+10," ");// imprimi haste
	}
	mvprintw(0,0," ");
} 

void Imprimir_H (Hanoi *hanoi,int ndiscos,int moves){
	int pino;
	clear();
	attrset(COLOR_PAIR(0));	
	mvaddstr(6,COLS/2-14, "T O W E R S   O F   H A N O I");		//impressao do titulo
	mvprintw(P_LINES+9,COLS/2-strlen("Movimentos: "),"Movimentos: %d",moves);	//impressao do numero de movimentos
	for (pino = 1; pino <=3;pino++){
	attrset(COLOR_PAIR(8));
	ImprimirDiscos(hanoi->pinos[pino-1],pino);	//impressao dos pinos
	}
}

int Movimentos(Hanoi *hanoi,int origem,int destino){
	attrset(COLOR_PAIR(0));	
	if(VazioPino(hanoi->pinos[origem-1])){		// confere se o pino de origem nao tem disco para deslocar
		mvprintw(P_LINES+6,COLS/2-strlen("Sem discos para deslocar "),"Sem discos para deslocar ");
		return 0;	
	}else if((!VazioPino(hanoi->pinos[destino-1]))&&(*(int*)Top(hanoi->pinos[origem-1])) >(*(int*)Top(hanoi->pinos[destino-1]))){ // confere se disco do pino de origem eh maior que o disco do pino de destino
		mvprintw(P_LINES+6,COLS/2-15,"Disco de origem maior  que o de destino ");
		return 0;
	}else
		return 1;
}

int main (){
	int ndiscos,origem,destino,moves;
	Hanoi *hanoi;
	initscr();
	cbreak();
	Colors();
	moves=0;
	mvprintw(LINES/2,COLS/2-strlen("insira o numero de discos entre 1-7: "),"insira o numero de discos entre 1-7: ");
	scanw ("%d",&ndiscos);
	hanoi = InicHanoi(ndiscos);
	Imprimir_H(hanoi,ndiscos,moves);

	while(!FimHanoi(hanoi)){
		attrset(COLOR_PAIR(0));
		mvprintw(P_LINES+3,COLS/2-strlen("Escolha os pinos que deseja deslocar: "),"Escolha os pinos que deseja deslocar: ");
		mvprintw(P_LINES+4,COLS/2-strlen("Pino de origem: "),"Pino de origem: ");

		origem=(getch()-'0');
		while((origem<1)||(origem>3)){	//confere se o numero do pino de origem escolhido esta entre 1 e 3
			mvprintw(P_LINES+4,COLS/2,"Opcao invalida");
		    	origem=(getch()-'0');
			mvprintw(P_LINES+4,COLS/2,"                   ");

		}
			mvprintw(P_LINES+4,COLS/2,"%d             ",origem);		

		mvprintw(P_LINES+5,COLS/2-strlen("Pino de destino: "),"Pino de destino: ");
		destino=(getch()-'0');
		while((destino<1)||(destino>3)){ //confere se o numero do pino de destino escolhido esta entre 1 e 3
			mvprintw(P_LINES+5,COLS/2,"Opcao invalida");
			destino=(getch()-'0');
			mvprintw(P_LINES+5,COLS/2,"                 ");			
		}
		mvprintw(P_LINES+5,COLS/2,"%d             ",destino);

		if (Movimentos(hanoi,origem,destino)){	//sem erros, movimenta o jogo
			MovimentaHanoi(hanoi,origem-1,destino-1);
			moves++;
			Imprimir_H(hanoi,ndiscos,moves);
		}
	}

	Imprimir_H(hanoi,ndiscos,moves);
	attrset(COLOR_PAIR(0));
	mvprintw(P_LINES+8,COLS/2-24,"PARABENS!! VOCE GANHOU COM APENAS %d MOVIMENTOS!!",moves);
	
	mvprintw(P_LINES+12,COLS/2-14,"aperte 0 para sair");
	getch();

	endwin();
	return 0;
}
