#include <stdio.h>
#include <string.h>

typedef struct Aluno { ///definindo struct
char nome[25];
char mat[11];
int idade;
float notas[3];
float media;
} Aluno;

#define A 4 //quantidade de aluno
#define N 3 //quantidade de notas
Aluno alunoSI[A];

//fazer com 100 alunos utilizando função
void dadosAluno() 
{
    for (int i = 0; i < A; i++)
    {
        printf("\nDigite o nome do aluno %d:", i+1);
        scanf("%s", alunoSI[i].nome);
        // fgets(alunoSI[i].nome, sizeof(alunoSI[i].nome), stdin);

        printf("Digite a matricula do aluno %d:", i+1);
        scanf("%s", alunoSI[i].mat);
        // fgets(alunoSI[i].mat, sizeof(alunoSI[i].mat), stdin);

        printf("Digite a idade do aluno %d:", i+1);
        scanf("%d", &alunoSI[i].idade);

        printf("-------NOTAS DO ALUNO-------\n\n");
            for(int j = 0; j < N; j++){
                printf("Digite a nota %d do aluno %s: ", j + 1, alunoSI[i].nome);
                scanf("%f", &alunoSI[i].notas[j]);
            }
        // alunoSI[].media += alunoSI.notas[i];

    }   
}
float notas_aluno(int a) 
{   
    float media = 0.0;
    for (int i = 0; i < A; i++)
    {
        media += alunoSI[a].notas[i];
    }
    media /= N;
    return media;
}

int main() {
    int a = 1;
    // int op = 1;
    printf("\nDigite os dados da struct\n\n");
    dadosAluno();

    while (a != 0)
    {
        printf("Digite o número do aluno que você quer saber a media ou 0 para encerrar: ");
        scanf("%d", &a); //diferente de zero 
        if(a == 0) {
            break;
        }
        float media = notas_aluno(a-1);
        printf("****************************\n\n");
        printf("A média de %s é %.2f\n", alunoSI[a-1].nome, media);
        printf("****************************\n\n");
    }
}