#include <stdio.h>
#define N 4

void iniciarMatriz(float matriz[N][N])
{
    int cont = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matriz[i][j] = cont;
            cont++;
        }
    }
}
void printarMatriz(float matriz[N][N])
{
    for (int i = 0; i < N; i++)
    {
        printf("|");
        for (int j = 0; j < N; j++)
        {
            printf("%.0f ", matriz[i][j]);
        }
        printf("| \n");
    }
    printf("\n");
}

void dividirMatriz(float matrizA[N][N], float matrizB[N][N])
{
    float maior[N];
    for (int i = 0; i < N; i++)
    {
        maior[i] = matrizA[i][0];
        for (int j = 1; j < N; j++)
        {
            if (matrizA[i][j] > maior[i])
            {
                maior[i] = matrizA[i][j];
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matrizB[i][j] = matrizA[i][j] / maior[i];
        }
    }
}

int main()
{
    float matrizA[N][N];
    float matrizResultado[N][N];
    iniciarMatriz(matrizA);
    printarMatriz(matrizA);

    dividirMatriz(matrizA, matrizResultado);

    printf("MATRIZ RESULTADO: \n\n");
    for (int i = 0; i < N; i++)
    {
        printf("|");
        for (int j = 0; j < N; j++)
        {
            printf("%.2f ", matrizResultado[i][j]);
        }
        printf("| \n");
    }
    printf("\n");
    return 0;
}