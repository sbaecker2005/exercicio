
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_MAXIMO_NOME 50
#define MAX_FUNCIONARIOS 100

struct Funcionario {
    char nome[TAMANHO_MAXIMO_NOME];
    int idade;
    float salario;
};

void adicionarRegistro(FILE *arquivo) {
    struct Funcionario novoFuncionario;

    printf("Digite o nome do funcionario: ");
    fgets(novoFuncionario.nome, TAMANHO_MAXIMO_NOME, stdin);
    novoFuncionario.nome[strcspn(novoFuncionario.nome, "\n")] = '\0'; // Remove a nova linha do final

    printf("Digite a idade do funcionario: ");
    scanf("%d", &novoFuncionario.idade);
    while (getchar() != '\n'); // Limpa o buffer de entrada

    printf("Digite o salario do funcionario: ");
    scanf("%f", &novoFuncionario.salario);
    while (getchar() != '\n'); // Limpa o buffer de entrada

    if (fwrite(&novoFuncionario, sizeof(struct Funcionario), 1, arquivo) != 1) {
        printf("Erro ao adicionar registro.\n");
    } else {
        printf("Registro adicionado com sucesso.\n");
    }
}


void listarRegistros(FILE *arquivo) {
    rewind(arquivo); 
    struct Funcionario funcionario;

    printf("\n=== Registros de Funcionarios ===\n");
    while (fread(&funcionario, sizeof(struct Funcionario), 1, arquivo)) {
        printf("Nome: %s\n", funcionario.nome);
        printf("Idade: %d\n", funcionario.idade);
        printf("Salario: %.2f\n", funcionario.salario);
        printf("\n");
    }
}

void buscarPorNome(FILE *arquivo, char *nomeBusca) {
    rewind(arquivo); 

    struct Funcionario funcionario;
    int encontrado = 0;

    while (fread(&funcionario, sizeof(struct Funcionario), 1, arquivo)) {
        if (strcmp(funcionario.nome, nomeBusca) == 0) {
            printf("Registro encontrado:\n");
            printf("Nome: %s\n", funcionario.nome);
            printf("Idade: %d\n", funcionario.idade);
            printf("Salario: %.2f\n", funcionario.salario);
            printf("\n");
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("Registro nao encontrado para o nome '%s'.\n", nomeBusca);
    }
}


void salvarFuncionarios(FILE *arquivo, struct Funcionario *novosFuncionarios, int numNovosFuncionarios) {
    fseek(arquivo, 0, SEEK_END);

    for (int i = 0; i < numNovosFuncionarios; i++) {
        if (fwrite(&novosFuncionarios[i], sizeof(struct Funcionario), 1, arquivo) != 1) {
            printf("Erro ao salvar registro.\n");
            return;
        }
    }

    printf("Registros salvos com sucesso.\n");
}int main() {
    FILE *arquivo;
    int opcao;
    char nomeBusca[TAMANHO_MAXIMO_NOME];
    struct Funcionario novosFuncionarios[MAX_FUNCIONARIOS];
    int numNovosFuncionarios = 0;

    arquivo = fopen("funcionarios.bin", "ab+");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    do {
        printf("\n===== Menu =====\n");
        printf("1. Adicionar novo registro de funcionario\n");
        printf("2. Listar todos os registros de funcionarios\n");
        printf("3. Buscar por nome de funcionario\n");
        printf("4. Salvar registros de funcionarios\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        while (getchar() != '\n');

        switch (opcao) {
            case 1:
                if (numNovosFuncionarios < MAX_FUNCIONARIOS) {
                    adicionarRegistro(arquivo);
                    numNovosFuncionarios++;
                } else {
                    printf("Limite de funcionarios atingido.\n");
                }
                break;
            case 2:
                listarRegistros(arquivo);
                break;
            case 3:
                printf("Digite o nome a ser buscado: ");
                fgets(nomeBusca, TAMANHO_MAXIMO_NOME, stdin);
                nomeBusca[strcspn(nomeBusca, "\n")] = '\0'; 
                buscarPorNome(arquivo, nomeBusca);
                break;
            case 4:
                salvarFuncionarios(arquivo, novosFuncionarios, numNovosFuncionarios);
                break;
            case 5:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 5);

    fclose(arquivo);

    return 0;
}
