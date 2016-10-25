
#include "game.h"
#include "function.h"
#include "drawerase.h"
#include "structs4.h"
#include "var.h"

void Inic_Jogo(Space_Invaders *SI,Player *player, Aliens *inimigo,Tiro *tiro_inimigo,Tiro *tiro_player,Shelter *shelter){	
	int i;

	curs_set(0);
	clear();
	keypad(stdscr,TRUE);
	Colors();
	noecho();
	cbreak();
	nodelay(stdscr,TRUE);
   	srand(time(NULL));

	SI->time = 0;
	SI->life = 3;        //inicializa informacoes do jogo
	SI->score = 0;

	player->desenho = &Player_d;
	player->lin = LINES-4;             //inicializa informacoes do player
	player->col = (COLS/2)-4;
	player->cor = 7;



	//iniciliza informacoes dos 60 inimigos 
	srand (rand());
	for(i=0;i<10;i++){ 
		inimigo[i].desenho = &Alien1;
		inimigo[i].lin = 6;
		inimigo[i].col = i*7;
		inimigo[i].estado = VIVO;
		inimigo[i].pontos = 25;
		inimigo[i].t_entrada = 0;
		inimigo[i].direcao = DIREITA; 
		inimigo[i].t_tiro[0] = rand()%6;inimigo[i].t_tiro[1] =10;inimigo[i].t_tiro[2] =0;
		inimigo[i].dano=2;
		inimigo[i].cor = 2;
	}
	for(i=10;i<20;i++){
		inimigo[i].desenho = &Alien2;
		inimigo[i].lin = 10;
		inimigo[i].col = (i-10)*7;
		inimigo[i].estado = VIVO;
		inimigo[i].pontos = 30;
		inimigo[i].t_entrada =0 ;
		inimigo[i].direcao = DIREITA;
		inimigo[i].t_tiro[0] = rand()%12 ;inimigo[i].t_tiro[1] =10;inimigo[i].t_tiro[2] =0;
		inimigo[i].dano=2;
		inimigo[i].cor =3 ;
	}
	for(i=20;i<30;i++){
		inimigo[i].desenho = &Alien3;
		inimigo[i].lin = 14;
		inimigo[i].col = (i-20)*7 ;
		inimigo[i].estado = VIVO;
		inimigo[i].pontos = 20;
		inimigo[i].t_entrada = 0;
		inimigo[i].direcao = DIREITA;
		inimigo[i].t_tiro[0] = rand()%8;inimigo[i].t_tiro[1] =10;inimigo[i].t_tiro[2] =0;
		inimigo[i].dano=2;
		inimigo[i].cor =7 ;
	}
	for(i=30;i<40;i++){
		inimigo[i].desenho = &Alien4;
		inimigo[i].lin = 18;
		inimigo[i].col = (i-30)*7;
		inimigo[i].estado = VIVO;
		inimigo[i].pontos = 15;
		inimigo[i].t_entrada = 0;
		inimigo[i].direcao = DIREITA;
		inimigo[i].t_tiro[0] = rand()%10;inimigo[i].t_tiro[1] =10;inimigo[i].t_tiro[2] =0;
		inimigo[i].dano=2;
		inimigo[i].cor =4 ;
	}
	for(i=40;i<50;i++){
		inimigo[i].desenho = &Alien5;
		inimigo[i].lin = 22;
		inimigo[i].col = (i-40)*7;
		inimigo[i].estado = VIVO;
		inimigo[i].pontos = 10;
		inimigo[i].t_entrada = 0;
		inimigo[i].direcao = DIREITA;
		inimigo[i].t_tiro[0] = rand()%10;inimigo[i].t_tiro[1] =10;inimigo[i].t_tiro[2] =1;
		inimigo[i].dano=2;
		inimigo[i].cor = 6;
	}

	//Alien especial, aparece mais tarde e so realiza movimento DIREITA - ESQUERDA	
	for(i=50;i<NALIENS;i++){
		inimigo[i].desenho = &Alien_S;
		inimigo[i].lin = 3;
		inimigo[i].col = 0;
		inimigo[i].estado = AGUARDANDO;
		inimigo[i].pontos = 230;
		inimigo[i].direcao = DIREITA;
		inimigo[i].t_tiro[0] = rand()%5;inimigo[i].t_tiro[1] =8;inimigo[i].t_tiro[2] =1;
		inimigo[i].dano=3;
		inimigo[i].cor = 4;
	}

	//inicializa tiro inimigo
	for(i=0;i<NTIROS;i++){
		tiro_inimigo[i].desenho = '*';
		tiro_inimigo[i].estado = OFF;
	}
	//inicializa tiro player
	for(i=0;i<NTIROSPLAYER;i++){
		tiro_player[i].desenho = '|';
		tiro_player[i].estado = OFF;
	}
	//inicializa protecao
	for(i=0;i<NSHELTER;i++){
		shelter[i].desenho = &Shelter_d;
		shelter[i].lin = LINES-10;
		shelter[i].col = ((COLS/5-5)+20*i) ;
		shelter[i].cor = 7;
	}
} 

