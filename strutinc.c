#include <stdio.h>

typedef struct {
        
        char nome[10];
        int n1;
        int n2;
        int n3;
        float media;
        
    } tipoAluno;
    
int main()
{

    tipoAluno aluno01;
    tipoAluno alunos[3];
    
    printf("CADASTRO DOS ALUNOS \n");
    for (int i = 0; i < 3; i++) {
        
        printf("Nome do aluno: \n");
        scanf("%s", alunos[i].nome);
        
        printf("Informe a nota 1 do aluno: \n");
        scanf("%d", &alunos[i].n1);
        printf("Informe a nota 2 do aluno: \n");
        scanf("%d", &alunos[i].n2);
        printf("Informe a nota 3 do aluno: \n");
        scanf("%d", &alunos[i].n3);
        
        alunos[i].media = (alunos[i].n1 + alunos[i].n2 + alunos[i].n3)/3.0;
        
    }
    
      printf("\n\nIPRESSÃO DOS ALUNOS \n\n");
      
    for (int i = 0; i < 3; i++) {
        
        printf("Nome: %s \n", alunos[i].nome);
        printf("Nota 1: %d \n", alunos[i].n1);
        printf("Nota 2: %d \n", alunos[i].n2);
        printf("Nota 3: %d \n", alunos[i].n3);
        printf("A media de %s foi: %.2f \n\n", alunos[i].nome, alunos[i].media);
        
    }

	return 0;
}
