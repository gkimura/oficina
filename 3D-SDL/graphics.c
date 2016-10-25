

#include "datatypes.h"

void Projecao_Vertices(int window_w,int window_h,Vertice *ap_v,float *proj_x,float *proj_y,float *cam,float *min_x,float *min_y,float *max_x,float *max_y,int n_vertice){
	int i;
	Vertice *aux;
	aux = ap_v;

	proj_x[1] = cam[0] + (cam[2]*((aux->x - cam[0])/(aux->z + cam[2])));
	proj_y[1] = cam[1] + (cam[2]*((aux->y - cam[1])/(aux->z + cam[2])));
	aux= aux ->prox;

	*min_x=proj_x[1];
	*max_x=(-1)*proj_x[1];
	*min_y=proj_y[1];
	*max_y=(-1)*proj_y[1]; 

	for(i=2;i<=n_vertice;i++){
		//xp      =  xc      +     zc     * ((  xv    -    xc   ) / (   zv   +    zc   ))
		proj_x[i] = cam[0] + (cam[2]*((aux->x - cam[0])/(aux->z + cam[2])));
		proj_y[i] = cam[1] + (cam[2]*((aux->y - cam[1])/(aux->z + cam[2])));
		if(proj_x[i]<*min_x){ 
			*min_x = proj_x[i];
		}
		if(proj_x[i]>*max_x){
			*max_x = proj_x[i];
		}
		if(proj_y[i]<*min_y){
			*min_y = proj_y[i];
		}
		if(proj_y[i]>*max_y){
			*max_y = proj_y[i];
		}
	aux = aux->prox;
	}
}

void Transforma_Desenho(int window_w,int window_h,Vertice *ap_v,float *proj_x,float *proj_y,float minx,float miny,float maxx,float maxy,int n_vertice){

	float escala,cen_x,cen_y,esc_x,esc_y,dif_x,dif_y;
	int i;
	cen_x = ((maxx + minx)/2); cen_y = ((maxy + miny)/2);
	dif_x = (maxx-minx); dif_y = (maxy-miny);
	esc_x = (window_w/dif_x); esc_y = (window_h/dif_y);
	escala = esc_x;
	if(esc_y < esc_x)
		escala = esc_y;
	escala = (-1)*escala;
	for(i=1;i<=n_vertice;i++){
			     //0.80 - menor tamanho da impressao	
		proj_x[i] = ((0.70*(proj_x[i]-cen_x)*escala)+(window_w/2));
		proj_y[i] = ((0.70*(proj_y[i]-cen_y)*escala)+(window_h/2));
	}

}

void Desenha_Objeto(SDL_Renderer *gRenderer,Face *ap_f,float *proj_x,float *proj_y,int n_face){
	int i,j;
	Face *aux;

	aux = ap_f;
	SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0x7F );//branco-desenho das linhas
	for(i=0;i<n_face;i++){
		for(j=0;j< aux->nv-1;j++){
			SDL_RenderDrawLine(gRenderer, proj_x[aux->vet[j]], proj_y[aux->vet[j]], proj_x[aux->vet[j+1]], proj_y[aux->vet[j+1]]);
		}
		SDL_RenderDrawLine(gRenderer, proj_x[aux->vet[0]], proj_y[aux->vet[0]], proj_x[aux->vet[j]], proj_y[aux->vet[j]]);
		// ultima dupla de vertices - primeiro e ultimo
		aux = aux->prox;
	}
}


