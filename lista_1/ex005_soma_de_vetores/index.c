#include <stdio.h>

int main()
{
    int vet01[10];
    int vet02[10];
    int vet03[10];

    
    for(int i = 0; i < 10; i++){ //adiciona as entradas aos indices do vetor
        scanf("%d", &vet01[i]);
    }
        
    for(int i = 0; i < 10; i++){ //adiciona as entradas aos indices do vetor
        scanf("%d", &vet02[i]);
    }

    for(int i = 0; i < 10; i++){ //soma os vetores
        vet03[i] = vet01[i] + vet02[i];
    }

    for(int i = 0; i < 10; i++) { //imprime o vetor
        printf("%d ", vet03[i]); 
    }
    


    return 0;
}