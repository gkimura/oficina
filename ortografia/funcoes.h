
#ifndef _funcoes_h
#define _funcoes_h

int Contagem_Palavras(FILE *stream);
char **Aloca_Vet(int cont);
void Copia_String(FILE *stream,char **vet,int cont);
int Compara(char **vet,char palavra[],int cont);
int Eh_Numero(char c);
void Minuscula (char *palavra);
void Corretor_Ortografico(FILE *in,FILE *out,char **vet,int cont);
void Free_Vet(char **vet,int numb);

#endif
