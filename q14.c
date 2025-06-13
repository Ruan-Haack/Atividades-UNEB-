#include <stdio.h>


int main () {
    
    int comparar = 0;
    int sinal=1;
    int numeros[10];

    for (int i = 0; i < 10; i++) {

        printf("Digite um numero: ");
        scanf("%d", &numeros[i]);
        } 
    printf("Agora, digite um numero para verificar se existe no vetor: ");
    scanf("%d", &comparar);
    
    for (int i = 0; i < 10; i++) {

        if (comparar == numeros[i]) {
            sinal = 0;
        }

        }

    if (sinal == 0)
    {
        printf("Existe um numero igual no vetor \n");
    
    } else {
        printf ("Nao existe numero igual\n");
}


    return 0;
}


