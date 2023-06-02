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
    struct estrutura *ant;
    struct estrutura *prox;
} NO;

typedef struct
{
    NO* cabeca;
    NO* cauda;
    int tamanho;
} LISTA;



// Inicializa a lista deixando-a pronta para ser utilizada.
void inicializar(LISTA *l)
{
    l->cabeca = NULL;
    l->cauda = NULL;
    l->tamanho = 0;
}


// Cria um novo no com o item, os apontadores para o anterior e para o proximo
NO* criarNo(ITEM item,  NO *ant, NO *prox)
{
    NO* pNovo = (NO*) malloc(sizeof(NO));
    pNovo->item = item;
    pNovo->ant = ant;
    pNovo->prox = prox;
    return pNovo;
}


// Retornar o tamanho da lista
int tamanho(LISTA *l)
{
    return l->tamanho;
}


// Retorna true se a lista esta vazia, ou seja, se tem tamanho = 0
bool vazia(LISTA *l)
{
    return tamanho(l) == 0;
}


// Exibicao da lista
void exibirListaCabecaCauda(LISTA *l)
{
    NO* p = l->cabeca;
    while (p)
    {
        printf("(%d,%s)", p->item.chave, p->item.valor);
        p = p->prox;
    }
}

// Exibicao da lista comecando da cauda
void exibirListaCaudaCabeca(LISTA *l)
{
    NO* p = l->cauda;
    while (p)
    {
        printf("(%d,%s)", p->item.chave, p->item.valor);
        p = p->ant;
    }
}


void imprimirLista(LISTA *l, bool crescente)
{
    printf("Tamanho = %d\n", tamanho(l));
    if (crescente)
        exibirListaCabecaCauda(l);
    else
        exibirListaCaudaCabeca(l);
    printf("\n");
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
    l->cabeca = NULL; // ajusta a cabeca da lista (vazia)
    l->cauda = NULL; // ajusta a cauda da lista (vazia)
}


/////////////////////////////////////////////////////

/*
 Objetivo: Inserir em uma lista ordenada o item passado e garantir
           que nao havera duplicacao.
*/
bool inserirNaOrdem(ITEM item, LISTA *l)
{
    NO* pNovo = criarNo(item, NULL, NULL); /*criei o no antes (poderia criar durante as selecoes,
    porem assim fica mais facil de visualizar) notas para o futuro: refazer esse codigo de modo mais otimizado*/ 
    if (l->cabeca == NULL){// caso base 0 (esqueci desse de primeira, os slides me salvaram aqui :D)
        l->cabeca = pNovo;
        l->cauda = pNovo;
        l->tamanho++;
        return true;
    }

    NO* pAtual = l->cabeca;
    while (pAtual != NULL)
    {
        if (pAtual->item.chave == item.chave) // checa no inicio do laco sempre se o item e duplicado 
        {
            free(pNovo);
            return false;
        }
        else if (pAtual->item.chave > item.chave ) // caso padrao, roda a lista ate achar um item com a chave maior que o nosso item a ser inserido
        {
            pNovo->prox = pAtual; // o campo prox aponta para o item maior
            pNovo->ant = pAtual->ant; // o campo anterior, copia o anterior do item maior
            if(pAtual->ant != NULL) //caso o primeiro maior, nao seja o primeiro NO, faz com que o NO anterior aponte para o novo NO como seu proximo
            {
                pAtual->ant->prox = pNovo;
            }
            else{//caso o primeiro maior, seja o primeiro da lista, toda o novo NO a "cabeca"
                l->cabeca = pNovo;
            }
            pAtual->ant = pNovo; //no final faz o anterior do primeiro maior apontar para o novo NO
            l->tamanho++;
            return true;
        }
        if(pAtual->prox == NULL){ // caso rode a lista e nao ache um item maior que ele
            pNovo->ant = pAtual;
            //note que nao preciso mecher no campo prox, porque ja o iniciei em NULL
            pAtual->prox = pNovo;
            l->cauda = pNovo;//torna o novo NO a cauda
            l->tamanho++;
            return true;
        }

        pAtual = pAtual->prox; // caso nada acima se encaixe, passa para o proximo NO
    }
    
    return false; //caso chegue aqui ocorreu um erro
}
  


//////////////////////////////////////////////////////////////

void lerItens(LISTA *l)
{
    int n;
    scanf("%d", &n);

    // insere os valores n pares chave,valor
    ITEM item;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &item.chave);
        scanf("%s", item.valor);
        inserirNaOrdem(item, l);
    }
}

//////////////////////////////////////////////////////////////

int main(){
  LISTA l;
  ITEM item;

  inicializar(&l);

  lerItens(&l);
  imprimirLista(&l, true);   // crescente
    
  lerItens(&l);
  imprimirLista(&l, false);  // decrescente

  destruir(&l);
  return 0;
}