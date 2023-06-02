#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>


int main() {

    int cont = 0;
    char text[1000];
    scanf("%[^\n]", &text);
    for(int i = 0; i < strlen(text); i++){
        if(toupper(text[i]) == 'A'){
            cont++;
        }
    }
    printf("%d ", cont);
    
	return 0;
}