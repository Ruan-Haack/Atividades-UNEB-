#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição das estruturas conforme a prova
typedef struct {
    char nome[25];
    char sexo; // 'M' ou 'F'
    int idade;
} Registro;

typedef struct {
    char nome[25];
    float porcentagem;
    int votos; // Auxiliar para contagem
} Resultado;

// Lista de opções de voto possíveis (para facilitar a contagem)
const char *OPCOES[] = {"Luís", "Flavio", "Ronaldo", "Társis", "Romeu", "Renan", "Branco", "Nulo", "Indeciso"};
const int NUM_OPCOES = 9;

// ============================================================================
// FUNÇÃO AUXILIAR: Cria um arquivo de teste para podermos rodar o código
// TESTES
// ============================================================================
void criar_arquivo_teste(const char *nome_arq) {
    FILE *arq = fopen(nome_arq, "wb");
    if (!arq) return;
    
    // Inserindo alguns dados fictícios
    Registro dados[] = {
        {"Luís", 'F', 20}, {"Ronaldo", 'M', 40}, {"Romeu", 'M', 60},
        {"Indeciso", 'F', 32}, {"Nulo", 'M', 70}, {"Luís", 'M', 25},
        {"Luís", 'F', 30}, {"Ronaldo", 'F', 22}, {"Branco", 'M', 18},
        {"Társis", 'F', 50}, {"Luís", 'M', 45}, {"Ronaldo", 'M', 33}
    };
    
    fwrite(dados, sizeof(Registro), 12, arq);
    fclose(arq);
    printf("--- Arquivo de teste '%s' criado com sucesso ---\n\n", nome_arq);
}

// ============================================================================
// QUESTÃO 1: Retornar tabela de porcentagens ordenada
// ============================================================================
Resultado* gerar_tabela_resultados(FILE *arq, int *tamanho_retorno) {
    // Aloca a tabela de resultados
    Resultado *tabela = (Resultado *)malloc(NUM_OPCOES * sizeof(Resultado));
    
    // Inicializa a tabela
    for (int i = 0; i < NUM_OPCOES; i++) {
        strcpy(tabela[i].nome, OPCOES[i]);
        tabela[i].votos = 0;
        tabela[i].porcentagem = 0.0;
    }

    Registro reg;
    int total_votos = 0;

    // Garante que o ponteiro do arquivo está no início
    rewind(arq);

    // Leitura do arquivo binário
    while (fread(&reg, sizeof(Registro), 1, arq) == 1) {
        total_votos++;
        // Procura o nome lido na nossa tabela para incrementar o voto
        for (int i = 0; i < NUM_OPCOES; i++) {
            if (strcmp(reg.nome, tabela[i].nome) == 0) {
                tabela[i].votos++;
                break;
            }
        }
    }

    // Calcula porcentagens
    if (total_votos > 0) {
        for (int i = 0; i < NUM_OPCOES; i++) {
            tabela[i].porcentagem = ((float)tabela[i].votos / total_votos) * 100.0;
        }
    }

    // Ordenação (Bubble Sort) - Maior porcentagem para menor
    for (int i = 0; i < NUM_OPCOES - 1; i++) {
        for (int j = 0; j < NUM_OPCOES - i - 1; j++) {
            if (tabela[j].porcentagem < tabela[j+1].porcentagem) {
                Resultado temp = tabela[j];
                tabela[j] = tabela[j+1];
                tabela[j+1] = temp;
            }
        }
    }

    *tamanho_retorno = NUM_OPCOES;
    return tabela;
}

