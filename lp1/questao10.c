#include <stdio.h>
#define A 5

void preenchermatriz(int matriz[A][A])
{
    int valor = 1;
    for (int i = 0; i < A; i++)
    {
        for (int j = 0; j < A; j++)
        {
            matriz[i][j] = valor;
            valor++;
        }
    }
}

int maiorLinha(int matriz[A][A])
{
    int maiorlinha = 0;
    int soma[A] = {0};
    for (int i = 0; i < A; i++)
    {
        for (int j = 0; j < A; j++)
        {
            soma[i] += matriz[i][j];
        }
    }
    for (int i = 0; i < A; i++)
    {
        if (soma[i] > soma[maiorlinha])
            maiorlinha = i;
    }
    return maiorlinha;
}
int main()
{

    int matriz[A][A];
    preenchermatriz(matriz);
    int maiorlinha = maiorLinha(matriz);
    for (int i = 0; i < A; i++)
    {
        printf("|");
        for (int j = 0; j < A; j++)
        {
            printf(" %2d ", matriz[i][j]);
        }
        printf("|\n");
    }

    printf("A maior linha é %d\n", maiorlinha+1);
}