void Movimento_Player(Space_Invaders *SI,Player *player,Tiro  *tiro_player,int *tiro_player_ativo,Aliens *inimigo,Tiro *tiro_inimigo,Shelter *shelter){
	int action,pause,i,help;
	action = getch();
	//apaga posicao atual
	Erase(player->desenho, player->lin,player->col);

	//atualiza posicao
	switch(action){
			//espaco: tiro 
			//verifica se ja nao possuem numero max de tiros ativos, senao, procura uma posicao de tiro disponivel e atualiza como indisponivel, e sua posicao (uma linha acima do player) 
			case ' ': if(*tiro_player_ativo < NTIROSPLAYER){
					i=0;
					while(tiro_player[i].estado == ON) i++;
						tiro_player[i].estado = ON;
						tiro_player[i].lin = player->lin - 1;
						tiro_player[i]. col = player->col;
						++*tiro_player_ativo;	
        			}
				  break;
			case KEY_LEFT: player->col--;
					break;
			case KEY_RIGHT: player->col++;
					 break;
			
			//P: pausar
			//espera usuario clicar H para ajuda, P para continuar o jogo ou Q para sair
			case('p'): 
	
					mvprintw(LINES/2-1,COLS/2,"PAUSE!");
					mvprintw((LINES/2),(COLS/2)-20,"Click P to continue,H for help or Q to quit");
					
					refresh();
					while (1){
						pause = getch();
						if((pause=='Q')||(pause=='q'))
							Game_Over(SI,inimigo,tiro_inimigo,tiro_player,shelter);
						else if((pause=='H')||(pause=='h')){
							mvprintw(LINES/2-1,COLS/2,"         ");
							mvprintw((LINES/2)-2,COLS/2-5,"HOW TO PLAY:");
							mvprintw((LINES/2),COLS/2-45,"Use the arrow keys from your keyboard to move the player and click the space bar to shoot");

							mvprintw((LINES/2)+3,COLS/2-14,"Click P to continue the game or Q to quit");
					
							refresh();
							help = getch();
							if((help=='Q')||(help=='q')) 
								Game_Over(SI,inimigo,tiro_inimigo,tiro_player,shelter);
							else if((help == 'p')||(help == 'P'))
								break;
							
						}else if ((pause == 'p')||(pause == 'P')){
							break;
						}
 					}
					mvprintw(LINES/2-1,COLS/2,"         ");
					mvprintw(LINES/2-2,(COLS/2)-5,"                   ");
					mvprintw((LINES/2),(COLS/2)-45,"                                                                                        ");   
					mvprintw(LINES/2+3,COLS/2-14,"                                               ");
					break;
					
   


	}

	//verifica se proxima posicao do player nao esta fora do tamanho de tela
	if(player->col > COLS-10)
		player->col=COLS-10;
	else if (player->col < 0)
		player->col=0;

	//desenha player
	Draw(player->desenho,player->lin,player->col,player->cor);
}

