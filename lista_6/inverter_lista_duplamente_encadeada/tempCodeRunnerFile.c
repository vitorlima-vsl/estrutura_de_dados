   NO *pAnterior = l->cabeca;
    NO *pTemp = NULL;
    l->cauda = l->cabeca; // troca o lugar da cauda pela cabeça
    while (pAnterior != NULL) { // inverte os apontadores prox e ant
        pTemp = pAnterior->ant;
        pAnterior->ant = pAnterior->prox;
        pAnterior->prox = pTemp;

        pAnterior = pAnterior->ant;
    }
    if(pTemp){
        l->cabeca = pTemp->ant; //faz a cabeça apontar para o ultimo no modificado
    }
    return true;