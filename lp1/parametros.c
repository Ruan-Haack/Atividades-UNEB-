#include <stdio.h>

void alteraValor(int *valor)
{
    *valor = *valor * 2;
    printf("Valor dentro da função: %d\n", *valor);
}

int main()
{
    int valor = 0;
    printf("Digite o valor para dobrar: ");
    scanf("%d", &valor);
    alteraValor(&valor);
    printf("Valor depois da função: %d\n", valor);
    return 0;
} 