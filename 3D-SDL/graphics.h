

#ifndef _graphics_h
#define _graphics_h
#include "datatypes.h"

void Projecao_Vertices(int window_w,int window_h,Vertice *ap_v,float *proj_x,float *proj_y,float *cam,float *min_x,float *min_y,float *max_x,float *max_y,int n_vertice);
void Transforma_Desenho(int window_w,int window_h,Vertice *ap_v,float *proj_x,float *proj_y,float minx,float miny,float maxx,float maxy,int n_vertice);
void Desenha_Objeto(SDL_Renderer *gRenderer,Face *ap_f,float *proj_x,float *proj_y,int n_face);

#endif
