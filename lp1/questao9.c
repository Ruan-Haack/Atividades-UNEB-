#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define A 3

void matrizAleatorio(int matriz[A][A])
{
    for (int i = 0; i < A; i++)
    {
        for (int j = 0; j < A; j++)
        {
            matriz[i][j] = rand() % 2; // Gera 0 ou 1
        }
    }
}

void matrizPerfeita(int matriz[A][A])
{
    for (int i = 0; i < A; i++)
    {
        for (int j = 0; j < A; j++)
        {
            matriz[i][j] = 0;
        }
        
    }
    
    matriz[0][A-1] = 1;
    matriz[1][A-2] = 1;
    matriz[2][A-3] = 1;
    
}

int verificarPermutacao(int matriz[A][A])
{
    // Verificação das LINHAS
    for (int i = 0; i < A; i++)
    {
        int soma_linha = 0; // Zera o contador para a linha atual
        for (int j = 0; j < A; j++)
        {
            if (matriz[i][j] == 1)
            {
                soma_linha++; // Incrementa o contador se encontrar um '1'
            }
        }
        if (soma_linha != 1)
        {
            return 0;
        }
    }

    // Verificação das COLUNAS
    for (int j = 0; j < A; j++)
    {
        int soma_coluna = 0;
        for (int i = 0; i < A; i++)
        {
            if (matriz[i][j] == 1)
            {
                soma_coluna++;
            }
        }

        if (soma_coluna != 1)
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    srand(time(NULL));
    int matrizA[A][A];
    int op = 0;
    printf("Matriz perfeita (1) ou Matriz aleatoria (2)? ");
    scanf("%d", &op);

    switch (op)
    {
    case 1:
        matrizPerfeita(matrizA);
        break;
    case 2:
        matrizAleatorio(matrizA);
        break;
    default:
        printf("[ERRO] Digite um numero valido!");
        break;
    }

    int resultado = verificarPermutacao(matrizA);

    // Imprime a matriz gerada
    printf("A matriz gerada foi: \n");
    for (int i = 0; i < A; i++)
    {
        printf("|");
        for (int j = 0; j < A; j++)
        {
            printf(" %2d ", matrizA[i][j]);
        }
        printf("|\n");
    }

    if (resultado == 1)
    {
        printf("\nÉ UMA MATRIZ DE PERMUTAÇÃO!\n\n");
    }
    else
    {
        printf("\nNão é uma matriz de permutação\n\n");
    }

    return 0;
}
