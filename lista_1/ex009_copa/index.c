#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char timeA[256];
    char timeB[256];

    int pontosA = 0;
    int saldoA = 0;
    int golsA = 0;
    int pontosB;
    int saldoB;
    int golsB;

    //leitura das entradas
    scanf("%s %d %d %d", &timeA, &pontosA, &saldoA, &golsA);
    scanf("%s %d %d %d", &timeB, &pontosB, &saldoB, &golsB);
    for (int i = 0; i < strlen(timeA); i++){ // transforma os caracteres em minusculos com tolower :))
        timeA[i] = tolower(timeA[i]);
    }
    for (int i = 0; i < strlen(timeB); i++){
        timeB[i] = tolower(timeB[i]);
    }


    if(pontosA > pontosB){//simplesmente compara (como foi feito com varios else if, quando for true, automaticamente acontece um break da estrutura)
        printf("%s",timeA);
    }
    else if(pontosA < pontosB){
        printf("%s",timeB);
    }
    else if(saldoA > saldoB)
    {
        printf("%s", timeA);


    }
    else if(saldoA < saldoB)
    {
        printf("%s", timeB);


    }
    else if(golsA > golsB){
        printf("%s", timeA);

    }

    else if(golsA < golsB){
        printf("%s", timeB);

    }
    else{ // caso nao caia em nenhum das anteriores e empate
        printf("EMPATE");
    }
    
    

    



	return 0;
}