void Tiro_Inimigo(int *tiro_ativo,Tiro *tiro_inimigo,Aliens *inimigo,int k){
	int j,lin,col,check,aux;

        //verifica se todos os inimigos da mesma coluna a frente deste inimigos estao mortos
	//e entao, permiti inimigo a atirar
	if((k>=40)&&(k<=49));
	else if (!((k>=50)&&(k<60))){	
		aux =k+10;	
		check = 0;
		while(aux<50){
			if( inimigo[aux].estado == VIVO)
				check =1;
			aux = aux+10;
		}
		if (check == 0){
			inimigo[k].t_tiro[2]=1;
		}
	}

	//controle de tempo de tiro
	if(inimigo[k].t_tiro[0]>0)
		inimigo[k].t_tiro[0]--;
	else if ((inimigo[k].t_tiro[0]==0)&&(inimigo[k].t_tiro[2]==1)){
		srand (rand());	
				j=0;
				if(*tiro_ativo<NTIROS){
				while(tiro_inimigo[j].estado == ON){
					j++; //acha o primeiro nao ativo
				}
				++*tiro_ativo;
				lin = inimigo[k].lin+2; col = inimigo[k].col+1;
				tiro_inimigo[j].estado = ON;
				tiro_inimigo[j].lin =lin ;
				tiro_inimigo[j].col = col;
				}
		inimigo[k].t_tiro[0]=inimigo[k].t_tiro[1];
		inimigo[k].t_tiro[0]= rand()%inimigo[k].t_tiro[1];
	}
}

