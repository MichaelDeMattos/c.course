#include <stdio.h>

/*

2. Fazer um  programa em C que imprime uma tabela com a tabuada de 1 a 9

*/

int main(){
    int tabuada = 0;

    printf("Informe a tabuada que deseja: \n>>> ");
    scanf("%i", &tabuada);

    for(int row = 1; row <=10; ++row){
        printf("%ix%i = %i\n", row, tabuada, row * tabuada);
    }

    return 0;
}
