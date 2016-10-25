
#ifndef _funcarq_h
#define _funcarq_h

int **Aloca_Matriz(int linhas,int colunas);
void Skip_Comments(FILE *in);
void Le_Valores(FILE *in,int *colunas,int *linhas,int *max_cinza);
char Confere_Formato(FILE *in, char c1);
void Leitura_Arquivo(FILE *in,int **mat,char tipo_mat,int linhas,int colunas,int max);
void Escrita_Arquivo(FILE *out,int **mat_final,int linhas,int colunas,int max_cinza,int c1,int c2);
void Free_Matriz(int **mat,int **mat_final,int linhas);

#endif
