#include <stdio.h>
#define D 10

// Função para preencher a matriz com valores de 1 a 100.
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

// Função para imprimir uma matriz
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

// Recebe a matriz original e a matriz de resultado.
void operacoesMatriz(int matrizOriginal[D][D], int matrizResultado[D][D])
{
    for (int i = 0; i < D; i++)
    {
        for (int j = 0; j < D; j++)
        {
            matrizResultado[i][j] = matrizOriginal[i][j];
        }
    }
    int temp;
    // 1. Trocar a linha 2 (índice 1) com a linha 8 (índice 7)
    for (int j = 0; j < D; j++)
    {
        temp = matrizResultado[1][j];
        matrizResultado[1][j] = matrizResultado[7][j];
        matrizResultado[7][j] = temp;
    }

    // 2. Trocar a coluna 4 (índice 3) com a coluna 10 (índice 9)
    for (int i = 0; i < D; i++)
    {
        temp = matrizResultado[i][3];
        matrizResultado[i][3] = matrizResultado[i][9];
        matrizResultado[i][9] = temp;
    }

    // 3. Trocar a diagonal principal com a diagonal secundária
    for (int i = 0; i < D; i++)
    {
        temp = matrizResultado[i][i];
        matrizResultado[i][i] = matrizResultado[i][D - 1 - i];
        matrizResultado[i][D - 1 - i] = temp;
    }

    // 4. Trocar a linha 5 (índice 4) com a coluna 10 (índice 9)
    for (int k = 0; k < D; k++)
    {
        temp = matrizResultado[4][k];
        matrizResultado[4][k] = matrizResultado[k][9];
        matrizResultado[k][9] = temp;
    }
}

int main()
{
    int matrizOriginal[D][D];
    int matrizResultado[D][D];

    iniciarMatriz(matrizOriginal);

    printf("--- MATRIZ ORIGINAL ---\n");
    printarMatriz(matrizOriginal);

    // Chama a função que preserva a original e cria a resultante
    operacoesMatriz(matrizOriginal, matrizResultado);

    printf("--- MATRIZ RESULTADO (APOS TODAS AS OPERACOES) ---\n");
    printarMatriz(matrizResultado);

    return 0;
}