void Movimento_Aliens(Space_Invaders *SI,Player *player,Aliens *inimigo,Tiro *tiro_inimigo,int *tiro_ativo,int *inimigo_ativo,int *time_alien,Shelter *shelter,Tiro *tiro_player,FILE *score,int *cont_especial,int *especial_ativo){
	int i;
	int line_i,col_i,j,c,l,k,lin_real,col_real;


	if((SI->time) % *time_alien == 0){ 
		//Inimigos especiais 
		//contador que controla quando ativar cada inimigo especial
		if(*especial_ativo >0){
			if(*cont_especial>0) --*cont_especial;	
			else if(*cont_especial == 0){
					i =50;
					while((i<NALIENS)&&(inimigo[i].estado != AGUARDANDO)){
					i++; //acha o primeiro inimigo especial AGUARDANDO
					}
					if(i<NALIENS){
					*cont_especial = 20;
					inimigo[i].estado = VIVO;
					}
			}	
		}

		for(i=0;i<NALIENS;i++){
			
			// inimigo QUASEMORTO , imprime com o desenho explodindo, e atualiza para MORTO
			if(inimigo[i].estado == QSE_MORTO){
				if(inimigo[i].dano==1){
					inimigo[i].estado = MORTO;
					Erase(inimigo[i].desenho,inimigo[i].lin,inimigo[i].col);
					if((i>=50)&&(i<NALIENS)) --*especial_ativo;	
					--*inimigo_ativo;	
				}else{
					Erase(inimigo[i].desenho,inimigo[i].lin,inimigo[i].col);
					Draw(inimigo[i].desenho,inimigo[i].lin,inimigo[i].col,inimigo[i].cor);

					inimigo[i].dano--;
					SI->score += inimigo[i].pontos;
					fprintf(score,"%d ",SI->score);
				}

			}

			//se vivo, atualiza posicao, verifica se deve atirar e imprime
			if(inimigo[i].estado == VIVO){
				//apaga posicao anterior
				Erase(inimigo[i].desenho,inimigo[i].lin,inimigo[i].col);    
	  	          	
				//atualiza posicao
				if(inimigo[i].direcao == DIREITA)     
					inimigo[i].col++;
				else
					inimigo[i].col--;

				//Em caso de inimigo especial, se ultrapassar a tela, aguarda um tempo antes de aparecer novamente
				//e seu movimento eh atualizado para ESQUERDA ou DIREITA,somente.
				if(inimigo[i].desenho==&Alien_S){
					if(inimigo[i].col==COLS){
						Erase(inimigo[i].desenho,inimigo[i].lin,inimigo[i].col);
						inimigo[i].estado = AGUARDANDO;
						inimigo[i].direcao = ESQUERDA;
						inimigo[i].col = COLS;
				
					}else if(inimigo[i].col+6 == 0){
						Erase(inimigo[i].desenho,inimigo[i].lin,inimigo[i].col);
						inimigo[i].estado = AGUARDANDO;
						inimigo[i].direcao = DIREITA;
						inimigo[i].col = -6;


					}
				}else if(inimigo[i].col==COLS-4){    //os demais inimigos ao ultrapassar a tela, 
						inimigo[i].lin= inimigo[i].lin+2;    //mudam de direcao e descem uma linha
						inimigo[i].direcao = ESQUERDA;
				}else if (inimigo[i].col == 0){           
						inimigo[i].lin= inimigo[i].lin+2;
						inimigo[i].direcao = DIREITA;
				}


				///////////////////// COLISAO INIMIGO - SHELTER ( GAME OVER )//////////////////////////////
				if(inimigo[i].desenho!= &Alien_S){
					for(j=0;j<inimigo[i].col;j++){
						line_i = inimigo[i].lin+2;   //linha inimigo
						col_i = inimigo[i].col+j;   //coluna inimigo
							for(k=0;k<NSHELTER;k++){						
								for(l=0;l<shelter[k].desenho->lin;l++){
									lin_real = shelter[k].lin+l;
									for (c = 0; c < shelter[k].desenho->col;c++){
									col_real = shelter[k].col+c;
										if((line_i == lin_real) && (col_i == col_real)){
						 					if (shelter[k].desenho->matriz[c+(shelter[k].desenho->col*l)] != ' '){
												Game_Over(SI,inimigo,tiro_inimigo,tiro_player,shelter);
											}
										}
									}
								}
							}
					}
				}
				//verifica se inimigo deve atirar
				Tiro_Inimigo(tiro_ativo,tiro_inimigo,inimigo,i);    

				//desenha inimigo
				Draw(inimigo[i].desenho,inimigo[i].lin,inimigo[i].col,inimigo[i].cor);

			}
		}
	}
	

}

