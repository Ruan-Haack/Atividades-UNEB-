#include <stdio.h>
#include <stdlib.h> // Para system()
#include <string.h> // Para strlen() e strcspn()
#include <ctype.h>  // Para isupper()

#define TAM 3 // tamamanho de alunos

typedef struct aluno
{ /// definindo struct
    char nome[25];
    char mat[11];
    int idade;
    float notas[3];
    float media;
} Aluno;

void login();
void menu();
void ler();
void imprimirAlunos();
void mudarNota();
int verificarAluno();
void ordenarPorNome();

void pausar()
{
    printf("\nPressione Enter para continuar...\n");
    getchar(); // esperar o enter
}

// Função para remover a quebra de linha do fgets
void remover_newline(char *str)
{
    str[strcspn(str, "\n")] = '\0'; //
}
// Função para limpar o buffer de entrada
void limpar_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void login()

{

    // utilizado para limpar a tela do terminal
    system("clear");
    printf("--------Sistema Acadêmico--------\n");

    char login[250];
    char senha[25];

    printf("Login: ");
    fgets(login, sizeof(login), stdin); // ler uma linha de texto
    remover_newline(login);             // Remove o \n que o fgets deixa

    do
    {
        printf("Senha: ");
        fgets(senha, sizeof(senha), stdin);
        remover_newline(senha);

        int temMaiuscula = 0;
        int temSimbolo = 0;
        int temTamanhoMinimo = 0;

        if (strlen(senha) >= 8) // validação de tamanho da senha
        {
            temTamanhoMinimo = 1;
        }
        else
        {
            printf("A senha deve ter no minimo 8 caracteres!\n");
            pausar();
            system("clear"); // Limpa a tela para a próxima tentativa
            continue;        // Volta para o início do do-while
        }

        for (int i = 0; i < strlen(senha); i++)
        {
            if (isupper(senha[i])) // é maiúsculo?
            {
                temMaiuscula = 1;
            }
            // 3. Validação de símbolo
            if (senha[i] == '#' || senha[i] == '!' || senha[i] == '-')
            {
                temSimbolo = 1;
            }
        }

        if (temMaiuscula == 0) // não possui caracter Maiúsculo
        {
            printf("A senha deve conter ao menos um caractere maiúsculo!!\n");
            pausar();
            system("clear");
            continue;
        }
        if (temSimbolo == 0)
        {
            printf("A senha deve conter ao menos um simbolo!\n");
            pausar();
            system("clear");
            continue;
        }

        printf("\nLogin e senha validados com sucesso!\n");
        break;
    } while (1); // sempre rodará
}

void menu(Aluno turmaSI[TAM])
{

    while (1)
    {
        int opc = 0;

        printf("1- Preencher dados dos alunos\n");
        printf("2- Imprimir alunos\n");
        printf("3- Mudar nota\n");
        printf("4- Encerrar\n");

        printf("Escolha sua opção: ");
        scanf("%d", &opc);
        limpar_buffer();

        switch (opc)
        {
        case 1:
            system("clear");
            ler(turmaSI, TAM);
            break;
        case 2:
            system("clear");
            imprimirAlunos(turmaSI, TAM);
            pausar();
            break;
        case 3:
            system("clear");
            mudarNota(turmaSI, TAM);
            break;
        case 4:
            printf("Programa encerrando.....");
            return;
        }
    }
}
void ler(Aluno alunos[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("--------- Aluno %d ---------\n", i + 1);
        printf("Nome: ");
        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);
        remover_newline(alunos[i].nome);
        printf("Matricula: ");
        fgets(alunos[i].mat, sizeof(alunos[i].mat), stdin);
        remover_newline(alunos[i].mat);
        printf("Idade: ");
        scanf("%d", &alunos[i].idade);
        limpar_buffer();
        alunos[i].media = 0.0;
        float somamedia = 0.0;

        for (int j = 0; j < 3; j++)
        {
            do
            {
                float nota;

                printf("Digite a %d nota: ", j + 1);
                scanf("%f", &nota);
                limpar_buffer();

                if (nota >= 0 && nota <= 10)
                {
                    alunos[i].notas[j] = nota;
                    break;
                }
                else
                {
                    printf("Digite um valor entre 0 e 10!\n");
                    pausar();
                }
            } while (1);

            somamedia += alunos[i].notas[j]; // calculando media do aluno[i]
        }
        alunos[i].media = somamedia / 3.0;
    }
}
void imprimirAlunos(Aluno alunos[], int tam)
{
    ordenarPorNome(alunos, TAM);
    printf("----- Alunos Cadastarados -----\n");
    for (int i = 0; i < tam; i++)
    {
        printf("----------------------\n");
        printf("Nome: %s\n", alunos[i].nome);
        printf("Matricula: %s\n", alunos[i].mat);
        printf("Idade: %d\n", alunos[i].idade);
        for (int j = 0; j < 3; j++)
        {
            printf("Nota %d: %.2f\n", j + 1, alunos[i].notas[j]);
        }
        printf("Media: %.2f\n", alunos[i].media);
        printf("----------------------\n");
    }
}
void mudarNota(Aluno alunos[], int tam)
{
    printf("----- Corrigir Nota -----\n");

    char mat[10];

    printf("Digite a matricula: ");
    fgets(mat, sizeof(mat), stdin);
    remover_newline(mat);
    int alunoPos = verificarAluno(mat, alunos, tam);

    if (alunoPos == -1)
    {
        printf("Aluno nao encontrado!\n");
    }
    else
    {
        char opt;

        for (int i = 0; i < 3; i++)
        {
            printf("Corrigir a %d nota? [y/n] ", i + 1);
            scanf(" %c", &opt);
            limpar_buffer();

            if (opt == 'y')
            {
                do
                {
                    float novaNota;

                    printf("Digite a nova nota: ");
                    scanf("%f", &novaNota);
                    getchar();

                    if (novaNota >= 0 && novaNota <= 10)
                    {
                        alunos[alunoPos].notas[i] = novaNota;
                        break;
                    }
                    else
                    {
                        printf("[ERRO]Digite um valor entre 0 e 10[ERRO]!\n");
                    }
                } while (1);
            }
        }
        float novaSoma = 0.0;
        for (int i = 0; i < 3; i++)
        {
            novaSoma += alunos[alunoPos].notas[i];
        }
        alunos[alunoPos].media = novaSoma / 3.0;

        printf("\nNotas atualizadas! A nova média do aluno é %.2f\n", alunos[alunoPos].media);
        pausar();
    }
}

int verificarAluno(char mat[], Aluno alunos[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        if (strcmp(mat, alunos[i].mat) == 0)
        {
            return i;
        }
    }
    return -1;
}

void ordenarPorNome(Aluno alunos[], int n)
{ // bubble sort
    Aluno temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (strcmp(alunos[j].nome, alunos[j + 1].nome) > 0)
            {

                temp = alunos[j];
                alunos[j] = alunos[j + 1];
                alunos[j + 1] = temp;
            }
        }
    }
}
int main()
{
    Aluno turmaSI[TAM];
    login();
    menu(turmaSI);

    return 0;
}