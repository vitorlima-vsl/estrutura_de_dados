#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
  

int main() 
{   
    int pos = 0; // posicao
    int menor = 0; // menor valor do array
    int i; // tamanho do array
    scanf("%d", &i); // recebe o tamanho
    int vet[i]; // cria o array com o tamanho
    for (int j = 0; j < i; j++) // recebe os valores
    {
        scanf("%d", &vet[j]);
    }
    menor = vet[0];
    for(int cont = 1; cont < i; cont++) //compara os valores (transformar em funcao depois)
    {
        if(menor > vet[cont])
        {
            menor = vet[cont]; //menor valor
            pos = cont; /*posicao do menor valor, note que inicia como zero para poder termos uma posicão inicial
            caso nao chegue a este ponto */
        }  

    }
    printf("Menor valor: %d", menor);
    printf("\nPosicao: %d", pos);

	return 0;
}
  
  
  

