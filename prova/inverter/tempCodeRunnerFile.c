 NO *pAnterior = l->cabeca;
    NO *pAtual = l->cabeca->prox;
    while (pAtual->prox != l->cabeca) { // percorre a lista até voltar ao início
        NO *pProximo = pAtual->prox;
        pAtual->prox = pAnterior;
        pAnterior = pAtual;
        pAtual = pProximo;
    }
    pAtual->prox = pAnterior; // ajusta o ultimo elemento para apontar para o penultimo elemento
    l->cabeca->prox = pAtual; // ajusta a cabeça da lista para o ultimo elemento