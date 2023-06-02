#include <stdio.h>

int main()
{
    // E == adicao S == subtracao
    char excedeu = 'N';
    int total_passageiros = 0;
    int N, C, S, E; 
    scanf("%i %i",&N,&C);
   //leitura de dois inteiros
    for (N; N--;){ //Utiliza da variavel N para fazer o numero de leituras
        scanf("%i %i",&S,&E); // Le a saida e a entrada de passageiros de forma respectiva
        total_passageiros += E - S;
        if (total_passageiros > C){ //utiliza a variavel C como o maximo estipulado pelo elevador
            excedeu = 'S';
        }
    }
    printf("%c", excedeu); // mostra se o elevador excedeu ou nao (bem intuitivo)
    return 0;
}

