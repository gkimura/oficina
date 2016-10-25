
#include"datatypes.h"
#include"objread.h"
#include"graphics.h"

int main(int argc,char *argv[]){
	float camera[3],min_x,min_y,max_x,max_y,*proj_x,*proj_y;
	int n_vertice,n_face,window_h,window_w,video;

	Vertice *ap_v;
	Face *ap_f;
	ap_v = (Vertice *)malloc(sizeof(Vertice));   //lista de Vertices
	ap_f = (Face*)malloc(sizeof(Face));        //lista de Faces
	window_w = 712; window_h = 712; //largura e altura da tela

	SDL_Window *Window ; //cria tela
	SDL_Renderer *renderer ; //informacoes da tela
	SDL_Init( SDL_INIT_VIDEO );

	Window = SDL_CreateWindow("Visualizador 3D",0,0,window_w,window_h,0); //cria janela de video com titulo
	renderer = SDL_CreateRenderer( Window, -1, SDL_RENDERER_ACCELERATED );
	SDL_Event event; // movimento teclado

	camera[0]=0; 
	camera[1]=0;  
	camera[2]=(-1)*1000; 

	Leitura_Arquivo(argc,argv,ap_v,ap_f,&n_vertice,&n_face);
	proj_x = (float*) malloc ((n_vertice)*sizeof(float));
	proj_y = (float*) malloc ((n_vertice)*sizeof(float));
	video=1;
	while(video==1){
		SDL_SetRenderDrawColor( renderer, 0, 0, 0, 0 ); //fundo preto
		SDL_RenderClear( renderer );	//limpa tela 
		Projecao_Vertices(window_w,window_h,ap_v,proj_x,proj_y,camera,&min_x,&min_y,&max_x,&max_y,n_vertice);
		Transforma_Desenho(window_w,window_h,ap_v,proj_x,proj_y,min_x,min_y, max_x,max_y,n_vertice);
		Desenha_Objeto(renderer, ap_f, proj_x, proj_y, n_face);
		SDL_RenderPresent( renderer ); // atualiza desenho	

        	if (SDL_PollEvent(&event)) {
			switch(event.type){
					case SDL_QUIT: video = 0;break;
					case SDL_KEYDOWN : switch(event.key.keysym.sym){
									case SDLK_LEFT: camera[0] = camera[0] - 50 ; 
											break;
									case SDLK_RIGHT:camera[0] = camera[0] + 50;
											break;
									case SDLK_UP:   camera[1] = camera[1] + 50; 
											break;
									case SDLK_DOWN: camera[1] = camera[1] - 50;
											break; 							
							 }
			}
		}
	}
	SDL_DestroyRenderer( renderer );
	Free_Listas(ap_v,ap_f);   //desaloca listas
	free(proj_x);
	free(proj_y);
	return (0);
}

