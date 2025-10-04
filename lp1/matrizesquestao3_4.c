#include <stdio.h>
#define M 4

void printarMatriz(int matriz[M][M])
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
void diagonaisMatriz(int matriz[M][M], int vetor_P[M], int vetor_S[M])
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (i == j)
            {
                vetor_P[j] = matriz[i][j];
            }
            if ((i + j) == (M - 1)) // diagonal secundária é igual a  Linha + Coluna = M(ordem da matriz)
            {
                vetor_S[j] = matriz[i][j];
            }
        }
    }
}

int main()
{
    int matriz[M][M];
    int vetor_P[M];
    int vetor_S[M];
    int somaDiagonal = 0;
    int somaDiagonalsecundaria = 0;

    preencherMatriz(matriz);
    diagonaisMatriz(matriz, vetor_P, vetor_S);
    printarMatriz(matriz);

    printf("\nElementos da diagonal principal:");
    for (int i = 0; i < M; i++)
    {
        printf(" %2d", vetor_P[i]);
        somaDiagonal += vetor_P[i];
    }
    printf("\nElementos da diagonal secundária:");
    for (int i = 0; i < M; i++)
    {
        printf(" %2d,", vetor_S[i]);
        somaDiagonalsecundaria += vetor_S[i];
    }
    printf("\n");
    printf("Soma da diagonal principal: %d \n", somaDiagonal);
    printf("Soma da diagonal secundaria: %d \n", somaDiagonalsecundaria);

    return 0;
}
