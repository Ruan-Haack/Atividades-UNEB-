#include <stdio.h>
#define M 3

void printarmatriz(int matriz[M][M])
{
    printf("Printando a Matriz: \n\n");
    for (int i = 0; i < M; i++)
    {
        printf("|");
        for (int j = 0; j < M; j++)
        {
            printf("%3d", matriz[i][j]);
        }
        printf("| \n");
    }
}
void preencherMatriz(int matriz[M][M])
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("Digite um número: ");
            scanf("%d", &matriz[i][j]);
        }
    }
}

int main()
{
    int matriz[M][M];
    int vetor_S[M];
    int somaDiagonal = 0;

    preencherMatriz(matriz);
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (i == j)
            {
                somaDiagonal += matriz[i][j];
                vetor_S[j] = matriz[i][j];
            }
        }
    }
    
    printarmatriz(matriz);
    printf("\nElementos da diagonal principal:");
    for (int i = 0; i < M; i++)
    {
        printf(" %2d", vetor_S[i]);
    }
    printf("\n");
    printf("Soma da vertical: %d \n", somaDiagonal);
    return 0;
}
