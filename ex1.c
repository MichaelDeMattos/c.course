#include <stdio.h>

/*

1.Fazer  um  programa  em  C  que  pergunta  um  valor  em  metros  e  imprime  ocorrespondente em decímetros, centímetros e milímetros

*/

int main(){
    float metros, milimetros, decimetros, centimetros; 
    
    printf("Informe um número: ");
    scanf("%f", &metros);

    decimetros = (metros * 10);
    centimetros = (metros * 100);
    milimetros = (metros * 1000);

    printf("Decímetros:  %.2f\n"
           "Centímetros: %.2f\n"
           "Milímetros:  %.2f\n", decimetros, centimetros, milimetros);

    return 0;
}
