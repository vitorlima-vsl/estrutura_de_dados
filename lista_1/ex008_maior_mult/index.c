#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){

    int M = 0, N = 0;
    scanf("%d %d", &M, &N);
    int multiplo = M;

    for (int i = M*2; i <= N; i += M){ /*ja começa com o primeiro multiplo de M, caso seja maior que N nao entra 
    no laco e por sua vez nao faz a soma
    */

        multiplo += M;

    }
    if (multiplo == M) /* caso nunca entre no laco cai aqui, por sua vez isto quer dizer que 
    nao existem multiplos menores que N */
    {
        printf("sem multiplos menores que %d", N);
    }
    else{ //caso nao caia no laco acima, mostra o maior multiplo que se aproxima de N
        printf("%d", multiplo);
    }


    return 0;
}