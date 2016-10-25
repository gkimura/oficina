

#ifndef _objread_h
#define _objread_h
#include "datatypes.h"

void Leitura_Faces(Face *ap_f, char *line);
void Leitura_Arquivo(int argc,char *argv[],Vertice *ap_v, Face *ap_f, int *n_vertice, int *n_face);
void Free_Listas(Vertice *ap_v, Face *ap_f);

#endif
