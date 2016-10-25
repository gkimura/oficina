
typedef struct _pilha{
        void *dados_pilha;
        int tam_pilha;
        int tam_elem;
        int topo_pilha;
}Pilha;

Pilha *InicPilha (int tamelem,int nelem);

void FimPilha(Pilha *pilha);

int Push(Pilha *pilha,void *elem);

void *Pop(Pilha *pilha);

void *Top(Pilha *pilha);

int N_Itens(Pilha *pilha);

void ImprimePilha(Pilha *pilha);

