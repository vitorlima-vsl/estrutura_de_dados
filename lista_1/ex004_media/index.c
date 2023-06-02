#include <stdio.h>
int main ()
{   
    float nota01 = 0.0, nota02 = 0.0, nota03 = 0.0, nota04 = 0.0;
    float media = 0.0;

    scanf("%f %f %f %f", &nota01, &nota02, &nota03, &nota04); //le as entradas
    
    nota01 = nota01 * 1;
    nota02 = nota02 * 2;
    nota03 = nota03 * 3;
    nota04 = nota04 * 4;
       
    media = (nota01 + nota02 + nota03 + nota04)/10; // calcula a media
    if(media >= 9){//checa em qual condicional o aluno se encaixa
        printf("aprovado com louvor");
    }
    else if(media >= 7){
        printf("aprovado");
    }
    else if(media < 3){
        printf("reprovado");
    }
    else if(3 <= media < 7 ){
        printf("prova final");
    }
  return 0;
}
 