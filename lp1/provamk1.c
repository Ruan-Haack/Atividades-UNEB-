#include <stdio.h>
#include <stdlib.h>
#define M 10

typedef struct
{
    char id;
    int fila[M];
    int totalProd;
} Caixa;

void funcao1(int produtos, Caixa *caixa1, Caixa *caixa2, Caixa *caixa3)
{
    int opcaixa = 0;

    while (1)
    {
        printf("Escolha seu caixa: 1| 2| 3| \n");
        scanf("%d", &opcaixa);

        while (opcaixa <= 0 || opcaixa > 3)
        {
            system("clear");
            printf("Opção inválida!!\n\n");
            printf("Escolha seu caixa: 1| 2| 3| \n");
            scanf("%d", &opcaixa);
        }

        if (opcaixa == 3 && produtos > 10)
        {
            system("clear");
            printf("!!! ERRO !!!\n");
            printf("O Caixa 3 é rápido (até 10 produtos).\n");
            printf("Você está com %d produtos. Por favor, escolha o Caixa 1 ou 2.\n\n", produtos);

            // 'continue' reinicia o loop while(1), forçando uma nova escolha
            continue;
        }

        printf("Caixa escolhido: %d\n", opcaixa);

        if (opcaixa == 1)
        {
            if (caixa1->fila[M - 1] != 0) // Verifica se está cheio
            {
                printf("Caixa 1 está cheio. Escolha outro.\n\n");
            }
            else
            {
                for (int i = 0; i < M; i++) // Acha o primeiro 0
                {
                    if (caixa1->fila[i] == 0)
                    {
                        caixa1->fila[i] = produtos;
                        caixa1->totalProd += produtos;
                        break;
                    }
                }
                break; // sai do while(1) pois o produto foi adicionado
            }
        }
        else if (opcaixa == 2)
        {
            if (caixa2->fila[M - 1] != 0)
            {
                printf("Caixa 2 está cheio. Escolha outro.\n\n");
            }
            else
            {
                for (int i = 0; i < M; i++)
                {
                    if (caixa2->fila[i] == 0)
                    {
                        caixa2->fila[i] = produtos;
                        caixa2->totalProd += produtos;
                        break;
                    }
                }
                break;
            }
        }
        else if (opcaixa == 3)
        {
            if (caixa3->fila[M - 1] != 0)
            {
                printf("Caixa 3 está cheio. Escolha outro.\n\n");
            }
            else
            {
                for (int i = 0; i < M; i++)
                {
                    if (caixa3->fila[i] == 0)
                    {
                        caixa3->fila[i] = produtos;
                        caixa3->totalProd += produtos;
                        break;
                    }
                }
                break;
            }
        }
    }
    system("clear");
    printf("Produto adicionado com sucesso!\n");
}

int funcao2(Caixa *ptr)
{
    int posicao = 0;
    int maiorValor = ptr->fila[0]; // guarda o valor do primeiro

    for (int i = 1; i < M; i++)
    {
        if (ptr->fila[i] > maiorValor)
        {
            maiorValor = ptr->fila[i]; // atualiza o maior valor
            posicao = i;
        }
    }
    return posicao;
}

