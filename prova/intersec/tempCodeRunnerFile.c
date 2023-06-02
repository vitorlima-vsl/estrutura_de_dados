void intersecao(LISTA *A, LISTA *B, LISTA *I)
{
  NO* pA = A->cabeca;

  for(int i = 0; i<A->tamanho; i++){
    NO* pB = B->cabeca;
    for(int k = 0; k < B->tamanho; k++){
      if(pA->item.chave == pB->item.chave){
        inserirNaOrdem(pA->item, I);
      }
    pB = pB->prox;
    }
    pA = pA->prox;

  }
}