void Movimento_Tiros(Space_Invaders *SI,Player *player,Aliens *inimigo,Tiro *tiro_inimigo,Tiro  *tiro_player,int *tiro_ativo,int *tiro_player_ativo,int *inimigo_ativo,Shelter *shelter){
	int i,j,c,k,l,colisao,lin_real,col_real;


	if((SI->time) % 1500== 0){ //controle de impressao do tiro de inimigo	
		for(i=0;i<NTIROS;i++){
			colisao = 0;
			if(tiro_inimigo[i].estado == ON){

				///////////////////// COLISAO TIRO INIMIGO - SHELTER ( APAGA )//////////////////////////////
				for(k=0;k<NSHELTER;k++){						
					for(l=0;l<shelter[k].desenho->lin;l++){                         //se posicao do tiro for igual a uma posicao 
						lin_real = shelter[k].lin+l;                            //nao vazia do shelter, shelter eh danificado
						for (c = 0; c < shelter[k].desenho->col;c++){		//apaga essa posicao
						col_real = shelter[k].col+c;
							if((tiro_inimigo[i].lin == lin_real) && (tiro_inimigo[i].col == col_real)){
							 	if (shelter[k].desenho->matriz[c+(shelter[k].desenho->col*l)] != ' '){
									mvprintw(lin_real,col_real," ");
									shelter[k].desenho->matriz[c+(shelter[k].desenho->col*l)] = ' ';
									Draw(shelter[k].desenho,shelter[i].lin,shelter[k].col,shelter[k].cor);
									colisao =1;
									tiro_inimigo[i].estado = OFF;
									--*tiro_ativo;
								}
							}
						}
					}
				}
				///////////////////// COLISAO TIRO INIMIGO - PLAYER /////////////////////////////////////////
				if(colisao==0){				
					for(l=0;l<player->desenho->lin;l++){
						for (c = 0; c < player->desenho->col;c++){              //se posicao do tiro for igual a do player
							lin_real = player->lin+l;			//player perde uma vida
							col_real = player->col+c;
							if((tiro_inimigo[i].lin == lin_real) && (tiro_inimigo[i].col == col_real)){
								if(player->desenho->matriz[c+(player->desenho->col*l)] != ' '){
									colisao = 1;
									tiro_inimigo[i].estado = OFF;
									--*tiro_ativo;
									SI->life--;							
								}
							}
						}
					}
				}
		
				if (colisao == 0){
					//apaga posicao anterior do tiro do inimigo
					mvprintw(tiro_inimigo[i].lin,tiro_inimigo[i].col," ");
	
					//atualiza posicao do tiro
					if(tiro_inimigo[i].lin <= LINES)
						tiro_inimigo[i].lin = tiro_inimigo[i].lin + 1;
					else{
						mvprintw(tiro_inimigo[i].lin,tiro_inimigo[i].col," ");      //ultrapassa tamanho da tela
						tiro_inimigo[i].estado = OFF;	             //eh desativado								
						--*tiro_ativo;
					}		
					//imprime tiro inimigo
					mvprintw(tiro_inimigo[i].lin,tiro_inimigo[i].col,"%c",tiro_inimigo[i].desenho);
				}

			}
		}
	}
	

	//TIRO PLAYER 
	if((SI->time) % 300== 0){      //controle de impressao do tiro do player
		for(i=0;i<NTIROSPLAYER;i++){
			colisao = 0;
			if(tiro_player[i].estado == ON){

				//apaga impressao na posicao anterior
				mvprintw(tiro_player[i].lin,tiro_player[i].col+4," ");


				//atualiza proxima posicao
				if(tiro_player[i].lin>=0)    
					tiro_player[i].lin--;
				else{
					--*tiro_player_ativo;
					tiro_player[i].estado=OFF;
				}

				///////////////////// COLISAO TIRO PLAYER - SHELTER ( CANCELA )//////////////////////////////
				for(k=0;k<NSHELTER;k++){
					for (j = 0; j < shelter[k].desenho->col;j++){    //verifica posicao do tiro eh igual a alguma coluna na ultima
						col_real = shelter[k].col+j-4;		      //linha do shelter		
						if ((tiro_player[i].lin == LINES-7) && (col_real == tiro_player[i].col) ){
								colisao =1;
								tiro_player[i].estado = OFF;
								--*tiro_player_ativo;  //menos um tiro de player ativo
						}
					}
				}
				//////////////////// COLISAO TIRO PLAYER - INIMIGOS ////////////////////////////////////////
				for(k=0;k<NALIENS;k++){
					if(inimigo[k].estado == VIVO){
						lin_real = inimigo[k].lin + inimigo[k].desenho->lin-1;
						for (c = 0; c < inimigo[k].desenho->col;c++){
							col_real = inimigo[k].col + c -4;
							if((tiro_player[i].lin == lin_real) && (tiro_player[i].col == col_real)){
									colisao =1;
									tiro_player[i].estado = OFF;
									--*tiro_player_ativo;    
									inimigo[k].estado = QSE_MORTO;   //inimigo quase morto, antes deve ser feito a impressao
									inimigo[k].desenho = &EXPLODE;   //do inimigo explodindo
							}
						}
					}
				}

				if(colisao == 0)      //se foi verificado que nao ha colisao, imprime o tiro
					mvprintw(tiro_player[i].lin,tiro_player[i].col+4,"%c",tiro_player[i].desenho);
	
			}
		}
	}
}


