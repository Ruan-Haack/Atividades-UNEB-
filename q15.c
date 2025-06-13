#include <stdio.h>

int main () {

    int n = 0;

    printf("Digite a quantidade de elementos: ");
    scanf("%d", &n);

    int numeros[n];

    for (int i = 0; i < n; i++) {

        printf("Digite um numero: \n");
        scanf("%d", &numeros[i]);

        } 

        for (int J = 0; J < n; J++)
        {
             printf("Vetor NORMAL: %d \n", numeros[J]);
        }
        printf("\n\n********************************************\n\n");
    for (int i = 0; i < (n/2); i++)
    {
        
        int aux = numeros[i];

        numeros[i] = numeros[n-1-i];
        numeros[n-1-i] = aux;

    }

    for (int i = 0; i < n; i++)
    {
        printf("Vetor inverso: %d \n", numeros[i]);
    }
            

    return 0;
}