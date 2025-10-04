#include <stdio.h>
#define A 5

void preenchermatrizAssimetrica(int matriz[A][A])
{
    int valor = 0;
    for (int i = 0; i < A; i++)
    {
        for (int j = 0; j < A; j++)
        {
            matriz[i][j] = valor++;
        }
    }
}

void preenchermatrizSimetrica(int matriz[A][A]){
    int cont=0;
    for (int i = 0; i < A; i++)
    {
        for (int j = 0; j < A; j++)
        {
            matriz[i][j] = cont;
            matriz[j][i] = cont;
            cont++; 
        }
    }
}

int main()
{
    int matrizA[A][A]; 
    int cont = 0;
    preenchermatrizAssimetrica(matrizA); //ASSIMETRICA
    // preenchermatrizSimetrica(matrizA); //SIMÉTRICA

    for (int i = 0; i < A; i++)
    {
        for (int j = 0; j < A; j++)
        {
            if (matrizA[i][j] == matrizA[j][i])
            {
                cont++;
            }
        }
    }

    if (cont == (A*A))
    {
        printf("MATRIZ SIMÉTRICA\n");
    } else {
        printf("MATRIZ ASIMÉTRICA\n");
    }
    

    return 0;
}