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