void funcao3(Caixa *caixa1, Caixa *caixa2, Caixa *caixa3)
{
    int vagaEncontrada = 0; // para saber se achou vaga no caixa 3

    printf("Iniciando reordenação de clientes (<= 15 produtos) para o Caixa 3...\n");

    // mover clientes do Caixa 1 para o Caixa 3
    for (int i = 0; i < M; i++)
    {
        if (caixa1->fila[i] > 0 && caixa1->fila[i] <= 15)
        {
            // ... (procura vaga) ...
            for (int j = 0; j < M; j++)
            {
                if (caixa3->fila[j] == 0)
                {
                    // ... (printf) ...

                    int produtosMovidos = caixa1->fila[i]; // Guarda o valor

                    // 1. Copia o valor
                    caixa3->fila[j] = produtosMovidos;

                    // 2. Retira o cliente
                    caixa1->fila[i] = 0;

                    // 3. ATUALIZA OS TOTAIS (LINHAS FALTANTES)
                    caixa3->totalProd += produtosMovidos;
                    caixa1->totalProd -= produtosMovidos;

                    vagaEncontrada = 1;
                    break;
                }
            }
            // Se o loop 'j' terminou e não encontramos vaga
            if (vagaEncontrada == 0)
            {
                printf("Caixa 3 está cheio. Não foi possível mover %d produtos do Caixa 1.\n",
                       caixa1->fila[i]);
                // Se o caixa 3 encheu, não adianta tentar mover mais ninguém do caixa 1
                break;
            }
        }
    }

    // mover clientes do Caixa 2 para o Caixa 3
    // (lógica é idêntica à anterior, mas para o caixa2)
    for (int i = 0; i < M; i++)
    {
        if (caixa2->fila[i] > 0 && caixa2->fila[i] <= 15)
        {
            for (int j = 0; j < M; j++)
            {
                if (caixa3->fila[j] == 0)
                {
                    int produtosMovidos = caixa2->fila[i];

                    caixa3->fila[j] = produtosMovidos;
                    caixa2->fila[i] = 0;   
                    caixa3->totalProd += produtosMovidos;
                    caixa2->totalProd -= produtosMovidos;

                    vagaEncontrada = 1;
                    break;
                }
            }
            if (vagaEncontrada == 0)
            {
                printf("Caixa 3 está cheio. Não foi possível mover %d produtos do Caixa 2.\n",
                       caixa2->fila[i]);
                // Se o caixa 3 encheu, para de tentar mover do caixa 2
                break;
            }
        }
    }

    // ordenar o Caixa 3 ---
    printf("\nOrdenando o Caixa 3...\n");
    int temp;
    for (int i = 0; i < M - 1; i++)
    {
        for (int j = 0; j < M - i - 1; j++)
        {
            // Se o elemento atual for MENOR que o próximo, troca
            // isso coloca os maiores valores no início
            if (caixa3->fila[j] < caixa3->fila[j + 1])
            {
                temp = caixa3->fila[j];
                caixa3->fila[j] = caixa3->fila[j + 1];
                caixa3->fila[j + 1] = temp;
            }
        }
    }

    // --- Parte 4: Imprimir o Caixa 3 ---
    printf("\n--- Caixa 3 - Fila Reordenada (Decrescente) ---\n");
    for (int i = 0; i < M; i++)
    {
        // Só imprime valores diferentes de 0 para clareza
        if (caixa3->fila[i] != 0)
        {
            printf("Posição %d: %d produtos\n", i, caixa3->fila[i]);
        }
        else
        {
            printf("Posição %d: [vazio]\n", i);
        }
    }
    printf("-----------------------------------------------\n");
}

int main()
{
    int produtos;
    Caixa caixa1;
    Caixa caixa2;
    Caixa caixa3;
    caixa1.id = '1';
    caixa1.totalProd = 0;
    caixa2.id = '2';
    caixa2.totalProd = 0;
    caixa3.id = '3';
    caixa3.totalProd = 0;

    // inicializa os vetores da fila com 0
    for (int i = 0; i < M; i++)
    {
        caixa1.fila[i] = 0;
        caixa2.fila[i] = 0;
        caixa3.fila[i] = 0;
    }
    // caixa1.fila[9] = 0; teste

    while (1)
    {
        int op, res, maiorcaixa = 0;

        printf("\n----------BEM VINDO----------\n");
        printf("Escolha sua função:\n");
        printf("Função 1 - escolher caixa\n");
        printf("Função 2 - ver posição na fila do maior comprador\n");
        printf("Função 3 - reordenar clientes para o caixa 3 e imprimir decrescente\n");
        printf("4 -Encerrar programa\n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("Digite a quantidade de produtos: ");
            scanf("%d", &produtos);
            funcao1(produtos, &caixa1, &caixa2, &caixa3);
            break;
        case 2:
            do
            {
                printf("Digite de qual caixa você quer ver o indice do maior comprador: ");
                scanf("%d", &maiorcaixa);
                if (maiorcaixa <= 0 || maiorcaixa > 3)
                {
                    printf("\nCaixa invalido, digite outro\n");
                }
            } while (maiorcaixa <= 0 || maiorcaixa > 3);
            switch (maiorcaixa)
            {
            case 1:
                res = funcao2(&caixa1);
                system("clear");
                printf("O indice na fila do comprador com maior quantidade de produtos eh: %d\n\n", res);
                break;
            case 2:
                res = funcao2(&caixa2);
                system("clear");
                printf("O indice na fila do comprador com maior quantidade de produtos eh: %d\n\n", res);
                break;
            case 3:
                res = funcao2(&caixa3);
                system("clear");
                printf("O indice na fila do comprador com maior quantidade de produtos eh: %d\n\n", res);
                break;
            default:
                break;
            }

            break;
        case 3:
            funcao3(&caixa1, &caixa2, &caixa3);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Digite uma opção válida");
            break;
        }
    }
    return 0;
}
