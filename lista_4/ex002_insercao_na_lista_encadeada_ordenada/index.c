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


// Exibicao da lista sequencial
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
 Objetivo: Inserir em uma lista ordenada o item passado e garantir
           que nao havera duplicacao.
*/
bool inserirNaOrdem(ITEM item, LISTA *l)
{
    //caso base zero fazer depois

    NO* pAnterior = l->cabeca;
    if(pAnterior == NULL){ // caso base, se a lista estiver vazia adiciona no inicio
    l->cabeca = criarNo(item, l->cabeca);
    return true;
    }
    else if(pAnterior->item.chave > item.chave){ /*
    caso o item chave seja menor que o apontado pela cabeca, redefine a cabeca e faz com que o primeiro item se torne o segundo
    */
        pAnterior = criarNo(item, pAnterior); //cria novo no e faz com que o ponteiro que apontava para a cabeca apontar para ele
        pAnterior->prox = l->cabeca; //faz com que o novo no aponte para o primeiro item
        l->cabeca = pAnterior;  // faz com que a cabeca pare de apontar para o antigo primeiro item, e aponte para o novo primeiro item
        return true;
    }
    else if(pAnterior->item.chave == item.chave){ // caso a chave do item seja igual a da cabeca retorna falso
        return false;
    }
   else
   { 
      //percorre a lista 
      while (pAnterior->prox)  //prox != NULL
      {
         NO* pAtual = pAnterior->prox; // pAnterior aponta inicialmente para o primeiro e o pAtual aponta para o proximo ao anterior checado
        
         if (pAtual->item.chave > item.chave)
         { 
            pAnterior->prox = criarNo(item, pAnterior->prox); /*faz com que o anterior aponte para o novo*/
            pAnterior->prox->prox = pAtual; // acessa o ponteiro proximo do novo item adicionado e aponta para o pAtual que e o primeiro da lista maior que ele
            return true;
         }
        else if(pAtual->item.chave == item.chave){// checa sempre antes de reiniciar o loop se aquele NO tem uma chave igual a que queremos adicionar
        return false;
        }
         pAnterior = pAtual;
      }
    }
    pAnterior->prox = criarNo(item, pAnterior->prox); // caso chegue aqui, o novo item eh maior que todos os anteriores a ele :))
    return true; 



    /* notas para o futuro, melhorar os comentarios e esse codigo*/

  
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
