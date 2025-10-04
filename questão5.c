#include <stdio.h>
#define N 3
#define M 4

void printarMatriz(int matriz[N][M])
{
    for (int i = 0; i < N; i++)
    {
        printf("|");
        for (int j = 0; j < M; j++)
        {
            printf("%3d", matriz[i][j]);
        }
        printf("| \n");
    }
    printf("\n\n");
}

int main()
{
    int matrizA[N][M];
    int matrizB[N][M];
    int matrizC[N][M];
    int i = 0;
    // PREENCHENDO MATRIZ A e B
    int valor = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            matrizA[i][j] = valor++; // Atribui o valor e incrementa ex 10 -> 11 -> 13
            matrizB[i][j] = valor++; // Atribui o valor e incrementa ex 11 -> 12 -> 14
        }
    }
    // preencher matriz C
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            matrizC[i][j] = matrizA[i][j] + matrizB[i][j];
        }
    }
    printf("Printando matriz A: \n");
    printarMatriz(matrizA);
    printf("Printando matriz B: \n");
    printarMatriz(matrizB);
    printf("Printando matriz C: \n");
    printarMatriz(matrizC);

    return 0;
}