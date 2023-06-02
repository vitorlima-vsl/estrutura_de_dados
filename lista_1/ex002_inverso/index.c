#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char c;
    int i, n, d;
    int vet[n];
    scanf ("%d", &n);
    for(i = 0; i < n; i++){ // cria o vetor
        scanf("%d%c", &vet[i], &c);
    }
    d = n;
    for(i = 0; i < n; i++) { 
        d--;
        printf("%d ", vet[d]); // inverte e imprime o vetor
    }
    
    return 0;
}