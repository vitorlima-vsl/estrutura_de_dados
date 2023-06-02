#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>




int main() {

    int i, n;
    int PROG2[45];
    int PROG3[30];

    for(i = 0; i < 45; i++){ //adiciona as entradas aos indices do vetor
        scanf("%d", &PROG2[i]);
    }
    for(i = 0; i < 30; i++){ //adiciona as entradas aos indices do vetor
        scanf("%d", &PROG3[i]);
    }

    //compara os vetores;
    for(i = 0; i < 45; i++) { 
        for(int z = 0; z < 30; z++){
        if(PROG2[i] == PROG3[z]){
            printf("%d ", PROG2[i]);
            break;
        }
    }

    }

    return 0;
}