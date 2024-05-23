#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FUNCIONARIOS 5

struct Funcionario {
    char nome[50];
    int idade;
    float salario;
};

int compararIdade(const void *a, const void *b) {
    const struct Funcionario *funcionarioA = (const struct Funcionario *)a;
    const struct Funcionario *funcionarioB = (const struct Funcionario *)b;

    return funcionarioA->idade - funcionarioB->idade;
}

void imprimirFuncionarios(struct Funcionario funcionarios[], int numFuncionarios) {
    for (int i = 0; i < numFuncionarios; i++) {
        printf("Nome: %s, Idade: %d, Salario: %.2f\n", funcionarios[i].nome, funcionarios[i].idade, funcionarios[i].salario);
    }
}

int main() {
    struct Funcionario funcionarios[MAX_FUNCIONARIOS] = {
        {"Joao", 25, 2500.0},
        {"Maria", 30, 2800.0},
        {"Pedro", 22, 2200.0},
        {"Ana", 35, 3000.0},
        {"Carlos", 28, 2700.0}
    };

    printf("Funcionarios antes da ordenacao:\n");
    imprimirFuncionarios(funcionarios, MAX_FUNCIONARIOS);

    qsort(funcionarios, MAX_FUNCIONARIOS, sizeof(struct Funcionario), compararIdade);

    printf("\nFuncionarios depois da ordenacao por idade:\n");
    imprimirFuncionarios(funcionarios, MAX_FUNCIONARIOS);

    return 0;
}