// ============================================================================
// QUESTÃO 2: Estatísticas demográficas (Retornando via parâmetros por referência)
// ============================================================================
/* Como C retorna apenas um valor, usaremos ponteiros para armazenar os resultados solicitados:
   - nome_win_F: buffer para nome do mais votado por mulheres
   - nome_win_M: buffer para nome do mais votado por homens
   - media_F: ponteiro para média de idade feminina
   - media_M: ponteiro para média de idade masculina
*/
void estatisticas_demograficas(FILE *arq, char *nome_win_F, char *nome_win_M, float *media_F, float *media_M) {
    Registro reg;
    
    // Contadores para média de idade
    int soma_idade_F = 0, count_F = 0;
    int soma_idade_M = 0, count_M = 0;

    // Estruturas auxiliares para contar votos por sexo
    // Vamos usar arrays paralelos simples mapeados pelos índices de OPCOES
    int votos_F[9] = {0}; 
    int votos_M[9] = {0};

    rewind(arq); // Reinicia leitura do arquivo

    while (fread(&reg, sizeof(Registro), 1, arq) == 1) {
        // Achar índice do candidato
        int idx = -1;
        for(int i=0; i<NUM_OPCOES; i++) {
            if(strcmp(reg.nome, OPCOES[i]) == 0) {
                idx = i;
                break;
            }
        }

        if (idx != -1) {
            if (reg.sexo == 'F') {
                soma_idade_F += reg.idade;
                count_F++;
                votos_F[idx]++;
            } else if (reg.sexo == 'M') {
                soma_idade_M += reg.idade;
                count_M++;
                votos_M[idx]++;
            }
        }
    }

    // Calcular Médias
    *media_F = (count_F > 0) ? (float)soma_idade_F / count_F : 0.0;
    *media_M = (count_M > 0) ? (float)soma_idade_M / count_M : 0.0;

    // Achar vencedores por sexo
    int max_votos_F = -1, max_idx_F = -1;
    int max_votos_M = -1, max_idx_M = -1;

    for(int i=0; i<NUM_OPCOES; i++) {
        if (votos_F[i] > max_votos_F) {
            max_votos_F = votos_F[i];
            max_idx_F = i;
        }
        if (votos_M[i] > max_votos_M) {
            max_votos_M = votos_M[i];
            max_idx_M = i;
        }
    }

    if (max_idx_F != -1) strcpy(nome_win_F, OPCOES[max_idx_F]);
    else strcpy(nome_win_F, "Nenhum");

    if (max_idx_M != -1) strcpy(nome_win_M, OPCOES[max_idx_M]);
    else strcpy(nome_win_M, "Nenhum");
}

// ============================================================================
// QUESTÃO 3: Verificar Empate Técnico
// ============================================================================
void verificar_empate(Resultado *tabela, int *empate) {
    // tabela[0] é o primeiro colocado, tabela[1] é o segundo (pois já ordenamos na Q1)
    
    float p1 = tabela[0].porcentagem;
    float p2 = tabela[1].porcentagem;
    
    // Lógica da prova:
    // Candidato 1 = p1 => p1 - 3%
    // Candidato 2 = p2 => p2 + 3%
    // Se (p1 - 3) <= (p2 + 3), então é empate técnico.
    
    if ((p1 - 3.0) <= (p2 + 3.0)) {
        *empate = 1; // Verdadeiro
    } else {
        *empate = 0; // Falso
    }
}

// ============================================================================
// MAIN (Para execução e teste)
// ============================================================================
int main() {
    char nome_arquivo[] = "ResultadosNov.dat";
    
    // 1. Criar arquivo fictício para teste
    criar_arquivo_teste(nome_arquivo);
    
    // 2. Abrir arquivo para leitura
    FILE *arq = fopen(nome_arquivo, "rb");
    if (!arq) {
        printf("Erro ao abrir arquivo.\n");
        return 1;
    }

    // --- Execução da Questão 1 ---
    int qtd_res;
    Resultado *tabela = gerar_tabela_resultados(arq, &qtd_res);
    
    printf("=== RESULTADO DA PESQUISA (QUESTAO 1) ===\n");
    printf("%-15s | %s\n", "Candidato", "Votos (%)");
    printf("-------------------------------\n");
    for(int i=0; i<qtd_res; i++) {
        printf("%-15s | %.2f%%\n", tabela[i].nome, tabela[i].porcentagem);
    }
    printf("\n");

    // --- Execução da Questão 2 ---
    char win_F[25], win_M[25];
    float med_F, med_M;
    
    estatisticas_demograficas(arq, win_F, win_M, &med_F, &med_M);
    
    printf("=== ESTATISTICAS DEMOGRAFICAS (QUESTAO 2) ===\n");
    printf("Mais votado por Mulheres: %s\n", win_F);
    printf("Mais votado por Homens:   %s\n", win_M);
    printf("Idade media Feminina:     %.1f anos\n", med_F);
    printf("Idade media Masculina:    %.1f anos\n", med_M);
    printf("\n");

    // --- Execução da Questão 3 ---
    int eh_empate = 0;
    verificar_empate(tabela, &eh_empate);
    
    printf("=== ANALISE DE EMPATE TECNICO (QUESTAO 3) ===\n");
    printf("O 1o (%s) e o 2o (%s) estao em empate?\n", tabela[0].nome, tabela[1].nome);
    if (eh_empate) {
        printf("RESULTADO: SIM (1)\n");
    } else {
        printf("RESULTADO: NAO (0)\n");
    }

    // Limpeza
    free(tabela);
    fclose(arq);
    
    return 0;
}