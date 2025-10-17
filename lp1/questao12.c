#include <stdio.h>
#define D 10

void iniciarMatriz(int matriz[D][D])
{
    int cont = 1;
    for (int i = 0; i < D; i++)
    {
        for (int j = 0; j < D; j++)
        {
            matriz[i][j] = cont;
            cont++;
        }
    }
}

float mediadiagonal(int matriz[D][D])
{
    float media = 0;
    for (int i = 0; i < D; i++)
    {
        for (int j = 0; j < D; j++)
        {
            if (i == j) // diagonal
            {
                media += matriz[i][j];
            }
        }
    }
    return media /= D;
}
void printarMatriz(int matriz[D][D])
{
    for (int i = 0; i < D; i++)
    {
        printf("|");
        for (int j = 0; j < D; j++)
        {
            printf("%3d ", matriz[i][j]);
        }
        printf("| \n");
    }
    printf("\n");
}
int main()
{
    int matriz[D][D];
    iniciarMatriz(matriz);
    printarMatriz(matriz);
    float media = mediadiagonal(matriz);

    printf("A média das somas da diagonal principal eh: %.2f\n", media);
    return 0;
}