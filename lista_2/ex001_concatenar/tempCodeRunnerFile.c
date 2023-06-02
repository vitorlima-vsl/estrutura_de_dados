if(l1->tamanho == MAX){
    return false;
  }
  else{
    int j = 0;
    while(l1->tamanho != MAX){
      if(j < l2->tamanho){
      l1->itens[l1->tamanho] = l2->itens[j];
      l1->tamanho++;
      j++; 
    }
      else{
        break;
      }
    }
  }
