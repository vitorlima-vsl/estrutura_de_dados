#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef int TIPOCHAVE;

typedef struct
{
    TIPOCHAVE chave;
    char valor[100];
} ITEM;

typedef struct estrutura
{
    ITEM item;
    struct estrutura *prox;
} NO;

typedef struct
{
    NO* cabeca;
} LISTA;



// Inicializa a lista deixando-a pronta para ser utilizada.
void inicializar(LISTA *l)
{
    l->cabeca = NULL;
}


// Cria um novo no com o item passado e tendo NULL como prox
NO* criarNo(ITEM item, NO *prox)
{
    NO* pNovo = (NO*) malloc(sizeof(NO));
    pNovo->item = item;
    pNovo->prox = prox;
    return pNovo;
}


// Retornar o tamanho da lista
int tamanho(LISTA *l)
{
    NO* p = l->cabeca;
    int tam = 0;
    while (p)  // p != NULL
    {
        tam++;
        p = p->prox;
    }
    return tam;
}


// Retorna true se a lista esta vazia (Cabeca = NULL)
bool vazia(LISTA *l)
{
    return l->cabeca == NULL;
}


// Exibicao da lista
void exibirLista(LISTA *l)
{
    NO* p = l->cabeca;
    while (p)  // p != NULL
    {
        printf("(%d,%s)", p->item.chave, p->item.valor);
        p = p->prox;
    }
}


// Liberacao das variaveis dinamicas dos nos da lista, iniciando da cabeca
void destruir(LISTA *l)
{
    NO* atual = l->cabeca;
    while (atual) {
        NO* prox = atual->prox; // guarda proxima posicao
        free(atual);            // libera memoria apontada por atual
        atual = prox;
    }
    l->cabeca = NULL; // ajusta inicio da lista (vazia)
}


void imprimirLista(LISTA *l)
{
    printf("Tamanho = %d\n", tamanho(l));
    exibirLista(l);
    printf("\n");
}


/////////////////////////////////////////////////////

/*
  Objetivo: Inserir o item passado como parametro na posicao pos da lista.
            Caso nao haja item com a mesma chave e a posicao seja valida
            (de 0 a tamanho), o item sera inserido e a funcao retorna true.
            Caso contrario, a funcao retorna false para indicar que o
            item nao foi inserido.
 */
bool inserirNaPos(ITEM item, int posInsercao, LISTA *l)
{   
    
    NO* pAnterior = l->cabeca;
    if(pAnterior == NULL && posInsercao == 0)
    { // caso base, se a lista estiver vazia adiciona no inicio
        l->cabeca = criarNo(item, l->cabeca);
        return true;
    }
    if(pAnterior->item.chave == item.chave)
    { // caso a chave do item seja igual a da cabeca retorna falso
        return false;
    }
    else{ // checa no restante da lista se ha alguma chave igual
            // caso nao haja segue para a insercao na posicao
            while (pAnterior->prox) //prox != null
            {
            NO* pAtual = pAnterior->prox;
            if(pAtual->item.chave == item.chave)
            {
                return false;
            }   
            pAnterior = pAtual;
            }   
    } // ta certo isso

    pAnterior = l->cabeca;
    if(posInsercao > tamanho(l) || posInsercao < 0) // caso a posInsercao seja invalida retorna falso
    {
        return false;
    }

   if ( posInsercao == 0) // inserir na cabeca
   {
        pAnterior = criarNo(item, pAnterior); //cria novo no e faz com que o ponteiro que apontava para a cabeca apontar para ele
        pAnterior->prox = l->cabeca; //faz com que o novo no aponte para o antigo primeiro item
        l->cabeca = pAnterior; // torna o novo item a cabeca
        return true;
   }
   else
   { 
        
    NO* p = l->cabeca;
    int i = 0;
    while (posInsercao > i)   // p != NULL e nao chegou a posicao n
    {
        if (i == posInsercao){
        NO* pAtual = p->prox;
        p = criarNo(item, p); /*faz com que o anterior aponte para o novo*/
        p->prox->prox = pAtual; // acessa o ponteiro prox do novo item adicionado e aponta para o pAtual que eh o primeiro da lista maior que ele
        return true;
    }
        p = p->prox;
        i++;
    }
    p = criarNo(item, p); // caso chegue aqui, o novo item eh maior que todos os anteriores a ele :))
    return true; 
   }

         // existe um n-esimo e p aponta para 
}// func final

//////////////////////////////////////////////////////////////


void lerItens(LISTA *l)
{
    int n;
    int pos;
    scanf("%d", &n);

    // insere os valores n pares chave,valor
    ITEM item;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &item.chave);
        scanf("%s", item.valor);
        scanf("%d", &pos);
        inserirNaPos(item, pos, l);
    }
}


int main(){
  LISTA l;
  ITEM item;

  inicializar(&l);

  lerItens(&l);
  imprimirLista(&l);
    
  lerItens(&l);
  imprimirLista(&l);

  destruir(&l);
  return 0;
}
